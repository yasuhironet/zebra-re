#!/bin/bash

IGNORE_PATHS=""

check () {
    if [ $# -eq 0 ]; then
        while IFS= read -r -d '' file
        do
            if [[ -z "IGNORE_PATHS" || ! "$file" =~ $IGNORE_PATHS ]]; then
            clang-format "$file" | diff -q "$file" - > /dev/null \
                || echo "$file needs to be fixed by update";
            fi
        done <   <(find . -name '*.[ch]' -print0)
     else
        for file in "$@"; do
            clang-format "$file" | diff -q "$file" - > /dev/null \
                || echo "$file needs to be fixed by update";
        done
     fi
}

update () {
    if [ $# -eq 0 ]; then
        while IFS= read -r -d '' file
        do
            if [[ -z "IGNORE_PATHS" || ! "$file" =~ $IGNORE_PATHS ]]; then
            clang-format -i "$file"
            fi
        done <   <(find . -name '*.[ch]' -print0)
     else
        for file in "$@"; do
            clang-format -i "$file"
        done
     fi
}

help () {
    echo "$0 [check | update]"
    exit 1
}

if ! command -v clang-format &> /dev/null; then
    echo "Please install clang-format"
    exit 1
fi

subcommand=$1
shift

case $subcommand in
    check) check "$@" ;;
    update) update "$@" ;;
    *) help "$@" ;;
esac

# vim: set ft=sh ts=8 expandtab sw=4 sts=4 :
