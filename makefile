all: rsa_keys rsa_encript rsa_decript

rsa_keys: rsa_keys.cc common.o primes.o
	g++ -o rsa_keys rsa_keys.cc common.o primes.o -O3 -Wall

rsa_encript: rsa_encript.cc common.o
	g++ -o rsa_encript rsa_encript.cc common.o -O3 -Wall

rsa_decript: rsa_decript.cc common.o
	g++ -o rsa_decript rsa_decript.cc common.o -O3 -Wall

common.o: common.h common.cc
	g++ -c common.cc -O3 -Wall

primes.o: primes.h primes.cc common.h
	g++ -c primes.cc -O3 -Wall

clean:
	rm -f *~ rsa_keys rsa_encript rsa_decript common.o

bak:
	rm -f *~
