#include<stdio.h>
int gcd(int m, int n) {
    if (n == 0) 
        return m;
    return gcd(n, m%n);
}

int main() {
    int m, n;
    printf("Enter two numbers: ");
    scanf("%d", &m);
    scanf("%d", &n);
    printf("\n GCD = %d", gcd(m,n));
    return 0;
}
