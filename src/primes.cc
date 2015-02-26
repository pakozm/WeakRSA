/*
  This file is a didactic implementation of RSA algorithm
  
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

#include <iostream>
#include <set>
#include <vector>

#include "common.h"
#include "primes.h"

using namespace std;

// initialize static properties
set<Number> Primes::primes;
Number Primes::last_upper_bound = 0;

// returns if a given number is a prime number, this is a private method, it
// can't be called outside the class; it requires the number to be less than the
// upper bound in Primes class
bool Primes::isPrime(Number n) {
  bool is_prime = true;
  for (set<Number>::const_iterator it=primes.begin();
       it != primes.end() && is_prime; ++it) {
    if (n % (*it) == 0) is_prime = false;
  }
  return is_prime;
}

// fills result vector with primes in range [a,b]
void Primes::getPrimesIn(Number a, Number b, vector<Number> &result) {
  if (primes.size() == 0) {
    // initialization of the class static properties the first time this
    // functions is executed
    primes.insert(2);
    last_upper_bound = 2;
  }
  // insert all yet calculated primes in the given range
  set<Number>::const_iterator it = primes.lower_bound(a);
  if ((*it) >= a) {
    for (; it != primes.end() && (*it) <= b; ++it) {
      result.push_back( *it );
    }
  }
  // compute all prime numbers from previous bound until the given b number,
  // and insert the new prime numbers which are in range [a,b]
  Number start = last_upper_bound + 1;
  for (unsigned int n=start; n < b; ++n) {
    if (isPrime(n)) {
      primes.insert(n);
      // check if the number is in range [a,b]
      if (n >= a) result.push_back(n);
    }
  }
  last_upper_bound = b;
}
