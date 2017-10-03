tests:
	../bst < tree0 > tree0.observed
	diff tree0.expected tree0.observed && echo OK
	../bst < tree1 > tree1.observed
	diff tree1.expected tree1.observed && echo OK
	../bst < tree2 > tree2.observed
	diff tree2.expected tree2.observed && echo OK
	../bst < tree3 > tree3.observed
	diff tree3.expected tree3.observed && echo OK
	../bst < tree4 > tree4.observed
	diff tree4.expected tree4.observed && echo OK
	../bst < test5 > test5.observed
	diff test5.expected test5.observed && echo OK
	../bst < test6 > test6.observed
	diff test6.expected test6.observed && echo OK
	rm *.observed
clean:
	rm -f *.observed
