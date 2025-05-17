/*       КАФЕДРА № 304 2 КУРС ПЯВУ СРР П Р А К Т И К А        *
 * __________________________________________________________ *
 * Project Type  : Win32 Console Application                  *
 * Project Name  : Матрицы                                    *
 * File Name     : main.cpp                                   *
 * Language      : C/C++ MS VS ver. 2019 and above            *
 * Programmer(s) : Порошин Г.Ф. Прошин Е.С.                   *
 * Modified By   :                                            *
 * Created       : 18/04/25                                   *
 * Last Revision : 05/05/25                                   *
 * Lit Sourse    :                                            *
 * Comment(s)    :                                            *
 * Временной интервал : 130 минут                             *
 *************************************************************/
#include <fstream>
#include <iostream>

using namespace std;

const int NMAX = 1000;

// const char FNAME1[] = "matr_eof.txt";
const char FNAME1[] = "matr_even.txt";

// const char FNAME1[] = "matr_A1.txt";
// const char FNAME2[] = "matr_B1.txt";

// const char FNAME1[] = "matr_A.txt";
const char FNAME2[] = "matr_B.txt";

// const char FNAME1[] = "nonexistent";
// const char FNAME1[] = "matr_char.txt";
// const char FNAME1[] = "matr_-2.txt";
// const char FNAME1[] = "matr_A-.txt";

