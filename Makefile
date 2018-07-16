CXX = g++
CXXFLAGS = -std=c++0x

OBJS = Die.o LoadedDie.o main.o Game.o libraryFunctions.o

SRCS = Die.cpp LoadedDie.cpp main.cpp Game.cpp libraryFunctions.cpp

HEADERS = Die.hpp LoadedDie.hpp Game.hpp

warGame: ${OBJS} ${HEADERS}
	${CXX} ${SRCS} -o warGame
	
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm ${OBJS}