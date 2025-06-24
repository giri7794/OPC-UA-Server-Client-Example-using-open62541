#include "opcua_server_wrapper.h"

OpcUaServerWrapper::OpcUaServerWrapper() {
    server = UA_Server_new();
    UA_ServerConfig *config = UA_Server_getConfig(server);
    UA_ServerConfig_setDefault(config);  // ✅ This binds to 0.0.0.0:4840 automatically
}

OpcUaServerWrapper::~OpcUaServerWrapper() {
    UA_Server_delete(server);
}

void OpcUaServerWrapper::addVariableNode(const char* name, int nodeId, int value) {
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    UA_Int32 val = value;
    UA_Variant_setScalar(&attr.value, &val, &UA_TYPES[UA_TYPES_INT32]);
    attr.description = UA_LOCALIZEDTEXT(const_cast<char*>("en-US"), const_cast<char*>(name));
    attr.displayName = UA_LOCALIZEDTEXT(const_cast<char*>("en-US"), const_cast<char*>(name));
	
    UA_NodeId varNodeId = UA_NODEID_NUMERIC(1, nodeId);
    UA_QualifiedName varName = UA_QUALIFIEDNAME(1, const_cast<char*>(name));
    UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
    UA_NodeId variableType = UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE);

    UA_Server_addVariableNode(
        server, varNodeId, parentNodeId,
        UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES),
        varName, variableType, attr, nullptr, nullptr);
}

void OpcUaServerWrapper::run(volatile sig_atomic_t *running) {
    // Create a UA_Boolean that will be passed to the server
    static volatile UA_Boolean serverRunning = true;

    // Thread to watch the `sig_atomic_t` flag and stop the server cleanly
    std::thread monitor([&]() {
        while (*running) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        serverRunning = false;
    });

    // Start server loop (pass pointer to `serverRunning`)
    UA_StatusCode retval = UA_Server_run(server, &serverRunning);

    if (retval != UA_STATUSCODE_GOOD) {
        std::cerr << "Server exited with error: " << UA_StatusCode_name(retval) << std::endl;
    }

    monitor.join();
}
