#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

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
