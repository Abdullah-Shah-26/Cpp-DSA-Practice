#include <bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;

class FreqStack {
public:
  int time;
  priority_queue<T> pq; // [freq, time, val]
  unordered_map<int, int> mp;

  FreqStack() { time = 0; }

  void push(int val) {
    mp[val]++;
    time++;
    pq.push({mp[val], time, val});
  }

  int pop() {
    auto [freq, t, val] = pq.top();
    pq.pop();

    mp[val]--;

    if (mp[val] == 0)
      mp.erase(val);

    return val;
  }
};
