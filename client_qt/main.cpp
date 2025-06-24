#include <iostream>
#include <QCoreApplication>
#include "includes/opcua_client_wrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    OpcUaClientWrapper client("opc.tcp://192.168.29.18:4840");
    int value = client.readIntValue("MyNode", 1001);
    std::cout << "Read value: " << value << std::endl;

    return a.exec();
}
