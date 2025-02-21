#include <cmath>
#include <string>
#include <vector>
using namespace std;

vector<unsigned int> sumDigPow(unsigned int a, unsigned int b) {
  vector<unsigned int> final;
  for (unsigned int i = a; i <= b; i++) {
    string strNum = to_string(i);
    int res = 0;

    for (unsigned int j = 0; j < strNum.size(); j++) {
      int n = strNum[j] - '0';
      res += pow(n, j + 1);
    }

    if (res == i) final.push_back(i);
  }

  return final;
}
