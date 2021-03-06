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

#ifndef PRIMES_H
#define PRIMES_H

#include <set>
#include <vector>

#include "common.h"

// static class which contains a set of primes numbers until a known upper bound
class Primes {
  static std::set<Number> primes;
  static Number last_upper_bound;
  
public:
  // fills result vector with primes in range [a,b]
  static void getPrimesIn(Number a, Number b,
                          std::vector<Number> &result);
  
private:
  // returns if a given number is a prime number, this is a private method, it
  // can't be called outside the class; it requires the number to be less than the
  // upper bound in Primes class
  static bool isPrime(Number n);
};

#endif // PRIMES_H
