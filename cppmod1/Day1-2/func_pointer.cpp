#include <iostream>

double add(double left, double right) {
  return left + right;
}

double multiply(double left, double right) {
  return left * right;
}

double binary_op(double left, double right, double (*f)(double, double)) {
  return (*f)(left, right);
}

int main() {
  double a = 5.0;
  double b = 10.0;

  std::cout << "Add: " << binary_op(a, b, add) << std::endl;
  std::cout << "Multiply: " << binary_op(a, b, multiply) << std::endl;

  return 0;
}