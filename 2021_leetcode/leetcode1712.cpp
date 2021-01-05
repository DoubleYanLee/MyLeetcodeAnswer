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

//下面一种解法的二分版本
class Solution {
public:
    int waysToSplit(vector<int>& a) {
        int n = a.size();
        vector<int> v(n + 1, 0);
        // 初始化前缀和数组
        for(int i = 1; i <= n; i++) {
            v[i] = v[i - 1] + a[i - 1];
        }
        // 返回值 ret
        long long ret = 0;
        const int M = 1e9 + 7;

        for(int i = 1; i < n; i++) {
            // 特判
            if(v[i] * 3 > v[n]) break;

            // 第一次二分找右边界
            int l = i + 1, r = n - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(v[n] - v[mid] >= v[mid] - v[i]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // 第二次二分找左边界
            int ll = i + 1, rr = n - 1;
            while(ll <= rr) {
                int mid = (ll + rr) / 2;
                if(v[mid] - v[i] >= v[i]) {
                    rr = mid - 1;
                } else {
                    ll = mid + 1;
                }
            }
            ret += r - ll + 1;
        }
        return ret % M;
    }
};



// 利用c++ STL的解决版本
const int MOD = 1e9 + 7;
typedef long long int64;
class Solution {
public:
    int waysToSplit(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] + a[i]; //前缀和数组

        int ret = 0;
        for (int X = 1; X + 2 <= n; ++X) {
            int Y1 = lower_bound(pre.begin(), pre.end(), 2 * pre[X]) - pre.begin();
            int Y2 = upper_bound(pre.begin(), pre.end(), (pre[n] + pre[X]) / 2) - pre.begin();

            Y1 = max(Y1, X + 1);
            Y2 = min(n, Y2);


            ret += max(0, Y2 - Y1);
            if (ret >= MOD) ret -= MOD;
        }
        return ret;
    }
};

int main(){

    vector<int> res {1,2,2,2,5,0};
    cout << Solution().waysToSplit( res ) << endl;



    return 0;
}
