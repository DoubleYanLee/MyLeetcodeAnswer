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

//通项公式


//通项公式写法

class Solution {
public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }
};


//矩阵快速幂解法

//递归写法
class Solution {
private:

    vector<vector<int>> matrix_pow( vector<vector<int>>& a, int n ){
        vector<vector<int>> ret{{1,0}, {1,0}}; //如果用一维就是横着的向量了
        while( n > 0 ){
            if( n & 1 )
                ret = matrix_multiply(a, ret);
            n >>= 1;
            a = matrix_multiply(a, a);
        }
        return ret;
    }

    vector< vector<int> > matrix_multiply( vector<vector<int>>& a, vector<vector<int>>& b ){

        vector<vector<int>> c{ {0, 0}, {0, 0} };
        for( int i = 0 ; i < 2; i ++ )
            for( int j = 0 ; j < 2; j ++ )
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];

        return c;

    }

public:
    //求n的斐波那契值
    int fib(int n) {

        if( n < 2 )
            return  n;

        vector< vector<int> > q{{1,1}, {1,0}};
        vector< vector<int> > res = matrix_pow(q, n-1); //这里传n-1 是因为2次方只用乘一次
        return res[1][0];

    }
};


// 动态规划解法
class Solution {
public:
    int fib(int n) {


        if( n == 0 )
            return 0;
        if( n == 1 )
            return 1;

        int pre1 = 1; int pre2 = 0;

        for(int i = 2; i < n ; i ++){

            int tmp = pre1 + pre2;
            pre2 = pre1;
            pre1 = tmp;

        }

        return pre1 + pre2;


    }
};



int main(){



    cout << Solution().fib( 4 ) << endl;



    return 0;
}
