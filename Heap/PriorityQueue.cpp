#include "PriorityQueue.h"

// One int holds two facts:   key = priority * 1000 + (999 - ticket)
//   - a higher priority always gives a larger key
//   - for the same priority the EARLIER ticket gives the larger key
const int MAX_TICKETS = 1000;       // tickets 0 ... 999

PriorityQueue::PriorityQueue()
{
    nextTicket = 0;
}

// ============================ Q7 ============================
int PriorityQueue::enqueue(int priority)
{
    int ticket = nextTicket;
    nextTicket++;
    heap.insert(priority * MAX_TICKETS + (MAX_TICKETS - 1 - ticket));
    return ticket;
}

bool PriorityQueue::dequeue(int& priority, int& ticket)
{
    int key = 0;
    if (!heap.removeMax(key))
        return false;               // nobody is waiting
    priority = key / MAX_TICKETS;
    ticket = MAX_TICKETS - 1 - key % MAX_TICKETS;
    return true;
}

// ============================ given ============================
bool PriorityQueue::isEmpty() const { return heap.isEmpty(); }
int  PriorityQueue::size() const { return heap.size(); }
