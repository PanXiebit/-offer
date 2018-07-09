/* 面试题8：二叉树的下一个节点
题目：给定一棵二叉树和其中的一个节点，如何找出中序遍历序列的下一个节点？
树中的节点除了有两个分别指向左、右子节点的指针，还有一个指向父节点的指针。
*/

/*
解题思路：
中序遍历的下一个节点，意味着不用考虑其左子树，因为左子树都在改节点之前。那么：
- 判断有无右子树，如果有，那么沿着右子树中的左指针走到头即可
- 没有右子树，判断是否有父节点，如果有父节点
    - 判断其是否是父节点的左儿子，如果是，输出父节点，
    - 如果是父节点的右儿子，找到根节点，判断是该节点在根节点的左子树中还是右子树中
        - 如果在左子树中，那么输出根节点的右儿子
        - 如果在右子树中，那么其就是最后一个节点。
*/



#include <iostream>
#include "BinaryTree_Parent.h"



BinaryTreeNode* NextNodeInorder(BinaryTreeNode* pNode)
{

    BinaryTreeNode* pNext = NULL;
    if (pNode == NULL)
        pNext = NULL;

    //  有右子树
    if (pNode ->pRight != NULL)
    {
        BinaryTreeNode* tempNode = pNode->pRight;
        while(tempNode->pLeft != NULL)
            tempNode = tempNode->pLeft;
        pNext = tempNode;
    }

    //我的代码，为啥就错了呢。。。
    else
    {
       // 无右子树，且没有父节点
        if (pNode->pParent == NULL)
            pNext = NULL;

        // 无右子树，有父节点
        else if (pNode->pParent != NULL)
        {
            BinaryTreeNode* pCurrent = pNode;
            BinaryTreeNode* pCurrParent = pCurrent->pParent;
            while(pCurrParent != NULL && pCurrent == pCurrParent->pRight)
            {
                pCurrent = pCurrParent;
                pCurrParent = pCurrParent->pParent;
            }
            pNext = pCurrParent;
        }
    }

    return pNext;
}

//========================== 测试代码 ==========================
void Test(const char* testName, BinaryTreeNode* pNode, BinaryTreeNode* excepted)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    BinaryTreeNode* pNext = NextNodeInorder(pNode);
    if(pNext == excepted)
        printf("Passes.\n");
    else
        printf("Failed.\n");
}

//            8
//        6      10
//       5 7    9  11

void Test1_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);


    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, NULL);

    DestroyTree(pNode8);

}

int main()
{
    Test1_7();
    std::cout << "Hello world!" << std::endl;
    return 0;
}
