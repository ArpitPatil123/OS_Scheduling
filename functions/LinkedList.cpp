#include <iostream>
#include "../headers/NodeStructure.h"
#include "../headers/Globals.h"
using namespace std;

class LinkedList
{
public:
    void deleteNode(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        deleteNode(node->next);
        delete node;
    }

    void deleteLinkedList()
    {
        deleteNode(HEAD);
        HEAD = NULL;
    }

protected:
    void insertNode(Node *newNode)
    {
        if (HEAD == NULL || newNode->arrival_time < HEAD->arrival_time)
        {
            newNode->next = HEAD;
            HEAD = newNode;
            return;
        }

        Node *temp = HEAD;
        while (temp->next != NULL)
        {
            if (temp->next->arrival_time > newNode->arrival_time)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            else if (temp->next->arrival_time == newNode->arrival_time)
            {
                if (temp->next->p_id < newNode->p_id)
                {
                    newNode->next = temp->next->next;
                    temp->next->next = newNode;
                    return;
                }
                else
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
            }
            temp = temp->next;
        }

        temp->next = newNode;

        return;
    }
};