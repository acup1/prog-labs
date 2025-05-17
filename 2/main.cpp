/*
╭────────────────────────────────────────────────────────────╮
│        КАФЕДРА № 304 2 КУРС ПЯВУ С/РР П Р А К Т И К А      │
├────────────────────────────────────────────────────────────┤
│ Project Type  : linux64 Console Application                │
│ Project Name  : Матрицы                                    │
│ File Name     : main.cpp                                   │
│ Language      : C/C++ MS VS ver. 2019 and above            │
│ Programmer(s) : Порошин Г.А. Прошин Е.С.                   │
│ Modified By   :                                            │
│ Created       : 18/04/25                                   │
│ Last Revision : 05/05/25                                   │
│ Lit Sourse    :                                            │
│ Comment(s)    :                                            │
│ Временной интервал : 145 минут                             │
╰────────────────────────────────────────────────────────────╯
*/

#include <fstream>
#include <iostream>

using namespace std;

// Объявление констант
const int NMAX = 9;

// корректные
// const char FNAME1[] = "matr_A.txt";
// const char FNAME2[] = "matr_B.txt";
// const char FNAME1[] = "matr_A1.txt";
// const char FNAME2[] = "matr_B1.txt";
// const char FNAME1[] = "matr_A2.txt";
// const char FNAME2[] = "matr_B2.txt";
// const char FNAME1[] = "matr_A3.txt";
// const char FNAME2[] = "matr_B3.txt";

// const char FNAME1[] = "matr_even2.txt";

// const char FNAME2[] = "matr_even3.txt";
// const char FNAME2[] = "matr_odd.txt";

const char FNAME1[] = "matr_NMAX.txt";
// const char FNAME2[] = "matr_7.txt";
const char FNAME2[] = "matr_1.txt";

// некорректные
//
// const char FNAME1[] = "nonexistent"; //code1
//
// const char FNAME1[] = "eof.txt"; //code2
//
// const char FNAME1[] = "matr_-2.txt";
//
// const char FNAME1[] = "matr_0.txt";
//
// const char FNAME1[] = "matr_NMAX1.txt";
//
// const char FNAME1[] = "matr_char.txt";
//
// const char FNAME1[] = "matr_A-.txt";
//
// const char FNAME1[] = "matr_even.txt";

//////////////////////////////////////////////////////
// Заголовки функций
//////////////////////////////////////////////////////

// обработчик ошибок
void error(int code); // код ошибки

// задание матрицы из файла
int readMatr(
    const char fname[], // название файла
    int matr[][NMAX],   // указатель на нулевой элемент квадратной матрицы
    int &N);            // ссылка на размерность матрицы

// очистка матрицы
void delMatr(int matr[][NMAX], // квадратная матрца
             int &N);          // ссылка на размерность матрицы

// печать матрицы
void printMatr(
    const char matr_name[], // название матрицы (A или B)
    int matr[][NMAX],       // указатель на нулевой элемент квадратной матрицы
    int N);                 // размерность матрицы

// печать результата
void printRes(const char out[], // строка, выводимая до печати результата
              int res);         // результат

// первое задание
int task1(int matr[][NMAX], // указатель на нулевой элемент квадратной матрицы
          int N,            // размерность матрицы
          int &prod);       // ссылка на произведение

// второе задание
int task2(int matr[][NMAX], // указатель на нулевой элемент квадратной матрицы
          int N,            // размерность матрицы
          int &max);        // ссылка на максимум

// поиск максимума вектора
int findMax(
    int *vector, // указатель на вектор значений сумм
    bool *flags, // указатель на вектор с флагами наличия элементов суммы
    int N);      // размерность матрицы

//////////////////////////////////////////////////////
// main
//////////////////////////////////////////////////////

