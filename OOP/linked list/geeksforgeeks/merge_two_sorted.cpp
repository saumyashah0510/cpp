#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void printList(node *curr)
{
    while (curr != nullptr)
    {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " -> ";
        curr = curr->next;
    }
    cout << " -> NULL" << endl;
}

void merge(node *&head1, node *&head2)
{
    node* temp = new node(0);
    node* dummy = temp;
    node *one = head1;
    node *two = head2;

    while(one != NULL && two != NULL)
    {
        if(one->data < two->data)
        {
            dummy->next = one;
            one = one->next;
        }
        else
        {
            dummy->next = two;
            two = two->next;
        }
        dummy = dummy->next;
    }
    if (one != NULL)
    {
        dummy->next = one;
    }
    else
    {
        dummy->next = two;
    }

    head1 = temp->next;
    delete(temp);

}

int main()
{

    node *head1 = new node(5);
    head1->next = new node(10);
    head1->next->next = new node(15);
    head1->next->next->next = new node(40);

    node *head2 = new node(2);
    head2->next = new node(3);
    head2->next->next = new node(20);

    printList(head1);
    printList(head2);

    merge(head1, head2);
    printList(head1);

    return 0;
}