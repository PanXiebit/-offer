/*
题目： 输入一个链表的头节点，从尾到头反过来打印每个节点的值。
链表节点定义如下：
struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
}
*/

/*
解题思路：
从头到尾读取链表的之，并放入栈中，“后进先出”
*/
#include <stack>
#include <iostream>
#include <stdio.h>
#include "List.h"

using namespace std;

void reversePrint(ListNode* pHead)
{
    std::stack <ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}


void reversePrint_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if (pHead->m_pNext != NULL)
            reversePrint_Recursively(pHead->m_pNext);
    }
    printf("%d\t", pHead->m_nValue);
}


//=======================测试代码=======================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    reversePrint(pHead);
    printf("\n");
    reversePrint_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins. \n");

    ListNode* pNode1 = CreatListNode(1);
    ListNode* pNode2 = CreatListNode(2);
    ListNode* pNode3 = CreatListNode(3);
    ListNode* pNode4 = CreatListNode(4);
    ListNode* pNode5 = CreatListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);
    DestroyList(pNode1);
    printf("\nTest1 begins. \n");
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreatListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}


int main()
{
    Test1();
    Test2();
    return 0;
}
