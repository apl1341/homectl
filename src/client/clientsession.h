#include "../com/session.h"

class ClientSession : public Session{
	private:
		int n;
	public:
		ClientSession(int, string);
		void connect();
};
