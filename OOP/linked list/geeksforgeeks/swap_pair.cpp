#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
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

void insert_at_head(node *&head, int data)
{
    node *temp = new node(data);

    temp->next = head;
    head = temp;
}

void swap(node *&head)
{
    node *prev = head;
    node *curr = head->next;

    if (head == NULL || head->next == NULL)
    {
        return;
    }
    head = head->next;

    while (1)
    {
        node *forw = curr->next;
        curr->next = prev;

        if (forw == NULL || forw->next == NULL)
        {
            prev->next = forw;
            return;
        }
        prev->next = forw->next;
        prev = forw;
        curr = forw->next;
    }
}

int main()
{

    node *head = new node(10);

    insert_at_head(head, 15);
    insert_at_head(head, 20);
    insert_at_head(head, 25);
    insert_at_head(head, 30);
    insert_at_head(head, 35);
    insert_at_head(head, 40);
    insert_at_head(head, 45);
    insert_at_head(head, 50);
    insert_at_head(head, 55);
    print(head);
    swap(head);
    print(head);

    return 0;
}