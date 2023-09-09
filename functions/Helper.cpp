#include <iostream>
#include <fstream>
#include <sstream>

#include "../headers/NodeStructure.h"
#include "../functions/LinkedList.cpp"
#include "../headers/Globals.h"

using namespace std;

class Helper : protected LinkedList
{
public:
    vector<vector<int>> split(const string &input, char delimiter)
    {
        vector<vector<int>> tokens;
        ifstream tokenStream(input);
        string token;
        while (getline(tokenStream, token))
        {
            istringstream iss(token);
            string temp;
            vector<int> temp1;

            while (getline(iss, temp, delimiter))
            {
                temp1.push_back(stoi(temp));
            }

            tokens.push_back(temp1);
        }

        return tokens;
    }

    void takeInput()
    {
        string filename = "inputs/FCFSinput.txt";
        vector<vector<int>> tokens = split(filename, ',');

        for (const auto i : tokens)
        {
            int p_id = i[0];
            int arrival_time = i[1];
            int burst_time = i[2];
            Node *newNode = new Node(p_id, arrival_time, burst_time);
            insertNode(newNode);
        }
        return;
    }

    void calculateTime(Node *head)
    {
        Node *temp = head;
        int prevTime = 0;
        while (temp != NULL)
        {
            temp->finish_time = prevTime + temp->burst_time;
            temp->tat = temp->finish_time - temp->arrival_time;
            temp->wt = temp->tat - temp->burst_time;
            prevTime = temp->finish_time;
            temp = temp->next;
        }

        return;
    }

    void generateGanChart(Node *head)
    {
        Node *temp = head;
        int i = 0;
        cout << "Gantt Chart is: " << endl;
        while (temp != NULL)
        {
            for (int j = 0; j < temp->burst_time; j++)
            {
                G_CHART.push_back(temp->p_id);
            }
            temp = temp->next;
        }

        return;
    }
};