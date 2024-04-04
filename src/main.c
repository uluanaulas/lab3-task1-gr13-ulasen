#include <stdio.h>
#include <stdlib.h>

// Функция для определения количества дней в заданном месяце
int daysInMonth(int month, int year) {
  switch (month) {
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2:
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      return 29; // Високосный год
    else
      return 28;
  default:
    return 31;
  }
}

// Функция для определения даты предыдущего дня
void previousDay(int *year, int *month, int *day) {
  if (*day > 1) {
    (*day)--;
  } else {
    if (*month > 1) {
      (*month)--;
      *day = daysInMonth(*month, *year);
    } else {
      (*year)--;
      *month = 12;
      *day = 31;
    }
  }
}

// Функция для определения даты следующего дня
void nextDay(int *year, int *month, int *day) {
  int days_in_month = daysInMonth(*month, *year);
  if (*day < days_in_month) {
    (*day)++;
  } else {
    if (*month < 12) {
      (*month)++;
      *day = 1;
    } else {
      (*year)++;
      *month = 1;
      *day = 1;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Использование: %s год месяц число\n", argv[0]);
    return 1;
  }

  int g, m, n;
  g = atoi(argv[1]);
  m = atoi(argv[2]);
  n = atoi(argv[3]);

  printf("Введенная дата: %d.%d.%d\n", n, m, g);

  // Дата предыдущего дня
  previousDay(&g, &m, &n);
  printf("Предыдущий день: %d.%d.%d\n", n, m, g);

  // Дата следующего дня дважды
  nextDay(&g, &m, &n);
  nextDay(&g, &m, &n);
  printf("Следующий день: %d.%d.%d\n", n, m, g);

  return 0;
}