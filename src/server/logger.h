#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Logger{//logs events for server
	private:
		string fp;
	public:
		Logger(string);
		void writeln(string);
		int size();
};
