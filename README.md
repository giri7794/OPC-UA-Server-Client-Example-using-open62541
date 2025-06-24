📡 OPC UA Server & Client Example using open62541
This repository contains a simple, functional OPC UA server implementation in C++ on Raspberry Pi (64-bit) and a matching Qt C++ client for Windows 11. The communication uses the open-source open62541 stack for OPC UA protocol compliance.

🧩 Prerequisites
1. open62541
Version: Latest stable release (tested with v1.3+)

Install on Raspberry Pi (for server):

sudo apt update
sudo apt install cmake build-essential
git clone https://github.com/open62541/open62541.git
cd open62541
cmake -DUA_NAMESPACE_ZERO=FULL -DBUILD_SHARED_LIBS=ON .
make
sudo make install

🖥️ Folder Structure

opc_ua_project/
├── server/                      # Raspberry Pi OPC UA server
│   ├── includes/
│   │   ├── opcua_server_wrapper.h
│   │   └── opcua_server_wrapper.cpp
│   ├── main.cpp
│   └── Makefile
├── client_qt/                   # Qt C++ client (Windows)
│   ├── includes/
│   │   ├── open62541.c
│   │   ├── open62541.h
│   │   ├── opcua_client_wrapper.h
│   │   └── opcua_client_wrapper.cpp
│   ├── main.cpp
│   └── opcua_client.pro
└── README.md

🚀 Building the Server (on Raspberry Pi)

cd server
make clean
make
./opcua_server

If build issues occur related to threading or network, ensure:

open62541 is compiled with -DUA_NAMESPACE_ZERO=FULL

You link with -lpthread

🧪 Running the Client (on Windows)
Open opcua_client.pro in Qt Creator

Build the project (ensure open62541.lib is linked)

Run the application

✅ Features
> Server creates and exposes custom variable nodes

> Client reads variable values and prints or displays

> Designed for extension into real-time monitoring or control systems

🛠️ To Do
> Add secure connection support (Basic256Sha256)

> Add write and subscription handling in client

> Dockerize server deployment (optional)

📚 Reference
open62541 documentation

OPC Foundation

Qt OPC UA Module (optional)

👨‍💻 Author
Giriprakash K.
Passionate about Embedded Systems, Industrial Protocols & Computer Vision.
