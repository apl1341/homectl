#include <iostream>
#include <memory>
#include <string>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

using namespace std;

class Session{
	protected:
		boost::asio::io_service ios;
		tcp::socket socket;
		tcp::acceptor acc;
		const int buf_sz = 1024;//max size for a buffer
	public:
		Session(int);
		void sendMessage(string&);
		string readMessage();
};
