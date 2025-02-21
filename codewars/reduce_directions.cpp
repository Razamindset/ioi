#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class DirReduction {
 public:
  static vector<string> dirReduc(const vector<string> &arr);
};

vector<string> DirReduction::dirReduc(const vector<string> &arr) {
  // we can use a stack for this problem and keep checking the entry aginst the
  // top element if they are opposite we can cancel them out. Else we can push
  // them in the stack
  stack<string> st;
  unordered_map<string, string> opposite = {{"NORTH", "SOUTH"},
                                            {"SOUTH", "NORTH"},
                                            {"EAST", "WEST"},
                                            {"WEST", "EAST"}};
  for (const string &dir : arr) {
    if (!st.empty() && st.top() == opposite[dir]) {
      st.pop();
    } else {
      st.push(dir);
    }
  }

  // At this point we will have the stack with our answer directions

  vector<string> result;

  while (!st.empty())  // loop until something remains
  {
    // Instert the data from teh stack into the array
    result.insert(result.begin(), st.top());
    st.pop();
  }

  return result;
}

int main() {
  DirReduction reducer;

  vector<string> reduced = reducer.dirReduc(
      {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"});

  for (auto dir : reduced) {
    cout << dir << endl;
  }
}