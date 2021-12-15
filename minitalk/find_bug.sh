#!/bin/bash

i=0
while [ $i -ne 10 ]
do
	./client 29775 m
	i=$(($i+1))
done