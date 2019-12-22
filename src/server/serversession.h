#include "../com/session.h"

class ServerSession : Session{
	private:
		int n;
	public:
		ServerSession(int);
		void getConnections();
};
