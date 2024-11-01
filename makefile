# the compiler: gcc for C program, define as g++ for C++
CC = gcc
CXX = g++
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
LINKING = -lglut -lGL -lGLU
TARGET = *

q:
	$(CXX) $(CFLAGS) -o quadrado quadrado.cpp $(LINKING)
	./quadrado
l:
	$(CXX) $(CFLAGS) -o spline spline.cpp $(LINKING)
	./spline

clean:
	$(RM) $(TARGET)

