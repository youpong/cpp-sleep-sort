TARGET := sleep_sort
SRCS   := $(wildcard *.cpp)
OBJS    = $(SRCS:.cpp=.o)

CXX       ?= clang++-15
FORMATTER ?= clang-format-14 -i

.PHONY: all clean format
all: $(TARGET)
clean:
	rm -f $(TARGET) $(OBJS)
format:
	$(FORMATTER) $(SRCS) util.h sleep_sort.h

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS)

sleep_sort.o: util.h
$(OBJS): sleep_sort.h
