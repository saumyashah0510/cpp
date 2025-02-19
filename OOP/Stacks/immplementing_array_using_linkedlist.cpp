#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
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

    bool isEmpty(node *top)
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    struct node *push(node *top, int data)
    {
        node *newnode = new node(data);
        newnode->next = top;
        top = newnode;
        return top;
    }

    struct node *pop(node *top)
    {

        if (isEmpty(top))
        {
            cout << "Stack underflow" << endl;
            return NULL;
        }
        else
        {
            node *temp = top;
            top = top->next;
            delete (temp);
            return top;
        }
    }

    void printStack(node *top)
    {
        while (top)
        {
            cout << top->data << " -> ";
            top = top->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{

    Stack s;
    Stack::node *top = NULL;

    top = s.push(top, 10);
    top = s.push(top, 20);
    top = s.push(top, 30);
    top = s.push(top, 40);
    s.printStack(top);

    top = s.pop(top);
    top = s.pop(top);
    top = s.pop(top);
    top = s.pop(top);
    top = s.pop(top);

    s.printStack(top);

    return 0;
}