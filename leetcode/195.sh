#!/bin/bash
#195. Tenth Line
head -n10 file.txt | awk '{
	if (NR == 10) {
		print $0;
	}
}'
