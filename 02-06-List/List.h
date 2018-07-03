#include <cstdlib>

#ifndef LIST_INCLUDED
#define LIST_INCLUDED

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

// 创建链表节点
ListNode* CreatListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;

    return pNode;
}

// 链接节点
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->m_pNext = pNext;
}

// 打印特定节点的值
void PrintListNode(ListNode* pNode)
{
    if(pNode == NULL)
    {
        printf("The node is NULL\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}

//遍历整个链表
void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");

    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    printf("\nPrintList ends.\n");
}

//删除链表
void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}


//尾部添加节点
void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;

    if(*pHead == NULL)
        *pHead = pNew;
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = pNew;
    }
}

// 删除节点
// 这里函数的地一个参数是指向指针的指针。当我们向一个空链表插入一个节点时，新插入的节点就是链表的指针。
// 由于会改动头指针，因此必须把 pHead 参数设为指向指针的指针，否则出了这个函数 pHead 仍然是一个空指针。
// 这么做都是因为头指针可能改变。。
void RemoveNode(ListNode** pHead, int value)
{
    if (*pHead == NULL || pHead == NULL)
        return;

    ListNode* pDele = NULL;

    // 如果删除的是头指针，指向头指针的指针就会指向第二个节点
    if((*pHead)->m_nValue == value)
    {
        pDele = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;
        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
        {
            pDele = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    // 如果找到被删除的值, 删除这个节点并释放内存。
    if (pDele != NULL)
    {
        delete pDele;
        pDele = NULL;
    }
}
#endif // LIST_INCLUDED
