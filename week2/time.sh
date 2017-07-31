#!/bin/sh

for i in 1 2 3 4 5 6 7 8 9 10
do
	seq 10000 | sort -R | (time ./usel) 2>foo.tmp >/dev/null
	grep user foo.tmp | cut -f2 >> foo.txt
done
