#include "MaxHeap.h"
#include <iostream>
#include <iomanip>                  // setw
#include <string>
using namespace std;

MaxHeap::MaxHeap()
{
    swapCount = 0;                  // the vector starts empty by itself
}

// ============================ Q1 ============================
int MaxHeap::parent(int i)
{
    return i;                       // TODO: the formula (i = placeholder)
}

int MaxHeap::leftChild(int i)
{
    return i;                       // TODO
}

int MaxHeap::rightChild(int i)
{
    return i;                       // TODO
}

bool MaxHeap::isMaxHeap(const vector<int>& a)
{
    return false;                   // TODO: every node <= its parent?
}

// ============================ Q2 ============================
void MaxHeap::insert(int value)
{
    // TODO: push_back the value, then bubbleUp from the last index
}

void MaxHeap::bubbleUp(int index)
{
    // TODO: while not the root and larger than the parent:
    //       swapNodes with the parent, continue from the parent
}

// ============================ Q3 ============================
bool MaxHeap::removeMax(int& value)
{
    return false;                   // TODO: root out, last leaf to the
    //       root, bubbleDown(0)
}

void MaxHeap::bubbleDown(int index)
{
    // TODO: find the largest of node, left child, right child;
    //       if it is a child: swapNodes, continue from that child
}

bool MaxHeap::getMax(int& value) const
{
    return false;                   // TODO: copy the root, change nothing
}

// ============================ given ============================
void MaxHeap::swapNodes(int a, int b)
{
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
    swapCount++;                    // every swap is counted
}

int MaxHeap::size() const
{
    return (int)heap.size();        // size_t -> int, in one place only
}

bool MaxHeap::isEmpty() const { return heap.empty(); }
void MaxHeap::clear() { heap.clear(); }
bool MaxHeap::isValid() const { return isMaxHeap(heap); }
int  MaxHeap::swaps() const { return swapCount; }
void MaxHeap::resetSwaps() { swapCount = 0; }

void MaxHeap::printArray() const
{
    if (heap.empty())
        cout << "(empty)";
    for (int value : heap)
        cout << value << " ";
}

void MaxHeap::printTree() const
{
    int n = size();
    int levels = 0;                 // how many levels does the tree have?
    while ((1 << levels) - 1 < n)   // 1 << k is 2 to the power k
        levels++;
    int index = 0;
    for (int level = 0; level < levels; level++) {
        int count = 1 << level;                 // nodes on this level
        int slot = 4 << (levels - 1 - level);   // columns per node
        for (int k = 0; k < count && index < n; k++) {
            cout << setw(slot / 2 + 1) << heap[index]
                << string(slot / 2 - 1, ' ');
            index++;
        }
        cout << endl;
    }
}
