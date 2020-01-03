#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/asio.hpp>

#include "serversession.h"
#include "../com/protocol.h"
#include "../com/logwriter.h"

using namespace boost::asio;
using namespace std;
using boost::asio::ip::tcp;

void log_prompt(Session* session){
	cout<<"Entering log mode"<<endl;
	session->sendMessage(LOG);
	string narg = session->readMessage();
	//the next arg is the file
	LogWriter lw(narg.c_str());
	session->sendMessage(LOG_PUT);
	narg = session->readMessage();
	while(!narg.empty()){
		lw.write(narg);
		session->sendMessage(LOG_PUT);
		narg = session->readMessage();
		if(narg.compare(END_LOG) == 0){
			cout<<"exiting log file and writing"<<endl;
			lw.close();
			return;
		}
	}
	lw.close();
}
	
	

int main(int c, char** argc){
	cout<<"Starting homectl server..."<<endl;
	ServerSession session(1200);
	session.connect();
	session.getConnections();
	string in = session.readMessage();
	cout<<flush;
	while(!in.empty()){
		if(in.compare(LOG) == 0){
			log_prompt(&session);
		}
		in = session.readMessage();
	}
		
}
