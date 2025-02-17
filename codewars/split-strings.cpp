#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) {
  std::vector<std::string> result;
  int n = s.size();

  for (int i = 0; i < n; i += 2) {
    if (i + 1 < n) {
      result.push_back(s.substr(i, 2));
    } else {
      result.push_back(s.substr(i, 1) + "_");
    }
  }

  return result;
}