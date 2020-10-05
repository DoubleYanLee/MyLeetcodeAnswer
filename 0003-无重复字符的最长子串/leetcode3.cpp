//
// Created by Yannie Lee on 2020-10-04.
//

//这道题的几个思考失误点
//1。 自己的i和j定义不明确，滑动的窗口一直很模糊
//2。对于辅助的索引数组设置有误。在移动的时候，i不必一下子就移动过去，并把沿途的
//所有元素索引都进行改变  可以每一轮每一轮的移动，这样就不用记录元素在原来数组中的下标了
//3。res计算的位置值得自己思考

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //在[i,j]中寻找字串
        int i = 0, j = -1; //这样都不用判断空字符串了
        vector<int> freq (256,0); //频率数组  为啥122不可以呢？？
        int MaxLength = 0;


        while( i < s.size() ){ //用i < s.size() 有一点点奇怪
            //如果用j 这里-1被隐式转换成无符号类型uint

            if( (j + 1) < s.size() && freq[ s[j + 1] ] == 0 )
                freq[ s[ ++ j ] ] ++;
            else
                freq[ s[ i ++ ] ] --;

            MaxLength = max( MaxLength, j-i+1);

        }

        return MaxLength;

    }
};




//自己直到用滑动窗口后，第一次写的垃圾代码。。。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> findarray(26,-1); //数组下标代表元素的ascii码 数组内存的是元素在原来数组中的下标


        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;


        //数组定义不清晰啊 在[i，j] 之间寻找
        int maxlength = 0;

        int i = 0, j = 0;
        while( j < s.size() ){

            int CurEleAscii = s[j] - 97;

            if( findarray[ CurEleAscii ] == -1 ){

                findarray[ CurEleAscii ] = j; //这里怎么是-1了呢

            }else{
                i = findarray[ CurEleAscii ] + 1;  //这里i就一直为1了
                //数组下标在 s[j] - 97 之前的就都要清空  这一步有一点难操作

                //在老师的解答中 每次只管了一个，即i只移动了一步 然后再接着判断来移动i  并不会一次性的将前面都清零

                //res的位置值得自己反复推敲

                for(int k = 0 ; k < 26; k ++){
                    if( findarray[k] <  findarray[CurEleAscii] ) findarray[k] = -1;
                }

            }

            int curlen = j - i + 1 ;
            if(curlen > maxlength)  maxlength = curlen ;
            j ++ ;

        }

        return maxlength;


    }
};

