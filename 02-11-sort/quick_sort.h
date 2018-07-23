#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED


/* 快速排序

1. 调整接口，快速排序的原理是两个指针从两端向中间移动
2. 找主元，每次选择的主元中分最好。所以选择左中右三个元素的中间值作为主元 pivot
3. 小细节： 将主元移动到倒数第二个位置。这样左右指针位置交叉时就是遍历结束时
4. 左边指针移动，遇到大于等于 pivot 的元素时停止，右边的指针开始移动，遇到小于等于 pivot 的元素时停止，交换两个指针所指的元素
5. 将所在位置元素与左指针所指元素交换 swap(num, p, right-1)
6. 将主元两边的元素划分为两个子集，重复上面的操作

快速排序的优点在于：一次交换即消除了很多逆序对，相比下插入排序和冒泡排序的交换操作只改变一个逆序对。
*/

void quicksort(int num[], int Left, int Right);
int Median3(int num[], int Left, int Right);
void InsertSort(int num[], int N);
void Swap(int num[], int i, int j);

void QuickSort(int num[], int N)
{
    quicksort(num, 0, N-1);
}

void quicksort(int num[], int Left, int Right)
{
  int cutoff = 0;
  if (Right - Left >= cutoff)
  {
    // find the pivot
    int pivot = Median3(num, Left, Right);

    // 划分子集
    int p = Left, q = Right-1;
    while (p < q)
    {
      // 等于 pivot 也停下来交换
      while (num[++p] < pivot) {}
      while (num[--q] > pivot) {}
      // 在循环内 p 最终会与 q 交错，但这个时候它们所在的位置已经排过序了，因此不需要交换
      if (p < q)
        Swap(num, p, q);
    }
    // 把主元换到中间来，也就是 p 位置
    Swap(num, p, Right-1);
    // 对子集重复上面的操作
    quicksort(num, Left, p-1);
    quicksort(num, p+1, Right);
  }
  else
    InsertSort(num+Left, Right-Left+1);
}


int Median3(int num[], int Left, int Right)
{
  int Center = (Left+Right)/2;
  if (num[Left] > num[Right])
    Swap(num, Left, Right);
  if (num[Left] > num[Center])
    Swap(num, Left, Center);
  if (num[Center] > num[Right])
    Swap(num, Center, Right);

  int pivot = num[Center];
  Swap(num, Center, Right-1);
  return pivot;
  // return num[Right-1];
}

void Swap(int num[], int i, int j)
{
  int temp = num[i];
  num[i] = num[j];
  num[j] = temp;
}

void InsertSort(int num[], int N)
{
  for (int i=1; i<N; i++)
  {
    for (int j=i; j>0; j--)
    {
      int flag = 0;
      if (num[j] < num[j-1])
      {
        int temp = num[j];
        num[j] = num[j-1];
        num[j-1] = temp;
        flag = 1;
      }
      // 内循环中如果已经大于某个位置的数了，就不用继续比较了
      if (flag == 0)
        break;
    }
  }
}
#endif // QUICK_SORT_H_INCLUDED
