# compiler name
CXX = g++
# g++ compiler flags
# -g: adds debugging information to the executable file
# -Wall: turns on most, but not  all, compiler warnings
# -std=C++17: uses c++17 standard
# put all the required flags separated by space
CXXFLAGS = -c -g -Wall -std=c++17

# there is a reason for using .out
# the build target executable file; .exe is not required -- jeremy uses .out
PROGRAM = ASCIIArt.out

# list .cpp files separated by space
CPPFILES = main.cpp

# make all rule/default rule that'll be run when we run "make"
# first compile each file to object file
# then make a single binary/executable program
all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

# make clean rule
# delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# FIXME #FIXED####
# add a rule to run the program
run:
	./$(PROGRAM)

	