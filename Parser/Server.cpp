#include "Server.h"

vector<string> Server::previousValues;


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
    char buffer[NUMBER_OF_VALUES] = {0};
    int isRead = 0;
    while (server.getClientSoc() == -1
           || server.getSocketFD() == -1) { //while socket with client isnt open
        sleep(1);
    }
    server.turnOnRunningMode();

    while (server.getIsRunning()) {

        isRead = read(server.getClientSoc(), buffer, sizeof(buffer));
        if (isRead <= 0) {//error getting info from client.
            cout << "Turning off server..." << endl;
            exit(1);
        }
        vector<double> values = valuesInDouble(buffer);//get values fro, buffer
        SymbolTable::Instance()->updateSimMap(values);// update all sim values

        usleep(5000);
    }

    close(server.getSocketFD());

}

vector<double> Server::valuesInDouble(char buffer[NUMBER_OF_VALUES]) {
    vector<double> valuesInDouble;
    vector<string> splittedByN = Lexer::split(buffer, '\n');
    vector<string> valuesInString = getRelevantValuesVector(buffer, splittedByN);

    valuesInDouble.reserve(valuesInString.size());//init
    for (const string &val:valuesInString) {
        valuesInDouble.push_back(atof(val.c_str()));
    }

    return valuesInDouble;
}

vector<string> Server::getRelevantValuesVector(char buffer[NUMBER_OF_VALUES], vector<string> splittedByN) {
    vector<string> valuesInString;
    if (splittedByN.size() == 0) {
        return valuesInString;
    }
    auto firstChunk = Lexer::split(splittedByN.at(0), ',');
    if (splittedByN.size() == 1) {
        //  the relevant values are in the last chunk
        valuesInString = firstChunk;
    } else {
        auto secondChunk = Lexer::split(splittedByN.at(1), ',');
        if (secondChunk.size() == 36) {
            //  update values from the first chunk, save the rest
            Server::previousValues.clear();
            //  push back the rest of the values
            valuesInString = secondChunk;
        } else if (firstChunk.size() == 36) {
            //  update values from the first chunk, save the rest
            Server::previousValues.clear();
            valuesInString = firstChunk;
            //  push back the rest of the values
            Server::previousValues = secondChunk;
        } else if (firstChunk.size() < 36) {
            //  update values from the first chunk and add them to the previous values, save the rest
            Server::previousValues.insert(end(Server::previousValues), begin(firstChunk), end(firstChunk));
            valuesInString.clear();
            valuesInString = Server::previousValues;
            //  push back the rest of the values
            Server::previousValues = secondChunk;
        }
    }
    return valuesInString;
}


void Server::turnOffRunningMode() {
    isRunning = false;
}

void Server::turnOnRunningMode() {
    isRunning = true;
}

