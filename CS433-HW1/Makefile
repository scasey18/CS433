# Sample Makefile to compile C programs 
CC = gcc 
CFLAGS = -Wall -g #replace -g with -O when not debugging 
DEPS     = Makefile 
OBJS     = helper.o forkexec.o commands.o shell.o
FIB      = fibonacci.o
HEL      = hello.o
EXECS    = uab_sh fibonacci hello

all:     $(EXECS) 

%.o:     %.c $(DEPS) 
		$(CC) $(CFLAGS) -c -o $@ $<  

uab_sh: $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

fibonacci: $(FIB)
		   $(CC) $(CFLAGS) -o $@ $^
		   
hello:  $(HEL)
		$(CC) $(CFLAGS) -o $@ $^

clean: 
		rm -rf *.o