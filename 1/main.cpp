// Creators: Порошин Г. А. , Прошин Е. С.

#include <fstream>
#include <iostream>

using namespace std;

const int NMAX = 1000;
// const char FNAME1[] = "matr_A1.txt";
// const char FNAME2[] = "matr_B1.txt";

const char FNAME1[] = "matr_A.txt";
const char FNAME2[] = "matr_B.txt";

// const char FNAME1[] = "nonexistent";
// const char FNAME1[] = "matr_char.txt";
// const char FNAME1[] = "matr_-2.txt";
// const char FNAME1[] = "matr_A-.txt";

int main() {
  // инициализация переменных
  int N;
  int matr[NMAX][NMAX];
  ifstream fin;
  fin.open(FNAME1);

  // Матрица A

  // входной контроль
  if (!fin) {
    cout << "Не удалось открыть файл!\n";
    return 1;
  }

  fin >> N;
  if (fin.fail()) {
    cout << "Получено не число!\n";
    return 4;
  }

  // считывает размера и матрицы из файла
  if (N <= 0 or N > NMAX) {
    cout << "Задан неверный размер матрицы или размер превышает лимит!\n";
    return 3;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> matr[i][j];
      if (fin.fail()) {
        cout << "Получено не число!\n";
        return 4;
      }
    }
  }
  fin.close(); // закрытие файла

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

  // посчёт и вывод сумм
  for (int i = 0; i < N; i++) {
    oddRowSums[i] = 0;
    for (int j = 0; j < N; j++) {
      if (matr[i][j] % 2 != 0)
        oddRowSums[i] += matr[i][j];
    }
    cout << "\t\toddRowSums[" << i << "]=" << oddRowSums[i] << "\n";
  }

  // инициализация переменных
  int maxi = 0;
  int max = oddRowSums[0];
  // поиск максимума
  for (int i = 0; i < N; i++) {
    if (oddRowSums[i] > max) {
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

  // Матрица B

  fin.open(FNAME2);

  // входной контроль
  if (!fin) {
    cout << "Не удалось открыть файл!\n";
    return 1;
  }

  fin >> N;
  if (fin.fail()) {
    cout << "получено не число!\n";
    return 4;
  }

  // считывает размера и матрицы из файла
  if (N <= 0 or N > NMAX) {
    cout << "Задан неверный размер матрицы или размер превышает лимит!\n";
    return 3;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      fin >> matr[i][j];
      if (fin.fail()) {
        cout << "получено не число!\n";
        return 4;
      }
    }
  }
  fin.close(); // закрытие файла

  // вывод матрицы
  cout << "\nB[" << N << "x" << N << "]=\n";
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
  prod = 1;
  is_elements = false;

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

  // посчёт и вывод сумм
  for (int i = 0; i < N; i++) {
    oddRowSums[i] = 0;
    for (int j = 0; j < N; j++) {
      if (matr[i][j] % 2 != 0)
        oddRowSums[i] += matr[i][j];
    }
    cout << "\t\toddRowSums[" << i << "]=" << oddRowSums[i] << "\n";
  }

  // инициализация переменных
  maxi = 0;
  max = oddRowSums[0];
  // поиск максимума
  for (int i = 0; i < N; i++) {
    if (oddRowSums[i] > max) {
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

  return 0;
}
