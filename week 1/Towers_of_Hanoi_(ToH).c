#include <stdio.h>
int d = 0;
void towerhanaoi(int n, int a, int b, int c)
{
    if (n == 1)
    {
        d++;
        return;
    }
    towerhanaoi(n - 1, a, c, b);
    d++;
    towerhanaoi(n - 1, b, a, c);
}
int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerhanaoi(n, 1, 2, 3);
    printf("Number of moves = %d\n", d);
    return 0;
}
