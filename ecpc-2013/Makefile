CXXFLAGS=-O2 -W -Wall -Wshadow -Wconversion -Wfloat-equal -U_FORTIFY_SOURCE

TEST=

all:
	@g++ $(CXXFLAGS) -o $(PROBLEM) $(PROBLEM).cpp

run: all
	@./$(PROBLEM) < $(PROBLEM)$(TEST).in > $(PROBLEM)$(TEST).run
	@#diff $(PROBLEM)$(TEST).run $(PROBLEM)$(TEST).out
	@cat $(PROBLEM)$(TEST).run
