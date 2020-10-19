//
// Created by Yannie Lee on 2020-10-19.
//


//直接用动态规划写出来了呀！

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector< vector<int> > memo ( m,vector<int>(n,0) );

        memo[0][0] = 1;

        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if( i == 0 )
                    memo[i][j] = (j-1 >= 0 ? memo[i][j-1] : 1);
                else if( j == 0 )
                    memo[i][j] = (i-1 >= 0 ? memo[i-1][j] : 1);
                else
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }

        return memo[m-1][n-1];

    }
};