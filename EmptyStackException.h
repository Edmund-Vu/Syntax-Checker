#include <exception>

using namespace std;

class EmptyStackException:public exception{
  public:
    const char *what() const throw(){
      return "Stack is empty";
    }
};
