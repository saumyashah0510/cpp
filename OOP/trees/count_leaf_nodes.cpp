// https://www.naukri.com/code360/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&leftPanelTabValue=SUBMISSION


/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int count = 0;

    while(!q.empty())
    {
        BinaryTreeNode<int>* temp = q.front();
        q.pop();

        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left == NULL && temp->right == NULL)
        {
            count++;
        }

    }
    return count;

}