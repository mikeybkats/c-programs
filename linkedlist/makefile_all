# compiler to use
CC = clang

# flags to pass compiler
CFLAGS = -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow -g

EXEC = run
TARGET = $@
DEPENDENCY = $<
OBJECTS = $(SOURCES:.cpp=.o)

#TARGET = %.c

#all: $(TARGET)

#$(TARGET): $(TARGET)
	#$(CC) $(CFLAGS) $(TARGET) -o $(TARGET).c

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(EXEC) $(OBJECTS)
