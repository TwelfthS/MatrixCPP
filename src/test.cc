#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(EqMatrix, test1) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 3);
    }
  }
  ASSERT_EQ(M1.EqMatrix(M2), 1);
}

TEST(EqMatrix, test2) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  ASSERT_EQ(M1.EqMatrix(M2), 0);
}

TEST(EqMatrix, test3) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 5);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      M2.SetValue(i, j, 3);
    }
  }
  ASSERT_EQ(M1.EqMatrix(M2), 0);
}

TEST(NewMatrix, test1) {
  S21Matrix M1;
  M1.SetValue(0, 0, 3);
  S21Matrix M2(M1);
  ASSERT_EQ(M1.EqMatrix(M2), 1);
}

TEST(NewMatrix, test2) {
  S21Matrix M1;
  S21Matrix M2(2, 2);
  int err = 0;
  try {
    M2 = M1;
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(SumMatrix, test1) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  S21Matrix M3(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M3.SetValue(i, j, 7);
    }
  }
  M1.SumMatrix(M2);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(M1.GetValue(i, j), M3.GetValue(i, j));
    }
  }
}

TEST(SumMatrix, test2) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  S21Matrix M3(3, 4);
  S21Matrix M4(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M3.SetValue(i, j, 7);
    }
  }
  M4 = M1 + M2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.PrintValue(i, j);
      ASSERT_EQ(M4.GetValue(i, j), M3.GetValue(i, j));
    }
  }
}

TEST(SumMatrix, test3) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  S21Matrix M3(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M3.SetValue(i, j, 7);
    }
  }
  M1 += M2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(M1.GetValue(i, j), M3.GetValue(i, j));
    }
  }
}

TEST(SumMatrix, test4) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 5);
  int err = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  try {
    M1 += M2;
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(SubMatrix, test1) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  S21Matrix M3(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M3.SetValue(i, j, -1);
    }
  }
  M1.SubMatrix(M2);
  ASSERT_EQ(M1.EqMatrix(M3), 1);
}

TEST(SubMatrix, test2) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  S21Matrix M3(3, 4);
  S21Matrix M4(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M3.SetValue(i, j, -1);
    }
  }
  M4 = M1 - M2;
  ASSERT_EQ(M4.EqMatrix(M3), 1);
}

TEST(SubMatrix, test3) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 4);
  S21Matrix M3(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M3.SetValue(i, j, -1);
    }
  }
  M1 -= M2;
  ASSERT_EQ(M1.EqMatrix(M3), 1);
}

TEST(SubMatrix, test4) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 5);
  int err = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  try {
    M1 -= M2;
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(MulMatrix, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  S21Matrix C(3, 3);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 1);
  B.SetValue(0, 1, -1);
  B.SetValue(0, 2, 1);
  B.SetValue(1, 0, 2);
  B.SetValue(1, 1, 3);
  B.SetValue(1, 2, 4);
  C.SetValue(0, 0, 9);
  C.SetValue(0, 1, 11);
  C.SetValue(0, 2, 17);
  C.SetValue(1, 0, 12);
  C.SetValue(1, 1, 13);
  C.SetValue(1, 2, 22);
  C.SetValue(2, 0, 15);
  C.SetValue(2, 1, 15);
  C.SetValue(2, 2, 27);
  A.MulMatrix(B);
  ASSERT_EQ(A.EqMatrix(C), 1);
}

TEST(MulMatrix, test2) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  S21Matrix C(3, 3);
  S21Matrix D(3, 3);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 1);
  B.SetValue(0, 1, -1);
  B.SetValue(0, 2, 1);
  B.SetValue(1, 0, 2);
  B.SetValue(1, 1, 3);
  B.SetValue(1, 2, 4);
  C.SetValue(0, 0, 9);
  C.SetValue(0, 1, 11);
  C.SetValue(0, 2, 17);
  C.SetValue(1, 0, 12);
  C.SetValue(1, 1, 13);
  C.SetValue(1, 2, 22);
  C.SetValue(2, 0, 15);
  C.SetValue(2, 1, 15);
  C.SetValue(2, 2, 27);
  D = A * B;
  ASSERT_EQ(D.EqMatrix(C), 1);
}

