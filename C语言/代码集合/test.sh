#!/bin/bash


echo "hello byt!"

byt=$(ls /home)

for i in $byt: do
    cd /home/$i
    ls > /tmp/$i.log
done



