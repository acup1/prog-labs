#include <iostream>

using namespace std;

const int NMAX = 1000;

void printMatr(int matr[][NMAX], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << matr[i][j] << "\t";
    }
    cout << "\n";
  }
}

int main() {
  int a[NMAX][NMAX];

  printMatr(a, 5);

  return 0;
}
