app: main.o search.o sort.o common.o backpack.o
	g++ --std=c++11 -o app main.o search.o sort.o common.o backpack.o

main.o: main.cpp utils.hpp
	g++ -c --std=c++11 main.cpp

search.o: search.cpp utils.hpp
	g++ -c --std=c++11 search.cpp

sort.o: sort.cpp utils.hpp
	g++ -c --std=c++11 sort.cpp

common.o: common.cpp utils.hpp
	g++ -c --std=c++11 common.cpp

backpack.o: problems/backpack.cpp problems/backpack.hpp
	g++ -c --std=c++11 problems/backpack.cpp

run: app
	./app < input.txt

.PHONY: clean
clean:
	rm -f *.exe *.out *.o app