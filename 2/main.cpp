// Creators: Порошин Г. А. , Прошин Е. С.

#include <fstream>
#include <iostream>

using namespace std;

// Объявление констант
const int NMAX = 1000;
const char *FNAME1 = "matr_A.txt";
const char *FNAME2 = "matr_B.txt";

// Заголовки функций
void error(int code); // обработчик ошибок

// задание матрицы из файла
int defMatr(const char fname[], int matr[][NMAX], int &N);

void delMatr(int matr[][NMAX], int &N); // очистка матрицы

// печать матрицы
void printMatr(const char matr_name[], int matr[][NMAX], int N);

void printRes(const char out[], int res); // печать результата

int task1(int matr[][NMAX], int N, int &prod); // первое задание
int task2(int matr[][NMAX], int N, int &max);  // второе задание

int findMax(int *massive, int N); // поиск максимума вектора

int main() {
  // инициализация переменных
  int matr[NMAX][NMAX];
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

// Реализации функций

// обработчик ошибок
void error(int code) {
  // выход из функции в случае нулевого кода
  if (code == 0)
    return;

  cout << "ERROR: ";
  switch (code) {
  case 1:
    cout << "Не удалось открыть файл!\n";
    break;
  case 3:
    cout << "Задан неверный размер матрицы или превышен лимит!\n";
    break;
  case 4:
    cout << "Получено не число!\n";
    break;
  case 5:
    cout << "Матрица не содержит положительных элементов над побочной "
            "диагональю!\n";
    break;
  }
  // выход из программы с ошибкой
  exit(code);
}

// функция задания матрицы из файла
int defMatr(const char fname[], int matr[][NMAX], int &N) {
  // инициализация переменных
  ifstream fin;
  fin.open(fname);

  // входной контроль
  if (!fin)
    return 1;

  fin >> N;
  if (fin.fail())
    return 4;

  if (N <= 0 or N > NMAX)
    return 3;

  // задание матрицы из файла
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> matr[i][j];
      if (fin.fail())
        return 4;
    }
  }

  fin.close(); // закрытие файла
  return 0;
}

// очистка матрицы
void delMatr(int matr[][NMAX], int &N) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      matr[i][j] = 0;
  N = 0;
}

// печать матрицы
void printMatr(const char matr_name[], int matr[][NMAX], int N) {
  cout << "\n" << matr_name << "[" << N << "x" << N << "]=\n";
  for (int i = 0; i < N; i++) {

    cout << "\t";

    for (int j = 0; j < N; j++) {
      cout << matr[i][j] << "\t";
    }

    // печать скобок
    if (i == 0)
      cout << "╮\r╭";
    else if (i == N - 1)
      cout << "╯\r╰";
    else
      cout << "│\r│";

    cout << "\n";
  }
}

// печать результата
void printRes(const char out[], int res) { cout << out << " " << res << "\n"; }

// первое задание: поиск произведения всех
// положительных чисел над побочной диагональю
int task1(int matr[][NMAX], int N, int &prod) {

  // инициализация переменных
  prod = 1;
  bool is_elements = false;

  // поиск элементов и подсчёт произведения
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1; j++) {
      if ((i < (N - 1 - j)) and matr[i][j] > 0) {
        prod *= matr[i][j];
        is_elements = true;
      }
    }
  }

  // проверка на положительные элементы
  if (!is_elements)
    return 5;

  return 0;
}

// поиск максимума вектора
int findMax(int *massive, int N) {
  // инициализация переменных
  int maxi = 0;
  int max = massive[0];
  // поиск максимума
  for (int i = 0; i < N; i++) {
    if (massive[i] > max) {
      max = massive[i];
      maxi = i;
    }
  }
  return max;
}

// второе задание: поиск максимума среди сумм
// по строкам нечётных элементов матрицы
int task2(int matr[][NMAX], int N, int &max) {

  // инициализация переменных
  int oddRowSums[N];

  // посчёт и вывод сумм
  for (int i = 0; i < N; i++) {
    oddRowSums[i] = 0;
    for (int j = 0; j < N; j++) {
      if (matr[i][j] % 2 != 0)
        oddRowSums[i] += matr[i][j];
    }
    cout << "TASK2: oddRowSums[" << i << "]=" << oddRowSums[i] << "\n";
  }

  max = findMax(oddRowSums, N);

  return 0;
}
