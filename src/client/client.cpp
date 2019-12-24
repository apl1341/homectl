//client.cpp

#include "clientsession.h"
#include "../com/protocol.h"

#include <iostream>
#include <boost/asio.hpp>

#include "../com/promptreader.h"

using namespace boost::asio;
using namespace std;
using ip::tcp;

void log_prompt(Session* session){
	cout<<"homectl-unix/log (enter filename)> "<<endl;
	string fname;
	cin>>fname;
	session->sendMessage(fname);
	string r = session->readMessage();
	cout<<flush;
	PromptReader pr("homectl-unix/log");
	while(r.compare(LOG_PUT) == 0){
		string msg = pr.prompt('\n');	
		if(msg.compare("QQ") == 0){
			cout<<"Quitting log mode..."<<endl;
			session->sendMessage(END_LOG);
			return;
		}
		session->sendMessage(msg);
		r = session->readMessage();
	}
}
	

int main(int c, char** argc){
	if(c<2){
		cerr<<"usage: client hostname"<<endl;
		return 1;
	}
	string host = argc[1];
	cout<<"Welcome to homectl client for unix/linux"<<endl;
	cout<<"Connecting to host: "<<host<<endl;
	ClientSession session(1200, host);
	session.connect();
	string in;
	cin>>in;
	while(!in.empty()){
		if(in.compare("quit") == 0){
			cout<<"Exiting...\n";
			return 0;
		}
		cout<<"homectl-unix> ";
		session.sendMessage(in);
		string r = session.readMessage();
		if(r.compare(LOG) == 0){
			log_prompt(&session);
		}
		cin>>in;
	}
}
