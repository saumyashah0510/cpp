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
    node *curr = NULL;

    while (prev != NULL && prev->next != NULL)
    {
        curr = prev;
        while(curr->next != NULL)
        {
            if(curr->next->data == prev->data)
            {
                node* duplicate = curr->next;
                curr->next = curr->next->next;
                delete(duplicate);
            }
            else
            {
                curr = curr->next;
            }
        }
        prev = prev->next;
    }
}

int main()
{

    node *head = new node(1);

    insert_at_head(head, 2);
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 4);
    insert_at_head(head, 5);
    insert_at_head(head, 2);
    insert_at_head(head, 2);
    print(head);
    remove_duplicate(head);
    print(head);

    return 0;
}