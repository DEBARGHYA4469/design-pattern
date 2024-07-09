CXX := g++
CXXFLAGS := -Wall -Iheaders -std=gnu++20
LDFLAGS := -lgtest -lgtest_main -lgmock -lgmock_main -lboost_serialization -fconcepts 
TARGET := main
SRCDIR := src
TESTDIR := tests

# Collect all sources except main.cpp for OBJECTS
SOURCES := $(filter-out $(SRCDIR)/main.cpp, $(wildcard $(SRCDIR)/*.cpp))
HEADERS := $(wildcard headers/*.hpp) $(wildcard headers/*.h) 
OBJECTS := $(SOURCES:.cpp=.o)

# Test sources and objects
TEST_SOURCES := $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJECTS := $(TEST_SOURCES:.cpp=.o)
TEST_TARGET := test_runner

.PHONY: all clean run test
all: $(TARGET)

# Build the main target
$(TARGET): $(OBJECTS) $(SRCDIR)/main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the main target
run: all
	./$(TARGET)

# Build and run the tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Build the test runner
$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TESTDIR)/%.o: $(TESTDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJECTS) $(SRCDIR)/main.o $(TEST_OBJECTS) $(TEST_TARGET)

clean_test: 
	rm -f $(TARGET) $(OBJECTS) $(TEST_OBJECTS) $(TEST_TARGET) 