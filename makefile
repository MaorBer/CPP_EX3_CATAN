# maorw9@gmail.com
# 212305965

CXX = g++
CXXFLAGS = -std=c++14 -Wall -I./hpp_files

# Define targets
TEST_TARGET = test
DEMO_TARGET = demo

# Source files
SOURCES = cpp_files/MonopolyCard.cpp cpp_files/RoadBuildingCard.cpp \
          cpp_files/YearOfPlentyCard.cpp cpp_files/board.cpp cpp_files/catan.cpp \
          cpp_files/city.cpp cpp_files/knightCard.cpp cpp_files/player.cpp \
          cpp_files/road.cpp cpp_files/settlement.cpp cpp_files/tile.cpp \

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Test and demo source files
TEST_SOURCES = Test.cpp
DEMO_SOURCES = Demo.cpp

# Test and demo object files
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
DEMO_OBJECTS = $(DEMO_SOURCES:.cpp=.o)

# Default target
all: $(TEST_TARGET) $(DEMO_TARGET)

# Rule for test target
$(TEST_TARGET): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJECTS) $(TEST_OBJECTS)

# Rule for demo target
$(DEMO_TARGET): $(OBJECTS) $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(OBJECTS) $(DEMO_OBJECTS)

# Generic rule for compiling .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TEST_TARGET) $(DEMO_TARGET) $(OBJECTS) $(TEST_OBJECTS) $(DEMO_OBJECTS)
