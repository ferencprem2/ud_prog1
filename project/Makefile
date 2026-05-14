CC      = gcc
CFLAGS  = -O2 -Wall -Wextra -std=c99
SRC     = base.c

ifeq ($(OS),Windows_NT)
    TARGET = alap.exe
    RM     = del /Q
else
    TARGET = alap
    RM     = rm -f
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	$(RM) alap.exe alap

.PHONY: all clean
