#! /bin/bash

input="$(readlink -f "$1")"
output="$(readlink -f "$2")"
file_num=0
dir_num=0

function bfs() {
    dirs=()
    end=0
    frt=0

    dirs[$((end++))]=$input
    while [ $frt -ne $end ]; do
        cur=${dirs[$((frt++))]}
        echo "[${cur##*/}]"
        for file in $(ls "$cur"); do
            echo "$cur"/"$file"
            if [ -d "$cur"/"$file" ]; then
                dirs[$((end++))]="$cur"/"$file"
                ((dir_num++))
            else
                ((file_num++))
            fi
        done
        echo
    done

    echo "[Directories Count]:$dir_num"
    echo "[Files Count]:$file_num"
}

OLD_IFS=$IFS
IFS=$(echo -en "\n\t")
>$output
bfs >>$output
IFS=$OLD_IFS
