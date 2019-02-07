#ifndef DEQUE_H
#define DEQUE_H
#include <string>

using namespace std;


typedef string Elem;

class Node {
    friend class Deque;
    private:
        Elem element;
        Node *next;
        Node* prev;
};

class Deque {

public:
    Deque();                //Constructor
    ~Deque();               //Deconstructor

    int size() const;
    bool empty() const;                 //Determines if Deque is empty
    const Elem& front() const;          //Returns the first element
    const Elem& back() const;           //Returns the last element
    void insertFront(const Elem& e);    //Insert element to the front of the deque
    void insertBack(const Elem& e);     //Insert element to the end of the deque
    void removeFront();                 //Removes element front the front of the deuque
    void removeBack();                  //Removes element from the back of the deuque

private:
    Node *header;
    Node *tail;
    int num = 0;
};



#endif /* NOTATIONCONVERTER_H */