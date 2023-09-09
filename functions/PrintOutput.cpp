#include <iostream>
#include "../headers/TextTable.h"
#include "../headers/NodeStructure.h"
#include <algorithm>
#include <vector>
using namespace std;

class PrintOutput
{
public:
    void printLinkedList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->finish_time << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    vector<Node *> SortElem(Node *head)
    {
        vector<Node *> nodes;

        Node *temp = head;
        while (temp != NULL)
        {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Sort the nodes by p_id using a custom comparison function
        sort(nodes.begin(), nodes.end(), [](const Node *a, const Node *b)
             { return a->p_id < b->p_id; });

        return nodes;
    }

    void printTable(Node *head)
    {
        vector<Node *> temp = this->SortElem(head);
        TextTable t('-', '|', '+');

        t.add("P_Id");
        t.add("Arrival Time");
        t.add("Burst Time");
        t.add("Finish Time");
        t.add("Turn Around Time");
        t.add("Waiting Time");
        t.endOfRow();

        for (const auto i : temp)
        {
            t.add(to_string(i->p_id));
            t.add(to_string(i->arrival_time));
            t.add(to_string(i->burst_time));
            t.add(to_string(i->finish_time));
            t.add(to_string(i->tat));
            t.add(to_string(i->wt));
            t.endOfRow();
        }
        t.setAlignment(6, TextTable::Alignment::RIGHT);
        cout << t;
    }

    void printGanChart(vector<int> g_chart)
    {
        TextTable t('-', '|', '+');

        for (auto i : g_chart)
        {
            t.add("P" + to_string(i));
        }
        t.endOfRow();

        t.setAlignment(2, TextTable::Alignment::RIGHT);
        cout << t;
        return;
    }
};