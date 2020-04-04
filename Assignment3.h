#include <fstream>
#include "GenStack.h"
#include "FileNotFoundException.h"

using namespace std;

class delimiter{
  public:
    delimiter();
    ~delimiter();

    string inputFile;
    char first;
    int lineCount;

    int checkDelimiters();
};
