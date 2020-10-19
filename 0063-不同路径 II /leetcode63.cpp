//
// Created by Yannie Lee on 2020-10-19.
//


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        if( m == 0 ) return 0;
        int n = obstacleGrid[0].size();

        //这一句没考虑到
        if( !n || obstacleGrid[0][0] ) return 0; //一开始就是1

        vector< vector<int> > memo (m, vector<int>(n,0));
        memo[0][0] = 1;

        //分开赋值
        for(int j = 1; j < n; j ++){
            if(obstacleGrid[0][j]) //为障碍的时候
                memo[0][j] = 0;
            else
                memo[0][j] = memo[0][j-1];
        }

        for(int i = 1; i < m; i ++){
            if(obstacleGrid[i][0]) //为障碍的时候
                memo[i][0] = 0;
            else
                memo[i][0] = memo[i-1][0];
        }

        for(int i = 1; i < m; i ++){
            for(int j = 1; j < n; j ++){
                if(obstacleGrid[i][j])
                    memo[i][j] = 0; //证明这条路不能走 也就少了一种可能性
                else
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }

        return memo[m-1][n-1];

    }
};


int main(){

    vector<vector<int>> obstacleGrid = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };

    int result = Solution().uniquePathsWithObstacles( obstacleGrid );

    cout << result << endl;

}