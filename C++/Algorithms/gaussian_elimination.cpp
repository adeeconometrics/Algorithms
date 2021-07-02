#include <cmath>
#include <iostream>
#include <vector>

/*
Gaussian Elimination Algorithm:
 - is_row_echelon
 - add_to
 - multiply_to
 - swap_rows
*/
typedef std::vector<std::vector<double>> Matrix;

Matrix initialize(const size_t &size) {
  return {size, std::vector<double>(size + 1, 0)};
}

std::ostream &operator<<(std::ostream &ss, const Matrix &matrix) {
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[0].size(); ++j)
      ss << matrix[i][j] << " ";
    ss << std::endl;
  }
  return ss;
}

size_t row(const Matrix &m) { return m.size(); }

size_t col(const Matrix &m) { return m[0].size(); }

void to_row_echelon(Matrix &matrix) {
  size_t nc{col(matrix)}, nr{row(matrix)};

  for (size_t r = 0; r < nr; ++r) {
    bool all_zeros = true;
    for (size_t c = 0; c < nc; ++c) {
      if (matrix[r][c] != 0) {
        all_zeros = false;
        break;
      }
    }
    if (all_zeros == true) {
      std::swap(matrix[r], matrix[nr]);
      nr -= 1;
    }
  }

  size_t p = 0;
  while (p < nr && p < nc) {
  next_pivot:
    int r = 1;
    while (matrix[p][p] == 0) {
      if (p + r <= nr) {
        p += 1;
        goto next_pivot;
      }
      std::swap(matrix[p], matrix[p + r]);
      r += 1;
    }

    for (size_t r = 1; r < (nr - p); ++r) {
      if (matrix[p + r][p] != 0) {
        int x = -(matrix[p + r][p] / matrix[p][p]);
        for (size_t c = p; c < nc; ++c) {
          matrix[p + r][c] = matrix[p + r][c] * x + matrix[p + r][c];
        }
      }
    }
    p += 1;
  }
}

void back_substitution(Matrix &matrix) {}

int main() {
  Matrix m = {
      {3.0, 2.0, -4.0, 3.0}, {2.0, 3.0, 3.0, 15.0}, {5.0, -3, 1.0, 14.0}};
  to_row_echelon(m);

  //	std::cout << "col size: " << m[0].size() << '\n' << "row size: " <<
  // m.size() << '\n';
  std::cout << m;
}