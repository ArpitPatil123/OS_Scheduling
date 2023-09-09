// NodeStructure.h
#ifndef NODESTRUCTURE_H
#define NODESTRUCTURE_H

class Node
{
public:
    int p_id;
    int arrival_time;
    int burst_time;
    int finish_time;
    int tat;
    int wt;
    Node *next;

    Node(int p_id, int arrival_time, int burst_time);
};

#endif
