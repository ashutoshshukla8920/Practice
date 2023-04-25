// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;


auto comp = [](const pair<int, int>& f, const pair<int, int>& s){
    if (f.first > s.first) return true;
    if (f.first < s.first) return false;
    if (f.second > s.second) return true;
    return false;
};

int maxNumBoxes(vector<vector<int>> boxes){
  set<pair<int, int>, decltype(comp)> s(comp);
  for (const auto &  box: boxes) {
    s.insert(pair<int, int>{box[0], box[1]});
    s.insert(pair<int, int>{box[1], box[0]});
  }
  int res = 1;
  pair<int, int> prev_box = *(s.begin());
  s.erase(prev_box);
  s.erase({prev_box.second, prev_box.first});
  
  while (s.size() > 0){
    auto it = s.begin();
    pair<int, int> next_box = *it;
    s.erase(it);
    if (next_box.first < prev_box.first) {
      s.erase({next_box.second, next_box.first});
      prev_box = next_box;
      ++res;
    }
  }
  return res;
}

int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    vector<vector<int>> boxes = {{2,2},{3,2},{3,4},{4,3}};
    std::cout<<maxNumBoxes(boxes)<<std::endl;
    return 0;
}
