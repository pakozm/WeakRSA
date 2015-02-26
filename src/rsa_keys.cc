/*
  This file is a didactic implementation of RSA algorithm, key pair computation
  part
  
  Copyright (c) 2015, Francisco Zamora-Martínez
  
  The MIT License (MIT)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
  IN THE SOFTWARE.
*/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

#include "common.h"
#include "primes.h"

using namespace std;

// Euclid's algorithm for GCD computation, iterative version
Number gcd(Number a, Number b) {
  while(a != b) {
    if (a > b) a -= b;
    else b -= a;
  }
  return a;
}

Number computePublicKeyExponent(Number phi_n) {
  Number e = 2;
  while(e < phi_n && gcd(e, phi_n) != 1) ++e;
  return e;
}

Number computePrivateKeyExponent(Number phi_n, Number e) {
  LongNumber d=3;
  while( (d*e) % phi_n != 1 ) d += 2;
  return d;
}

Number findPrime(Number a, Number b) {
  vector<Number> primes;
  // fill the vector with all prime numbers in range [a,b]
  Primes::getPrimesIn(a, b, primes);
  // take one randomly
  Number i = random() % primes.size();
  return primes[i];
}

Number findPrimeDifferentOf(Number p, Number a, Number b) {
  Number q;
  do {
    q = findPrime(a, b);
  } while( p == q);
  return q;
}

void computePrimeRange(Number nbits, Number &a, Number &b) {
  // compute minimum n number with nbits, which is: 2^(nbits-1) + 1
  Number min_n = (1 << (nbits - 1)) + 1;
  // compute minimum n number with nbits, which is: 2^nbits - 1
  // casting to LongNumber is needed in this computation to avoid overflow
  Number max_n = static_cast<Number>((static_cast<LongNumber>(1) << nbits) - 1);
  // take as lower bound the ceil(sqrt(min_n))
  a = static_cast<Number>(ceill(sqrtl(static_cast<long double>(min_n))));
  // take as upper bound the floor(sqrt(max_n))
  b = static_cast<Number>(floorl(sqrtl(static_cast<long double>(max_n))));
}

void writeKey(const char *filename, Number a, Number n) {
  ofstream key_file(filename);
  key_file << a << endl << n << endl;
  key_file.close();
}

int main(int argc, char **argv) {
  const char *public_key = "public_key.txt";
  const char *private_key = "private_key.txt";
  // check command line arguments
  if (argc > 1) {
    public_key = argv[1];
    if (argc > 2) {
      private_key = argv[2];
      if (argc > 3) {
        srandom(atoi(argv[3]));
      }
    }
  }
  //////////// MAIN PROGRAM ////////////
  Number nbits = sizeof(Number)*8;
  cout << "Computing RSA for " << nbits << " bits" << endl;
  Number a, b;
  computePrimeRange(nbits, a, b);
  Number p = findPrime(a, b);
  Number q = findPrimeDifferentOf(p, a, b);;
  //
  Number n = p * q;
  Number phi_n = (p - 1) * (q - 1);
  Number e = computePublicKeyExponent(phi_n);
  Number d = computePrivateKeyExponent(phi_n, e);
  //
  writeKey(public_key, e, n);
  writeKey(private_key, d, n);
  //
  return 0;
}
