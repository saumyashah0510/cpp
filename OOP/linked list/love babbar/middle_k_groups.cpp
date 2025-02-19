#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *next;
    int data;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

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

node *kreverse(node *&head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    node *prev = NULL;
    node *forw = NULL;
    node *curr = head;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
        count++;
    }

    if (forw != NULL)
    {
        head->next = kreverse(forw, k);
    }

    return prev;
}

int main()
{

    node *head = new node(3);
    insert(head, 5);
    insert(head, 7);
    insert(head, 9);
    insert(head, 11);
    insert(head, 13);
    print(head);

    head = kreverse(head, 3);
    print(head);

    return 0;
}