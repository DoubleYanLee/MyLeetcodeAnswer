//
// Created by Yannie Lee on 1/5/21.
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

//双指针优化了一下
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        vector< vector<int> > res; //使用双指针可能更简单呀 不用一个计数器

        for( int i = 0; i < s.size(); ++i ){
            int j = i;
            while( i < s.size() && s[j] == s[i] )
                j ++;
            if( j - i >= 3 )
                res.push_back( {i, j-1} );

            i = j - 1;
        }


        return res;

    }
};

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        vector< vector<int> > res;

        int start = 0;  int count = 1;  int n = s.size();
        for( int i = 1; i < n; ++i ){
            if( s[i] == s[i-1] ){
                count ++;
            } else{
                if( count >= 3 )
                    res.push_back( {start, i-1} );
                count = 1;
                start = i;
            }

        }
        if( count >= 3 )
            res.push_back( {start, n-1} );

        return res;

    }
};

int main(){


    vector<int> arr {9,4,2,3,4};
    string s = "abcdddeeeeaabbbcd";
    vector< vector<int> > result = Solution().largeGroupPositions( s );
    for( auto &it : result ){
        for( auto &item : it )
            cout << item << " ";

        cout << endl;
    }

    return 0;
}
