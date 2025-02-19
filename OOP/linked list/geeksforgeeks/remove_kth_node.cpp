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

void kremove(node *&head, int index)
{

    if (index <= 1 || head == NULL) // Handle edge cases
        return;

    int count = 1;
    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        node *forw = temp->next;
        count++;

        if (count % index == 0)
        {
            temp->next = forw->next;
            forw->next = NULL;
            delete (forw);
            count++;
        }
        temp = temp->next;
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
    kremove(head, 4);
    print(head);
    kremove(head, 2);
    print(head);

    return 0;
}