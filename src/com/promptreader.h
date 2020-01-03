#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

class PromptReader{
	private:
		string prompt;
		size_t max_input;
	public:
		PromptReader(string, size_t);
		string getInput();
		void flush();
};

