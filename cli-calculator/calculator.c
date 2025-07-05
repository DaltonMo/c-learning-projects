/*  CLI Calculator
    This program allows a user to select an operation, then the user can enter
    two numbers to be used within the operation.
*/

#include <stdio.h>

void print_welcome();
void print_operation_options();
int get_user_choice();
double get_number(const char* prompt);
double add(double a, double b);
double sub(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
  int choice;
  print_welcome();

  do {
    print_operation_options();
    choice = get_user_choice();
    if (choice < 1 || choice > 4) {
      printf("Please choose a valid operation. (1-5)\n\n");
      continue;
    }

    int a = get_number("Enter first number: ");
    int b = get_number("Enter second number: ");
    double result;

    switch (choice) {
      case 1:
        result = add(a, b);
        break;
      case 2:
        result = sub(a, b);
        break;
      case 3:
        result = multiply(a, b);
        break;
      case 4:
        result = divide(a, b);
        break;
    }

    printf("Result: %.2lf\n\n", result);
  } while (choice != 5);

  return 0;
}

double add(double a, double b) {
  return a + b;
}

double sub(double a, double b) {
  return a - b;
}

double multiply(double a, double b) {
  return a * b;
}

double divide(double a, double b) {
  if (b == 0) {
    printf("ERROR: Cannot divide by 0.\n");
    return 0;
  }

  return a / b;
}

void print_welcome() {
  printf("Welcome to CLI Calulator!\n");
}

void print_operation_options() {
  printf(
      "Select an operation:\n"
      "1) Add\n"
      "2) Subtract\n"
      "3) Multiply\n"
      "4) Divide\n"
      "5) Exit\n");
}

int get_user_choice() {
  int choice;
  printf("Choice: ");
  if (scanf("%d", &choice) != 1) {
    // Clear invalid input from stdin
    while (getchar() != '\n') {
      return -1;
    }
  }
  return choice;
}

double get_number(const char* prompt) {
  double number;
  printf(prompt);
  scanf("%lf", &number);
  return number;
}
