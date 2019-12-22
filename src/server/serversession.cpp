#include "serversession.h"

ServerSession::ServerSession(int p) : Session(p, "127.0.0.1") {
}

void ServerSession::getConnections(){
	cout<<"Getting connections..."<<endl;
	acc->accept(*this->socket);
	cout<<"Connection recieved"<<endl;
}

void ServerSession::connect(){
	this->acc = new tcp::acceptor(ios, tcp::endpoint(tcp::v4(), port));
	this->socket = new tcp::socket(ios);
}


