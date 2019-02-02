#!/bin/bash
cnt=200
for ((i=0;i<=cnt;i++));
do
    ./isPrime-correct $i
    ./isPrime-broken2 $i
    echo
done
