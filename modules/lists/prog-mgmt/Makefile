#------------------------------------------------------------------------
# File:          Makefile
# Author:        Henry M. Walker
# Created:       20 April 2008
# Last revised:  20 April 2008
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# Acknowledgement
# Comments and some segments adapted from an example by Marge Coahran
#------------------------------------------------------------------------


#------------------------------------------------------------------------
# Use the gcc compiler
CC = gcc
#------------------------------------------------------------------------

#------------------------------------------------------------------------
# Set compilation flags
#   -ansi (check syntax against the American National Standard for C
#------------------------------------------------------------------------
CFLAGS = -ansi

#------------------------------------------------------------------------
# build rules:
#
# Each rule takes the following form>  (Note that there MUST be a tab,
# as opposed to several spaces, preceeding each command.
#
# target_name:  dependency_list
#	command(s)
#
#------------------------------------------------------------------------

all: main

# List program components, what they depend on, and how to compile each

main:  main.o list-proc.o
	$(CC) -o main main.o list-proc.o

main.o:  main.c node.h list-proc.h
	$(CC) $(CFLAGS) -c main.c

list-proc.o:  list-proc.c list-proc.h node.h
	$(CC) $(CFLAGS) -c list-proc.c

# pattern rules:
#
# Note that the last two rules above could be replaced with the following 
# rule. This rule must come after the rules for all targets that give more
# specific dependency lists.
#
# The rule says that any .o file (for which a rule has not already been found)
# should be made with two prerequisites, the associated .c and .h files.
# In the given command, $< expands to mean "the first prerequisite" (i.e.
# the .c file).
#
# %.o: %.c %.h
#	$(CC) $(CFLAGS) $<
#----------------------------------------------------------------------------

#-----------------------------------------------------------------------
# dependencies: 
#
# Note that it is critical that all dependencies are listed. Any header 
# file that is #include'd, either directly or indirectly, in a source file
# must be listed as a prerequisite for building that source file.
#
# For example, if foo.c includes foo.h, and foo.h includes bar.h, then the
# target for foo.o must list both foo.h and bar.h as prerequisites.
#
# Warning: Missing dependencies can cause extreme aggravation during debugging.
#  The symptoms go like this: you find a bug, you fix the bug, your rebuild 
#  your program, but the bug does not go away. (This occurs if the bug was
#  in a file that should have been listed as a prerequisite somewhere, but
#  was not. Then some target file does not get rebuilt, so the executable
#  code still contains the bug.) If you see this symptom, you can check
#  whether your makefile is at fault by using "make clean" and rebuilding
#  the entire program from scratch. If the bug is gone, then your makefile
#  is missing (at least one) dependency.
#-----------------------------------------------------------------------


#----------------------------------------------------------------------------
# Use this target to clean up your directory. To invoke it, type "make clean".
# It will delete (without warning) object files, old emacs source versions, 
# and core dumps.
#----------------------------------------------------------------------------
clean:
	rm -f *.o *~ core*
