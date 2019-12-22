#include "serversession.h"

ServerSession::ServerSession(int port) : Session(port) {
	int n = 1;
}

void ServerSession::getConnections(){
	cout<<"Getting connections..."<<endl;
	acc.accept(this->socket);
	cout<<"Connection recieved"<<endl;
}

