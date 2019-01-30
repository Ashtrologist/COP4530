#include "NotationConverter.hpp"
#include "LinkedList.hpp"

NotationConverter::NotationConverter(){
    LinkedList();
}


//Inserts element to the front of the deque
void NotationConverter::insertFront(const Elem& e){
    element.addFront(e);
    num ++;
}

//Inserts element to the end of the deque
void NotationConverter::insertBack(const Elem& e){
    element.addBack(e);
    num ++;
}

//Returns if deque is empty
bool NotationConverter::empty() const{
    return element.empty();
}

//Returns the size of the deque
int NotationConverter::size() const{
    return num;
}

//Removes element from the front of the deque
void NotationConverter::removeFront(){
    if(empty())
        throw ("DequeEmpty");
    
    else{
        element.removeFront();
        num --;
    }
}

//Removes element from the back of the deque
void NotationConverter::removeBack(){
    if(empty())
        throw("DequemEmpty");
    
    else {
        element.removeBack();
        num --;
    }
}

std::string NotationConverter::postfixToInfix(std::string inStr){
    return inStr;
}

std::string NotationConverter::postfixToPrefix(std::string inStr){

    stringstream word;
    word << inStr;

    return word.str();
}

std::string NotationConverter::infixToPostfix(std::string inStr){
    return inStr;
}

std::string NotationConverter::infixToPrefix(std::string inStr){
    return inStr;
}

std::string NotationConverter::prefixToInfix(std::string inStr){
    return inStr;
}

std::string NotationConverter::prefixToPostfix(std::string inStr){
    return inStr;
}


