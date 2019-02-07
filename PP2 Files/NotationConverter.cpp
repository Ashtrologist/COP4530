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

std::string NotationConverter::postfixToPrefix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
    // char temp1 = 0;
    // char temp2 = 0;
    string returnString = "";


//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

//     for(int i = 0; i < inStr.length(); i++){
//         if(isalpha(inStr[i])){
//             element.insertBack(inStr[i]);
//         }

//         else if(isOperator(inStr[i])){
//             temp1 = element.front();
//             element.removeFront();
//             temp2 = element.front();
//             element.insertBack(temp1);
//             element.insertBack(inStr[i]);
//             element.insertBack(temp2);
//             temp1 = 0;
//             temp2 = 0;
//         }

//         else
//             continue;
        
//     }

//     while(!element.empty()){
//         returnString += element.front();
//         returnString += ' ';
//         element.removeFront();


//     }
    
    return returnString;

}

std::string NotationConverter::infixToPostfix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");  
    string returnString = "";

//Regex to ensure input validation
    if(regex_match(inStr, self_regex) == false){
        throw("Invalid String");
    }

    // for(int i = 0; i < inStr.length(); i ++){
    //     if(inStr[i] == '('){
    //         element.insertFront(inStr[i]);
    //     }

    //     if(isalpha(inStr[i])){
    //         returnString += inStr[i];
    //         returnString += ' ';
    //     }

    //   //  if(isOperator(inStr[i]))

    // }
    

    return inStr;
}

std::string NotationConverter::infixToPrefix(std::string inStr){
    std::regex self_regex("[a-zA-Z +-/*()]+");
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

//     char temp1 = 0;
//     char temp2 = 0;
//     char test = 0;
  
    string returnString = "";

// //Reverse the input string
//      reverse(inStr.begin(), inStr.end());

// //We want to loop through the string character for character
//     for (int i = 0; i < inStr.length(); i++){
//        //Checks if character is a letter 
//         if(isalpha(inStr[i])){
//             element.insertBack(inStr[i]);
//              test = element.back();
//         }

//     //Checks if character is an operator
//         else if(isOperator(inStr[i])){
//             temp1 = element.back();
//             element.removeBack();
//             temp2 = element.back();
//             element.removeBack();
//             element.insertBack(inStr[i]);
//             element.insertBack(temp1);
//             element.insertBack(temp2);
//             temp1 = 0;
//             temp2 = 0;

//         }
//     //If character is a space
//         else
//             continue;
        
//     }
 
// //While the deque is not empty we want to add each character in the deque to a string
//     while(!element.empty()){
//         returnString += element.front();
//         element.removeFront();
//     }

// //Calls a function to insert spaces into the string between each character  

    return returnString;


}