TEST(MulMatrix, test3) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  S21Matrix C(3, 3);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 1);
  B.SetValue(0, 1, -1);
  B.SetValue(0, 2, 1);
  B.SetValue(1, 0, 2);
  B.SetValue(1, 1, 3);
  B.SetValue(1, 2, 4);
  C.SetValue(0, 0, 9);
  C.SetValue(0, 1, 11);
  C.SetValue(0, 2, 17);
  C.SetValue(1, 0, 12);
  C.SetValue(1, 1, 13);
  C.SetValue(1, 2, 22);
  C.SetValue(2, 0, 15);
  C.SetValue(2, 1, 15);
  C.SetValue(2, 2, 27);
  A *= B;
  ASSERT_EQ(A.EqMatrix(C), 1);
}

TEST(MulMatrix, test4) {
  S21Matrix M1(3, 4);
  S21Matrix M2(3, 5);
  int err = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
      M2.SetValue(i, j, 4);
    }
  }
  try {
    M1 *= M2;
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(MulNum, test1) {
  S21Matrix A(3, 2);
  double num = 4;
  S21Matrix B(3, 2);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 4);
  B.SetValue(0, 1, 16);
  B.SetValue(1, 0, 8);
  B.SetValue(1, 1, 20);
  B.SetValue(2, 0, 12);
  B.SetValue(2, 1, 24);
  A.MulNumber(num);
  ASSERT_EQ(A.EqMatrix(B), 1);
}

TEST(MulNum, test2) {
  S21Matrix A(3, 2);
  double num = 4;
  S21Matrix B(3, 2);
  S21Matrix C(3, 2);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 4);
  B.SetValue(0, 1, 16);
  B.SetValue(1, 0, 8);
  B.SetValue(1, 1, 20);
  B.SetValue(2, 0, 12);
  B.SetValue(2, 1, 24);
  C = A * num;
  ASSERT_EQ(C.EqMatrix(B), 1);
}

TEST(MulNum, test3) {
  S21Matrix A(3, 2);
  double num = 4;
  S21Matrix B(3, 2);
  S21Matrix C(3, 2);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 4);
  B.SetValue(0, 1, 16);
  B.SetValue(1, 0, 8);
  B.SetValue(1, 1, 20);
  B.SetValue(2, 0, 12);
  B.SetValue(2, 1, 24);
  C = num * A;
  ASSERT_EQ(C.EqMatrix(B), 1);
}

TEST(Determinant, test1) {
  S21Matrix A(3, 3);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 2);
  A.SetValue(0, 2, 3);
  A.SetValue(1, 0, 4);
  A.SetValue(1, 1, 5);
  A.SetValue(1, 2, 6);
  A.SetValue(2, 0, 7);
  A.SetValue(2, 1, 8);
  A.SetValue(2, 2, 9);
  double x = A.Determinant();
  ASSERT_EQ(x, 0);
}

TEST(Determinant, test2) {
  S21Matrix M1(3, 4);
  int err = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      M1.SetValue(i, j, 3);
    }
  }
  try {
    double x = M1.Determinant();
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(Determinant, test3) {
  S21Matrix A;
  A.SetValue(0, 0, 1);
  double x = A.Determinant();
  ASSERT_EQ(x, 1);
}

TEST(Trans, test1) {
  S21Matrix A(3, 2);
  S21Matrix B(2, 3);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 4);
  A.SetValue(1, 0, 2);
  A.SetValue(1, 1, 5);
  A.SetValue(2, 0, 3);
  A.SetValue(2, 1, 6);
  B.SetValue(0, 0, 1);
  B.SetValue(0, 1, 2);
  B.SetValue(0, 2, 3);
  B.SetValue(1, 0, 4);
  B.SetValue(1, 1, 5);
  B.SetValue(1, 2, 6);
  S21Matrix C = A.Transpose();
  ASSERT_EQ(B.EqMatrix(C), 1);
}

