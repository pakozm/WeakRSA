BUILD=build
BIN=.
CC=g++
CFLAGS=-O3 -Wall

all: rsa_keys rsa_encript rsa_decript

$(BIN)/rsa_keys: $(BUILD)/rsa_keys.o $(BUILD)/common.o $(BUILD)/primes.o
	$(CC) -o $(BIN)/rsa_keys $(BUILD)/rsa_keys.o $(BUILD)/common.o $(BUILD)/primes.o $(CFLAGS)

$(BIN)/rsa_encript: $(BUILD)/rsa_encript.o $(BUILD)/common.o
	$(CC) -o $(BIN)/rsa_encript $(BUILD)/rsa_encript.o $(BUILD)/common.o $(CFLAGS)

$(BIN)/rsa_decript: $(BUILD)/rsa_decript.o $(BUILD)/common.o
	$(CC) -o $(BIN)/rsa_decript $(BUILD)/rsa_decript.o $(BUILD)/common.o $(CFLAGS)

$(BUILD)/common.o: src/common.h src/common.cc
	$(CC) -o $(BUILD)/common.o -c src/common.cc $(CFLAGS)

$(BUILD)/primes.o: src/primes.h src/primes.cc src/common.h
	$(CC) -o $(BUILD)/primes.o -c src/primes.cc $(CFLAGS)

$(BUILD)/rsa_encript.o: src/rsa_encript.cc src/common.h
	$(CC) -o $(BUILD)/rsa_encript.o -c src/rsa_encript.cc $(CFLAGS)

$(BUILD)/rsa_decript.o: src/rsa_decript.cc src/common.h
	$(CC) -o $(BUILD)/rsa_decript.o -c src/rsa_decript.cc $(CFLAGS)

$(BUILD)/rsa_keys.o: src/rsa_keys.cc src/common.h src/primes.h
	$(CC) -o $(BUILD)/rsa_keys.o -c src/rsa_keys.cc $(CFLAGS)

clean:
	rm -f *~ $(BIN)/rsa_keys $(BIN)/rsa_encript $(BIN)/rsa_decript $(BUILD)/*.o

bak:
	find -name "*~" -exec rm -f {} ";"
