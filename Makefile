TARGET := sleep_sort
SRCS   := $(wildcard *.cpp)
OBJS    = $(SRCS:.cpp=.o)

CXX       ?= clang++-15
CXXFLAGS  := -std=c++2a -Wall -Wextra -Wpedantic
FORMATTER ?= clang-format-14 -i

.PHONY: all clean format check
all: $(TARGET)
check: $(TARGET)
	./$(TARGET)
	@echo "All Test passed"
clean:
	rm -f $(TARGET) $(OBJS)
format:
	$(FORMATTER) $(SRCS) sleep_sort.h

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

$(OBJS): sleep_sort.h
