// unsort.c ... make a sequence of numbers not sorted
// Usage: unsort [FileName]
// If no file name supplied, unsorts stdin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

int main (int argc, char *argv[])
{
   FILE *in;

   if (argc == 1) 
      in = stdin;
   else {
      if ((in = fopen(argv[1],"r")) == NULL) {
         fprintf(stderr, "Can't open file '%s'\n",argv[1]);
         exit(1);
      }
   }
  
   // Put code here read numbers and "unsort" them
   // Hint: for reading the input
    int vals[100000], i = 0;
    while (fscanf(in, "%d", &vals[i]) != EOF){
        // index of the big array;
        i++;
    }


    //set up the random number environment
    srand((unsigned)time(0));



    // unsort the list
    for (int j = 0; j < i; j++) {
        // read throught all the item in the list, try to rearrage each items
        int tmp = vals[j];
        int swap_index= rand()%i;
        // swap both value in the swap_index and that value
        vals[j]=vals[swap_index];
        vals[swap_index]= tmp;
    }

    
    // print the unsorted list
    for (int j = 0; j < i; j++) {
        printf("%d\n",vals[j]);
    }
   return 0;
}      
