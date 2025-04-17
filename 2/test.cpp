#include <iostream>

using namespace std;

const int NMAX = 10000;

void printMatr(int **&matr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; i < size; j++) {
      cout << matr[i][j] << "\t";
    }
    cout << "\n";
  }
}

int main() {
  int a[10][10];
  printMatr(a, 10);

  return 0;
}
