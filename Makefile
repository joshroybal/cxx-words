CXX = g++
CFLAGS = -std=c++98 -O2
LFLAGS = -static -s

words: main.o words.o
	$(CXX) -o $@ $^ $(LFLAGS)

main.o: main.cpp words.hpp
	$(CXX) -c $< $(CFLAGS)

words.o: words.cpp words.hpp
	$(CXX) -c $< $(CFLAGS)

clean:
	$(RM) words *.o
