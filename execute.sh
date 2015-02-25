#!/bin/bash
make
./rsa_keys
./rsa_encript < message > message.encripted
./rsa_decript < message.encripted > message.decripted
if ! diff -q messagemessage.decripted; then
    echo "Fail!"
else
    echo "Success!"
fi
