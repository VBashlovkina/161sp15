# File:          Makefile
# Author:        Henry M. Walker
# Created:       20 April 2008
# Simplified:    18 November 2011
# Acknowledgement:  adapted from an example by Marge Coahran
#----------------------------------------------------------------------------
# Use the gcc compiler
CC = gcc

# Set compilation flags
#   -ansi (check syntax against the American National Standard for C
CFLAGS = -ansi

#----------------------------------------------------------------------------
# build rules:
#
# Each rule takes the following form>  (Note there MUST be a tab,
# as opposed to several spaces, preceeding each command.
#
# target_name:  dependency_list
#	command(s)

all: 

# List program components, what they depend on, and how to compile each

main:  main.o list-proc.o
	$(CC) -o main main.o list-proc.o

main.o:  main.c node.h list-proc.h
	$(CC) $(CFLAGS) -c main.c

list-proc.o:  list-proc.c list-proc.h node.h
	$(CC) $(CFLAGS) -c list-proc.c

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   object files, old emacs source versions, and core dumps.

clean:
	rm -f *.o *~ core*
