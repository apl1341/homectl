#include "promptreader.h"

PromptReader::PromptReader(string pr, size_t ml):prompt(pr), max_input(ml){
	this->prompt.append("> ");
}

string PromptReader::getInput(){
	printf(this->prompt.c_str());
	char* in;
	fgets(in, max_input, stdin);
	printf(in);
	return string(in);
}
