#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;
        Node(T _data, Node * _next, Node * _prev) : next(_next), prev(_prev), data(_data) {}
};

#endif