#!/bin/bash



echo "hello bao!"

bao=$(ls /home)

for i in $bao; do
    cd /home/baotongyu/$i
    chown -R baotongyu:baotongyu /home/$i 
done
