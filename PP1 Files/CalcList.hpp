#ifndef CALCLIST_H
#define CALCLIST_H

#include <string>
#include <vector>
#include<sstream>
#include<iomanip>
#include "CalcListInterface.hpp"
using namespace std;

  typedef struct {      
        string operation;
        double totalValue = 0.0;
        double userInput;
        double prevTotal;
        FUNCTIONS function;
    } Data;

class Node {
    
   // friend class CalcListInterface;
    friend class CalcList;

    private:
        Data element;
        Node* prev;
        Node* next;

};

//I would like to store a pair within the linkedList
class CalcList : public CalcListInterface {
    public:
        CalcList();
        ~CalcList();
        bool empty() const; //Checks if the list is empty;
        const Data& front() const; //Gets the element at the front of the list
        const Data& back() const; //Gets the element at the back of the list
        void addBack (const Data& e); //Adds an element to the end of the linked list
        void removeFront(); //Removes an element from the front of the linked list
        void removeBack(); //Removes an element from the end of the linked list
        
        double total() const override;
        void newOperation(const FUNCTIONS func, const double operand)  override;
        void removeLastOperation() override;
        std::string toString(unsigned short precision) const override;

        void add(Node* v, const Data& e); //Function to add an element
        void remove(Node* v);       //Function to remove an element

    private:
      //  double totalVal = 0;
        Node* header;
        Node* trailer;
        int count = 0;
    };

#endif /* CALCLIST_H */