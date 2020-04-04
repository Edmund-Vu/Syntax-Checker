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

template <class T>
GenStack<T>::~GenStack(){
    delete []myArray;
}

template <class T>
void GenStack<T>::push(T data){
  if(isFull()){
    increaseSize();
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    throw EmptyStackException();
  }
  return myArray[top--];
}

template <class T>
T GenStack<T>::topStack(){
  if(isEmpty()){
    throw EmptyStackException();
  }
  return myArray[top];
}

template <class T>
bool GenStack<T>::isFull(){
  return(top == size-1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize(){
  return top + 1;
}

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
