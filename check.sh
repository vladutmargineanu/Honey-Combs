#!/bin/bash

simpleTestsNumber=4
testsNumber=5
executable=tema2
sum=0

make 

if test ! -x $executable; then
    echo "Executable file missing."
    exit 1
fi

mkdir -p output

echo "------------Small honeycombs------------"
for i in $(seq 1 $simpleTestsNumber); do
	./$executable < input/simple_input$i.txt > output/simple_out$i
	diff -Z output/simple_out$i output/simple_output$i.txt > /dev/null 
	if [ $? -eq 0 ]; then
		echo "Test $i ......................... passed"
		sum=$(($sum + 10))
	else
		echo "Test $i ......................... failed"
	fi
done
echo "-------------Big honeycombs-------------"
for i in $(seq 1 $testsNumber); do
	./$executable < input/input$i.txt > output/out$i
	diff -Z output/out$i output/output$i.txt > /dev/null 
	if [ $? -eq 0 ]; then
		echo "Test $i ......................... passed"
		sum=$(($sum + 10))
	else
		echo "Test $i ......................... failed"
	fi
done
echo ""
echo "TOTAL: $sum/90 puncte"
