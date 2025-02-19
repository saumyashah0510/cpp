// one method is to store elemnets in array and apply logic but space complexxity will be O(n)
// so approach with S.C. O(1):
// reach the middle elemnt and reverse the next half and check data

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

bool palindrome(node *&head)
{
    node *temp = head;
    int length = 0;
    bool pal = true;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < length / 2; i++)
    {
        temp = temp->next;
    }
    if (length % 2 != 0)
    {
        reverse(temp->next);
        temp = temp->next;
    }
    else
    {
        reverse(temp);
    }

    node *check = head;

    for (int i = 0; i < length / 2; i++)
    {
        if (check->data != temp->data)
        {
            pal = false;
            break;
        }
        check = check->next;
        temp = temp->next;
    }
    return pal;
}

int main()
{

    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(3);
    head->next->next->next->next = new node(2);
    head->next->next->next->next->next = new node(1);
    print(head);
    bool check = palindrome(head);

    if (check == true)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}