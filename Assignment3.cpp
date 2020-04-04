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
  // Check if the file exists
  if(!iStream){
    throw FileNotFoundException();
  }

  // Read through each character in the file
  while(!iStream.eof()){
    iStream >> noskipws >> c;
    if(c == '(' || c == '[' || c == '{'){
      // Push the starting delimiters onto the stack
      stack.push(c);
    }
    else if(c == '\n'){
      // Keeps track of what line we're on so we can use it to write error messages
      ++lineCount;
    }
    else if(c == ')' || c == ']' || c == '}'){
      first = stack.topStack();
      if(stack.isEmpty()){
        cout << "The stack is empty" << endl;
        throw EmptyStackException();
      }
      if(first == '(' && c != ')'){
        cout << "On line " << lineCount << ":expected ) and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      else if(first == '[' && c != ']'){
        cout << "On line " << lineCount << ":expected ] and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      else if(first == '{' && c != '}'){
        cout << "On line " << lineCount << ":expected } and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      stack.pop();
    }
  }
  iStream.close();
  if(stack.isEmpty()){
    cout << "The code is error-free." << endl;
  }
  first = stack.topStack();
  if(first == '('){
    cout << "End of file reached, expected )" << endl;
    exit(0);
  }
  else if(first == '['){
    cout << "End of file reached, expected ]" << endl;
    exit(0);
  }
  else if(first == '{'){
    cout << "End of file reached, expected }" << endl;
    exit(0);
  }
}
