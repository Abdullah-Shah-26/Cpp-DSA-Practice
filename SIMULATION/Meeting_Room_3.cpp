#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(begin(meetings), end(meetings));

    vector<ll> meetingCnt(n, 0), endTime(n, 0);

    for (auto it : meetings) {
      int st = it[0];
      int end = it[1];
      ll duration = end - st;

      int free = -1;

      for (int i = 0; i < n; i++) {
        if (endTime[i] <= st) {
          free = i;
          break;
        }
      }

      if (free != -1) {
        endTime[free] = end;
        meetingCnt[free]++;
      } else {
        int earlyRoom = 0;
        ll time = endTime[0];

        for (int i = 1; i < n; i++) {
          if (endTime[i] < time) {
            time = endTime[i];
            earlyRoom = i;
          }
        }

        endTime[earlyRoom] = time + duration;
        meetingCnt[earlyRoom]++;
      }
    }

    int maxCnt = *max_element(begin(meetingCnt), end(meetingCnt));

    for (int i = 0; i < n; i++) {
      if (maxCnt == meetingCnt[i]) {
        return i;
      }
    }

    return -1;
  }
};

class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(begin(meetings), end(meetings));

    vector<ll> meetingCnt(n, 0);
    priority_queue<int, vector<int>, greater<int>> freeRooms;
    priority_queue<P, vector<P>, greater<P>> busyRooms;

    for (int i = 0; i < n; i++)
      freeRooms.push(i);

    for (auto it : meetings) {
      int st = it[0];
      int end = it[1];
      ll duration = end - st;

      int free = -1;

      while (!busyRooms.empty() && busyRooms.top().first <= st) {
        freeRooms.push(busyRooms.top().second);
        busyRooms.pop();
      }

      if (!freeRooms.empty()) {
        int room = freeRooms.top();
        freeRooms.pop();

        busyRooms.push({end, room});
        meetingCnt[room]++;
      } else {
        auto [time, room] = busyRooms.top();
        busyRooms.pop();

        busyRooms.push({time + duration, room});
        meetingCnt[room]++;
      }
    }

    int maxCnt = *max_element(begin(meetingCnt), end(meetingCnt));

    for (int i = 0; i < n; i++) {
      if (maxCnt == meetingCnt[i]) {
        return i;
      }
    }

    return -1;
  }
};