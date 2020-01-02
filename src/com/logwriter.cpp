#include "logwriter.h"

LogWriter::LogWriter(const char* fname){
	this->file = fopen(fname, "w");
}

void LogWriter::write(string str){
	fprintf(this->file, str.c_str());
}

bool LogWriter::close(){
	fclose(this->file);
}
	
