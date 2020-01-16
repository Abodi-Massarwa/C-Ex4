#-*-Makefile-*-
CC=gcc
OBJECTS_TRIE=trie.o
FLAGS= -Wall -g
OBJECT_FREQUENCY=frequency.o
OBJECT_FREQUENCY_R=frequency_r.o

all: frequency frequency_r
	 
frequency: frequencyd $(OBJECTS_TRIE)
	$(CC) $(OBJECTS_TRIE) -o frequency ./libfrequency.so
	
frequencyd: $(OBJECT_FREQUENCY)
	$(CC) -shared -o libfrequency.so $(OBJECT_FREQUENCY)

frequency.o: frequency.c
	$(CC) $(FLAGS) -fPIC -c frequency.c

############################################################################
frequency_r: frequency_rd $(OBJECTS_TRIE)
	$(CC) $(OBJECTS_TRIE) -o frequency_r ./libfrequency_r.so
	
frequency_rd: $(OBJECT_FREQUENCY_R)
	$(CC) -shared -o libfrequency_r.so $(OBJECT_FREQUENCY_R)

frequency_r.o: frequency_r.c
	$(CC) $(FLAGS) -fPIC -c frequency_r.c

$(OBJECTS_TRIE): trie.c trie.h
	$(CC) $(FLAGS) -fPIC -c trie.c
	
.PHONY: clean all

clean:
	rm -f *.o frequency frequency_r *.so 