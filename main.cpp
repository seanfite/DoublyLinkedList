#include "BigInteger.h"
#include <iostream>
using namespace std;

int main()
{

    DoublyLinkedList<int> dll;
    dll.insertFirst(5);
    dll.insertFirst(15);
    dll.insertFirst(11);
    dll.insertFirst(7);
    dll.insertFirst(4);
    dll.insertFirst(10);
    dll.hasNext();
    dll.setIteratorFirst();
    cout << "First Display: ";
    dll.display();
    cout << "Copy Constructor: ";
    DoublyLinkedList<int> dllcopy(dll);
    // cout << dllcopy << endl;
    dll.deleteFirst();
    dll.deleteLast();
    cout << "Delete first and last: ";
    dll.display();
    cout << endl;
    dll.getLength();
    dll.clear();
    cout << "List is cleared.." << endl;
    dll.display();

    BigInteger<int> list;
    list.display();
    

}