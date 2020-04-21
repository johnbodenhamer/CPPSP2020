//
// Created by John on 4/14/2020.
//

#ifndef A03_PRIORITYQUEUE_PRIORITYQUEUE_H
#define A03_PRIORITYQUEUE_PRIORITYQUEUE_H

template <class DT>
class PriorityQueue
{
public:
    PriorityQueue(int);
    PriorityQueue(const DT [], int);
    void enqueue(const DT & newElement);
    bool dequeue(DT & remElement);
    bool isEmpty() const;
    void makeEmpty();
private:
    DT* elements;
    int heapsize;
    inline void heapify(int);
};

template <class DT>
PriorityQueue<DT> :: PriorityQueue(int capacity)
{
    elements = new DT[capacity];
    heapsize=0;
}

template <class DT>
PriorityQueue<DT> :: PriorityQueue(const DT arr[], int h)
{
    heapsize = h;
    elements = new DT[heapsize];
    for(int k=0; k<heapsize; k++)
    {
        elements[k]=arr[k];
    }

    for ( int i = ( heapsize - 2 ) /2; i >= 0; i-- )
    {
        heapify(i);
    }
}

template <class DT>
void PriorityQueue<DT> :: enqueue(const DT & newElement)
{
    int i = heapsize;
    for (;(i != 0) && elements[(i-1)/2] <= newElement; i = (i - 1) /2)
    {
        elements[i] = elements[(i -1)/2];
    }

    elements[i] = newElement;
    heapsize++;
}

template <class DT>
bool PriorityQueue<DT> ::dequeue(DT &remElement)
{
    if (!heapsize)
    {
        return false;
    }

    remElement = elements[0];
    heapsize--;
    elements[0] = elements[heapsize];
    heapify(0);
    return true;
}

template <class DT>
bool PriorityQueue<DT> ::isEmpty() const
{
    return !heapsize;
}

template <class DT>
void PriorityQueue<DT> ::makeEmpty()
{
    heapsize = 0;
}

template <class DT>
inline void PriorityQueue<DT> :: heapify(int i)
{
    int leftChild, rightChild, largest;
    bool stop = false;

    DT temp = elements[i];

    leftChild = (i * 2) + 1;

    while (leftChild < heapsize && !stop)
    {
        rightChild = leftChild +1;

        if(rightChild == heapsize)
        {
            largest = leftChild;
        }
        else if (elements[leftChild] > elements[rightChild])
        {
            largest = leftChild;
        }
        else
        {
            largest = rightChild;
        }

        if (elements[largest] > temp) // must overload in app's struct
        {
            elements[i] = elements[largest];
            i = largest;
            leftChild = (i * 2) + 1;
        }
        else
        {
            stop = true;
        }

        elements[i] = temp;
    }
}

#endif //A03_PRIORITYQUEUE_PRIORITYQUEUE_H
