/* 面试题7：重建二叉树
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
假设输入的前序遍历和中序遍历的结果中都不包含重复的数字。
例如，输入前序遍历序列{1,2,4,7,3,5,6,8} 和中序遍历序列
{4,7,2,1,5,3,8,6}。 重建如图2.6,并输出它的头节点。

二叉树节点的定义如下：
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}

*/

/*
解题思路：
1. 前序遍历： 根节点、左子树、右子树
2. 中序遍历： 左子树、根节点、右子树

通过前序遍历序列确定根节点 1 ，然后从中序遍历可以看出左子树 4,7,2 和右子树 5,3,6,8。
同理，对于左子树 4,7,2 从前序遍历可以看出 根节点是 2, 那么左子树是 4,7,没有右子树。。。
由此可以看出，这是一个递归
*/

#include <iostream>
#include <exception>
#include "BinaryTree.h"

//struct BinaryTreeNode
//{
//    int                    m_nValue;
//    BinaryTreeNode*        m_pLeft;
//    BinaryTreeNode*        m_pRight;
//};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;

    return ConstructCore(preorder, preorder+length-1,
                         inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    // 前序遍历序列的地一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (startPreorder == endPreorder)
    {
        if(*startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input");
    }

    // 在中序遍历中寻找根节点的值
    int* pInorder = startInorder;
    while(pInorder <= endInorder && *pInorder != rootValue)
        ++ pInorder;

    // 中序遍历序列中没有找到根节点的值，返回错误
//    if(pInorder == endInorder && *pInorder != rootValue)
//        return;

    int leftLength = pInorder - startInorder;  // 地址的加减运算
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树,每递归调用一次函数，找到左子树，并将根节点添加进二叉树中
        root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd,
                                      startInorder, pInorder-1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
                                       pInorder+1, endInorder);
    }
    return root;
}

//============================== 测试代码 ===============================

// 普通二叉树
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8

void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestoryTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

void Test2()
{
    try
    {
        BinaryTreeNode* root = Construct(NULL, NULL, 0);
        PrintTree(root);

        DestoryTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}



int main()
{
    Test1();
    Test2();
    return 0;
}
