//
// Created by Yannie Lee on 2020-10-17.
//

//动态规划

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        for(int i = 1 ; i < n ; i ++){

            //先把两边的求一下
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for(int j = 1 ; j < i ; j ++)
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]); //求中间的
        }

        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};


//记忆化搜索

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0 ; i < n ; i ++)
            go(triangle, n - 1, i, dp);

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }

private:
    int go(const vector<vector<int>>& triangle, int i, int j,
           vector<vector<int>>& dp){

        if(dp[i][j] != -1)  //记忆化搜索
            return dp[i][j];

        if(i == 0) //第一个元素
            return dp[i][j] = triangle[i][j];

        if(j == 0)
            return dp[i][j] = triangle[i][j] + go(triangle, i - 1, 0, dp);

        if(j == i) //和j==0一样处理最边上的两个数字
            return dp[i][j] = triangle[i][j] + go(triangle, i - 1, i - 1, dp);

        return dp[i][j] = triangle[i][j] + min(go(triangle, i - 1, j - 1, dp),
                                               go(triangle, i - 1, j, dp));
    }
};



//递归写法（用了一下回溯法）  超出时间限制了
class Solution {

private:
    vector<int> save; //如何保存多条路径  然后计算每一个路径的长度
    int MinEle = INT_MAX;
    int m, n ;

    //判断第index行 j代表上一行元素的纵坐标
    void findMinMethod(vector<vector<int>>& triangle, int index, int j){

        if(index == m) {
            MinEle = min( MinEle, accumulate(save.begin(), save.end(), 0) );
            return  ;
        }

        for(int i = 0; i < n; i ++)
            if( i == j || i == j + 1){
                save.push_back(triangle[index][i]);
                findMinMethod(triangle, index + 1, i);
                save.pop_back();
            }

        return ;

    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {

        save.clear();
        save.push_back(triangle[0][0]);

        m = triangle.size();
        n = triangle[m-1].size();

        findMinMethod( triangle, 1, 0 );

        return MinEle;

    }
};