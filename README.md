# WeakRSA
A very basic implementaion of RSA algorithm for educational purposes. It is
slow, unsafe and it never should be used for real purposes.

## Dependencies

This software needs `unzip` or similar to unpack the sources, and `g++`
compiler for compilation.

## Execution

For its execution in *nix systems (MacOS X, Linux, BSD flavors, etc):

1. Download the [ZIP](https://github.com/pakozm/WeakRSA/archive/master.zip)
2. Unzip it with command: `unzip WeakRSA-master.zip`
3. Enter to the directory: `cd WeakRSA-master`
4. Execute the test: `./execute.sh`
```
$ ./execute.sh
g++ -o build/rsa_keys.o -c src/rsa_keys.cc -O3 -Wall
g++ -o build/common.o -c src/common.cc -O3 -Wall
g++ -o build/primes.o -c src/primes.cc -O3 -Wall
g++ -o ./rsa_keys build/rsa_keys.o build/common.o build/primes.o -O3 -Wall
g++ -o build/rsa_encript.o -c src/rsa_encript.cc -O3 -Wall
g++ -o ./rsa_encript build/rsa_encript.o build/common.o -O3 -Wall
g++ -o build/rsa_decript.o -c src/rsa_decript.cc -O3 -Wall
g++ -o ./rsa_decript build/rsa_decript.o build/common.o -O3 -Wall
GENERATING KEYS
Computing RSA for 32 bits
ENCRIPTING MESSAGE
DECRIPTING MESSAGE
CHECKING RESULT
Success!
```

## Generating pair of keys

Using the command `./rsa_keys [PUB_FILE [PRIV_FILE [SEED]]]]` where PUB_FILE is
an optional argument indicating where to store the public key (by default it is
`public_key.txt`), PRIV_FILE is a second optional argument with the private key
filename (by default it is `private_key.txt`), and SEED is a third optional
argument with with the seed to initialize the random numbers generator (by
default it is system dependent).

```
$ ./rsa_keys
Computing RSA for 32 bits
```

This command generates two files, `public_key.txt` and `private_key.txt`:

```
$ cat public_key.txt 
7
3127829293
$ cat private_key.txt 
2680900663
3127829293
```

## Encripting a message

Using the command `./rsa_encript public_key.txt`. This command
reads the message from the standard input, so you can write it
by using the keyboard, redirecting the input,
or by means of `cat` or `echo` commands.
The encripted message is shown at standard output, so it is
recommended to redirect the output to a file.

```
$ ./rsa_encript public_key.txt > encripted1.txt
Testing a message.
$ echo "Testing another message." | ./rsa_encript public_key.txt > encripted2.txt
$ cat encripted1.txt
2640209941
119942456
3016625791
2854215521
2642555434
$ cat encripted2.txt
2640209941
119942456
2484317359
3111061414
676374081
620561897
304336982
```

## Decripting a message

Using the command `./rsa_decript private_key.txt`. Similar as `rsa_encript`,
this command reads the encripted message from the standard input,
so you can write it by using the keyboard, redirecting the input,
or by means of `cat` or `echo`
commands. The decripted message is shown at standard output, so it is
recommended to redirect the output to a file.

```
$ cat encripted1.txt | ./rsa_decript private_key.txt
Testing a message.
$ cat encripted2.txt | ./rsa_decript private_key.txt
Testing another message.
```
