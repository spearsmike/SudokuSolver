#!/bin/bash

. GetGlobals.sh

export PATH=$CXXTEST/bin:$PATH

# create runner.cpp
cxxtestgen --error-printer -o runner.cpp Tests.h

# compile runner.cpp
g++ -o runner -I$CXXTEST runner.cpp ../solver.o

# run the test runner
./runner

# remove runner/runner.cpp
\rm -f runner runner.cpp
