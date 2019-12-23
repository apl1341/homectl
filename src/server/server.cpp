#include <iostream>
#include <boost/asio.hpp>

#include "serversession.h"

using namespace boost::asio;
using namespace std;
using boost::asio::ip::tcp;

void log_prompt(Session* session){
}
	
	

int main(int c, char** argc){
	cout<<"Starting homectl server..."<<endl;
	ServerSession session(1200);
	session.connect();
	session.getConnections();
	string in = session.readMessage();
	while(!in.empty()){
		if(in.compare("log") == 0){
			log_prompt(&session);
		}
		in = session.readMessage();
	}
		
}
