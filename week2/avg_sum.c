#include <stdio.h>

int main(int argc, char const *argv[]) {
    /* code */
    int count=0, sum_min=0;
    double sum_sec = 0;
    scanf("%d", &count );
    scanf("%d", &sum_min);
    scanf("%lf", &sum_sec );


    printf("%lf \n", (sum_min*60.0 + sum_sec)/count );
    return 0;
}
