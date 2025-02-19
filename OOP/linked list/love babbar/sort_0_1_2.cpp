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

void sort(node *&head)
{
    int zerocount = 0, onecount = 0, twocount = 0;
    node *temp = head;
    node *sort = new node(10);
    node *dummy = sort;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocount++;
        }
        else if (temp->data == 1)
        {
            onecount++;
        }
        else if (temp->data == 2)
        {
            twocount++;
        }
        temp = temp->next;
    }
    for (int i = 0; i < zerocount; i++)
    {
        dummy->next = new node(0);
        dummy = dummy->next;
    }
    for (int i = 0; i < onecount; i++)
    {
        dummy->next = new node(1);
        dummy = dummy->next;
    }
    for (int i = 0; i < twocount; i++)
    {
        dummy->next = new node(2);
        dummy = dummy->next;
    }
    head = sort->next;
    delete sort;
}

int main()
{
    node *head = new node(1);
    head->next = new node(0);
    head->next->next = new node(2);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(2);
    print(head);
    sort(head);
    print(head);

    return 0;
}