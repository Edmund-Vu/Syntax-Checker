#include <exception>

using namespace std;

class FileNotFoundException:public exception{
  public:
    const char *what() const throw(){
    return "File not found";
    }
};
