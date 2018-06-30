// 不修改数组找出重复的数字

/*
在一个长度为 n+1 的数组里的所有数字都在 1～n 的范围内，所以数组中至少有一个数字是重复的。
请找出数组中任意一个重复的数字，但不能修改输入的数组。例如，如果输入长度为 8 的数组 {2,3,5,4,3,2,6,7},
那么对应的输出是重复的数字 2 或 3.
*/

/*
解题思路:
1. 创建一个长度为 n+1 的辅助数组，然后逐一把原数组中的每个数字复制到辅助数组中。
如果原数组中的数字是 m， 则复制到辅助数组中的下标为 m-1 的位置。时间复杂度是 O(n), 空间复杂度也是 O(n)

2. hash table

3. 首先要想明白 1~n 范围里只有 n 个数字。由于数组中超过 n 个数字，所以一定包含了重复的数字。
所以一个范围内有多少个数字对解决这个问题很重要。至少一定在某个范围内有多余的数字。所以可以采用二分法逐渐缩小这个范围。

但有点不好的是，比如数组是 {1,1,1,1,1,1,1,1,1,1,,1,1,1.....}, 那意味这要二分很多次才能找到这个重复的数字。

*/

#include <iostream>

using namespace std;

int countRange(const int* numbers, int length, int start, int end);

int get_dup(const int* numbers, int length)
{
    if(numbers==NULL || length <= 0)
        return false;
    int start = 1;
    int end = length-1;
    while(end >= start)
    {
        int middle = ((end - start) >> 1) + start;
        int count = countRange(numbers, length, start, middle);
        if(end == start)
        {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count>(middle - start +1))
            end = middle;
        else
            start = middle+1;
    }
    return -1;
}

int countRange(const int *numbers, int length, int start, int end)
{
    if (numbers == NULL)
        return 0;
    int count  = 0;
    for(int i=0; i<length-1; i++)
    {
        if (numbers[i]<=end && numbers[i] >= start)
            count ++;
    }
    return count;
}

int main()
{
    int numbers[] = {2,3,5,4,3,2,6,7};
    int length = 8;
    int ans = get_dup(numbers, length);
    cout << ans << endl;
    return 0;
}

