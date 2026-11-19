#pragma once
#include <vector>

// Max-heap of ints: a complete binary tree written level by level into
// a vector. heap[0] is the root and always holds the largest value.
class MaxHeap
{
private:
    std::vector<int> heap;          // index 0 = root
    int swapCount;                  // swaps since the last resetSwaps()

    void swapNodes(int a, int b);   // swaps two positions and counts it
    void bubbleUp(int index);       // Q2: repair upwards after insert
    void bubbleDown(int index);     // Q3: repair downwards after remove

public:
    MaxHeap();

    // ---- Q1: the array is the tree ----
    static int  parent(int i);      // index of the parent of node i
    static int  leftChild(int i);   // index of the left child
    static int  rightChild(int i);  // index of the right child
    static bool isMaxHeap(const std::vector<int>& a);

    // ---- Q2 / Q3: the heap operations ----
    void insert(int value);         // add at the end, bubble up
    bool removeMax(int& value);     // false = the heap is empty
    bool getMax(int& value) const;  // look at the root, remove nothing

    // ---- given ----
    int  size() const;
    bool isEmpty() const;
    void clear();
    bool isValid() const;           // heap rule true at every node?
    int  swaps() const;             // swap counter, for Q6
    void resetSwaps();
    void printArray() const;        // 20 15 10 4 0
    void printTree() const;         // the same values, level by level
};
