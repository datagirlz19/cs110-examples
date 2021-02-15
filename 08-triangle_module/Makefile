# This is a Makefile. A Makefile contains instructions for build a program.
# In a directory containing a Makefile, running the command make will build
# everything automatically.

# CFLAGS is a variable which stores gcc compiler options for the project. To
# use the variable, you need to use $(CFLAGS)
CFLAGS=-std=c99 -Wall

# A Makefile builds targets. A target has the following syntax:
# <target name>: <target dependencies>
#       <command>
#       <optionally more commands>
#
# It is important that the whitespace before a command is a tab, not spaces.
#
# The name of the target is the name of the file that will be built. The
# dependencies are files that need to exist in order to build the target. The
# target's commands will be run if the target file does not exist, or if any of
# the dependency files have been updated more recently than the target file.

# When running make, the first target in the Makefile is examined. If any of
# its dependencies do not exist, or if any dependencies need re-compiling, it
# will try to build those first. Here we want to build the executable
# test_triangle, which requires the compiled object files triangle.o and
# test_triangle.o.
test_triangle: triangle.o test_triangle.o
	gcc $(CFLAGS) triangle.o test_triangle.o -o test_triangle

# This target is the object file triangle.o, which depends on triangle.c and
# triangle.h
triangle.o: triangle.c triangle.h
	gcc $(CFLAGS) -c triangle.c

# The test_triangle.o target depends on triangle.h because it includes it. If
# triangle.h changes we should recompile test_triangle.c
test_triangle.o: test_triangle.c triangle.h
	gcc $(CFLAGS) -c test_triangle.c

# clean is a special target because it does not build anything. Instead, it
# removes the executable and the object file. Run "make clean" to clean up the
# compiled files.
clean:
	rm -f test_triangle test_triangle.o triangle.o
