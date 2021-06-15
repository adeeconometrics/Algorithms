// closest pair point
#include <cmath>
#include <iostream>

struct Point final {
  int x{0}, y{0};

  explicit Point(int _x, int _y) : x(_x), y(_y) {}
  explicit Point() {}

  float distance(const Point &other) {
    return std::sqrt(
        std::abs(std::pow(x - other.x, 2) + std::pow(y - other.y, 2)));
  }
};

float min_point(Point p[], int n) {}

float min(float a, float b) { return (a < b) ? a : b; }

int main() {
  Point p(2, 3);
  Point q(3, 45);
  std::cout << FLT_MAX;
}
