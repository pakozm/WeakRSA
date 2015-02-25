all: rsa_keys rsa_encript rsa_decript

rsa_keys: src/rsa_keys.cc build/common.o build/primes.o
	g++ -o rsa_keys src/rsa_keys.cc build/common.o build/primes.o -O3 -Wall

rsa_encript: src/rsa_encript.cc build/common.o
	g++ -o rsa_encript src/rsa_encript.cc build/common.o -O3 -Wall

rsa_decript: src/rsa_decript.cc build/common.o
	g++ -o rsa_decript src/rsa_decript.cc build/common.o -O3 -Wall

build/common.o: src/common.h src/common.cc
	g++ -o build/common.o -c src/common.cc -O3 -Wall

build/primes.o: src/primes.h src/primes.cc src/common.h
	g++ -c -o build/primes.o src/primes.cc -O3 -Wall

clean:
	rm -f *~ rsa_keys rsa_encript rsa_decript build/*.o

bak:
	rm -f *~
