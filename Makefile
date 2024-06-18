# ID: 3224653689
# MAIL: adam.sinale@gmail.com

CC=g++
FLAGS=-std=c++14 -Werror -Wsign-conversion

CPPs = catan.cpp board.cpp player.cpp spot.cpp devcard.cpp
OBJECTS=$(subst .cpp,.o,$(CPPs))

run: demo
	./$^

demo: Demo.o $(filter-out Test.o, $(OBJECTS))
	$(CC) $(FLAGS) $^ -o demo

# test: TestCounter.o Test.o $(filter-out Demo.o, $(OBJECTS))
# 	$(CC) $(FLAGS) $^ -o test

%.o: %.cpp
	$(CC) $(FLAGS) --compile $< -o $@

clean:
	rm -f *.o demo test
