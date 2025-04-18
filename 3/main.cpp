// Creators: Порошин Г. А. , Прошин Е. С.

#include "func.cpp"
#include "func.h"

const char *FNAME1 = "matr_A.txt";
const char *FNAME2 = "matr_B.txt";

int main() {
  // инициализация переменных
  int **matr;
  int N;
  int err_code;

  // решение задач для первой матрицы
  err_code = defMatr(FNAME1, matr, N);
  error(err_code);
  printMatr("A", matr, N); // печать матрицы
  err_code = task1(matr, N);
  error(err_code);
  err_code = task2(matr, N);
  error(err_code);

  // очистка матрицы
  delMatr(matr, N);

  // решение задач для второй матрицы
  err_code = defMatr(FNAME2, matr, N);
  error(err_code);
  printMatr("A", matr, N); // печать матрицы
  err_code = task1(matr, N);
  error(err_code);
  err_code = task2(matr, N);
  error(err_code);

  // очистка матрицы
  delMatr(matr, N);

  return 0;
}
