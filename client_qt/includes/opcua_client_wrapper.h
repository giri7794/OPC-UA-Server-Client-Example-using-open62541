#ifndef OPCUA_CLIENT_WRAPPER_H
#define OPCUA_CLIENT_WRAPPER_H

#include "open62541.h"

class OpcUaClientWrapper {
public:
    OpcUaClientWrapper(const char* endpoint);
    ~OpcUaClientWrapper();

    int readIntValue(const char* nodeUri, int nodeId);

private:
    UA_Client* client;
};

#endif // OPCUA_CLIENT_WRAPPER_H
