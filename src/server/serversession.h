#include "../com/session.h"

class ServerSession : public Session{
	private:
		int n;
		tcp::acceptor* acc;
	public:
		ServerSession(int);
		void getConnections();
		void connect();
};
