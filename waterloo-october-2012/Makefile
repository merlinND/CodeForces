PROBLEM=problem
SRC=$(PROBLEM).cpp

# Choose test case to run
# Preferred: use `make run TEST=2`
TEST=

build:
	@mkdir -p bin
	@g++ -Wall -O2 -pipe -o bin/$(PROBLEM) $(SRC)

run: build
	@../test.sh $(PROBLEM) $(TEST)

clean:
	rm -f bin/$(PROBLEM)
