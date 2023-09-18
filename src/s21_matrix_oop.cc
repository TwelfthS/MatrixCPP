#include "s21_matrix_oop.h"

#include <cmath>
#include <exception>
#include <iostream>

// constructors
S21Matrix::S21Matrix() {
  this->rows_ = 1;
  this->cols_ = 1;
  this->matrix_ = new double*[1];
  this->matrix_[0] = new double[0];
}

S21Matrix::S21Matrix(int rows_, int cols_) {
  if (rows_ > 0 && cols_ > 0) {
    this->rows_ = rows_;
    this->cols_ = cols_;
    this->matrix_ = new double*[rows_];
    for (int i = 0; i < this->rows_; ++i) this->matrix_[i] = new double[cols_];
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->SetValue(i, j, 0);
      }
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = new double*[rows_];
  for (int i = 0; i < this->rows_; ++i) this->matrix_[i] = new double[cols_];
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.matrix_ = NULL;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;
  this->rows_ = 0;
  this->cols_ = 0;
}

// accessors
int S21Matrix::GetRows() { return this->rows_; }

int S21Matrix::GetCols() { return this->cols_; }

double S21Matrix::GetValue(int row, int col) { return this->matrix_[row][col]; }

// mutators
void S21Matrix::SetValue(int row, int col, double x) {
  this->matrix_[row][col] = x;
}

void S21Matrix::SetRows(int x) {
  // this->rows_ = x;
  this->resize(x, this->cols_);
}

void S21Matrix::SetCols(int x) {
  // this->cols_ = x;
  this->resize(this->rows_, x);
}

void S21Matrix::resize(int row, int col) {
  int old_row = this->rows_;
  int old_col = this->cols_;
  this->rows_ = row;
  this->cols_ = col;
  double** new_ = new double*[row];
  for (int i = 0; i < row; i++) new_[i] = new double[col];
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      new_[i][j] = (i < old_row && j < old_col) ? matrix_[i][j] : 0;
    }
  }
  this->matrix_ = new_;
}

// operations
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  int ret = 1;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    ret = 0;
  } else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > EPS) ret = 0;
      }
    }
  }
  return ret;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw matrix_error("invalid matrix");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw matrix_error("invalid matrix");
  }
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = this->matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_) {
    throw matrix_error("invalid matrix");
  }
  S21Matrix result(this->rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  this->resize(this->rows_, other.cols_);
  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(this->cols_, this->rows_);
  for (int i = 0; i < this->cols_; i++) {
    for (int j = 0; j < this->rows_; j++) {
      result.matrix_[i][j] = this->matrix_[j][i];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw matrix_error("invalid matrix");
  }
  S21Matrix result(this->cols_, this->rows_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      result.matrix_[i][j] = this->minor(i, j) * pow(-1, i + j + 2);
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_) {
    throw matrix_error("invalid matrix");
  }
  double result = 0;
  int n = this->rows_;
  if (n == 2) {
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[0][1] * this->matrix_[1][0];
  } else if (n == 1) {
    result = this->matrix_[0][0];
  } else {
    S21Matrix B(this->rows_ - 1, this->cols_ - 1);
    double res;
    for (int k = 1; k <= n; k++) {
      this->helper(B, 0, k - 1);
      res = B.Determinant();
      result = result + pow(-1, k + 1) * this->matrix_[0][k - 1] * res;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (det == 0) {
    throw matrix_error("invalid matrix");
  }
  S21Matrix A = this->CalcComplements();
  S21Matrix result = A.Transpose();
  result.MulNumber(1 / det);
  return result;
}

// helpers
void S21Matrix::PrintValue(int row, int col) {
  std::cout << this->matrix_[row][col] << " ";
}

double S21Matrix::minor(int i, int j) {
  double ret = 0;
  S21Matrix other(this->rows_ - 1, this->cols_ - 1);
  this->helper(other, i, j);
  ret = other.Determinant();
  return ret;
}

void S21Matrix::helper(const S21Matrix& other, int c, int k) {
  int x = 0;
  int y = 0;
  for (int i = 0; i < this->rows_ - 1; i++) {
    y = 0;
    for (int j = 0; j < this->cols_ - 1; j++) {
      if (i == c) x = 1;
      if (j == k) y = 1;
      other.matrix_[i][j] = this->matrix_[i + x][j + y];
    }
  }
}

// overload
S21Matrix S21Matrix::operator=(S21Matrix other) {
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw matrix_error("invalid matrix");
  }
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->SetValue(i, j, other.GetValue(i, j));
    }
  }
  return *this;
}

bool S21Matrix::operator==(S21Matrix other) { return this->EqMatrix(other); }

S21Matrix S21Matrix::operator+(S21Matrix x) {
  S21Matrix result(*this);
  result.SumMatrix(x);
  return result;
}
S21Matrix S21Matrix::operator-(S21Matrix x) {
  S21Matrix result(*this);
  result.SubMatrix(x);
  return result;
}
S21Matrix S21Matrix::operator*(S21Matrix x) {
  S21Matrix result(*this);
  result.MulMatrix(x);
  return result;
}

S21Matrix S21Matrix::operator+=(S21Matrix other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(S21Matrix other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(S21Matrix other) {
  this->MulMatrix(other);
  return *this;
}

double S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i > this->rows_ || j > this->cols_) {
    throw matrix_error("Index is outside the matrix");
  }
  return this->matrix_[i][j];
}

S21Matrix& operator*(double num, S21Matrix& x) {
  x.MulNumber(num);
  return x;
}
S21Matrix& operator*(S21Matrix& x, double num) {
  x.MulNumber(num);
  return x;
}
