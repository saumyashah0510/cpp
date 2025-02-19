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

int middle(node *&head)
{
    node *temp = head;
    node *temp1 = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    for (int i = 0; i < length / 2; i++)
    {
        temp1 = temp1->next;
    }

    return temp1->data;
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
    cout << "Middle element is " << middle(head) << endl;

    return 0;
}