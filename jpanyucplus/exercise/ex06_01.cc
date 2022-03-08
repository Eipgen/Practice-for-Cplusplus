#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int n = 5;
    int a[n] = {1, 2, 3, 4, 5};

    cout << "first method " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    cout << "second method with pointer " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *(a+i) << " ";
    }
    cout << "\n\n";

    cout  << "third method wirh pointer and pointer arithmetic(1) " << endl;
    for (int *pa = a; pa < a+n; pa++)
    {
        cout << *pa << " ";
    }
    cout << "\n\n";

    cout << "third method with pointer and pointer arithmetic(2) " << endl;
    for (int *pa = a, i=0; i < n; i++)
    {
        cout << pa[i] << " ";
    }
    cout << "\n\n";

    return 0;
}

/*
int a[] = {1, 2, 3, 4, 5};
int *pa = a;
*pa = 10; a[0] = 10;
*(a+1) = 20; a[1] = 20;
*(pa++) = 3; a[0] = 3; pa=pa+1;
*(a++)=4; error;
*(pa+1)=5; a[1] = 5;

一维数组名a是地址变量，变量名a与&a[0] 等价
a+i 是a[i]的地址，a[i]的值是*(a+i)

若指针pa是一维数组名a的地址，则pa+i 是a[i]的地址，a[i]的值是*(pa+i)
数组元素的下标访问是按照地址来的
指针的值可以随时改变，可以执行不同的元素。
pa++ 合法，++pa 合法，但是a++不合法。

a[i] = pa[i]=*(pa+i)=*(a+i)
&变量名字，返回变量的地址
*指针，引用指针的值
*/