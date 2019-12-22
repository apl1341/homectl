#include "serversession.h"

ServerSession::ServerSession(int p) : Session(p) {
}

void ServerSession::getConnections(){
	cout<<"Getting connections..."<<endl;
	acc.accept(*this->socket);
	cout<<"Connection recieved"<<endl;
}

void ServerSession::connect(){
	this->acc = tcp::acceptor(ios, tcp::endpoint(tcp::v4(), 1234 ));
	this->socket = new tcp::socket(ios);
}


