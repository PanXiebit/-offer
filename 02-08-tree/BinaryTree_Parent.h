#ifndef BINARYTREE_PARENT_H_INCLUDED
#define BINARYTREE_PARENT_H_INCLUDED

#include <stdio.h>
using namespace std;

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode* pParent;
};

// 创建节点
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->value = value;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    pNode->pParent = NULL;

    return pNode;
}


// 连接节点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != NULL)
    {
        pParent->pLeft = pLeft;
        pParent->pRight = pRight;

        if(pLeft != NULL)
            pLeft->pParent = pParent;
        if(pRight != NULL)
            pRight->pParent = pParent;
    }
}

// 打印当前节点
void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d\n", pNode->value);

        if(pNode->pLeft != NULL)
            printf("value of its left child is: %d.\n", pNode->pLeft->value);
        else
            printf("left child is null.\n");

        if(pNode->pRight != NULL)
            printf("value of its right child is: %d.\n", pNode->pRight->value);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

// 打印二叉树
void PrintTree(BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->pLeft != NULL)
            PrintTree(pRoot->pLeft);

        if(pRoot->pRight != NULL)
            PrintTree(pRoot->pRight);
    }
}

// 删除树
void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != NULL)
    {
        BinaryTreeNode* pLeft = pRoot->pLeft;
        BinaryTreeNode* pRight = pRoot->pRight;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

#endif // BINARYTREE_PARENT_H_INCLUDED
