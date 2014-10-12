#!/bin/bash

if( [[ $# -ge 2 ]] ) then
	./$1 < sample$2.in > output$2;
	cat output$2;
  echo "----- Diff -----";
  diff output$2 sample$2.out;
else
  # Default test
  ./$1 < sample.in > output;
  cat output;
  echo "----- Diff -----";
  diff output sample.out;
fi;

