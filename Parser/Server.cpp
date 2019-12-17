#include "Server.h"

int Server::openSocket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    if (fd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        socketFD = -1;
        return -1;
    }
    socketFD = fd;
    return fd;
}

int Server::bindListenSocket(int socketFd) {
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address{}; //in means IP4
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
    if (client_socket < 0) {
        cerr << "Cannot accept connection" << endl;
        return 0;
    } else {
        cout << "Connection successful" << endl;
    }

    return client_socket;


}

void Server::readFromClient(int client_socket) {
//reading from client
    char buffer[2048] = {0};
    int valread = 1;
    while (valread != 0) {
        valread = read(client_socket, buffer, sizeof(buffer));
        SymbolTable st;
        st.addToMap(buffer, sizeof(buffer));
        //TODO create ad map and add the values read from server
    }
}