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

//Returns the element at the beginning of the deque
const Elem& NotationConverter::front() const{
    return element.front();
}

const Elem& NotationConverter::back() const{
    return element.back();
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

//Helper function to test if it's an operand
bool NotationConverter::isOperator(char ex){
    switch(ex){
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
    }
    return false;
}






std::string NotationConverter::postfixToInfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string currentChar = " ";
    string character1 = " ";
    string character2 = " ";
    string returnString = " ";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    for (char i = 0; i < inStr.length(); i++){
        if(isOperator(i)){
            currentChar += i;
            element.addBack(currentChar);
            currentChar = " ";
        }
        //Add the current character to a string
        //Add top character to a string and then pop
        //Add top character to a string and then pop
        //Readd all three back to the string in order of poppage
        else {
            currentChar += i;
            character1 = element.back();
            element.removeBack();
            character2 = element.back();
            element.removeBack();
            element.addBack(currentChar);
            element.addBack(character1);
            element.addBack(character2);
            currentChar = " ";
            character1 = " ";
            character2 = " ";
        }

    }

            while(!element.empty()){
            returnString += element.back();
            element.removeBack();
        } 

        return returnString;
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


