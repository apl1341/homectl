//promptreader.h
#include <iostream>
#include <string>

using namespace std;

class PromptReader{
 private:
  string cm_prompt;
 public:
  PromptReader(string);
  string prompt(char);
};