int main() {
  // инициализация переменных
  int N;
  int matr[NMAX][NMAX];
  int err_code = 0;
  ifstream fin;
  fin.open(FNAME1);

  // Матрица A

  // входной контроль
  if (!fin) {
    cout << "Не удалось открыть файл!\n";
    err_code = 1;
  }

  if (!err_code) {
    fin >> N;
    if (fin.eof()) {
      cout << "Встречен непредвиденный конец файла!\n";
      err_code = 2;
    }

    if (!err_code and fin.fail()) {
      cout << "Получено не число!\n";
      err_code = 4;
    }

    // считывает размера и матрицы из файла
    if (!err_code and (N <= 0 or N > NMAX)) {
      cout << "Задан неверный размер матрицы или размер превышает лимит!\n";
      err_code = 3;
    }
  }

  if (!err_code) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        fin >> matr[i][j];
        if (fin.fail()) {
          cout << "Получено не число!\n";
          err_code = 4;
          break;
        } else if (fin.eof()) {
          cout << "Встречен непредвиденный конец файла!\n";
          err_code = 2;
          break;
        }
      }
    }
  }
  fin.close(); // закрытие файла
               //
               // начало заданий
  if (!err_code) {
    // вывод матрицы
    cout << "\nA[" << N << "x" << N << "]=\n";
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

    // первое задание: поиск произведения всех
    // положительных чисел над побочной диагональю
    cout << "\n";

    // инициализация переменных
    int prod = 1;
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
    if (is_elements) {
      cout << "Задание 1.\n";
      cout << "\tПроизведение всех положительных\n\tчисел над побочной "
              "диагональю равно "
           << prod << endl;
    } else {
      cout << "Матрица не содержит положительных элементов над побочной "
              "диагональю!\n";
    }

    // второе задание: поиск максимума среди сумм
    // по строкам нечётных элементов матрицы
    cout << "\nЗадание 2.\n";
    cout << "\tСуммы по строкам нечётных элементов матрицы равны:\n";

    // инициализация переменных
    int oddRowSums[NMAX];
    bool oddRowFlag[N];
    for (int i = 0; i < N; i++)
      oddRowFlag[i] = false;

    // посчёт и вывод сумм
    for (int i = 0; i < N; i++) {
      oddRowSums[i] = 0;
      for (int j = 0; j < N; j++) {
        if (matr[i][j] % 2 != 0) {
          oddRowSums[i] += matr[i][j];
          oddRowFlag[i] = true;
        }
      }
      if (oddRowFlag[i])
        cout << "\t\toddRowSums[" << i << "]=" << oddRowSums[i] << "\n";
    }

    // инициализация переменных
    int maxi;
    int max;
    for (int i = 0; i < N; i++) { // ищем первую валидную сумму
      if (oddRowFlag[i]) {
        maxi = i;
        max = oddRowSums[i];
        break;
      }
    }
    // поиск максимума
    for (int i = 0; i < N; i++) {
      if (oddRowSums[i] > max and oddRowFlag[i]) {
        max = oddRowSums[i];
        maxi = i;
      }
    }
    cout << "\n\tmax(oddRowSums)=oddRowSums[" << maxi << "]=" << max << "\n";

    // обнуление oddRowSums
    for (int i = 0; i < N; i++)
      oddRowSums[i] = 0;

    // очистка матрицы
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        matr[i][j] = 0;
    N = 0;
  } // конец заданий
  err_code = 0;

  // Матрица B

  fin.open(FNAME2);

  // входной контроль
  if (!fin) {
    cout << "Не удалось открыть файл!\n";
    err_code = 1;
  }

  if (!err_code) {
    fin >> N;
    if (fin.fail()) {
      cout << "Получено не число!\n";
      err_code = 4;
    }

    if (fin.eof()) {
      cout << "Встречен непредвиденный конец файла!\n";
      err_code = 2;
    }

    // считывает размера и матрицы из файла
    if (N <= 0 or N > NMAX) {
      cout << "Задан неверный размер матрицы или размер превышает лимит!\n";
      err_code = 3;
    }
  }

  if (!err_code) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        fin >> matr[i][j];
        if (fin.fail()) {
          cout << "Получено не число!\n";
          err_code = 4;
          break;
        } else if (fin.eof()) {
          cout << "Встречен непредвиденный конец файла!\n";
          err_code = 2;
          break;
        }
      }
    }
  }
  fin.close(); // закрытие файла
               //
               // начало заданий
  if (!err_code) {
    // вывод матрицы
    cout << "\nA[" << N << "x" << N << "]=\n";
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

    // первое задание: поиск произведения всех
    // положительных чисел над побочной диагональю
    cout << "\n";

    // инициализация переменных
    int prod = 1;
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
    if (is_elements) {
      cout << "Задание 1.\n";
      cout << "\tПроизведение всех положительных\n\tчисел над побочной "
              "диагональю равно "
           << prod << endl;
    } else {
      cout << "Матрица не содержит положительных элементов над побочной "
              "диагональю!\n";
    }

    // второе задание: поиск максимума среди сумм
    // по строкам нечётных элементов матрицы
    cout << "\nЗадание 2.\n";
    cout << "\tСуммы по строкам нечётных элементов матрицы равны:\n";

    // инициализация переменных
    int oddRowSums[NMAX];
    bool oddRowFlag[N];
    for (int i = 0; i < N; i++)
      oddRowFlag[i] = false;

    // посчёт и вывод сумм
    for (int i = 0; i < N; i++) {
      oddRowSums[i] = 0;
      for (int j = 0; j < N; j++) {
        if (matr[i][j] % 2 != 0) {
          oddRowSums[i] += matr[i][j];
          oddRowFlag[i] = true;
        }
      }
      if (oddRowFlag[i])
        cout << "\t\toddRowSums[" << i << "]=" << oddRowSums[i] << "\n";
    }

    // инициализация переменных
    int maxi;
    int max;
    for (int i = 0; i < N; i++) { // ищем первую валидную сумму
      if (oddRowFlag[i]) {
        maxi = i;
        max = oddRowSums[i];
        break;
      }
    }
    // поиск максимума
    for (int i = 0; i < N; i++) {
      if (oddRowSums[i] > max and oddRowFlag[i]) {
        max = oddRowSums[i];
        maxi = i;
      }
    }
    cout << "\n\tmax(oddRowSums)=oddRowSums[" << maxi << "]=" << max << "\n";

    // обнуление oddRowSums
    for (int i = 0; i < N; i++)
      oddRowSums[i] = 0;

    // очистка матрицы
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        matr[i][j] = 0;
    N = 0;
  } // конец заданий
  err_code = 0;

  return 0;
}
