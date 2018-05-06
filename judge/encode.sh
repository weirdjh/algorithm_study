#!/bin/bash

find "." -name "*.cc" -o -name "*.cpp" | while read filename
do
  echo $filename
  tempName=${filename}_temp
  mv "$filename" "$tempName"
  iconv -c -f euc-kr -t utf-8 "$tempName" > "$filename"
  rm "$tempName"
done
