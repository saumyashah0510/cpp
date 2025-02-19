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
        this->next = NULL;
        this->data = data;
    }
};

void print(node *&tail)
{
    node *temp = tail;

    if(tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail);

    cout << tail->data << endl;
}

void insert(node *&tail, int element, int data)
{

    // empty list
    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        temp->next = temp;
        return;
    }
    // non empty
    else
    {
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

bool check(node* &head)
{
    if(head == NULL)
    {
        return true;
    }
    node* temp = head->next;
    while(temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return false;
    }
    if(temp == head)
    {
        return true;
    }
}

int main(){

    node* tail = NULL;
    insert(tail, 5, 1);
    print(tail);
    insert(tail, 1, 3);
    print(tail);
    insert(tail, 3, 5);
    print(tail);
    insert(tail, 3, 4);
    print(tail);
    insert(tail, 5, 7);
    insert(tail, 7, 9);
    print(tail);
    
    cout << check(tail) << endl;

    return 0;

}