#!/bin/bash
#192. Word Frequency
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk -F' ' '{print $2,$1}'
