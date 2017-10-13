#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int dump;
    long long int nk,nu;
    double nb,nbs;
    double avg=0;
    printf("%lf\n",avg );
    nk = 5000;
    nu = 1666;
    int depth = 0;
    int depthAvg = 0;
    for (int i = 0; i < 10; i++) {
        // initial the values use in table
        nb=nbs =0;
        scanf("#nodes = %d,  depth = %d,  #compares = %lf,  #rotates = %d",&dump,&depth,&nb,&dump);
        depthAvg+= depth;
        scanf("#nodes = %d,  depth = %d,  #compares = %lf,  #rotates = %d",&dump,&depth,&nbs,&dump);
        // calculate the correspond average
        depthAvg += depth;
        // printf("%d,%d",nk, nu);
        // printf("%lld %lld\n", nbs,nb);
        avg+= (nbs-nb)/((double)nk+nu);
        printf("%lf\n",avg );
    }
    // print the average for all the test
    printf("%d %lf\n",depthAvg/20,(avg/10));
    return 0;
}
