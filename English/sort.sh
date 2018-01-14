#!/bin/sh

for i in word/[a-z]
do
    cat ${i} | sort | grep -v "^$" > $i.bak
    rm $i
    mv $i.bak $i
done
