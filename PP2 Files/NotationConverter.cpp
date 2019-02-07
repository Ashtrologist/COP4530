#include "NotationConverter.hpp"
#include "Deque.hpp"


NotationConverter::NotationConverter(){
    Deque();
    
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

int NotationConverter::precedence(char ex){
    switch (ex){
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        default:
            return -1;
    }
}

std::string NotationConverter::prefixToInfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string temp1 = "";
    string temp2 = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

//Reverse the String
    reverse(inStr.begin(), inStr.end());

//Loop through the string
    for(auto i : inStr){

//If its a character push it to the stack
        if(isalpha(i)){
            temp1 = "";
            temp1 += i;
            element.insertBack(temp1);
        }
//If its an operator do this
        else if (isOperator(i)){
            temp2 = "";
            temp2 += '(';
            temp2 += element.back();
            element.removeBack();
            temp2 += ' ';
            temp2 += i;
            temp2 += ' ';
            temp2 += element.back();
            element.removeBack();
            temp2 += ')';
            element.insertBack(temp2);
        }
//If its a space
        else if (i == ' ')
            continue;

    }

    return temp2;

}

//We want to skip spaces!
std::string NotationConverter::postfixToInfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string returnString = "";
     string temp1 = "";
     string temp2 = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    for(auto i : inStr){

//If its a character push it to the stack
        if(isalpha(i)){
            temp1 = "";
            temp1 += i;
            element.insertBack(temp1);
        }
//If its an operator do this
        else if (isOperator(i)){
            temp2 = "";
            temp2 += ')';
            temp2 += element.back();
            element.removeBack();
            temp2 += ' ';
            temp2 += i;
            temp2 += ' ';
            temp2 += element.back();
            element.removeBack();
            temp2 += '(';
            element.insertBack(temp2);
        }
//If its a space
        else if (i == ' ')
            continue;

    }

    reverse(temp2.begin(), temp2.end());

    return temp2;
}

std::string NotationConverter::postfixToPrefix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string temp = "";
    string returnString = "";


//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    temp = postfixToInfix(inStr);
    returnString = infixToPrefix(temp);

    return returnString;

}

std::string NotationConverter::infixToPostfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");  
    element.insertBack("flag");

    string temp1 = "";
    string temp2 = "";
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    for (auto i : inStr){
        if(i == ' '){
            continue;

        }
//Push it to the stack
        else if (i == '('){
            temp1 += i;
            element.insertFront(temp1);
            temp1 = "";
        }

        else if(i == ')'){
            while(element.front() != "flag" && element.front() != "("){
                temp1 = element.front();
                element.removeFront();
                returnString += temp1;
                returnString += ' ';
                temp1 = "";
            }

            if(element.front() == "("){
                element.removeFront();
            }

        }

        else if(isalpha(i)){
            returnString += i;
            returnString += ' ';
        }

        else if(isOperator(i)) {

            while(element.front() != "flag" && precedence(i) <= precedence(element.front().at(0))){
                temp1 = "";
                temp1 = element.front();
                element.removeFront();
                returnString += temp1;
                returnString += ' ';
            }
            temp2 += i;
            element.insertFront(temp2);
            temp2 = "";
        }
    }

    while(element.front() != "flag"){
        temp1 = "";
        temp1 = element.front();
        element.removeFront();
        returnString += temp1;
        returnString += ' ';
    }
    

    return returnString;
}

std::string NotationConverter::infixToPrefix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string returnString = "";
    string temp = "";


//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    for (auto i : inStr){
        temp += i;
    }

    for (int i = 0; i < temp.length(); i ++){
        if (temp[i] == '('){
            temp[i] = ')';
        }
        else if (temp[i] == ')'){
            temp[i] = '(';
        }
    }

    reverse(temp.begin(), temp.end());

    returnString = infixToPostfix(temp);

    reverse(returnString.begin(), returnString.end());

    return returnString;
}

std::string NotationConverter::prefixToPostfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string temp = "";
    string returnString = "";
//Input validation
     if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

     temp = prefixToInfix(inStr);
     returnString = infixToPostfix(temp);


    return returnString;


}




