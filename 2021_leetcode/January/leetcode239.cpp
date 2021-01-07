//
// Created by Yannie Lee on 1/2/21.
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

using namespace std;


//判断某数乘10是否溢出，就将该数与INT_MAX除以10进行比较
//一般判断的条件
//if( res > INT_MAX /10 || res == INT_MAX / 10 && r > 7 )


class Solution{

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums. size();
        priority_queue< pair<int,int> > q;
        for( int i = 0; i < k ; i++ )
            q.emplace(make_pair(nums[i], i) );

        vector<int> ans = {q.top().first};
        for( int i = k; i < n ; i ++ ){
            q.emplace( make_pair(nums[i], i) );
            while( q.top().second <= i-k )
                q.pop();
            ans.push_back( q.top().first );
        }

        return ans;

    }

};



int main(){

    vector<int> num {1,3,-1,-3,5,3,6,7};

    vector<int> res =  Solution(). maxSlidingWindow(num,3) ;

    for( auto it : res )
        cout << it << " ";


    return 0;
}







