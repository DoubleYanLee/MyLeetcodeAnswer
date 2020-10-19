//
// Created by Yannie Lee on 2020-10-18.
//


//动态规划

class Solution {

public:
    int numSquares(int n) {

        vector<int>memo(n+1, n+1);

        memo[1] = 1; memo[0] = 0;

        for(int i = 2; i <= n ; i ++){
            for(int j = 1; j <= sqrt(i); j++)
                memo[i] = min(memo[i],  1 + memo[i-j*j] );
        }

        return memo[n];

    }
};



//记忆化搜索
class Solution {

private:

    vector<int> memo; //memo[i] 记录的是正整数i其最少的完全平方数
    //寻找正整数n的完全平方数和
    //个数怎么表示呢？
    int findSqrtNum(int n){

        memo[1] = 1;

        if( memo[n] != -1) return memo[n];

        int sqtn = floor(sqrt(n)); //向下取整
        if( sqtn * sqtn == n ) return 1; //设置在这里也有减少循环次数的意思

        int res = INT_MAX; //res要设置在这里  不能设置在外面(这个错好多次了,不然个数就不会变了)
        for( int i = sqtn; i > 0; i --){ //不能用加法，不然就算的次数太多了  这里个数不太会弄啊
            res = min( res, 1 + findSqrtNum( n - i * i) );
            memo[n] = res; //这里是memo[n]不是memo[i]哦
        }

        return res;

    }

public:
    int numSquares(int n) {

        memo = vector<int>(n+1, -1);

        int res = n; //最多都是1的平方组成

        return min(res, findSqrtNum(n) );

    }
};




//递归的方法照例超时
class Solution {

private:

    //寻找正整数n的完全平方数和
    //个数怎么表示呢？
    int findSqrtNum(int n){

        int sqtn = floor(sqrt(n));

        if( n == 1 ) return 1;
        if( sqtn * sqtn == n ) return 1;

        int res = INT_MAX; //res要设置在这里  不能设置在外面(这个错好多次了,不然个数就不会变了)
        for( int i = sqtn; i > 0; i --){ //不能用加法，不然就算的次数太多了  这里个数不太会弄啊
            res = min( res, 1 + findSqrtNum( n - i * i) );
        }

        return res;

    }

public:
    int numSquares(int n) {

        int res = n; //最多都是1的平方组成

        return min(res, findSqrtNum(n) );

    }
};
