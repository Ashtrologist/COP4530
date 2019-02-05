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

//We want to skip spaces!
std::string NotationConverter::postfixToInfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

 
//     for (int i = 0; i < inStr.length(); i++){
    
// //If the current character is an arithmetic operator
//         if(isOperator(inStr[i])){
//             currentChar = inStr[i];
//             character1 = back();
//             removeBack();
//             character2 = back();
//             removeBack();
//             insertBack(currentChar);
//             insertBack(character1);
//             insertBack(character2);
//             currentChar = 0;
//             character1 = 0;
//             character2 = 0;
//         }

// //Otherwise just add the character to the deque
//         else {
//             currentChar = inStr[i];
//             insertBack(currentChar);
//             currentChar = 0;
//         }
//     }
 
//             while(!empty()){
//             returnString += front();
//             removeFront();
//         } 

        return returnString;
}

std::string NotationConverter::postfixToPrefix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string currentChar = "";
    string character1 = "";
    string character2 = "";
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }
    return inStr;

}

std::string NotationConverter::infixToPostfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string currentChar = "";
    string character1 = "";
    string character2 = "";
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    return inStr;
}

std::string NotationConverter::infixToPrefix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string currentChar = "";
    string character1 = "";
    string character2 = "";
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }
    return inStr;
}

std::string NotationConverter::prefixToInfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    string currentChar = "";
    string character1 = "";
    string character2 = "";
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }
    return inStr;

}

std::string NotationConverter::prefixToPostfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
//Input validation
     if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    char temp1 = 0;
    char temp2 = 0;
    char test = 0;
  
    string returnString = "";

//Reverse the input string
     reverse(inStr.begin(), inStr.end());

//We want to loop through the string character for character
    for (int i = 0; i < inStr.length(); i++){
       //Checks if character is a letter 
        if(isalpha(inStr[i])){
            element.insertBack(inStr[i]);
             test = element.back();
        }

    //Checks if character is an operator
        else if(isOperator(inStr[i])){
            temp1 = element.back();
            element.removeBack();
            temp2 = element.back();
            element.removeBack();
            element.insertBack(inStr[i]);
            element.insertBack(temp1);
            element.insertBack(temp2);
            temp1 = 0;
            temp2 = 0;

        }
    //If character is a space
        else
            continue;
        
    }
 
//While the deque is not empty we want to add each character in the deque to a string
    while(!element.empty()){
        returnString += element.front();
        element.removeFront();
    }

//Calls a function to insert spaces into the string between each character  

    return returnString;


}




