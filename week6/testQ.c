// testQ1.c ... simple tester for Queue ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Queue.h"

#define MAX 10

int main (int argc, char *argv[])
{
   int i;
   Item it;
   Queue q1,q2;
   
   printf("Test 1: Create queues\n");
   q1 = createQueue();
   q2 = createQueue();
   assert(q1 != NULL);
   assert(q2 != NULL);
   assert(queueLength(q1) == 0);
   assert(queueLength(q2) == 0);
   printf("Passed\n");

   printf("Test 2: Add to queues\n");
   for (i = 1; i <= MAX; i++){
      enterQueue(q2,i);
      enterQueue(q1,i);
      assert(queueLength(q2) == i);
      assert(queueLength(q1) == i);
   }
   printf("Final q1: ");showQueue(q1);
   printf("Final q2: ");showQueue(q1);
   printf("Passed\n");

   printf("Test 3: Remove from queues\n");
   for (i = 1; i <= MAX; i++){
      it = leaveQueue(q1);
      assert(queueLength(q1) == MAX-i);
      assert(i == it);
      it = leaveQueue(q2);
      assert(queueLength(q2) == MAX-i);
      assert(i == it);
   }
   printf("Passed\n");

   printf("Test 4: Destroy queues\n");
   dropQueue(q1);
   dropQueue(q2);  
   printf("Passed\n");
 
   printf("Test 5: Remove from emoty queue\n");
   printf("This test should fail an assertion\n");
   q1 = createQueue();
   it = leaveQueue(q1);
   printf("Passed\n");
  
   return 0;
}      
