C = g++
CFLAGS = -std=c++11 -Wall

TARGET = socket_server

OBJS = main.o socket.o 



$(TARGET): $(OBJS)
	$(C) $(CFLAGS) -o $(TARGET) $(OBJS)



main.o: main.cpp head_files.h
	$(C) $(CFLAGS) -c main.cpp

socket.o: socket.cpp head_files.h
	$(C) $(CFLAGS) -c socket.cpp



clean:
	rm -f $(OBJS) $(TARGET)

