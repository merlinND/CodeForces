#!/bin/bash

if( [[ $# -ge 2 ]] ) then
	./bin/$1 < $1$2.in > $1$2.run;
	cat $1$2.run;
  echo "----- Diff -----";
  diff $1$2.run $1$2.out;
  rm $1$2.run;
else
  # Default test
  ./bin/$1 < $1.in > $1.run;
  cat $1.run;
  echo "----- Diff -----";
  diff $1.run $1.out;
  rm $1.run;
fi;

