#!/bin/bash

directory="/Users/cperez/Documents/GitHub/unixTools/qplot/"
file=$1
bins=100

autosearch=true
min=-1
max=+1

root -b -l ${directory}/qhist.C\(\"${file}\",${autosearch},${bins},${min},${max}\)
