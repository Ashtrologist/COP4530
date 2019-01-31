#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "LinkedList.hpp"
#include "NotationConverterInterface.hpp"

using namespace std;

typedef string Elem;

class NotationConverter : public NotationConverterInterface {
public:
    NotationConverter();                //Constructor
    int size() const;
    bool empty() const;                 //Determines if Deque is empty
    const Elem& front() const;          //Returns the first element
    const Elem& back() const;           //Returns the last element
    void insertFront(const Elem& e);    //Insert element to the front of the deque
    void insertBack(const Elem& e);     //Insert element to the end of the deque
    void removeFront();                 //Removes element front the front of the deuque
    void removeBack();                  //Removes element from the back of the deuque

//Functions to be implemented. They are inhereted from base class
   std::string postfixToInfix(std::string inStr);
   std::string postfixToPrefix(std::string inStr);
   std::string infixToPostfix(std::string inStr);
   std::string infixToPrefix(std::string inStr);
   std::string prefixToInfix(std::string inStr);
   std::string prefixToPostfix(std::string inStr);

private:
    LinkedList element;
    int num = 0;
};



#endif /* NOTATIONCONVERTER_H */