#include "func.cpp"

int main() {
  // инициализация переменных
  int matr[NMAX][NMAX];
  int N;

  // решение задач для первой матрицы
  error(defMatr("matr_A.txt", matr, N));
  printMatr("A", matr, N); // эхо-печать матрицы
  error(task1(matr, N));
  error(task2(matr, N));

  // удаление матрицы
  delMatr(matr, N);

  return 0;
}
