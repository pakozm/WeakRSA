# WeakRSA
A very basic implementaion of RSA algorithm for educational purposes.
For its execution in *nix systems (MacOS X, Ubuntu, etc):

1. Download the [ZIP](https://github.com/pakozm/WeakRSA/archive/master.zip)
2. Unzip it with command: `unzip WeakRSA-master.zip`
3. Enter to the directory: `cd WeakRSA-master`
4. Execute the test: `./execute.sh`
```
$ ./execute.sh
g++ -o build/common.o -c src/common.cc -O3 -Wall
g++ -c -o build/primes.o src/primes.cc -O3 -Wall
g++ -o rsa_keys src/rsa_keys.cc build/common.o build/primes.o -O3 -Wall
g++ -o rsa_encript src/rsa_encript.cc build/common.o -O3 -Wall
g++ -o rsa_decript src/rsa_decript.cc build/common.o -O3 -Wall
GENERATING KEYS
Computing RSA for 32 bits
ENCRIPTING MESSAGE
DECRIPTING MESSAGE
CHECKING RESULT
Success!
```

## Generating pair of keys

Using the command `./rsa_keys [SEED]` where SEED is an optional argument
to initialize the random numbers generator.

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
