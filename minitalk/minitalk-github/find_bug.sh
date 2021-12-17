#!/bin/bash

i=0
while [ $i -ne 100 ]
do
	./client 36844 mdddddddddddrrrrrrrrrrrrrrrrrrrr
	i=$(($i+1))
done