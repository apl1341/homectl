/** 
 * Uses lower-level C-style calls to write to files
 */

#include <iostream>
#include <string>
#include "protocol.h"

using namespace std;

class LogWriter{
	private:
		FILE* file;
	public:
		LogWriter(const char*);
		void write(string);//writes a single block or word to the log
		bool close();
};
	
