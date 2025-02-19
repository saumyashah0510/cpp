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

bool floyd_detect(node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

int length_loop(node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    node *slow = head;
    node *fast = head;
    node *temp = NULL;
    int count = 1;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
        {
            temp = fast;
            break;
        }
    }
    temp = temp->next;
    while (temp != fast)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{

    node *head = new node(1);

    node *one = new node(2);
    head->next = one;

    node *two = new node(3);
    one->next = two;

    node *three = new node(4);
    two->next = three;

    node *four = new node(5);
    three->next = four;

    node *five = new node(6);
    four->next = five;

    node *six = new node(7);
    five->next = six;
    six->next = three;

    int check = floyd_detect(head);

    if (check == 1)
    {
        cout << "Loop detected" << endl;
        cout << "Length of loop is " << length_loop(head) << endl;
    }
    else
    {
        cout << "No loop detected" << endl;
    }

    return 0;
}