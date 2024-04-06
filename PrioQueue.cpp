#include "PrioQueue.h"

PrioQueue::~PrioQueue(){
    adjNode* temp;
    while (front != nullptr && front->next != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    delete front;
    //cout << "Queue destructed." << endl;
};


void PrioQueue::enqueue(int v,int prio){
    adjNode *temp, *q;
    temp = new adjNode;
    temp->val = v;
    temp->cost = prio;
    if(front == nullptr || prio < front->cost){
        temp->next = front;
        front = temp;
    }
    else{
        q = front;
        while (q->next != nullptr && q->next->cost <= prio)
        {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
};

adjNode* PrioQueue::dequeue(){
    adjNode *temp;
    if(front != nullptr)
    {
        temp = front;
        front = front->next;
        return temp;
    }
    else return nullptr;
};

void PrioQueue::display(){
    if(front == nullptr){
        cout << "Queue is empty." << endl;
    }
    else{
        adjNode* temp;
        temp = front;
        while (temp != nullptr)
        {
            cout << "->" << temp->val <<"(" << temp->cost << ")";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool PrioQueue::isEmpty(){
    return front == nullptr;
};