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
    node()
    {
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

void insert_at_last(node *&head, int data)
{
    node *temp = head;
    node *n = new node(data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    n->next = NULL;
    temp->next = n;
}

void insert_at_index(node *&head, int data, int index)
{
    node *temp = head;
    node *n = new node(data);

    if (index == 0)
    {
        insert_at_head(head, data);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void delete_first(node *&head)
{
    node *temp = head;
    head = temp->next;
    delete (temp);
}

void delete_end(node *&head)
{
    node *temp = head->next;
    node *p = head;

    while (temp->next != NULL)
    {
        p = p->next;
        temp = temp->next;
    }

    p->next = temp->next;
    delete (temp);
}

void delete_at_index(node *&head, int index)
{
    node *p = head->next;
    node *q = head;

    if (index == 0)
    {
        delete_first(head);
    }
    else
    {
        for (int i = 1; i < index; i++)
        {
            p = p->next;
            q = q->next;
        }

        q->next = p->next;
        delete (p);
    }
}

int main()
{

    node *head = new node(10);

    print(head);
    insert_at_head(head, 15);
    print(head);
    insert_at_last(head, 5);
    print(head);
    insert_at_index(head, 7, 2);
    print(head);
    insert_at_index(head, 20, 0);
    print(head);
    delete_first(head);
    print(head);
    delete_end(head);
    print(head);
    delete_at_index(head, 2);
    print(head);

    return 0;
}