#include "clientsession.h"

ClientSession::ClientSession(int port):Session(port){
	n = 2;
}

ClientSession::connect(){
	this->socket =  new tcp::socket(ios);
}
