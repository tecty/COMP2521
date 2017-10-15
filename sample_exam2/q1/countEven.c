
/* countEven.c
   Written by Ashesh Mahidadia, October 2017
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BSTree.h"

/*
    You will submit only this one file.

    Implement the function "countEven" below. Read the exam paper for
    detailed specification and description of your task.

    - You can add helper functions in this file, if required.

    - DO NOT modify code in the file BSTree.h .
    - DO NOT add "main" function in this file.
*/


int countEven(BSTree t){


	// Implement this function,
	// also change the return value below!
    int count = 0;

    if (t == NULL) {
        /* the end of the tree, terminate the recursive */
        return 0;
    }
    else {
        if (t->key%2  == 0) {
            /* current key is even, increment the count */
            count = 1;
        }
        else {
            // current key is not even
            count  =0;
        }
    }

    // return the total count by recursive calling itself.
    return count+countEven(t->left)+ countEven(t->right);

}
