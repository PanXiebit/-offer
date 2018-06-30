// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3


/*
长度为n的数组中，其中的数字都在 0～n-1 之间，如果没有重复的话，经过排序后得到的数组中数字 i 就应该出现在下标 i 处。

从头到尾扫描这个数组，当扫描到下标为i位置时，比较其对应的数字 m 是不是等于 i 。
- 如果是，则扫描下一个数字，
- 如果不是，则拿它和位置为 m 的数进行比较，如果相等，就找到重复的数字了；如果不想等，就把第 i 个数字和第 m 个数字交换，
  也就是让m到属于它的位置。
- 接下来重复上面的比较。

总的来说，第一个位置的数字最多交换一次，其他位置的数字最多交换两次就可以找到属于它们的位置。

因此，总的时间复杂度是O(n), 不需要额外的空间，空间复杂度是O(1).

*/

#include <iostream>
#include <stdio.h>

using namespace std;

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字

bool duplicate(int numbers[], int length, int* duplication)
{
    /* 检查是否为空串 */
    if(numbers == NULL || length < 0)
    {
        return false;
    }


    /* 检查数组的元素是否在0～n-1之间*/
    for (int i=0; i<length; ++i)
    {
        if(numbers[i]<0 || numbers[i]>length - 1)
            return false;
    }


    for (int i=0; i<length; ++i)
    {
        /* 如果当前i位置元素不等于i，如果是j=numbers[i] */
        while(numbers[i] != i)
        {
            /* 那么属于 j=numbers[i] 的位置如果已经是j了，就说明重复了,那么返回 true*/
            if (numbers[i] == numbers[numbers[i]])
            {
                // *duplication 相当与一个整数
                *duplication = numbers[i];
                return true;
            }

            /* 如果属于 j=numbers[i] 的位置不是 j ，那么交换把 j=numbers[i] 放到属于
            它的位置 j 处， 至于j位置的数 numbers[j] 先放到 i 处，然后再比较当前交换回来的位置*/
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }

    }
    return false;
}

/* 数组第一个元素最多交换一次就能找到属于自己的位置，其他的元素最多交换两次 */



// 期望得到的重复的数组成的数组
bool contains(int array[], int length, int number)
{
    for (int i=0; i<length; i++)
    {
        if (array[i] == number)
            return true;
    }

    return false;
}


// 测试 duplicate 函数得到的重复数 是否在 expected[]数组中
void test(const char* testName, int numbers[], int lengthNumbers,  int expected[], int expectedNumbers, bool validArgument)
{
    printf("%s begins:\n", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    // 如果都为 true 或者 都为 false
    if(validArgument == validInput)
    {
        // 只有都为true时才返回 true
        if (validArgument)
        {
            if (contains(expected, expectedNumbers, duplication))
            {
                printf("%d\n", duplication);
                printf("passed.\n");
            }

            else
                printf("FAILED.\n");
        }
        else
            printf("FAILED.\n");
    }
    else
        printf("FAILED.\n");
}


void test1()
{
    int numbers[] = {1,2,3,2,1};
    int duplications[] = {1,2};
    test ("Test1", numbers, sizeof(numbers)/sizeof(int), duplications, sizeof(duplications)/sizeof(int), true);

}

// 不存在重复的数字，failed
void test2()
{
    int numbers[] = {1,2,3,4,0};
    int duplications[] = {};
    test ("Test2", numbers, sizeof(numbers)/sizeof(int), duplications, sizeof(duplications)/sizeof(int), false);

}

// 数组中存在多个重复的数字, pass
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 5, 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

