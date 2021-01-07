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

const int MOD = 1e9 + 7;
class Solution {
public:
    int countPairs(vector<int>& a) {

        map<int, int> findmap;

        sort( a.begin(), a.end() );

        for( auto& it : a )
            findmap[it] ++;

        int ret = 0;

        for( const auto &[k, v] : findmap ){
            for( int i = 1; i <= (1 << 21); i *= 2 ){
                if( i < k ) continue;
                int nk = i - k;
                if( nk < k ) continue;  //这里的索引用排序解决了

                if( findmap.find(nk) != findmap.end() ){
                    if( nk != k  ) //这里的索引怎么解决呢  直接比较元素大小
                        ret += 1LL * findmap[nk] * findmap[k] % MOD;
                    else
                        ret += 1LL * v * (v - 1) / 2 % MOD;
                }

                if (ret >= MOD) ret -= MOD;

            }
        }

        return ret;

    }
};


int main(){

    vector<int> res {1,3,5,7,9};
    cout << Solution().countPairs( res ) << endl;

    return 0;
}
