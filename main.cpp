#include <iostream>
#include "Labs/Labs.h"              // Labs.h is in the Labs subfolder
using namespace std;

int main()                          // the ONLY main() of the project
{
    int choice;
    do {
        cout << "\n===== CENG203 Data Structures Lab =====" << endl;
        cout << " 2. Week 2 - Project structure test" << endl;
        cout << " 3. Week 3 - Linked lists" << endl;
        cout << " 4. Week 4 - Stacks and queues" << endl;
        cout << " 5. Week 5 - Recursion" << endl;
        cout << " 6. Week 6 - Trees and BSTs" << endl;
        cout << " 0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 2:  runWeek02(); break;
        case 3:  runWeek03(); break;
        case 4:  runWeek04(); break;
        case 5:  runWeek05(); break;
        case 6:  runWeek06(); break;
        case 0:  cout << "Bye!" << endl; break;
        default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
