CXX = clang++
CFLAGS = -g -Wall -Wextra -Werror -Weffc++ -pedantic-errors -std=c++11
DEPS = TextQuery.h QueryResult.h \
	   Query.h Query_base.h WordQuery.h NotQuery.h \
	   BinaryQuery.h AndQuery.h OrQuery.h QueryHistory.h \
	   buildQuery.h
TARGET = 18.12
OBJ = $(TARGET).o TextQuery.o QueryResult.o \
	  Query.o Query_base.o WordQuery.o NotQuery.o \
	  BinaryQuery.o AndQuery.o OrQuery.o QueryHistory.o \
	  buildQuery.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o $(TARGET)
