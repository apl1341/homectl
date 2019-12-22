#include <iostream>
#include <memory>
#include <string>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

using namespace std;

class Session{
	protected:
		int port;
		string bindaddr;
		boost::asio::io_service ios;
		tcp::socket* socket;
		const int buf_sz = 1024;//max size for a buffer
	public:
		Session(int, string);
		void sendMessage(const string&);
		virtual void connect() = 0;//init socket
		string readMessage();
};
