CXX := g++
CXXFLAGS := -Wall -Iheaders -Wno-narrowing
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