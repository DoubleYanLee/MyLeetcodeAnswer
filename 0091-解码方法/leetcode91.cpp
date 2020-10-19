//
// Created by Yannie Lee on 2020-10-18.
//

//动态规划

class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        if( n == 0 ) return 0;

        vector<int> memo(n, 0); //memo[i]来记录以i为终止下标所能解析的字母数量
        //不能用-1初始化了，这样会影响后面的值

        //又有点像青蛙跳台阶

        if(s[0] - '0' == 0 ) return 0;
        memo[0] = 1;

        //不知道怎么判断每一次出现的0
        for(int i = 1; i < n; i ++){
            if( s[i] != '0' )
                memo[i] = memo[i-1];  //在这里就先算第一个了
            if( s[i-1] != '0' && s.substr(i-1, 2) <= "26" )
                memo[i] += ( i-2 >= 0 ? memo[i-2] : 1);

        }

        return memo[n-1];

    }
};



//记忆化搜索
class Solution {

private:

    int n;
    vector<int> memo; //用memo[i]来存储s[0...i] 这个字符串的解码数量

    //求s[0...index]的字符串解码数量  怎么来记录个数呢  这个递归卡在如何取一个 如何取两个了
    //这不跟🐸蹦台阶是一样的吗。。。 就是不知道怎样对分别蹦的元素进行判断（真是改一点就不会了。。）
    int findDecodingNum(string s, int index){


        if(s[index] - '0' == 0 ) return 0;
        if(index >= n ) return 1; //大于也返回1，是因为前面取两个字符串的时候那一个1没有加
        //不能为 index >= n-1 的时候就返回 因为这样取一个字符串的就也少加了一个1

        if(memo[index] != -1) return memo[index];

        int res = findDecodingNum(s,index+1);
        if( index + 1 < n && s.substr(index, 2)  <= "26" ){
            res += findDecodingNum(s, index + 2);
            memo[index] = res;
        }

        return res;
    }

public:
    int numDecodings(string s) {

        n = s.size();
        memo = vector<int>(n+1, -1);

        return findDecodingNum(s,0);

    }
};



//递归超时。。。
class Solution {

private:

    int n;

    //求s[index...n-1]的字符串解码数量  怎么来记录个数呢  这个递归卡在如何取一个 如何取两个了
    //这不跟🐸蹦台阶是一样的吗。。。 就是不知道怎样对分别蹦的元素进行判断（真是改一点就不会了。。）
    int findDecodingNum(string s, int index){


        if(s[index] - '0' == 0 ) return 0;
        if(index >= n ) return 1; //大于也返回1，是因为前面取两个字符串的时候那一个1没有加
        //不能为 index >= n-1 的时候就返回 因为这样取一个字符串的就也少加了一个1

        int res = findDecodingNum(s,index+1);
        if( index + 1 < n && s.substr(index, 2)  <= "26" )
            res += findDecodingNum(s, index + 2);

        return res;
    }

public:
    int numDecodings(string s) {

        n = s.size();

        return findDecodingNum(s,0);

    }
};

