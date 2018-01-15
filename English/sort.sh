#!/bin/sh

for i in word/[a-z]
do
    cat ${i} | sort -t " " -k1.1,1.20 | grep -v "^$" > $i.bak
    rm $i
    mv $i.bak $i
done
