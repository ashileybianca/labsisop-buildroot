#!/bin/sh
case "$1" in
    start)
        /usr/bin/python3 /usr/bin/systeminfo.py & exit 0
        ;;
    stop)
        exit 1
        ;;
    *)
        exit 1
        ;;
esac
exit 0
