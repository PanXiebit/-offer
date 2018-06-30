// 二维数组的查找

/*
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有这个整数。
*/

/*
解题思路： P45
*/

#include <iostream>

using namespace std;

bool Find(int *matrix, int rows, int columns, int number)
{
    bool found = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while (row < rows && columns >=0)
        {
            if (matrix[row*column + column] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row*column + column] < number)
                column --;
            else
                row ++;
        }
    }
    return found;
}

int main()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int* matrix1  = (int*) matrix;
    cout << *matrix1 << endl;
    int rows = 4, columns = 4, number = 7;
    bool ans = Find((int*)matrix, rows, columns, number);
    cout << ans << endl;
    return 0;
}
