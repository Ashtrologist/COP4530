#ifndef LINKEDLIST_H   
#define LINKEDLIST_H

#include <string>
#include<iostream>
#include<sstream>

using namespace std;

typedef char Elem;
class Node {
    friend class LinkedList;

    private:
        Elem element;
        Node* prev;
        Node* next;
};

class LinkedList {
    friend class NotationConverter;
    public:
        LinkedList();
        ~LinkedList();

        bool empty() const; //Checks if the list is empty;
        const Elem& front() const; //Gets the element at the front of the list
        const Elem& back() const; //Gets the element at the back of the list
        void addFront(const Elem& e);
        void addBack (const Elem& e); //Adds an element to the end of the linked list
        void removeFront(); //Removes an element from the front of the linked list
        void removeBack(); //Removes an element from the end of the linked list
        
    protected:
        void add(Node* v, const Elem& e); //Function to add an element
        void remove(Node* v);       //Function to remove an element

    private:
        Node* header;
        Node* trailer;
        int count = 0;
};

#endif