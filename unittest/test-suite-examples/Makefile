CXX := g++
CXXFLAGS := -Wall -Iheaders 
LDFLAGS :=  -lgtest -lgtest_main -lgmock -lgmock_main -lpthread -lboost_serialization

TARGET := main
SRCDIR := src
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard headers/*.hpp)
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
 
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) -c -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)