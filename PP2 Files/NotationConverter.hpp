#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include "LinkedList.hpp"
#include "NotationConverterInterface.hpp"


#include <string>
#include<iostream>
#include<sstream>

using namespace std;

typedef string Elem;

class NotationConverter : public NotationConverterInterface {
public:
    NotationConverter();
    int size() const;
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront();
    void removeBack();

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