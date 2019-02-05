#include"Deque.hpp"

Deque::Deque(){
    header = NULL;
    tail = NULL;

}
int Deque::size() const{
    return num;
}

bool Deque::empty() const{
    return (header->next == tail);
}

void Deque::insertBack(const Elem& e){
    Node *current = new Node;
    
    if(header == NULL) { 
        current->element = e;
        header = current;
      //  tail = NULL;//tail and node can not point to the same node in this implementation
        header->prev = NULL;
        header->next = tail;
    } 
    
    else if(tail == NULL){
        current->element = e;
        tail = current;
        tail->prev = header;
        tail->next = NULL;
        header->next = tail;
    }

    else{
       current->element = e;
       current->prev = tail;
       tail->next = current;
       tail = current;
       tail->next = NULL; 
    }

    num++;
    
}

void Deque::insertFront(const Elem& e){
    Node *current = new Node;

    if(header == NULL){ 
        current->element = e;
        header = current;
        tail = NULL;
        header->prev = NULL;
        header->next = tail;
    } 
    
    else if(tail == NULL){ 
        current->element = e;
        tail = header;
        tail->prev = current;
        tail->next = NULL;
        header = current;
        header->prev = NULL;
        header->next = tail;
     }
        
     else { 
       current->element = e;
       current->next = header;
       header->prev = current;
       header = current;
       header->prev = NULL; 
        }
    num++;
}


void Deque::removeBack(){
    Node *current = new Node;

    if(header != NULL){ 

        if(tail != NULL){
            current = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete(current);

            if(header == tail){ 
                tail = NULL;
            }
        } 
    else
        header = NULL;
        
    }

    num--;
}

void Deque::removeFront(){
    Node *current = new Node;
    if(header != NULL){ 
        current = header;
        header = header->next;

        if(header != NULL){ 
            header->prev = NULL;  
        }
        else { 
            tail = NULL;
            header = NULL;
        }
        delete(current);
    }

    num--;
}

const Elem& Deque::back() const {
    if(tail != NULL){ 
        return tail->element;
    }
    else if(header !=NULL){
        return header->element;
    }
    else{
        throw ("Empty list");
    }
}

const Elem& Deque::front() const{
    if(header != NULL){ 
        return header->element;
    }
    else{
        throw ("Empty list");
    }
}



Deque::~Deque(){
while(header != NULL){
    removeFront();
}
delete header;
delete tail;
}