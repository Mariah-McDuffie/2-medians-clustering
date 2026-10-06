#Mariah McDuffie

CC = g++
CFLAGS = -g -Wall -std=c++11
TARGET = P0
OBJS = P0_Project.o clustering.o

all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

P0_Project.o: P0_Project.cpp defs.h clustering.h
	$(CC) $(CFLAGS) -c P0_Project.cpp

clustering.o: clustering.cpp clustering.h defs.h
	$(CC) $(CFLAGS) -c clustering.cpp

# Clean
clean:
	rm -f $(OBJS) $(TARGET) 
