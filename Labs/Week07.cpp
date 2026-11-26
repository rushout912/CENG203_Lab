#include "Labs.h"
#include "../Heap/MaxHeap.h"
#include "../Heap/PriorityQueue.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Q4 and Q6 are prediction questions: their blocks stay switched off
// until your tables are filled in. Then change false to true.
const bool SHOW_Q4 = true;
const bool SHOW_Q6 = true;

// Q1: prints an array and whether it obeys the max-heap rule
void w7Check(const vector<int>& a)
{
    cout << "[Q1] ";
    for (int v : a)
        cout << v << " ";
    cout << " max-heap? " << MaxHeap::isMaxHeap(a) << endl;
}

// Inserts the values one by one; prints the heap after every insert
void w7InsertAll(const char* tag, MaxHeap& h, const vector<int>& values)
{
    for (int v : values) {
        int before = h.swaps();
        h.insert(v);
        cout << tag << " insert " << setw(2) << v << ": swaps = "
            << h.swaps() - before << "  heap: ";
        h.printArray();
        cout << endl;
    }
}

// Removes the maximum until the heap is empty; prints every step
void w7RemoveAll(const char* tag, MaxHeap& h)
{
    int value = 0;
    int before = h.swaps();
    while (h.removeMax(value)) {
        cout << tag << " removeMax = " << setw(2) << value << ": swaps = "
            << h.swaps() - before << "  heap: ";
        h.printArray();
        cout << endl;
        before = h.swaps();
    }
}

// Q6: 1000 values, starting at first and changing by step each time;
// prints the swaps of the insert phase and of the removal phase
void w7Measure(const char* label, int first, int step)
{
    MaxHeap h;
    for (int i = 0; i < 1000; i++)
        h.insert(first + i * step);
    int insertSwaps = h.swaps();
    int value = 0;
    while (h.removeMax(value)) {}      // empty body: just remove all
    cout << "[Q6] n = 1000 " << label << ": insert swaps = "
        << insertSwaps << "  remove swaps = "
        << h.swaps() - insertSwaps << endl;
}

// Q5: interactive mode - a sub-menu in a function, NOT a second main()
void heapMenu()
{
    MaxHeap heap;
    int choice = 0;
    int value = 0;
    int before = 0;
    do {
        cout << "\n--- Heap menu ---" << endl;
        cout << " 1. Insert a number" << endl;
        cout << " 2. Remove maximum" << endl;
        cout << " 3. Show heap" << endl;
        cout << " 4. Clear heap" << endl;
        cout << " 0. Back" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (cin.fail()) {               // a letter was typed: repair cin
            cin.clear();
            cin.ignore(1000, '\n');
            choice = -1;                // ends in "Invalid choice!"
        }

        switch (choice) {
        case 1:
            cout << "Number: ";
            cin >> value;
            before = heap.swaps();
            heap.insert(value);
            cout << value << " inserted, swaps = "
                << heap.swaps() - before << endl;
            break;
        case 2:
            if (heap.removeMax(value))
                cout << "Removed " << value << endl;
            else
                cout << "Heap is empty!" << endl;
            break;
        case 3:
            cout << "Array: ";
            heap.printArray();
            cout << endl;
            heap.printTree();
            break;
        case 4:
            heap.clear();
            cout << "Heap cleared." << endl;
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

void runWeek07()
{
    cout << "--- Week 7: Heaps and Priority Queues ---" << endl;
    cout << boolalpha;

    // ---------- Q1: the array is the tree ----------
    cout << "[Q1] parent(4) = " << MaxHeap::parent(4)
        << "  leftChild(1) = " << MaxHeap::leftChild(1)
        << "  rightChild(1) = " << MaxHeap::rightChild(1) << endl;
    cout << "[Q1] parent(1) = " << MaxHeap::parent(1)
        << "  parent(2) = " << MaxHeap::parent(2)
        << "  parent(0) = " << MaxHeap::parent(0) << endl;
    w7Check({ 20, 15, 10, 4, 0 });
    w7Check({ 10, 4, 15 });
    w7Check({ 9, 9, 9 });
    w7Check({ 50, 30, 40, 10, 20, 35 });
    w7Check({ 5, 3, 4, 6 });

    // ---------- Q2: insert and bubble up ----------
    MaxHeap h;
    w7InsertAll("[Q2]", h, { 10, 4, 15, 20, 0 });
    cout << "[Q2] size = " << h.size()
        << "  valid = " << h.isValid() << endl;
    h.printTree();

    // ---------- Q3: remove the maximum and bubble down ----------
    int top = 0;
    bool ok = h.getMax(top);            // look first, print afterwards
    cout << "[Q3] getMax = " << ok << "  top = " << top
        << "  size is still " << h.size() << endl;
    w7RemoveAll("[Q3]", h);
    ok = h.removeMax(top);
    cout << "[Q3] removeMax on an empty heap = " << ok << endl;

    // ---------- Q4: the guessing game (needs SHOW_Q4) ----------
    if (SHOW_Q4) {
        MaxHeap g;
        w7InsertAll("[Q4]", g, { 3, 17, 1, 8, 9, 2 });
        g.printTree();
        w7RemoveAll("[Q4]", g);
    }

    // ---------- Q6: order analysis (needs SHOW_Q6) ----------
    if (SHOW_Q6) {
        MaxHeap up, down;
        w7InsertAll("[Q6 up]  ", up, { 1, 2, 3, 4, 5, 6 });
        w7InsertAll("[Q6 down]", down, { 20, 18, 15, 10, 5, 1 });
        cout << "[Q6] insert swaps: increasing = " << up.swaps()
            << "  decreasing = " << down.swaps() << endl;
        up.resetSwaps();
        down.resetSwaps();
        w7RemoveAll("[Q6 up]  ", up);
        w7RemoveAll("[Q6 down]", down);
        cout << "[Q6] remove swaps: increasing = " << up.swaps()
            << "  decreasing = " << down.swaps() << endl;
        w7Measure("increasing", 1, 1);      // 1, 2, 3 ... 1000
        w7Measure("decreasing", 1000, -1);  // 1000, 999 ... 1
    }

    // ---------- Q7: priority queue (emergency room) ----------
    const string names[] = { "Ali", "Berk", "Cem", "Deniz", "Ece" };
    const int urgency[] = { 2,     5,      2,     9,       5 };
    PriorityQueue er;
    for (int i = 0; i < 5; i++)
        er.enqueue(urgency[i]);         // ticket i belongs to names[i]
    int priority = 0;
    int ticket = 0;
    while (er.dequeue(priority, ticket)) {
        string who = (ticket >= 0 && ticket < 5) ? names[ticket] : "??";
        cout << "[Q7] " << who << " (priority " << priority
            << ", ticket " << ticket << ")" << endl;
    }
    ok = er.dequeue(priority, ticket);
    cout << "[Q7] dequeue on an empty queue = " << ok << endl;

    // ---------- Q5: interactive mode (last: it waits) ----------
    char answer = 'n';
    cout << "[Q5] Open the interactive heap menu? (y/n): ";
    cin >> answer;
    cin.ignore(1000, '\n');             // drop the rest of the line
    if (answer == 'y' || answer == 'Y')
        heapMenu();
}
