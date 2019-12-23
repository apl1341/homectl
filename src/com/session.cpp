#include "session.h"

Session::Session(int p, string host) : port(p), bindaddr(host){}


void Session::sendMessage(const string& msg){
	const string message = msg + "\n";
	boost::system::error_code err;
	boost::asio::write(*socket, boost::asio::buffer(message), err);
	if(err){
		cout<<"Error in connection: "<<err.message()<<endl;
	}
}
	

string Session::readMessage(){
	boost::asio::streambuf buf;
	boost::asio::read_until(*(this->socket), buf, "\n" );
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	data.erase(remove(data.begin(), data.end(), '\n'), data.end());
	return data;
}
