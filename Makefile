CPP_FILES := $(wildcard *.cpp)

OBJ_FILES := $(CPP_FILES:.cpp=.o)

CPP_FLAGS := -I/usr/include/qt4/

main: $(OBJ_FILES)

%.o: %.cpp
	g++ $(CPP_FLAGS) -c -o $@ $<
