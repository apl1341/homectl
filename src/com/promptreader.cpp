//promptreader.cpp
#include "promptreader.h"

PromptReader::PromptReader(string p):cm_prompt(p){}

string PromptReader::prompt(char end_char){
  cout<<this->cm_prompt+"> ";
  string s;
  cin>>s;
  size_t f = s.find(end_char);
  if(f != string::npos){
    s[f] = '\0';
  }
  return s;
}
    
  
