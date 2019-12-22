#include <iostream>
#include <boost/asio.hpp>

#include "serversession.h"

using namespace boost::asio;
using namespace std;
using boost::asio::ip::tcp;

int main(int c, char** argc){
	cout<<"Starting homectl server..."<<endl;
	ServerSession session(1200);
	session.connect();
	session.getConnections();
	while(true){
		string g = session.readMessage();
		cout<<g<<endl;
	}
}
