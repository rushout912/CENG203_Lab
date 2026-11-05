    #include "Labs.h"                   // same folder (Labs)
#include "../LinkedList/Node.h"     // ".." = go up one folder
#include "../LinkedList/LinkedList.h"   // it ALSO includes Node.h
#include <iostream>
using namespace std;

void runWeek02()
{
    cout << "--- Week 2: project structure test ---" << endl;

    Node single;                    // a Node can be used on its own
    single.data = 5;
    single.next = nullptr;
    cout << "Single node: " << single.data << endl;

    LinkedList list;
    cout << "Empty list? " << (list.isEmpty() ? "yes" : "no") << endl;
    list.insertAtFront(30);
    list.insertAtFront(20);
    list.insertAtFront(10);
    list.display();
    cout << "Empty list? " << (list.isEmpty() ? "yes" : "no") << endl;
}
