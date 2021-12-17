#!/bin/bash

i=0
while [ $i -ne 50 ]
do
	if [ $i -eq 0 ]
	then
		./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' > results.txt
	else
		./push_swap `ruby -e "puts (0..99).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' >> results.txt
	fi
	i=$(($i+1))
done