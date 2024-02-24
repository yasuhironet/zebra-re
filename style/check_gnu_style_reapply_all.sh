#!/bin/bash

files=`find . -name "*.[ch]"`

for i in $files; do
    echo $i
    git checkout frr-9.0.2 $i;
    bash style/check_gnu_style.sh update $i;
    git add $i;
done

