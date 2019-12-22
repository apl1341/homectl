//client.cpp

#include "clientsession.h"

#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;
using ip::tcp;

int main(int c, char** argc){
	cout<<"Welcome to homectl client for unix/linux"<<endl;
	ClientSession session(1234);
}
