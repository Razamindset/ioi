#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <vector>

unsigned int countBits(unsigned long long n) {
  return std::bitset<32>(n).count();
}

int square_digits(int num) {
  std::string result = "";

  std::string temp = std::to_string(num);

  for (char ch : temp) {
    int dg = ch - '0';  // will convert to number
    result += std::to_string(dg * dg);
  }

  return std::stoi(result);
}

std::vector<int> tribonacci(std::vector<int> signature, int n) {
  if (n == 0) {
    return {};
  }
  if (n == 1) {
    return {signature[0]};
  }
  if (n == 2) {
    return {signature[0], signature[1]};
  }
  if (n == 2) {
    return {signature[0], signature[1], signature[2]};
  }

  std::vector<int> result;

  // we ned to sum last 3 elements to get the tribonacci sequence
  int a = signature[0], b = signature[1], c = signature[2];

  result.push_back(a);
  result.push_back(b);
  result.push_back(c);

  for (int i = 3; i < n; i++) {
    int next = a + b + c;
    result.push_back(next);

    // update a b and c
    a = b;
    b = c;
    c = next;
  }

  return result;
}

// std::vector<int> tribonacci(std::vector<int> signature, int n) {
//   if (n < 3) {
//     signature.resize(n);
//   }
//   for (unsigned int i = 3; i < n; i++) {
//     signature.push_back(signature[i - 3] + signature[i - 2] + signature[i -
//     1]);
//   }
//   return signature;
// }

// float find_uniq(const std::vector<float> &v) {
//   std::unordered_map<int || float> hashMap;

//   for (auto num : v) {
//     // If the number is already in the set, remove it
//     if (uniqueElements.count(num)) {
//       uniqueElements.erase(num);
//     } else {
//       uniqueElements.insert(num);  // Otherwise, add it
//     }
//   }

//   // The set should contain exactly one unique number
//   return *uniqueElements.begin();
// }