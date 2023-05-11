#include <stdio.h>
#include<unistd.h>
#include <limits.h>

int put_nbr(int a)
{
    if (a < 0)
        a *= -1;
    if (a > 9)
    {
        put_nbr(a / 10);
        put_nbr(a % 10);
    }
    else
    {
        a += '0';
        write(1, &a, 1);
    }
    return (0);
}

int main()
{
    int a = -1234;
    put_nbr(a);
}
