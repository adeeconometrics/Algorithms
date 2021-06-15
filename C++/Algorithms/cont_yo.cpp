// recursive yo
#include <iostream>
#include <string>

int count_yo(const std::string &string, int index = 0, int count = 0) {
  if (index == string.size())
    return count;

  std::cout << "{" << index << ", " << index + 1 << "}" << std::endl;
  std::cout << string.substr(index, 2) << '\n';

  if (string.substr(index, 2) == "yo") {
    count += 1;
  }
  index += 1;
  return count_yo(string, index, count);
}

int main() {
  std::string str = "ayoxyoxyoxyo";
  std::cout << count_yo(str);
}
