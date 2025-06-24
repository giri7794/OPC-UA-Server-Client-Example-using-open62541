#include "includes/opcua_server_wrapper.h"
#include <csignal>
#include <iostream>

volatile sig_atomic_t running = 1;

static void signalHandler(int sig) {
    running = 0;
}

int main() {
    signal(SIGINT, signalHandler);  // Handle Ctrl+C
    signal(SIGTERM, signalHandler); // Handle termination signal

    OpcUaServerWrapper server;

    server.addVariableNode("MyNode", 1001, 42);

    std::cout << "\n\nServer running. Press Ctrl+C to stop.\n\n";
    server.run(&running);

    std::cout << "Server shutting down.\n";
    return 0;
}