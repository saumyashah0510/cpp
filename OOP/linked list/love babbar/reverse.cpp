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

void reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

// reference: https://youtu.be/vqS1nVQdCJM?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&t=1400
node *recursive_reverse(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *revhead = recursive_reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return revhead;
}

int main()
{

    node *head = new node(3);
    insert(head, 5);
    insert(head, 7);
    insert(head, 9);
    print(head);
    reverse(head);
    print(head);
    head = recursive_reverse(head);
    print(head);

    return 0;
}