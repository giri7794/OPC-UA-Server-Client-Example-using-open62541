#ifndef OPCUA_SERVER_WRAPPER_H
#define OPCUA_SERVER_WRAPPER_H

#pragma once

#include <iostream>
#include <csignal>
#include <thread>
#include <open62541/server_config_default.h>
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>

class OpcUaServerWrapper {
public:
    OpcUaServerWrapper();
    ~OpcUaServerWrapper();

    void addVariableNode(const char* name, int nodeId, int value);
    void run(volatile sig_atomic_t *running);

private:
    UA_Server* server;
};

#endif // OPCUA_SERVER_WRAPPER_H
