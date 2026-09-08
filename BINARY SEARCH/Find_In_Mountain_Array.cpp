#include <bits/stdc++.h>
using namespace std;

class MountainArray {
public:
  int get(int index);
  int length();
};

class Solution {
public:
  int findPeakIdx(MountainArray &mountainArr) {
    int n = mountainArr.length();

    int l = 0, r = n - 1;

    while (l < r) {
      int mid = l + (r - l) / 2;

      if (mid + 1 < n && (mountainArr.get(mid) < mountainArr.get(mid + 1))) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return r;
  }

  int bs(MountainArray &mountainArr, int l, int r, int t) {
    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (mountainArr.get(mid) == t)
        return mid;
      else if (mountainArr.get(mid) > t)
        r = mid - 1;
      else
        l = mid + 1;
    }

    return -1;
  }

  int rbs(MountainArray &mountainArr, int l, int r, int t) {
    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (mountainArr.get(mid) == t)
        return mid;
      else if (mountainArr.get(mid) > t)
        l = mid + 1;
      else
        r = mid - 1;
    }

    return -1;
  }

  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();

    // Peak Index
    int idx = findPeakIdx(mountainArr);

    // 0 -> idx, BS on ascending half
    int resIdx = bs(mountainArr, 0, idx, target);

    if (resIdx != -1)
      return resIdx;

    // idx + 1 -> n - 1, BS on descending half
    resIdx = rbs(mountainArr, idx + 1, n - 1, target);

    return resIdx;
  }
};