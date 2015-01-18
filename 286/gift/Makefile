PROBLEM=gift
SRC=$(PROBLEM).cpp

# Choose test case to run
# Preferred: use `make run TEST=2`
TEST=

build:
	@mkdir -p bin
	@g++ -Wall -O2 -pipe -o bin/$(PROBLEM) $(SRC)

run: build
	@../test.sh bin/$(PROBLEM) $(TEST)

clean:
	rm -f bin/$(PROBLEM)
