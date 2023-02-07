TARGET := sleep_sort
SRCS   := $(wildcard *.cpp)
OBJS    = $(SRCS:.cpp=.o)

CXX    ?= clang++-15

.PHONY: all clean
all: $(TARGET)
clean:
	rm -f $(TARGET) $(OBJS)
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

sleep_sort.o: util.h
$(OBJS): sleep_sort.h
