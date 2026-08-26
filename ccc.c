
#include <stdio.h>

int main()
{
    int i;
    long long l;
    char c;
    float ff;
    double dd;
    scanf("%d %lld %c %f %lf", &i, &l, &c, &ff, &dd);
    printf("%d\n", i);
    printf("%lld\n", l);
    printf("%c\n", c);
    printf("%f\n", ff);
    printf("%lf\n", dd);

    return 0;
}