// testList.c - testing DLList data type
// Written by John Shepherd, March 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"
void hr() {
    /* code */
    printf("\n<-----> \t<-----> \n" );
}
void showState(DLList L) {
    /* show the current state*/
    if (validDLList(L)) {
        /* code */
        printf("List is still valid\n" );
        if (DLListLength(L)) {
            /* the list have items, so show the current item */
            // show the number of items
            printf("now list have:%d items\n",DLListLength(L) );
            // print the rep info
            printf("Current node has value %s\n",L->curr->value );
            printf("first node is %s\n",L->first->value );
            printf("last node is %s\n",L->last->value );
        }
    }

}
int main(int argc, char *argv[])
{
	DLList myList;
	myList = getDLList(stdin);


    printf("inputed this was:\n" );
	putDLList(stdout,myList);

	assert(validDLList(myList));

    hr();
    printf("inserting 10 items into list before the current item;\n" );
    showState(myList);

    for (int n = 0; n < 10; n++) {
        /* adding node in the list */
        char this_string[2];
        sprintf(this_string, "%d",n);
        DLListBefore(myList, this_string);
    }

    showState(myList);
    printf("the list now is:\n" );
    putDLList(stdout,myList);

    hr();
    printf("move the curr pointer to 3rd item\n" );
    // swtich it to the first item
    DLListMoveTo(myList,3);
    showState(myList);


    hr();
    printf("trying to move outside the boundry\n" );
    showState(myList);
    printf("\nmove To\n" );
    DLListMoveTo(myList,333333);
    showState(myList);
    printf("\nmove afront\n" );
    DLListMove(myList,1233333);
    showState(myList);
    printf("\nmove backward\n" );
    DLListMove(myList,-12233333);
    showState(myList);

    printf("now the list is:\n" );
    putDLList(stdout,myList);

    hr();
    DLListMoveTo(myList,3);
    printf("insert 3 items after the 3rd node\n" );
    for (int i = 80; i < 101; i+=7) {
        /* inserting items  */
        //construct the insert string
        char this_string[10];
        sprintf(this_string,"%d",i);
        DLListAfter(myList,this_string);
    }
    showState(myList);
    printf("current list now is\n" );
    putDLList(stdout, myList);

    hr();
    DLListMoveTo(myList,3);
    printf("insert 3 items before third item\n" );
    showState(myList);
    for (int i = 56; i < 81; i+=7) {
        /* inserting items  */
        //construct the insert string
        char this_string[10];
        sprintf(this_string,"%d",i);
        DLListBefore(myList,this_string);
    }
    showState(myList);
    printf("current list now is\n" );
    putDLList(stdout, myList);

    hr();
    printf("Delete 4 items in the list\n" );
    showState(myList);
    for (int i = 0; i < 4; i++) {
        /* Delete the node and show statuts */
        // delete the node;
        DLListDelete(myList);
        showState(myList);
    }
    printf("current list now is\n" );
    putDLList(stdout, myList);

    hr();
    printf("end of the test\n" );

	return 0;
}
