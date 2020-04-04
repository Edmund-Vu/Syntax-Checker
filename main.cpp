#include "Assignment3.h"

int main(int argc, char **argv){
  GenStack<char> stack;
  // Try block to handle exceptions that occur
  try{
    delimiter d;
    bool exit;
    char c;
    // While loop to prompt user if they want to check another file.
    while(exit){
      d.checkDelimiters();
      cout << "Would you like to check another file? (Y/N)" << endl;
      cin >> c;
      if(c == 'N'){
        exit = false;
      }
    }
  }
  catch(EmptyStackException e){
    cout << e.what() << endl;
  }
  catch(FileNotFoundException e){
    cout << e.what() << endl;
  }
  stack.~GenStack();
  exit(0);
  return 0;
}
