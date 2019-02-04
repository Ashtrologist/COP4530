#include "LinkedList.hpp"

//Constructor for the linkedList
LinkedList::LinkedList(){
    header = new Node; //Creates the list sentinenls
    trailer = new Node;
    header->next = trailer; //Sets the sentinenls to point to each other
    trailer->prev = header;
}

LinkedList::~LinkedList(){
    while(!empty()) {
        removeFront(); //Removes the nodes except the sentinenls
    }
    delete header; //Removes the sentinenls
    delete trailer;
}

//Returns if the list is empty
bool LinkedList::empty () const {
    return (header->next == trailer);
}

//Returns the element at the front of the list
const Elem& LinkedList::front() const{
    return header->next->element;
}

//Returns element at the back of the list
const Elem& LinkedList::back() const{
    return trailer->prev->element;
}

//The logic for inserting a node
void LinkedList::add(Node *v, const Elem& e){
    Node* u = new Node;
    u->element = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = v->prev = u;
}

//Adds an element to the end of the linkedlist. 
void LinkedList::addBack(const Elem& e){
    add(trailer, e);
}

//Adds an element to the front of the linkedlist
void LinkedList::addFront(const Elem& e){
    add(header->next, e);
}

//The logic for deleting a node
void LinkedList::remove(Node* v){
    Node* u = v->prev;
    Node* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

//Removes the first element of the linkedlist
void LinkedList::removeFront(){
    remove(header->next);
}

//Removes the last element of the linkedlist
void LinkedList::removeBack(){
    remove(trailer->prev);
}
