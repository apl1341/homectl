#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;
using boost::asio::ip::tcp;

int main(int c, char** argc){
	cout<<"Starting homectl server..."<<endl;
	io_service svc;
	tcp::acceptor acc(svc);
	acc.open(tcp::v4());
	acc.set_option(tcp::acceptor::reuse_address(1));
	acc.bind({{}, 4567});
	acc.listen(5);

}
