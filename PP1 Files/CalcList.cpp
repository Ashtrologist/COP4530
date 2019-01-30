#include "CalcList.hpp"
#include "CalcListInterface.hpp"

//Constructor
CalcList::CalcList(){
    header = new Node; //Creates the list sentinenls
    trailer = new Node;
    header -> next = trailer; //Sets the sentinenls to point to each other
    trailer -> prev = header;
}

/*
Returns if the list is empty. If the header is pointing
to the trailer, the list must be empty.
*/
bool CalcList::empty () const {
    return (header -> next == trailer);
}

//Returns the element at the front of the list
const Data& CalcList::front() const{
    return header->next->element;
}

//Returns element at the back of the list
const Data& CalcList::back() const{
    return trailer->prev->element;
}

//The logic for inserting a node
void CalcList::add(Node *v, const Data& e){
    Node* u = new Node;
    u -> element = e;
    u -> next = v;
    u -> prev = v -> prev;
    v -> prev -> next = v -> prev = u;
}

//Adds an element to the end of the linkedlist. 
//Just calls the above function. Will be used within the new operation function.
void CalcList::addBack(const Data& e){
    add(trailer, e);
}

//The logic for deleting a node
void CalcList::remove(Node* v){
    Node* u = v->prev;
    Node* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

//Removes the first element of the linkedlist
//Calls the remove function
void CalcList::removeFront(){
    remove(header->next);
}

//Removes the last element of the linkedlist
//Calls the function above
void CalcList::removeBack(){
    remove(trailer -> prev);
}

//Adds an operation to the end of the linkedlist
//It also changes the total
void CalcList::newOperation(const FUNCTIONS func, const double operand){

//Create a new node
    Node* current = new Node();

//Increase count, so that we can track amount of nodes
    count ++;
        
    current -> element.userInput = operand;
    current -> element.function = func;

     if(empty()){
            current->next = trailer;
            current->prev = header;
            header->next = current;
            trailer->prev = current;
        }

        else{
            current -> next = trailer; //Inserted node points to trailer
            current -> prev = trailer -> prev; //Inserted node points to node trailer was previously pointing to
            trailer -> prev -> next = current; //Old node points to inserted node
            trailer -> prev = current; //Trailer points to inserted node
        }
    
         //A switch statment that decides how to append to total value
    switch (func){
        case ADDITION:
         
         if(empty()){
             current -> element.prevTotal = 0;
             current -> element.totalValue += operand;
         }
            // current -> element.totalValue += operand;
            current -> element.totalValue = current->prev->element.prevTotal + operand;
            current -> element.prevTotal = current -> element.totalValue;
            current -> element.operation = "+";
            break;

        case MULTIPLICATION:

        if(empty()){
            current -> element.prevTotal = 0;
            current -> element.totalValue *= operand;
        }
        


            // current -> element.totalValue *= operand;
             current -> element.totalValue = current->prev->element.prevTotal * operand;
             current -> element.prevTotal = current -> element.totalValue;
            current -> element.operation = "*";
            break;

        case SUBTRACTION:
            if (empty()){
                current -> element.prevTotal = 0;
                current -> element.totalValue -= operand;
            }

            // current -> element.totalValue -= operand;
            current -> element.totalValue = current->prev->element.prevTotal - operand;
            current -> element.prevTotal = current -> element.totalValue;
            current -> element.operation = "-";
            break;

        case DIVISION:

            if(operand == 0)
                throw("DivisionByZero");

            if(empty()){
                current -> element.prevTotal = 0;
                current -> element.totalValue /= operand;
            }

            // current -> element.totalValue /= operand;
            current -> element.totalValue = current->prev->element.prevTotal / operand;
            current -> element.prevTotal = current -> element.totalValue;
            current -> element.operation = "/";
            break;

        default:
            break;
    }


 }


//Removes the last operation from the linked list and restores the previous total
 void CalcList::removeLastOperation(){
     //If the list is empty throw an error
     if(empty()){
         throw("EmptyList");
     }


    // Checks if only one node is in the list
    else  {
        removeBack();
    }
//Decrease count so I know the size of the linkedList
     count --;
 }

 //Returns the current total of the CalcList
 //This total is calculated in other functions
double CalcList::total() const{

    return trailer->prev->element.totalValue;
    
}

CalcList::~CalcList(){
    while(!empty()) {
        removeFront(); //Removes the nodes except the sentinenls
    }
    delete header; //Removes the sentinenls
    delete trailer;
}

std::string CalcList::toString(unsigned short precision) const{
    ostringstream output;
    string newString;

    Node* current = new Node ();
    current = trailer -> prev;


    int counter = count;

    if(empty()){
        return " ";
    }

    output << setprecision(precision) << fixed;

    while(counter != 0){
        
        //Data data = current -> element;
        output << counter << ": " << current -> element.prevTotal << current -> element.operation << current -> element.userInput << "=" << current -> element.totalValue << "\n";
        current = current -> prev;
        counter --;

    }

    newString = output.str();
    return newString;

}

