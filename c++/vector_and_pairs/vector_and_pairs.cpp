#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
/* Author: José Rodolfo (jric2002) */
using namespace std;
/* Declaration */
int main() {
  int k, v;
  vector<pair<int, int>> a;
  a.push_back(make_pair(1, 10));
  a.push_back(make_pair(4, 20));
  a.push_back(make_pair(2, 30));
  a.push_back(make_pair(3, 40));
  a.push_back(make_pair(5, 50));
  sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
    return (a.second < b.second);
  });
  // sort(a.begin(), a.end());
  for (int j = 0; j < 5; j++) {
    cout << a.at(j).first << " -> " << a.at(j).second << endl;
  }
  return 0;
}
/* Definition */