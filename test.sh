#!/bin/bash

if( [[ $# -ge 2 ]] ) then
	./bin/$1 < $1$2.in;
else
  # Default test
  ./bin/$1 < $1.in;
fi;

