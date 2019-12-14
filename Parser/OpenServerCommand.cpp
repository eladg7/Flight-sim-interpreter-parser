#include "OpenServerCommand.h"
// Server side C/C++ program to demonstrate Socket programming

void OpenServerCommand::init(vector<std::string> &origLexer, int index) {
    for (int i = 1; i <= numberOfParameters; i++) {
        commandLexer.push_back(origLexer.at(index + i));
    }
//    if (commandLexer.size() == 0) {
//        port = 5400;
//    }else{
//
//    }
    port = stoi(commandLexer.at(0));
}

int OpenServerCommand::execute() {
    thread th(serverThread, this);
    th.join();
}

void OpenServerCommand::serverThread(void *obj) {
    //  TODO check if worked
    OpenServerCommand *myObj = (OpenServerCommand *) obj;
    myObj->threadWork();
}

void OpenServerCommand::threadWork() {
    int socketFd = openSocket();
    int clientSocket = bindListenSocket(socketFd);

    if (clientSocket < 0) {
        cerr << "server could not read data";
        return;
    }

    readFromClient(clientSocket);
    close(socketFd); //closing the listening socket
}

int OpenServerCommand::openSocket() {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }
    return socketfd;
}

int OpenServerCommand::bindListenSocket(int socketFd) {
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.
    //the actual bind command
    if (bind(socketFd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    if (listen(socketFd, MAX_CONNECTED) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    }
    std::cout << "Server is now listening ..." << std::endl;
    int client_socket = accept(socketFd, (struct sockaddr *) &address,
                               (socklen_t *) &address);

    if (client_socket == -1) {
        std::cerr << "Error accepting client" << std::endl;
        return -4;
    }
    std::cout << "Client connected ..." << std::endl;
    return client_socket;
}

void OpenServerCommand::readFromClient(int client_socket) {
//reading from client
    char buffer[2048] = {0};
    int valread = 1;
    while (valread != 0) {
        valread = read(client_socket, buffer, sizeof(buffer));
        addToMap(buffer, sizeof(buffer));
        //TODO create ad map and add the values read from server
    }
}

void OpenServerCommand::addToMap(char *buffer, int size) {
    mutex_lock.lock();

    mutex_lock.unlock();
}

////writing back to client
//    char *hello = "Hello, I can hear you! \n";
//    send(client_socket, hello, strlen(hello), 0);
//    std::cout << "Hello message sent\n" <<
//              std::endl;
//    return 0;