#include "session.h"

Session::Session(int p) : port(p){
}


void Session::sendMessage(const string& msg){
	const string message = msg + "\n";
	boost::system::error_code err;
	boost::asio::write(*(this->socket), boost::asio::buffer(message), err);
	if(err){
		cout<<"Error in connection"<<endl;
	}
}
	

string Session::readMessage(){
	boost::asio::streambuf buf;
	boost::asio::read_until(*(this->socket), buf, "\n" );
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;
}
