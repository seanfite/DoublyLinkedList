#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

template<class T>
class BigInteger
{
    private:
        int size;
        DoublyLinkedList<int> list;        

    public:
        BigInteger operator+(const BigInteger &num);
        BigInteger operator-(const BigInteger &num);
        
        bool operator<=(const BigInteger &num);
        bool operator>=(const BigInteger &num);
        bool operator==(const BigInteger &num);
        bool operator>(const BigInteger &num);
        bool operator<(const BigInteger &num);
        bool operator=(const BigInteger &num);
       
        void display();
};

template<class T>
BigInteger BigInteger<T>:: operator+(const BigInteger &num)
{

}
template<class T>
BigInteger<T> BigInteger<T>:: operator-(const BigInteger &num)
{

}
template<class T>
bool BigInteger<T>::operator<=(const BigInteger &num)
{

}
template<class T>
bool BigInteger<T>::operator>=(const BigInteger &num)
{

}
template<class T>
bool BigInteger<T>::operator==(const BigInteger &num)
{

}
template<class T>
bool BigInteger<T>::operator>(const BigInteger &num)
{

}
template<class T>
bool BigInteger<T>::operator<(const BigInteger &num)
{

}
template<class T>
bool BigInteger<T>::operator=(const BigInteger &num)
{

}
template<class T>
void BigInteger<T>::display();
{

}


