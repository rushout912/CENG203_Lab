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
    return -1;                      // TODO: take the next ticket, build
    //       the key, insert it
}

bool PriorityQueue::dequeue(int& priority, int& ticket)
{
    return false;                   // TODO: remove the largest key,
    //       split it into its two parts
}

// ============================ given ============================
bool PriorityQueue::isEmpty() const { return heap.isEmpty(); }
int  PriorityQueue::size() const { return heap.size(); }
