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

void remove_duplicate(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *prev = head;
    node *curr = head->next;
    node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        if (curr->data == prev->data)
        {
            prev->next = forw;
            curr->next = NULL;
            delete(curr);
            curr = forw;
        }
        else
        {
            prev = curr;
            curr = forw;
        }
    }
}

int main()
{

    node *head = new node(4);

    insert_at_head(head, 3);
    insert_at_head(head, 3);
    insert_at_head(head, 3);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 2);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    print(head);
    remove_duplicate(head);
    print(head);

    return 0;
}