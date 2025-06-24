#include "opcua_client_wrapper.h"
#include <iostream>

OpcUaClientWrapper::OpcUaClientWrapper(const char* endpoint) {
    client = UA_Client_new();
    UA_ClientConfig_setDefault(UA_Client_getConfig(client));
    UA_StatusCode status = UA_Client_connect(client, endpoint);
    if (status != UA_STATUSCODE_GOOD) {
        std::cerr << "Client connection failed: " << UA_StatusCode_name(status) << std::endl;
    }
}

OpcUaClientWrapper::~OpcUaClientWrapper() {
    UA_Client_disconnect(client);
    UA_Client_delete(client);
}

int OpcUaClientWrapper::readIntValue(const char* nodeUri, int nodeId) {
    UA_Variant value;
    UA_Variant_init(&value);

    UA_NodeId nodeIdToRead = UA_NODEID_NUMERIC(1, nodeId);
    UA_StatusCode status = UA_Client_readValueAttribute(client, nodeIdToRead, &value);

    if (status == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(&value, &UA_TYPES[UA_TYPES_INT32])) {
        return *(UA_Int32*)value.data;
    } else {
        std::cerr << "Failed to read value or unexpected type." << std::endl;
        return -1;
    }
}
