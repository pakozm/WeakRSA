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

#include <cstdlib>
#include <iostream>
#include <vector>

#include "common.h"

using namespace std;

bool isOdd(Number n) {
  return (n & 1) == 1;
}

// computes b^e (mod m)
Number modExp(Number b, Number e, Number m) {
  // https://en.wikipedia.org/wiki/Modular_exponentiation
  LongNumber result = 1;
  for (Number i=0; i<e; ++i) {
    result = (result * b) % m;
  }
  return result;
}

void applyModExp(const vector<Number> &numbers, Number e, Number m,
                 vector<Number> &result) {
  for (unsigned int i=0; i<numbers.size(); ++i) {
    Number n = modExp(numbers[i], e, m);
    result.push_back(n);
  }
}
