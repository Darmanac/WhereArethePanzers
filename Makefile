# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g     adds debugging information to the executable file
#  -Wall  turns on most, but not all, compiler warnings
CFLAGS = -Wall -g

# the build target executable
TARGET = main
LIB = Funcoes

all: $(TARGET)

$(TARGET): $(LIB).o $(TARGET).o
	$(CC) $(CFLAGS) *.o -o $(TARGET) -lm

$(TARGET).o: $(LIB).h $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c -lm

$(LIB).o: $(LIB).h $(LIB).c
	$(CC) $(CFLAGS) -c $(LIB).c

clean:
	$(RM) *.o
