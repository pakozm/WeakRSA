/*
  This file is a didactic implementation of RSA algorithm, encript part
  
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
#include <fstream>
#include <vector>

#include "common.h"

using namespace std;

#define MAX_BUFFER_LEN 1024

void readAllInputBytes(vector<Byte> &bytes) {
  char c;
  while(cin.get(c)) bytes.push_back(static_cast<Byte>(c));
}

Number convertBytesVectorSliceToNumber(const vector<Byte> &bytes,
                                       unsigned int start,
                                       unsigned int len) {
  Number n = 0;
  for (unsigned int j=start; j<start+len; ++j) {
    // check j is in the bounds of bytes vector, otherwise c=0
    Byte c = (j < bytes.size()) ? bytes[j] : 0;
    n = (n << 8) | c;
  }
  return n;
}

void convertBytesVectorIntoNumbersVector(const vector<Byte> &bytes,
                                         vector<Number> &numbers) {
  for (unsigned int i=0; i<bytes.size(); i += BLOCK_SIZE) {
    Number n = convertBytesVectorSliceToNumber(bytes, i, BLOCK_SIZE);
    numbers.push_back(n);
  }
}

void show(const vector<Number> &v) {
  for (unsigned int i=0; i<v.size(); ++i) {
    cout << v[i] << endl;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Sintaxis: " << argv[0] << " key" << endl;
    return 1;
  }
  ifstream f(argv[1]);
  Number e, n;
  f >> e >> n;
  f.close();
  //
  vector<Byte> bytes;
  readAllInputBytes(bytes);
  vector<Number> numbers;
  convertBytesVectorIntoNumbersVector(bytes, numbers);
  //
  vector<Number> result;
  applyModExp(numbers, e, n, result);
  show(result);
  return 0;
}
