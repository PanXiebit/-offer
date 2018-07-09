#include <iostream>
#include <stdio.h>
#include <malloc.h>

#include "simple_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"

using namespace std;



int main()
{
    int num[] = {8,3,4,10,5,11,1,2,4};
    int N = 9;
//    Bubble_sort(num, N);
//    for (int j=0; j<N; j++)
//        printf("%d ", num[j]);
//    printf("\n");
//
//    InsertOrder(num+0, N-1+1);
//    for (int j=0; j<N; j++)
//        printf("%d ", num[j]);
//    printf("\n");
//
//    HeapSort(num, N);
//    for (int j=0; j<N; j++)
//        printf("%d ", num[j]);
//    printf("\n");

    QuickSort(num, N);
    for (int j=0; j<N; j++)
        printf("%d ", num[j]);
    return 0;
}
