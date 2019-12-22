#include "session.h"

Session::Session(int port):acc(ios, tcp::endpoint(tcp::v4(), port)), 
	socket(ios){
}


void Session::sendMessage(string& msg){
	const string message = msg + "\n";
	boost::asio::write(this->socket, boost::asio::buffer(message));
}
	

string Session::readMessage(){
	boost::asio::streambuf buf;
	boost::asio::read_until(this->socket, buf, "\n" );
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;
}
