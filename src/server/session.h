#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::tcp;

class Session{
	private:
		tcp::socket socket;
		const int buf_sz = 1024;//max size for a buffer
	public:
		Session(boost::asio::io_service&);
		void sendMessage(string& msg);
		string readMessage();
}
