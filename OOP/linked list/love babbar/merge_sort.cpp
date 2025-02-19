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

node *middle(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *slow = head;
    node *fast = head->next; // Start fast pointer one step ahead to handle even-length lists.

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *merge(node *&left, node *&right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    // merge two sorted linked list
    node *temp = new node(0);
    node *dummy = temp;
    node *one = left;
    node *two = right;

    while (one != NULL && two != NULL)
    {
        if (one->data < two->data)
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

    left = temp->next;
    delete (temp);
    return left;
}

node *merge_sort(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // find mid
    node *mid = middle(head);

    // divide linked list in two parts
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = merge_sort(left);
    right = merge_sort(right);

    // merge both left and right halves
    node *result = merge(left, right);
    return result;
}

int main()
{

    node *head = new node(4);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(5);
    print(head);

    head = merge_sort(head);
    print(head);

    return 0;
}