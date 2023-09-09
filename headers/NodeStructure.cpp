#include "NodeStructure.h"

Node::Node(int p_id, int arrival_time, int burst_time)
{
    this->p_id = p_id;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;
    this->finish_time = 0;
    this->tat = 0;
    this->wt = 0;
    this->next = nullptr;
}