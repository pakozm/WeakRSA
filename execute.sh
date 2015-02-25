#!/bin/bash
make
./rsa_keys
./rsa_encript private_key.txt < message > message.encripted
./rsa_decript public_key.txt < message.encripted > message.decripted
if ! diff -q message message.decripted; then
    echo "Fail!"
else
    echo "Success!"
fi
