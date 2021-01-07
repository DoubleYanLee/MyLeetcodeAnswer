//
// Created by Yannie Lee on 1/4/21.
//



#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    int minOperations(vector<int>& b, vector<int>& c) {
        map<int, int> A;
        for (int i = 0; i < (int)b.size(); ++i) A[b[i]] = i;
        vector<int> a;
        for (auto& x : c) {
            if (A.count(x)) a.push_back(A[x]);
        }
        vector<int> d;
        for (auto& x : a) {
            auto it = lower_bound(d.begin(), d.end(), x);
            if (it == d.end()) {
                d.push_back(x);
            } else {
                *it = x;
            }
        }
        return b.size() - d.size();
    }
};

int main(){

    vector<int> res {5,1,3};
    vector<int> arr {9,4,2,3,4};
    cout << Solution().minOperations( res, arr ) << endl;


    return 0;
}


//最长上升子序列变体
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) { // 最长上升子序列, O(nlogn)
//        int len = 1, n = (int)nums.size();
//        if (n == 0) {
//            return 0;
//        }
//        vector<int> d(n + 1, 0);
//        d[len] = nums[0];
//        for (int i = 1; i < n; ++i) {
//            if (nums[i] > d[len]) {
//                d[++len] = nums[i];
//            } else {
//                int l = 1, r = len, pos = 0;
//                while (l <= r) {
//                    int mid = (l + r) >> 1;
//                    if (d[mid] < nums[i]) {
//                        pos = mid;
//                        l = mid + 1;
//                    } else {
//                        r = mid - 1;
//                    }
//                }
//                d[pos + 1] = nums[i];
//            }
//        }
//        return len;
//    }
//
//    int minOperations(vector<int>& target, vector<int>& arr) {
//        // 「标号」
//        unordered_map<int, int> m;
//        int idx = 0;
//        for (int i = 0; i < target.size(); i++) {
//            m[target[i]] = i;
//        }
//        vector<int> actual;
//        for (int x: arr) {
//            if (m.find(x) != m.end()) {
//                actual.push_back(m[x]);
//            }
//        }
//
//        int lis = lengthOfLIS(actual);
//        return target.size() - lis;
//    }
//};
//
