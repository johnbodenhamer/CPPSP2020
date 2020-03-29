//
// Created by John on 2/25/2020.
//

#ifndef ASSIGNMENT11_NODE_H
#define ASSIGNMENT11_NODE_H

template <typename T>
struct Node
{
    T data;
    Node <T> * next;
    Node <T> * prev;
    Node();
    Node(const T & d, Node <T> * n = nullptr, Node <T> *p = nullptr);
};

//****************************************************************************************************

template <typename T>
Node<T> :: Node()
{
    next = nullptr;
    prev = nullptr;
}

//****************************************************************************************************

template<typename T>
Node<T>::Node(const T & d, Node <T> * n, Node <T> * p)
{
    data = d;
    next = n;
    prev = p;
}

//****************************************************************************************************
#endif //ASSIGNMENT11_NODE_H
