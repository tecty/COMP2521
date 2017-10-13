#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int dump;
    int nb,nbs,nk,nu;
    double avg=0;
    nk = 5000;
    nk = 1666;
    for (int i = 0; i < 10; i++) {
        // initial the values use in table
        nb=nbs=nk=nu =0;
        scanf("#nodes = %d,  depth = %d,  #compares = %d,  #rotates = %d",&dmup,&dmup,&nb,&dmup);
        scanf("#nodes = %d,  depth = %d,  #compares = %d,  #rotates = %d",&dmup,&dmup,&nbs,&dmup);
        // calculate the correspond average
        avg+= (nbs-nb)/(double)(nk+nu);

    }
    // print the average for all the test
    print("%d",(int)(avg/10));
    return 0;
}
