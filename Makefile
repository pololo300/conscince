CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = simulation
SRCDIR = src
INCDIR = include
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCDIR)

$(BINDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCDIR)

clean:
	rm -f $(OBJS) $(TARGET)

