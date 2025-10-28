# Makefile for Tic-Tac-Toe Game (WinBGIm)
# Note: This Makefile is for Windows with MinGW/GCC compiler

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = -lbgi -lgdi32 -luser32 -lcomdlg32 -lwinmm -lole32 -loleaut32
TARGET = TicTacToe.exe

SOURCES = main.cpp Game.cpp Board.cpp Cell.cpp Player.cpp HumanPlayer.cpp \
          ComputerPlayer.cpp Shape.cpp Cross.cpp Circle.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
