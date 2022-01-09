#include <stdio.h>

int main()
{
    int a;
    float b;
    char c[20];

    scanf("%d %f", &a , &b);
    gets(c);
    printf("%d %f %s", a , b , c);

    return 0;
}