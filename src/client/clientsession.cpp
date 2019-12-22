#include "clientsession.h"

ClientSession::ClientSession(int port, string host):Session(port, host){
	n = 2;
}

void ClientSession::connect(){
	this->socket = new tcp::socket(ios);
	this->socket->connect(tcp::endpoint(boost::asio::ip::address::from_string(bindaddr), port));
}
