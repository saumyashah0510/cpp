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

void intersect(node *&head1, node *&head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return;
    }

    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }
        else if (temp1->data == temp2->data)
        {
            cout << temp1->data << " ";
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        else
        {
            temp1 = temp1->next;
        }
    }
}

int main()
{

    node *head1 = new node(6);
    insert_at_head(head1, 4);
    insert_at_head(head1, 3);
    insert_at_head(head1, 2);
    insert_at_head(head1, 1);

    node *head2 = new node(8);
    insert_at_head(head2, 6);
    insert_at_head(head2, 4);
    insert_at_head(head2, 2);

    print(head1);
    print(head2);
    intersect(head1,head2);

    return 0;
}