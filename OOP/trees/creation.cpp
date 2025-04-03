#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *&root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data  for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level completed
            cout << endl;
            if (!q.empty())
            {
                // still has some chhild nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverse_levelOrderTraversal(node *root)
{
    stack<node *> s;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level completed
            s.push(0);
            if (!q.empty())
            {
                // still has some chhild nodes
                q.push(NULL);
            }
        }
        else
        {
            s.push(temp);
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }

    while (!s.empty())
    {
        if (s.top() == 0)
        {
            cout << endl;
            s.pop();
        }
        else
        {
            int x = s.top()->data;
            cout << x << " ";
            s.pop();
        }
    }
}

void inorder_traversal(node *root) // LNR (Left node right)
{
    if (root == NULL)
    {
        return;
    }

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void preorder_traversal(node *root) // NLR (node left right)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(node *root) // LRN (left right node)
{
    if (root == NULL)
    {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;

    buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Printing the level order traversal:" << endl;
    levelOrderTraversal(root);

    cout << "Printing reverse level order traversal:" << endl;
    reverse_levelOrderTraversal(root);

    cout << endl
         << "Inorder traversal:" << endl;
    inorder_traversal(root);

    cout << endl
         << "Preorder traversal:" << endl;
    preorder_traversal(root);

    cout << endl
         << "Postorder traversal:" << endl;
    postorder_traversal(root);

    return 0;
}