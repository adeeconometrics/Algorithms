/**
 * Copyright 2021, Amiana, D.A.D., Cortes, J.K.S., Yapan, A.A. C.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

import java.util.Arrays;

class Equations {
  private double[][] matrix = null; // defaul-value initialization
  private int length = 0;           // defaul-value initialization

  public Equations(double[][] M) {
    this.length = M.length;

    matrix = new double[this.length][M[0].length];
    for (int i = 0; i < this.length; ++i) {
      System.arraycopy(M[i], 0, matrix[i], 0, M[i].length);
    } // for emulating value-semantics and eliminating potential side effects
  }

  /**
   * function that prints out solution of the matrix.
   */
  public void solve() {
    int flag = this.forward_elimination(this.matrix);
    if (flag != -1) {
      System.out.println("matrix is singular");
      if (matrix[flag][matrix[flag].length] == 0) {
        System.out.println(
            "system of equations may have infinitely many solutions.");
      } else {
        System.out.println("system of equations are inconsistent");
      }
      return;
    }
    System.out.println("Solution: " +
                       Arrays.toString(this.back_substitution(this.matrix)));
    return;
  }

  /**
   * helper function for transforming matrix into row-echelon form.
   *
   * @param M - internal representation of the matrix.
   * @returns flag for checking if matrix has an analytic solution or it belongs
   *          to special cases where matix either is singular, may have
   * infinitely many solutions, or the system is inconsistent.
   */
  private int forward_elimination(double[][] M) {
    for (int k = 0; k < this.length; ++k) {
      int i_max = k;
      int v_max = (int)M[i_max][k];

      for (int i = k + 1; i < this.length; ++i) {
        if (Math.abs(M[i][k]) > v_max) {
          v_max = (int)M[i][k];
          i_max = i;
        }
      }

      if (M[k][i_max] == 0)
        return k;
      if (i_max != k)
        this.swap(M, k, i_max);

      for (int i = k + 1; i < this.length; ++i) {
        double f = (M[i][k] / M[k][k]);
        for (int j = k + 1; j <= this.length; ++j) {
          M[i][j] -= M[k][j] * f;
        }
        M[i][k] = 0; // for numerical precision
      }
      this.print(M);
    }
    this.print(M);
    return -1;
  }

  /**
   * helper function for transforming row-echelon to its reduced form.
   *
   * @param M - internal representation of the matrix.
   * @return double[] which represents the solution vector.
   */
  private double[] back_substitution(double[][] M) {
    double[] solution = new double[this.length];
    for (int i = this.length - 1; i >= 0; --i) {
      solution[i] = M[i][this.length];

      for (int j = i + 1; j < this.length; ++j) {
        solution[i] -= M[i][j] * solution[j];
      }
      solution[i] = solution[i] / M[i][i];
    }
    return solution;
  }

  /**
   * helper function for swapping rows -- uses deep copy.
   *
   * @param M - internal representation of the matrix.
   * @param i - row element of the matrix.
   * @param j - row element of the matrix.
   */
  private void swap(double[][] M, int i, int j) {
    for (int k = 0; k <= this.length; ++k) {
      double temp = M[i][k];
      M[i][k] = M[j][k];
      M[j][k] = temp;
    }
  }

  /**
   * helper function to check state of the matrix.
   *
   * @param M - internal representation of the matrix.
   */
  private void print(double M[][]) {
    for (int i = 0; i < this.length; i++, System.out.println())
      for (int j = 0; j <= this.length; j++) {
        System.out.format("%.3f", M[i][j]);
        System.out.print(" ");
      }
    System.out.println();
  }
}

public class GaussianElimination {
  public static void main(String[] args) {
    double mat[][] = {
        {3.0, 2.0, -4.0, 3.0}, {2.0, 3.0, 3.0, 15.0}, {5.0, -3, 1.0, 14.0}};

    Equations eqs = new Equations(mat);
    eqs.solve();
  }
}