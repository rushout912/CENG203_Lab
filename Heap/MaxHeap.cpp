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
    return (i - 1) / 2;
}

int MaxHeap::leftChild(int i)
{
    return 2 * i + 1;
}

int MaxHeap::rightChild(int i)
{
    return 2 * i + 2;
}

bool MaxHeap::isMaxHeap(const vector<int>& a)
{
    int n = (int)a.size();
    for (int i = 1; i < n; i++)     // every node except the root
        if (a[i] > a[parent(i)])
            return false;           // a child is larger than its parent
    return true;
}

// ============================ Q2 ============================
void MaxHeap::insert(int value)
{
    heap.push_back(value);          // step 1: the next free leaf
    bubbleUp(size() - 1);           // step 2: repair the path to the root
}

void MaxHeap::bubbleUp(int index)
{
    while (index > 0 && heap[index] > heap[parent(index)]) {
        swapNodes(index, parent(index));
        index = parent(index);      // follow the value one level up
    }
}

// ============================ Q3 ============================
bool MaxHeap::removeMax(int& value)
{
    if (heap.empty())
        return false;
    value = heap[0];                // the maximum is always the root
    heap[0] = heap.back();          // step 1: last leaf replaces the root
    heap.pop_back();
    bubbleDown(0);                  // step 2: repair downwards
    return true;
}

void MaxHeap::bubbleDown(int index)
{
    int n = size();
    while (true) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;
        if (largest == index)
            return;                 // both children are smaller: done
        swapNodes(index, largest);
        index = largest;            // follow the value one level down
    }
}

bool MaxHeap::getMax(int& value) const
{
    if (heap.empty())
        return false;
    value = heap[0];
    return true;
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
