TARGET = sleep_sort
SRCS = sleep_sort.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++-15

.PHONY: all clean
all: $(TARGET)
clean:
	rm -f $(TARGET) $(OBJS)
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)
sleep_sort.o: util.h
