prefix = /usr/local

CXX = g++
CXXFLAGS = -g -std=c++11
DEPS = Sequence.h PostScript.h
OBJ = main.o Sequence.o PostScript.o

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

maxcontig: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)

install: maxcontig
	install -D maxcontig \
		$(DESTDIR)$(prefix)/bin/

.PHONY: clean

clean:
	rm -f *.o