int main() {
  // инициализация переменных
  int matr[NMAX][NMAX]; // квадратная матрица
  int N;                // размерность матрицы
  int err_code;         // код ошибки
  int res;              // результат задания

  // решение задач для первой матрицы
  err_code = readMatr(FNAME1, matr, N);
  error(err_code); // проверяем наличие ошибки

  if (!err_code) {
    printMatr("A", matr, N); // печать матрицы

    // решение первой задачи
    err_code = task1(matr, N, res);
    error(err_code);
    if (!err_code) {
      printRes("Задание 1.\n\tПроизведение всех положительных\n\tчисел над "
               "побочной диагональю равно",
               res);
    }

    // решение второй задачи
    err_code = task2(matr, N, res);
    error(err_code);

    if (!err_code) {
      printRes(
          "Задание 2.\n\tМаксимум среди сумм по строкам нечётных\n\tэлементов "
          "матрицы равен",
          res);

      // очистка матрицы
      delMatr(matr, N);
    }
  }

  // решение задач для первой матрицы
  err_code = readMatr(FNAME2, matr, N);
  error(err_code); // проверяем наличие ошибки

  if (!err_code) {
    printMatr("B", matr, N); // печать матрицы

    // решение первой задачи
    err_code = task1(matr, N, res);
    error(err_code);
    if (!err_code) {
      printRes("Задание 1.\n\tПроизведение всех положительных\n\tчисел над "
               "побочной диагональю равно",
               res);
    }

    // решение второй задачи
    err_code = task2(matr, N, res);
    error(err_code);
    if (!err_code) {
      printRes(
          "Задание 2.\n\tМаксимум среди сумм по строкам нечётных\n\tэлементов "
          "матрицы равен",
          res);

      // очистка матрицы
      delMatr(matr, N);
    }
  }

  return 0;
}

//////////////////////////////////////////////////////
// Реализации функций
//////////////////////////////////////////////////////

// обработчик ошибок
void error(int code) {
  if (code == 0)
    return;
  cout << "ERROR: ";

  switch (code) {
  case 1:
    cout << "Не удалось открыть файл!\n";
    break;
  case 2:
    cout << "Встречен непредвиденный конец файла!\n";
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
  case 6:
    cout << "Матрица не содержит нечётные элементы!\n";
    break;
  }
}

// функция задания матрицы из файла
int readMatr(const char fname[], int matr[][NMAX], int &N) {
  // инициализация переменных
  ifstream fin;
  fin.open(fname);
  cout << "\nDEFMATR: считывание из файла " << fname << "\n";

  // входной контроль
  if (!fin)
    return 1;

  fin >> N;
  if (fin.eof())
    return 2;
  if (fin.fail())
    return 4;

  if (N <= 0 or N > NMAX)
    return 3;

  // задание матрицы из файла
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> matr[i][j];
      if (fin.eof())
        return 2;
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
int findMax(int *massive, bool *flags, int N) {
  // инициализация переменных
  int maxi;
  int max;
  for (int i = 0; i < N; i++) { // ищем первую валидную сумму
    if (flags[i]) {
      maxi = i;
      max = massive[i];
      break;
    }
  }
  // поиск максимума
  for (int i = 0; i < N; i++) {
    if (massive[i] > max and flags[i]) {
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
  bool oddRowFlag[N];
  for (int i = 0; i < N; i++)
    oddRowFlag[i] = false;
  bool is_elements = false;

  // посчёт и вывод сумм
  for (int i = 0; i < N; i++) {
    oddRowSums[i] = 0;
    for (int j = 0; j < N; j++) {
      if (matr[i][j] % 2 != 0) {
        oddRowSums[i] += matr[i][j];
        oddRowFlag[i] = true;
        is_elements = true;
      }
    }
    // эхо-печать
    if (oddRowFlag[i])
      cout << "TASK2: oddRowSums[" << i << "]=" << oddRowSums[i] << "\n";
  }

  // проверка на наличие нечётных элементов
  if (!is_elements)
    return 6;

  // поиск максимума
  max = findMax(oddRowSums, oddRowFlag, N);

  return 0;
}
