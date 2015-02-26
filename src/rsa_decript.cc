/*
  This file is a didactic implementation of RSA algorithm, decript part
  
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
#include <stack>
#include <vector>

#include "common.h"

using namespace std;

void readAllNumbers(vector<Number> &numbers) {
  Number n;
  while(cin >> n) numbers.push_back(n);
}

void convertNumberToBytesStack(Number n, stack<Byte> &bytes) {
  for (unsigned int j=0; j<BLOCK_SIZE; ++j) {
    Byte b = n & 0xFF;
    if (b > 0) {
      bytes.push(b);
    }
    n >>= 8;
  }  
}

void printBytesStack(stack<Byte> &bytes) {
  while(!bytes.empty()) {
    cout << bytes.top();
    bytes.pop();
  }
}

void show(const vector<Number> &v) {
  for (unsigned int i=0; i<v.size(); ++i) {
    Number n = v[i];
    stack<Byte> bytes;
    convertNumberToBytesStack(n, bytes);
    printBytesStack(bytes);
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Sintaxis: " << argv[0] << " key" << endl;
    return 1;
  }
  ifstream f(argv[1]);
  Number d, n;
  f >> d >> n;
  f.close();
  //
  vector<Number> numbers;
  readAllNumbers(numbers);
  //
  vector<Number> result;
  applyModExp(numbers, d, n, result);
  show(result);
  return 0;
}
