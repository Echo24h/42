#!/bin/bash

i=0
while [ $i -ne 100 ]
do
	echo $i
	./client 69872 mdr
	i=$(($i+1))
done