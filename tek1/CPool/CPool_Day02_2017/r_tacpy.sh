#!/bin/bash
cat Day02/passwd | cut -d ":" -f 1 | rev | sort -r | sed '0~2d' | tr '\n' ', '
