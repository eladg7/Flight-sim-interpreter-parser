#include <queue>
#include "Client.h"
#include "SymbolTable.h"

int Client::openSocket() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Could not create a socket" << endl;
        return -1;
    }
}

int Client::connectClient() {
    //We need to create a sockaddr obj to hold address of server
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;//IP4
    address.sin_addr.s_addr = inet_addr(this->ip);  //the localhost address
    address.sin_port = htons(this->port);

    int is_connect = -1;
    int tryNumber = 5;
    while (tryNumber != 0) {
        is_connect = connect(this->clientSocket,
                             (struct sockaddr *) &address, sizeof(address));
        if (is_connect != -1) {
            std::cout << "Client is now connected to server" << endl;
            break;
        } else {
            usleep(5000);
            tryNumber--;
        }
    }


    return 1;
}

int Client::sendMessage(const char *msg) {
    int sent = send(this->clientSocket, msg, strlen(msg), 0);
    if (sent == -1) {
        std::cout << "Error sending message" << endl;
    } else {
        std::cout << "sent: " << msg << endl;
    }

    return 1;
}

void Client::runningClientThread(Client &client) {

    while (client.getClientSocket() == -1) {
        sleep(1);
    }
    client.turnOnRunningMode();
    while (client.getIsRunning()) {

        while ( !SymbolTable::Instance()->isQueueEmpty()) {
            string str= SymbolTable::Instance()->getLastMessage();
            char message[str.size()+1];
            strcpy(message,str.c_str());

            int is_sent = send(client.getClientSocket()
                    , message ,strlen(message) , 0 );

            if (is_sent == -1) {
                std::cout<<"Error changing value"<<std::endl;
            }
        }
        usleep(5000);
    }

    close(client.getClientSocket());
}

void Client::turnOffRunningMode() {
    isRunning=false;
}

void Client::turnOnRunningMode() {
    isRunning=true;
}
