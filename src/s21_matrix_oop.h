#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#define EPS 0.0000001

#include <exception>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  // constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // accessors
  int GetRows();
  int GetCols();
  double GetValue(int row, int col);
  // mutators
  void SetValue(int row, int col, double x);
  void SetRows(int x);
  void SetCols(int x);
  void resize(int row, int col);

  // operations
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  // helpers
  void PrintValue(int row, int col);
  double minor(int i, int j);
  void helper(const S21Matrix& other, int c, int k);

  // overload
  bool operator==(S21Matrix other);
  S21Matrix operator=(S21Matrix other);
  S21Matrix operator+(S21Matrix x);
  S21Matrix operator-(S21Matrix x);
  S21Matrix operator*(S21Matrix x);
  S21Matrix operator+=(S21Matrix other);
  S21Matrix operator-=(S21Matrix other);
  S21Matrix operator*=(S21Matrix other);
  double operator()(int i, int j);

  friend S21Matrix& operator*(double num, S21Matrix& x);
  friend S21Matrix& operator*(S21Matrix&, double num);
};

class matrix_error : public std::exception {
 public:
  matrix_error(const std::string& message) : message{message} {}
  const char* what() const noexcept override { return message.c_str(); }

 private:
  std::string message;
};

S21Matrix& operator*(double num, S21Matrix& x);
S21Matrix& operator*(S21Matrix& x, double num);

#endif