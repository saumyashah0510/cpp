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

void add(node *&head1, node *&head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    int i = 0;

    vector<int> arr1, arr2;
    while (temp1 != NULL)
    {
        arr1.push_back(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        arr2.push_back(temp2->data);
        temp2 = temp2->next;
    }
    int n1 = arr1[0];
    int n2 = arr2[0];
    for (int i = 1; i < arr1.size(); i++)
    {
        n1 = n1*10 + arr1[i];
    }
    for (int i = 1; i < arr2.size(); i++)
    {
        n2 = n2*10 + arr2[i];
    }
    int sum = n1+n2;
    vector<int> summ;
    while(sum != 0)
    {
        int rem = sum%10;
        summ.push_back(rem);
        sum = sum / 10;
    }

    node* dummy = new node(summ[0]);
    for(int i=1;i<=summ.size();i++)
    {
        insert(dummy,summ[i]);
    }
    head1 = dummy->next;
}

int main()
{

    node *head1 = new node(9);
    insert(head1, 8);

    node *head2 = new node(1);
    insert(head2, 1);
    // insert(head2, 3);

    print(head1);
    print(head2);

    add(head1,head2);
    print(head1);

    return 0;
}