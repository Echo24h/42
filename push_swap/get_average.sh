#!/bin/bash

i=0
while [ $i -ne 100 ]
do
	if [ $i -eq 0 ]
	then
		./push_swap `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' > results_3.txt
		./push_swap `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' > results_5.txt
		./push_swap `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' > results_100.txt
		./push_swap `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' > results_500.txt
	else
		./push_swap `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' >> results_3.txt
		./push_swap `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' >> results_5.txt
		./push_swap `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' >> results_100.txt
		./push_swap `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"` | wc -l | tr -d ' ' >> results_500.txt
	fi
	i=$(($i+1))
done