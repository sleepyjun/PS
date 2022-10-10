#include <string>
#include <vector>
#include <sstream>
#include <iostream>

std::vector<std::string> split(const std::string& sentence, char delimiter) {
  std::vector<std::string> ret;
  std::stringstream stream(sentence);
  std::string temp;

  while (std::getline(stream, temp, delimiter)) {
    ret.push_back(temp);
  }

  return ret;
}

int main() {
  std::string s = "2013.04.05";
  std::vector<std::string> answer = split(s, '.');

  for (const auto& ans: answer) {
    std::cout << ans << ' ';
  }
}