#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList 
{
    
protected:
    Node<T> *first;              //a pointer to the first of the linked list
    Node<T> *last;               //a pointer to the last node of the linked list
    mutable Node<T> *iterator;   //internal iterator for the linked list object
    int length;                  //number of items in the linked list
                                                                    
public:
    
    DoublyLinkedList();     //default no-argument constructor  
    ~DoublyLinkedList();    //destructor  
    DoublyLinkedList(const DoublyLinkedList<T> &num);             //copy constructor 
    DoublyLinkedList operator=(const DoublyLinkedList<T> &num);   //copy assignment operator

    void init();                        //initializes an empty list                            
    void insertFirst(const T &num);     //inserts a new item to the beginning of the list   
    void insertLast(const T &num);      //inserts a new item at the end of the list
    void deleteFirst();                 //deletes the first item from the list        
    void deleteLast();                  //deletes the last item in the list
    void clear();                       //destroys the list and makes it empty
    void setIteratorFirst() const;      //sets the iterator to the beginning of the linked list     
    void setIteratorLast();             //sets the iterator to the beginning of the linked list
    void next() const;                  //sets the iterator to the next node
    void prev();                        //sets the iterator to the previous node
    void display();

    bool isEmpty() ;                    //returns true if the list is empty, false otherwise               
    bool hasNext() const;               //checks if the iterator has next
    bool hasPrev();                     //checks if the iterator has prev   
    bool isIteratorNULL();              //returns true if the iterator is null
   
    int getLength();                    //returns the number of items in the list   
    
    T getData() const;                  //gets the data the iterator pointing at 

    template <class U>                  //friend functions
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<U> &);     //overloading operator<<

    template <class U>
    friend istream& operator>>(istream& in, DoublyLinkedList<U> &);            //overloading operator>>   
};
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : first(nullptr), last(nullptr), iterator(nullptr), length(0) 
{
}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()    //destructor 
{
    clear();
} 
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &num) : first(nullptr), last(nullptr), iterator(nullptr), length(0)    
{                                           //copy constructor
    num.setIteratorFirst();
    while(num.hasNext() != false)
    {
        insertLast(num.getData());
        num.next();
    }
} 
template <class T>
DoublyLinkedList<T> DoublyLinkedList<T>:: operator=(const DoublyLinkedList<T> &num)   //copy assignment operator
{
    this->first = num.first;
}
template <class T>
void DoublyLinkedList<T>::init()                      //initializes an empty list  
{
    first = nullptr;
    last = nullptr;
    iterator = nullptr;
    length = 0;
} 
template <class T>                         
void DoublyLinkedList<T>::insertFirst(const T& num)       //inserts a new item to the beginning of the list 
{
    Node<T> * temp = new Node<T>(num, first, nullptr);
    length++;
    if(first == nullptr)
    {
        last = temp;
        first = temp;
    }
    else
    {
        first->prev = temp;
    }
    first = temp;
    iterator = temp;
} 
template <class T> 
void DoublyLinkedList<T>::insertLast(const T &num)         //inserts a new item at the end of the list
{
    Node<T> * temp = new Node<T>(num, nullptr, last); 
    length++;
    if(last == nullptr)
    {
        first = temp;
        last = temp;
    }  
    else
    {
        last->next = temp;
    }       
    last = temp;
    iterator = temp;
}
template <class T>
void DoublyLinkedList<T>::deleteFirst()                 //deletes the first item from the list  
{
    if(first == nullptr)
    {
        return;
    }
    if(first->next == nullptr)
    {
        first = nullptr;
        last = nullptr;
        iterator = nullptr;
        length = 0;
        return;
    }
    Node<T> * temp = first;
    first = first->next;
    delete temp;
    length--;
} 
template <class T>     
void DoublyLinkedList<T>::deleteLast()                  //deletes the last item in the list
{
    if(last == nullptr)
    {
        return;
    }
    if(last->prev == nullptr)
    {
        first = nullptr;
        last = nullptr;
        iterator = nullptr;
        length = 0;
        return;
    }
    Node<T> * temp = last;
    last = last->prev;
    delete temp;
    length--;
}
template <class T>
void DoublyLinkedList<T>::clear()                      //destroys the list and makes it empty
{
    while(first != nullptr)
    {
        deleteFirst();
    }
}
template <class T>
void DoublyLinkedList<T>::setIteratorFirst() const           //sets the iterator to the beginning of the linked list 
{
    iterator = first;
}   
template <class T> 
void DoublyLinkedList<T>::setIteratorLast()            //sets the iterator to the beginning of the linked list
{
    iterator = last;
}
template <class T>
void DoublyLinkedList<T>::next() const                        //sets the iterator to the next node
{
    iterator = iterator->next;
}
template <class T>
void DoublyLinkedList<T>::prev()                        //sets the iterator to the previous node
{
    iterator = iterator->prev;
}
template <class T>
void DoublyLinkedList<T>::display()
{
    Node<T> * temp = first;
    if(temp == nullptr)
    {
        cout << "list is empty";
    }
    while(temp != nullptr)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    } 
    cout << endl; 
}
template <class T>
bool DoublyLinkedList<T>::isEmpty()                     //returns true if the list is empty, false otherwise 
{
    return length == 0;
}  
template <class T>            
bool DoublyLinkedList<T>::hasNext() const                   //checks if the iterator has next
{
    return iterator->next != nullptr;
}
template <class T>
bool DoublyLinkedList<T>::hasPrev()                     //checks if the iterator has prev  
{
    return iterator->prev != nullptr;
} 
template <class T>
bool DoublyLinkedList<T>::isIteratorNULL()              //returns true if the iterator is null
{
    return iterator == nullptr;
}
template <class T>
int DoublyLinkedList<T>::getLength()                    //returns the number of items in the list 
{
    return length;
}  
template <class T>
T DoublyLinkedList<T>::getData() const                     //gets the data the iterator pointing at 
{
    if(iterator == nullptr)
    {
        return 0;
    }
    return iterator->data;
}

#endif 