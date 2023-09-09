// Importing Global Files
#include <iostream>

// Importing Local Files
#include "headers/NodeStructure.h"
#include "headers/TextTable.h"
#include "functions/PrintOutput.cpp"
#include "functions/Helper.cpp"
#include "headers/Globals.h"

// Specifying Namespace std;
using namespace std;

int main()
{
    // Creating objects
    Helper helper;
    PrintOutput table;
    LinkedList ll;

    // Creating menu driven program for FCFS and SJF (Non-preemptive)
    while (true)
    {
        cout << "1. FCFS" << endl;
        cout << "2. SJF" << endl;
        cout << "3. EXIT" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            helper.takeInput();
            helper.calculateTime(HEAD);
            helper.generateGanChart(HEAD);

            table.printGanChart(G_CHART);
            table.printTable(HEAD);

            // Printing Linked List
            table.printLinkedList(HEAD);

            ll.deleteLinkedList();
            cout << "Printing linked List after deleting node: " << endl;
            table.printLinkedList(HEAD);
            break;

        case 3:
            cout << "Thank You!!!";
            exit(1);

        default:
            break;
        }
    }
}