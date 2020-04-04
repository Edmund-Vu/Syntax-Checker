#include <iostream>
#include <fstream>
#include "Assignment3.h"

using namespace std;

delimiter::delimiter(){

}

delimiter::~delimiter(){

}

int delimiter::checkDelimiters(){
  cout << "What is the name of the file you would like to check?" << endl;
  cin >> inputFile;
  GenStack<char>stack;

  ifstream iStream;
  iStream.open(inputFile);
  char c;
  int line = 1;

  if(!iStream){
    throw FileNotFoundException();
  }

  while(!iStream.eof()){
    iStream >> noskipws >> c;
    if(c == '(' || c == '[' || c == '{'){
      stack.push(c);
    }
    else if(c == '\n'){
      ++lineCount;
    }
    else if(c == ')' || c == ']' || c == '}'){
      first = stack.topStack();
      if(stack.isEmpty()){
        cout << "The stack is empty" << endl;
        throw EmptyStackException();
      }
      if(first == '(' && c != ')'){
        cout << "on line " << lineCount << ":expected ) and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
    }
  }
}
