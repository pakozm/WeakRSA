#!/bin/bash
make
echo "GENERATING KEYS"
./rsa_keys
echo "ENCRIPTING MESSAGE"
./rsa_encript private_key.txt < message > message.encripted
echo "DECRIPTING MESSAGE"
./rsa_decript public_key.txt < message.encripted > message.decripted
echo "CHECKING RESULT"
if ! diff -q message message.decripted; then
    echo "Fail!"
else
    echo "Success!"
fi
