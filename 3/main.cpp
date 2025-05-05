// Creators: Порошин Г. А. , Прошин Е. С.

#include "func.cpp"
#include "func.h"

// const char FNAME1[] = "matr_A1.txt";
// const char FNAME2[] = "matr_B1.txt";

const char FNAME1[] = "matr_A2.txt";
const char FNAME2[] = "matr_B2.txt";

// const char FNAME1[] = "matr_A.txt";
// const char FNAME2[] = "matr_B.txt";

// const char FNAME1[] = "nonexistent";
// const char FNAME1[] = "matr_char.txt";
// const char FNAME1[] = "matr_-2.txt";
// const char FNAME1[] = "matr_A-.txt";

int main() {
  // инициализация переменных
  int **matr;
  int N;
  int err_code;
  int res;

  // решение задач для первой матрицы
  err_code = defMatr(FNAME1, matr, N);
  error(err_code);
  printMatr("A", matr, N); // печать матрицы
  err_code = task1(matr, N, res);
  error(err_code);
  printRes("Задание 1.\n\tПроизведение всех положительных\n\tчисел над "
           "побочной диагональю равно",
           res);
  err_code = task2(matr, N, res);
  error(err_code);
  printRes("Задание 2.\n\tМаксимум среди сумм по строкам нечётных\n\tэлементов "
           "матрицы равен",
           res);

  // очистка матрицы
  delMatr(matr, N);

  // решение задач для первой матрицы
  err_code = defMatr(FNAME2, matr, N);
  error(err_code);
  printMatr("B", matr, N); // печать матрицы
  err_code = task1(matr, N, res);
  error(err_code);
  printRes("Задание 1.\n\tПроизведение всех положительных\n\tчисел над "
           "побочной диагональю равно",
           res);
  err_code = task2(matr, N, res);
  error(err_code);
  printRes("Задание 2.\n\tМаксимум среди сумм по строкам нечётных\n\tэлементов "
           "матрицы равен",
           res);

  // очистка матрицы
  delMatr(matr, N);

  return 0;
}
