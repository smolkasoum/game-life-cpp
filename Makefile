CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = infoSystem.exe
SRC = infoSystem.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	del $(TARGET)

.PHONY: clean
