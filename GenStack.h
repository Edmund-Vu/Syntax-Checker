#include <iostream>
#include <string>
#include "EmptyStackException.h"

using namespace std;

template <class T>
class GenStack{
    public:
        GenStack();
        GenStack(int maxsize);
        ~GenStack();

        void push(T data);
        T pop();
        T topStack();
        bool isFull();
        bool isEmpty();
        int getSize();
        void increaseSize();

        int top;
        int size;

        T *myArray;
};

// Default Constructor
template <class T>
GenStack<T>::GenStack(){
    myArray = new T[256];
    top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

// Destructor
template <class T>
GenStack<T>::~GenStack(){
    delete []myArray;
}

// Adds elements to the stack
template <class T>
void GenStack<T>::push(T data){
  if(isFull()){
    increaseSize();
  }
  myArray[++top] = data;
}

// Removes the top element of the stack if the stack isn't empty
template <class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    throw EmptyStackException();
  }
  return myArray[top--];
}

// Returns the top element of the stack if the stack isn't empty
template <class T>
T GenStack<T>::topStack(){
  if(isEmpty()){
    throw EmptyStackException();
  }
  return myArray[top];
}

// Returns a boolean indicating whether the stack is full or not
template <class T>
bool GenStack<T>::isFull(){
  return(top == size-1);
}

// Returns a boolean indicating whether the stack is full or not
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

// Returns the current size of the stack
template <class T>
int GenStack<T>::getSize(){
  return top + 1;
}

// Increases the size of the stack 
template <class T>
void GenStack<T>::increaseSize(){
    T* tempArray = new T[2*size];
    for(int i = 0; i < size; ++i){
      tempArray[i] = myArray[i];
    }
    delete myArray;
    T* myArray = new T[2*size];
    for(int i = 0; i < size; ++i){
      myArray[i] = tempArray[i];
    }
    delete tempArray;
    size = 2 * size;
}
