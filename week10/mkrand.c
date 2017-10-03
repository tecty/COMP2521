// mkrand ... generate sequence of distinct random values in 1..max

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	int max;   // range of generated values is 1..max
	int nvals; // number of values to be generated
	int val;   // next random value generated
	int sofar; // number of values generated so far
	int *already; // array of flags for generated values

	if (argc < 4) {
		fprintf(stderr, "Usage: %s max nvals seed\n", argv[0]);
		return EXIT_FAILURE;
	}
	max = atoi(argv[1]);
	nvals = atoi(argv[2]);
	if (nvals > max/3) {
		fprintf(stderr, "%s: nvals << max\n", argv[0]);
		return EXIT_FAILURE;
	}
	if (nvals > 1000) {
		fprintf(stderr, "%s: nvals <= 1000\n", argv[0]);
		return EXIT_FAILURE;
	}
	srand(atoi(argv[3]));

	// sets all values in already[] to zero
	already = calloc(nvals,sizeof(int));
	assert(already != NULL);

	// beware: loop body may not increment sofar
	//         and sofar is what leads to loop completion
	// potential for infinite loop if rand() no good
	// guaranteed infinite loop if nvals > max
	// can become very s-l-o-w if nvals close to max
	sofar = 0;
	while (sofar < nvals) {
		val = 1 + (rand()%max);
		if (!already[val]) {
			printf("%d\n", val);
			already[val] = 1;
			sofar++;
		}
	}

	return EXIT_SUCCESS;
}
