#!/bin/sh

tmp=$(echo "5.17.0-gentoo-x86_64" | grep -Eo "^.*[a-zA-Z]+.*$")
echo $tmp
