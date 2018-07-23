#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;



//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void treaver(TreeNode* pNode);

TreeNode* firstNode = NULL;
TreeNode* secondNode = NULL;
TreeNode* prevNode = new TreeNode(INT_MIN);


int recoverTree(TreeNode* root) {
    treaver(root);

    int temp = firstNode->val;
    firstNode->val = secondNode->val;
    secondNode->val = temp;

    return temp;
}


void treaver(TreeNode* pNode)
{
    if (pNode == NULL)
        return;

    treaver(pNode->left);

    // 只有在最左边的时候，firstNode为空，这个时候先赋予最左节点为prevNode
    // 然后递归遍历左子树，并将当前节点赋予prevNode. prevNode是不断变化的
    // 当prevNode节点值大于当前val时，
    if (firstNode == NULL && prevNode->val >= pNode->val)
        firstNode = prevNode;
    if (firstNode != NULL && prevNode->val >= pNode->val)
        secondNode = pNode;
    prevNode = pNode;

    treaver(pNode->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* p1 = new TreeNode(3);
    TreeNode* p2 = new TreeNode(2);
    root->left = p1;
    p1->right = p2;

    int res = recoverTree(root);
    cout << res << endl;
    return 0;
}
