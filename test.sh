#!/bin/bash

if( [[ $# -ge 2 ]] ) then
	./$1 < sample$2.in > output$2;
	cat output$2;
else
  # Default test
	./$1 < sample.in > output;
	cat output;
fi;

#diff output < output_ref
