//
// Created by Yannie Lee on 2020-10-17.
//

//自己第一次写错误的代码
class Solution {

private:
    int times = 0; //表示最后的那一次

public:
    int climbStairs(int n) {

        //递归写法
        if( n == 1 ) {
            return 1;
        }
        if( n == 2 ){
            return 2;
        }

        times += climbStairs(n-1); //这样的话在2那里就截胡了，不过也挺好啊，省了算1了 但是返回的时候这里多算了一个加法
        times += climbStairs(n-2);

        return times;

    }
};


//递归的方法  超出时间限制了
class Solution {

public:
    int climbStairs(int n) {

        //递归写法
        if( n == 1 ) {
            return 1; //这里return的是有几种方法
        }
        if( n == 2 ){
            return 2;
        }

        return climbStairs(n-1) + climbStairs(n-2); //将n-1阶台阶的方法+n-2阶台阶的方法


    }
};

//记忆化搜索的方法

class Solution {

private:
    vector<int> memo ;

    int findMethod( int n ){

        //递归写法
        if( n == 1 ) {
            return 1; //这里return的是有几种方法
        }
        if( n == 2 ){
            return 2;
        }

        if( memo[n] == -1 )
            memo[n] = findMethod(n-1) + findMethod(n-2); //将n-1阶台阶的方法+n-2阶台阶的方法

        return memo[n];

    }

public:


    int climbStairs(int n) {

        memo = vector<int>(n+1, -1);

        return findMethod(n);

    }
};

//动态规划方法

class Solution {

private:
    vector<int> memo ;

    int findMethod( int n ){

        //动态规划方法
        memo[1] = 1;  memo[0] = 1;
        //memo[2] = 2; //这样当n=1的时候 memo[2]就下标越界了

        for(int i = 2; i <= n ; i ++)
            memo[i] = memo[i-1] + memo[i-2];



        return memo[n];

    }

public:


    int climbStairs(int n) {

        memo = vector<int>(n+1, -1);

        return findMethod(n);

    }
};
