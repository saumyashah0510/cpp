#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insert_at_start(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_at_last(node *&head, int data)
{
    node *temp = new node(data);
    node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
    temp->prev = p;
}

void insert_at_index(node *&head, int data, int index)
{
    node *temp = head;
    node *n = new node(data);

    if (index < 0)
    {
        cout << "Error: Invalid index." << endl;
        return;
    }

    if (index == 0)
    {
        insert_at_start(head, data);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }

        n->next = temp->next;
        n->prev = temp;
        temp->next = n;
    }   
}

void reverse(node *&head)
{
    node *previous = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        node *forward = curr->next;
        curr->next = previous;
        curr->prev = forward;
        previous = curr;
        curr = forward;
    }
    head = previous;
}

int main()
{

    node *head = new node(10);
    print(head);
    insert_at_start(head, 5);
    print(head);
    insert_at_last(head, 15);
    print(head);
    insert_at_index(head, 12, 2);
    print(head);
    reverse(head);
    print(head);

    return 0;
}