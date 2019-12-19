#include "Lexer/Lexer.h"
#include "Parser/OpenServerCommand.h"
#include "Parser/Parser.h"
#include "Parser/Client.h"
#include "Parser/ConnectClientCommand.h"
#include "Parser/FuncCommand.h"
#include "Parser/PrintCommand.h"
#include "Parser/SleepCommand.h"
#include "Parser/StringUtils.cpp"

int main() {
    char * asasd = "\"asdasdasdasd\"";
    char result[123];
    sprintf(result, "%s",removeApostrophes(asasd).c_str());
    char filename[1024] = {0};
    strcpy(filename, "fly.txt");
    vector<string> *lexer = Lexer::getLexer(filename);

    map<string, Command *> mapCommand;

    Server server;
    OpenServerCommand serverCommand(server);
    mapCommand.insert(pair<string, Command *>("openDataServer", &serverCommand));

    Client client;
    ConnectClientCommand clientCommand(client);
    mapCommand.insert(pair<string, Command *>("connectControlClient", &clientCommand));

    PrintCommand printCommand;
    mapCommand.insert(pair<string, Command *>("Print", &printCommand));

    SleepCommand sleepCommand;
    mapCommand.insert(pair<string, Command *>("Sleep", &sleepCommand));

    thread serverTh(Server::runningServerThread, ref(server));
    thread clientTh(Client::runningClientThread, ref(client));

    Parser parser(mapCommand);
    parser.parse(*lexer);

//    server.closeSocketFD();
//    client.closeClientSocket();
    serverTh.join();
    clientTh.join();

    return 0;
}

