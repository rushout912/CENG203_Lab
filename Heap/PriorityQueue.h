#pragma once
#include "MaxHeap.h"

// Priority queue: the item with the highest priority leaves first.
// Items with the SAME priority leave in arrival order (first come,
// first served). The heap is the engine; users see enqueue / dequeue.
class PriorityQueue
{
private:
    MaxHeap heap;                   // one int key per waiting item
    int nextTicket;                 // arrival number: 0, 1, 2 ...

public:
    PriorityQueue();

    int  enqueue(int priority);     // priority >= 0; returns the ticket
    bool dequeue(int& priority, int& ticket);   // false = nobody waits
    bool isEmpty() const;
    int  size() const;
};
