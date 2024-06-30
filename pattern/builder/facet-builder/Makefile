CXX := g++
CXXFLAGS := -Wall -Iheaders -g -Wunused-function
LDFLAGS :=

TARGET := main
SRCDIR := src
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard headers/*.hpp)
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)