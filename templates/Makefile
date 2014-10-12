PROBLEM=problem
SRC=$(PROBLEM).cpp

# Choose test case to run
# Preferred: use `make run TEST=2`
TEST=

build:
	@g++ -Wall -O2 -pipe -o $(PROBLEM) $(SRC)

run: build
	@../test.sh $(PROBLEM) $(TEST)
