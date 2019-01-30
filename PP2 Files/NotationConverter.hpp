#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H

#include "NotationConverterInterface.hpp"
#include <string>

using namespace std;

typedef string Elem;

class Node {
    friend class NotationConverter;
    friend class LinkedList;

    private:
        string element;
        Node* prev;
        Node* next;
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        bool empty() const; //Checks if the list is empty;
        const Elem& front() const; //Gets the element at the front of the list
        const Elem& back() const; //Gets the element at the back of the list
        void addBack (const Elem& e); //Adds an element to the end of the linked list
        void removeFront(); //Removes an element from the front of the linked list
        void removeBack(); //Removes an element from the end of the linked list
        void add(Node* v, const Elem& e); //Function to add an element
        void remove(Node* v);       //Function to remove an element

    private:
        Node* header;
        Node* trailer;
        int count = 0;
};


class NotationConverter : public NotationConverterInterface {
public:
    NotationConverter();
    int size() const;
    bool empty() const;
    const Elem& front() const throw(DequeEmpty);
    const Elem& back() const throw(DequeEmpty);
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront() throw(DequeEmpty);
    void removeBack() throw(DequeEmpty);

private:
    LinkedList D;
    int n;



//Functions to be implemented. They are inhereted from base class
   std::string postfixToInfix(std::string inStr);
   std::string postfixToPrefix(std::string inStr);
   std::string infixToPostfix(std::string inStr);
   std::string infixToPrefix(std::string inStr);
   std::string prefixToInfix(std::string inStr);
   std::string prefixToPostfix(std::string inStr);

};



#endif /* NOTATIONCONVERTER_H */