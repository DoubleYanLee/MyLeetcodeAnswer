//
// Created by Yannie Lee on 2020-10-18.
//

//动态规划


class Solution {
private:
    int maxThree(int i, int j, int k){
        return max( i, max(j, k) );
    }

public:
    int integerBreak(int n) {

        vector<int>memo(n+1,-1);

        memo[1] = 1;

        for(int i = 1; i <= n ; i ++){
            //求memo[i] memo[i]保存了正整数i的最大乘积
            for(int j = 1; j < i; j ++){
                memo[i] = maxThree( memo[i], j * (i-j), j * memo[i-j] );
            }
        }
        return memo[n];
    }
};


//记忆化搜索
class Solution {

private:

    vector<int> memo;

    int maxThree(int i, int j, int k){
        return max( i, max(j, k) );
    }

    //求正整数n的最大乘积
    int ProductN(int n){

        if( n == 1) return 1;

        if( memo[n] != -1) return memo[n];

        int res = 0;
        for(int i = 1; i < n; i ++ ){
            res = maxThree(res, i * (n - i), i * ProductN(n-i) );
            memo[n] = res;
        }

        return res;
    }

public:
    int integerBreak(int n) {

        memo = vector<int>(n+1,-1);

        return ProductN(n);

    }
};


//递归果然又超时了。。
class Solution {

private:

    int maxThree(int i, int j, int k){
        return max( i, max(j, k) );
    }

    //求正整数n的最大乘积
    int ProductN(int n){

        if( n == 1) return 1;

        int res = 0;
        for(int i = 1; i < n; i ++ )
            res = maxThree(res, i * (n - i), i * ProductN(n-i) );

        return res;
    }

public:
    int integerBreak(int n) {

        return ProductN(n);

    }
};