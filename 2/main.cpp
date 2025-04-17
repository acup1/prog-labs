#include "func.cpp"
#include "func.h"

const int NMAX = 10000;

int main() {
  // инициализация переменных
  int **matr;
  int N;

  // решение задач для первой матрицы
  error(defMatr("matr_A.txt", matr, N));
  printMatr("A", matr, N); // эхо-печать матрицы
  error(task1(matr, N));
  error(task2(matr, N));

  // удаление матрицы
  delMatr(matr, N);

  // решение задач для второй матрицы
  error(defMatr("matr_B.txt", matr, N));
  printMatr("B", matr, N); // эхо-печать матрицы
  error(task1(matr, N));
  error(task2(matr, N));

  return 0;
}
