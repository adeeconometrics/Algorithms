#include <cmath>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrix;

std::ostream &operator<<(std::ostream &ss, const Matrix &m) {
  for (size_t i = 0; i < m.size(); ++i) {
    for (size_t j = 0; j < m[i].size(); ++j) {
      ss << m[i][j] << " ";
    }
    ss << std::endl;
  }
  return ss;
}

class Equations {
  Matrix matrix;

  int forward_elimination(Matrix &M) {
    for (int k = 0; k < M.size(); ++k) {
      int i_max = k;
      int v_max = (int)M[i_max][k];

      for (int i = k + 1; i < M.size(); ++i) {
        if (std::abs(M[i][k]) > v_max) {
          v_max = (int)M[i][k];
          i_max = i;
        }
      }

      if (M[k][i_max] == 0)
        return k;
      if (i_max != k)
        std::swap(M[i_max], M[k]);

      for (int i = k + 1; i < M.size(); ++i) {
        double f = -(M[i][k] / M[k][k]);
        for (int j = k + 1; j < M.size(); ++j)
          M[i][j] += M[k][j] * f;

        M[i][k] = 0;
      }
    }
    return -1;
  }

  std::vector<double> backward_substitution(Matrix &M) {
    std::vector<double> solution(M.size());
    for (size_t i = M.size() - 1; i >= 0; --i) {
      solution[i] = M[i][M.size()];

      for (size_t j = i + 1; j <= M.size(); ++j) {
        solution[i] -= M[i][j] * solution[j];
      }
      solution[i] = solution[i] / M[i][i];
    }
    return solution;
  }

public:
  Equations(Matrix i_m) : matrix(i_m) {
    matrix.push_back(std::vector<double>(i_m[0].size(), 0));
  };

  std::vector<double> solve() {
    int flag = forward_elimination(matrix);
    if (flag != -1) {
      std::cout << "matrix is singular" << '\n';
      if (matrix[flag][matrix[flag].size()] == 0)
        std::cout << "May have infinitely many solutions." << '\n';
      else
        std::cout << "Inconsistent system." << '\n';
      return {0};
    }

    std::cout << "ended: solve \n";
    return backward_substitution(matrix);
  }
};

std::ostream &operator<<(std::ostream &ss, const std::vector<double> &v) {
  ss << "[";
  for (size_t i = 0; i < v.size(); ++i)
    ss << v[i] << " ";
  return ss << "]";
}

int main() {
  Equations eq({{3, 2, -4, 3}, {2, 3, 3, 15}, {5, -3, 1, 14}});
  std::cout << eq.solve();
}