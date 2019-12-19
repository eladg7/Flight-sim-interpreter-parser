#include "Server.h"

int Server::openSocket() {
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }


    return 0;

}

int Server::bindSocket() {
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.
    //the actual bind command

    if (bind(socketFD, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }
    return 0;
}

int Server::listenToClients() {
    if (listen(socketFD, MAX_CONNECTED) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    }
    std::cout << "Server is now listening ..." << std::endl;
    return 0;
}


int Server::acceptClients() {
    clientSoc = accept(socketFD, (struct sockaddr *) &address,
                       (socklen_t *) &address);
    if (clientSoc < 0) {
        cerr << "Cannot accept connection" << endl;
        return -4;
    } else {
        cout << "Connection successful" << endl;
    }


    return 0;
}

void Server::runningServerThread(Server &server) {

    char buffer[264]={0};
    int isRead = 0;

    while (server.getClientSoc() == -1
    || server.getSocketFD() == -1) {
        sleep(1);
    }

    while (server.getSocketFD() != -1) {
        isRead = read(server.getClientSoc(), buffer, sizeof(buffer));
        if (isRead < 0) {
            cerr << "Cannot read from server" << endl;
            continue;
        }
        vector<double> values = valuesInDouble(buffer);
        SymbolTable::Instance()->updateSimMap(values);

        usleep(5000);
    }

    close(server.getSocketFD());
}

vector<double> Server::valuesInDouble(char *buffer) {
    vector<double> valuesInDouble;
    vector<string> valuesInString = Lexer::split(buffer, ',');
    for (string val:valuesInString) {
        valuesInDouble.push_back(atof(val.c_str()));
    }

    return valuesInDouble;
}

