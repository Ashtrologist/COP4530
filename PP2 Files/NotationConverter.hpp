#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include<cstring>
#include<ctype.h>
#include<algorithm>
#include "NotationConverterInterface.hpp"
#include"Deque.hpp"

using namespace std;

typedef string Elem;

class NotationConverter : public NotationConverterInterface {
public:
    NotationConverter();                //Constructor

    bool isOperator(char ex);           //Helper function to 
    bool isOperand(char ex);            //Helper function 
    int precedence(char ex);            //Helper function

//Functions to be implemented. They are inhereted from base class
   std::string postfixToInfix(std::string inStr);
   std::string postfixToPrefix(std::string inStr);
   std::string infixToPostfix(std::string inStr);
   std::string infixToPrefix(std::string inStr);
   std::string prefixToInfix(std::string inStr);
   std::string prefixToPostfix(std::string inStr);

private:
    int num = 0;
    Deque element;
};



#endif /* NOTATIONCONVERTER_H */