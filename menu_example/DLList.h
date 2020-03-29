//
// Created by John on 2/25/2020.
//

#include <new>
#include "Node.h"

#ifndef ASSIGNMENT11_DLLIST_H
#define ASSIGNMENT11_DLLIST_H

template <typename T>
class DLList
{
    private:
        Node <T> * front;
        Node <T> * rear;

    public:
        DLList();
        ~DLList();
        bool insert(const T & dataIn);
        bool remove(T & dataIn);
        bool retrieve(T & dataOut) const;
        bool viewFront(T & dataOut) const;
        bool viewRear(T & dataOut) const;
        void display() const;
        void displayReverse() const;
        int getNumValues() const;
        bool isEmpty() const;
        bool isFull();
};

//****************************************************************************************************

template <typename T>
DLList <T> :: DLList()
{
    front = nullptr;
    rear = nullptr;
}

//****************************************************************************************************

template <typename T>
DLList <T> :: ~DLList()
{
    Node <T> * pTemp;

    while (front)
    {
        pTemp = front;
        front = front -> next;
        delete pTemp;
    }

    rear = nullptr;
}

//****************************************************************************************************

template <typename T>
bool DLList <T> :: insert(const T & dataIn)
{
    bool success = false;
    Node <T> * pBefore = nullptr;
    Node <T> * pAfter = front;
    Node <T> * pNew;

    while ((pAfter) && (pAfter -> data < dataIn))
    {
        pAfter = pAfter -> next;
    }

    if (pAfter)
    {
        pBefore = pAfter -> prev;
    }
    else
    {
        pBefore = rear;
    }

    pNew = new (nothrow) Node <T> (dataIn, pAfter, pBefore);

    if (pNew)
    {
        if (pBefore)
        {
            pBefore -> next = pNew;
        }
        else
        {
            front = pNew;
        }

        if (pAfter)
        {
            pAfter -> prev = pNew;
        }
        else
        {
            rear = pNew;
        }

        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename T>
bool DLList <T> :: remove(T & dataOut)
{
    bool success = false;
    Node <T> * pDel = front;

    while ((pDel) && (pDel -> data < dataOut))
    {
        pDel = pDel -> next;
    }

    if ((pDel) && (pDel -> data == dataOut))
    {
        dataOut = pDel -> data;

        if (pDel -> prev)
        {
            pDel -> prev -> next = pDel -> next;
        }

        else
        {
            front = pDel -> next;
        }

        if (pDel -> next)
        {
            pDel -> next -> prev = pDel -> prev;
        }
        else
        {
            rear = pDel -> prev;
        }

        delete pDel;
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename T>
bool DLList<T> :: retrieve(T & dataOut) const
{
    bool success = false;
    Node<T> * pTemp = front;

    while((pTemp) && (pTemp -> data < dataOut))
    {
        pTemp = pTemp -> next;
    }

    if ((pTemp) && (pTemp -> data == dataOut))
    {
        dataOut = pTemp -> data;
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename T>
bool DLList<T> :: viewFront(T & dataOut) const
{
    bool success = false;
    Node<T> * pTemp = front;

    if (pTemp)
    {
        dataOut = pTemp -> data;
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename T>
bool DLList <T> :: viewRear(T & dataOut) const
{
    bool success = false;
    Node<T> * pTemp = rear;

    if (pTemp)
    {
        dataOut = pTemp -> data;
        success = true;
    }

    return success;
}

//****************************************************************************************************

template <typename T>
void DLList <T> :: display() const
{
    Node<T> * pTemp = front;

    while (pTemp)
    {
        cout << pTemp -> data << endl;
        pTemp = pTemp -> next;
    }
}

//****************************************************************************************************

template <typename T>
void DLList <T> :: displayReverse() const
{
    Node<T> * pTemp = rear;

    while (pTemp)
    {
        cout << pTemp -> data << endl;
        pTemp = pTemp -> prev;
    }
}

//****************************************************************************************************


template <typename T>
int DLList <T> :: getNumValues() const
{
    int count = 0;
    Node<T> * pTemp = front;

    while(pTemp)
    {
        count ++;
        pTemp = pTemp -> next;
    }

    return count;
}

//****************************************************************************************************

template <typename T>
bool DLList <T> :: isEmpty() const
{
    return front == nullptr;
}

//****************************************************************************************************

template <typename T>
bool DLList <T> :: isFull()
{
    bool success = false;
    Node<T> * pNew;

    pNew = new (nothrow) Node<T> ();

    if (!pNew)
    {
        success = true;
    }

    delete pNew;
    return success;
}

//****************************************************************************************************
#endif //ASSIGNMENT11_DLLIST_H