TEST(Calc, test1) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 2);
  A.SetValue(0, 2, 3);
  A.SetValue(1, 0, 0);
  A.SetValue(1, 1, 4);
  A.SetValue(1, 2, 2);
  A.SetValue(2, 0, 5);
  A.SetValue(2, 1, 2);
  A.SetValue(2, 2, 1);
  B.SetValue(0, 0, 0);
  B.SetValue(0, 1, 10);
  B.SetValue(0, 2, -20);
  B.SetValue(1, 0, 4);
  B.SetValue(1, 1, -14);
  B.SetValue(1, 2, 8);
  B.SetValue(2, 0, -8);
  B.SetValue(2, 1, -2);
  B.SetValue(2, 2, 4);
  S21Matrix C = A.CalcComplements();
  ASSERT_EQ(B == C, 1);
}

TEST(Calc, test2) {
  S21Matrix A(3, 4);
  int err = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      A.SetValue(i, j, 3);
    }
  }
  try {
    S21Matrix C = A.CalcComplements();
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(Inverse, test1) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.SetValue(0, 0, 2);
  A.SetValue(0, 1, 5);
  A.SetValue(0, 2, 7);
  A.SetValue(1, 0, 6);
  A.SetValue(1, 1, 3);
  A.SetValue(1, 2, 4);
  A.SetValue(2, 0, 5);
  A.SetValue(2, 1, -2);
  A.SetValue(2, 2, -3);
  B.SetValue(0, 0, 1);
  B.SetValue(0, 1, -1);
  B.SetValue(0, 2, 1);
  B.SetValue(1, 0, -38);
  B.SetValue(1, 1, 41);
  B.SetValue(1, 2, -34);
  B.SetValue(2, 0, 27);
  B.SetValue(2, 1, -29);
  B.SetValue(2, 2, 24);
  S21Matrix C = A.InverseMatrix();
  ASSERT_EQ(B == C, 1);
}

TEST(Inverse, test2) {
  S21Matrix A(3, 3);
  int err = 0;
  A.SetValue(0, 0, 1);
  A.SetValue(0, 1, 2);
  A.SetValue(0, 2, 3);
  A.SetValue(1, 0, 4);
  A.SetValue(1, 1, 5);
  A.SetValue(1, 2, 6);
  A.SetValue(2, 0, 7);
  A.SetValue(2, 1, 8);
  A.SetValue(2, 2, 9);
  try {
    S21Matrix C = A.InverseMatrix();
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(index, test1) {
  S21Matrix A(3, 3);
  A.SetValue(0, 0, 2);
  A.SetValue(0, 1, 5);
  A.SetValue(0, 2, 7);
  A.SetValue(1, 0, 6);
  A.SetValue(1, 1, 3);
  A.SetValue(1, 2, 4);
  A.SetValue(2, 0, 5);
  A.SetValue(2, 1, -2);
  A.SetValue(2, 2, -3);
  double x = A(0, 0);
  ASSERT_EQ(x, 2);
}

TEST(index, test2) {
  S21Matrix A(3, 3);
  A.SetValue(0, 0, 2);
  A.SetValue(0, 1, 5);
  A.SetValue(0, 2, 7);
  A.SetValue(1, 0, 6);
  A.SetValue(1, 1, 3);
  A.SetValue(1, 2, 4);
  A.SetValue(2, 0, 5);
  A.SetValue(2, 1, -2);
  A.SetValue(2, 2, -3);
  double x = A.GetValue(1, 1);
  ASSERT_EQ(x, 3);
}

TEST(index, test3) {
  S21Matrix A(3, 3);
  int err = 0;
  A.SetValue(0, 0, 2);
  A.SetValue(0, 1, 5);
  A.SetValue(0, 2, 7);
  A.SetValue(1, 0, 6);
  A.SetValue(1, 1, 3);
  A.SetValue(1, 2, 4);
  A.SetValue(2, 0, 5);
  A.SetValue(2, 1, -2);
  A.SetValue(2, 2, -3);
  try {
    double x = A(4, 4);
  } catch (matrix_error) {
    err = 1;
  }
  ASSERT_EQ(err, 1);
}

TEST(resize, test1) {
  S21Matrix A(3, 3);
  A.SetRows(4);
  double x = A.GetRows();
  ASSERT_EQ(x, 4);
}

TEST(resize, test2) {
  S21Matrix A(3, 3);
  A.SetCols(4);
  double x = A.GetCols();
  ASSERT_EQ(x, 4);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}