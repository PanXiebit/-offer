// 替换空格

/*
题目：请实现一个函数，把字符串中的每个空格替换成"%20".
例如，输入 "we are happy", 则输出 "we%20are%20happy."
*/

#include <iostream>
#include <stdio.h>

/*
using namespace std;


void replaceSpace(char *str,int length) {
    if (str==NULL || length <=0)
        return;

    int numberofspace = 0;
    int originlength = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        originlength ++;
        if (str[i] == ' ')
            numberofspace ++;
        i++;
    }

    int newlength = originlength + 2 * numberofspace;

    int indexOforigin = originlength;
    int indexOfnew = newlength;
    while(indexOforigin >=0 && indexOfnew > indexOforigin)
    {
        if(str[indexOforigin] != ' ')
            str[indexOfnew--] = str[indexOforigin];
        else
        {
            str[indexOfnew--] = '0';
            str[indexOfnew--] = '2';
            str[indexOfnew--] = '%';

        }
        indexOforigin --;
    }
}
*/


#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
//length 为字符数组str的总容量，大于或等于字符串str的实际长度
void ReplaceBlank(char str[], int length)
{
    if(str == NULL && length <= 0)
        return;

    //originalLength 为字符串str的实际长度
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    //newLength 为把空格替换成'%20'之后的长度
    int newLength = originalLength + numberOfBlank * 2;
    //if(newLength > length)
        //return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}


void test1()
{
    //const int length = 100;
    char* str1= " xie pan ";
    //char str2[] = "%20xie%20pan%20";
    replaceSpace(str1, 9);
    //int ans = strcmp(str1, str2);
    cout << str1 << endl;
    //cout << ans <<endl;
}

int main()
{
    test1();
    return 0;
}


