#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

/* 堆排序

1. 在给定数组基础上建立最大堆
2. 将最大堆的根节点与数组的最后一个元素交换
3. 剩下的元素调整为最大堆
*/

void HeapSort(int num[], int N)
{
    // 建立最大堆
    for (int i=1; i<N; i++)
    {
        // 子节点大于父节点时
        int temp = num[i];     // 把当前值暂时保存在 temp 中,因为如果发生交换，会有父节点的值移动到这个位置
        while (num[(i-1)/2]<temp && i>0)  // 这里要注意是与temp比较，不能是 num[i],因为父节点虽然下移了，但并未更新为temp.
        {
            num[i] = num[(i-1)/2]; // 把父节点往下移
            i = (i-1)/2;
        }
        num[i] = temp;
    }

    // 将最大堆的根节点与数组的最后一个元素交换，;
    // 然后调整最大堆, 将根节点与倒数第二个位置交换， 依次循环
    for (int End=N-1; End>0; End--)
    {
        // 交换
        int temp = num[0];
        num[0] = num[End];
        num[End] = temp;

        // 调整剩下的数组 {0...End-1} 为最大堆
        for (int k=1; k<End; k++)
        {
            // 这里用不同与上面类似于那种过滤的方式，而是每比较一次就交换一次
            while (num[k] > num[(k-1)/2])
            {
                // 交换
                int temp2 = num[k];
                num[k] = num[(k-1)/2];
                num[(k-1)/2] = temp2;
                k = (k-1)/2;
            }
        }
    }

}


#endif // HEAP_SORT_H_INCLUDED
