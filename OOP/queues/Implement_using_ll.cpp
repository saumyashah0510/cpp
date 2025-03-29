#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    struct node
    {
        node *next;
        int data;

        node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    bool isEmpty(node* front)
    {
        if(front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(node *&f, node *&r, int data)
    {
        node *n = new node(data);

        // queue empty
        if (r == nullptr)
        {
            f = r = n;
            return;
        }

        r->next = n;
        r = n;
    }

    void dequeue(node *&f, node *&r)
    {
        if (f == nullptr)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        node *temp = f;
        f = temp->next;
        delete (temp);

        if (f == nullptr)
        {
            r = NULL;
        }
    }

    int peek(node *f)
    {
        if (f == nullptr)
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        return f->data;
    }
};

int main()
{

    Queue q;
    Queue::node *front = NULL;
    Queue::node *rear = NULL;

    q.enqueue(front, rear, 1);
    q.enqueue(front, rear, 2);
    q.enqueue(front, rear, 3);
    cout << q.peek(front) << endl;

    q.dequeue(front, rear);
    cout << q.peek(front) << endl;

    q.dequeue(front, rear);
    cout << q.peek(front) << endl;

    q.dequeue(front, rear);
    cout << q.peek(front) << endl;

    return 0;
}