#!/bin/zsh
rm main.exe
echo "Compiling..."
g++ -std=c++17 -O2 -Wall -Wextra -Wshadow -o main.exe main.cpp 

if [ -f ./main.exe ]; then
  echo "Testing..."
  for file in tests/*.txt
  do
    echo "Testing on $file"
    # cat $file | ./main.exe
    ./main.exe < $file

  done
else
  echo "Compilation error"
fi
