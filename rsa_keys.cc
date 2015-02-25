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

// Euclid's algorithm for GCD computation
Number gcd(Number a, Number b) {
  if (a == b) return a;
  else if (a > b) {
    return gcd(a - b, b);
  }
  else { // a < b
    return gcd(a, b - a);
  }
}

Number computePublicKeyExponent(Number phi_n) {
  Number e = 2;
  while(e < phi_n && gcd(e, phi_n) != 1) ++e;
  return e;
}

Number computePrivateKeyExponent(Number phi_n, Number e) {
  Number Y = 1;
  while( ( ( Y*phi_n + 1 ) % e ) != 0 ) ++Y;
  return (Y*phi_n + 1) / e;
}

Number findPrime(Number a, Number b) {
  vector<Number> primes;
  Primes::getPrimesIn(a, b, primes);
  Number i = random() % primes.size();
  return primes[i];
}

int main() {
  Number nbits = sizeof(Number)*8;
  Number min_n = (1 << (nbits - 1)) + 1;
  Number max_n = static_cast<Number>((static_cast<LongNumber>(1) << nbits) - 1);
  cout << "Computing RSA for " << nbits << " bits" << endl;
  Number a = static_cast<Number>(ceilf(sqrtf(static_cast<float>(min_n))));
  Number b = static_cast<Number>(floorf(sqrtf(static_cast<float>(max_n))));
  Number p = findPrime(a, b);
  Number q;
  do {
    q = findPrime(a, b);
  } while( p == q);
  //
  Number n = p * q;
  Number phi_n = (p - 1) * (q - 1);
  Number e = computePublicKeyExponent(phi_n);
  Number d = computePrivateKeyExponent(phi_n, e);
  //
  ofstream public_key_file("public_key.txt");
  public_key_file << e << endl << n << endl;
  public_key_file.close();
  //
  ofstream private_key_file("private_key.txt");
  private_key_file << d << endl << n << endl;
  private_key_file.close();
  //
  return 0;
}
