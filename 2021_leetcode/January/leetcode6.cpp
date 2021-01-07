//
// Created by Yannie Lee on 1/1/21.
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

//好厉害呀 有一种回溯的思想在里面

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};




// 不知道为什么过不了

class Solution {
public:
    string convert(string s, int numRows) {

        int num = s.size(); string res = "";
        int less =  num % (numRows*2-2); int tmp = (num / (numRows*2-2) )*2;
        int numcolumn = (less == 0) ? tmp : tmp+1;

        vector< vector<char> > save( numRows, vector<char>(numcolumn, ' ') );

        bool zRow = false; int k = 0;

        for( int i = 0 ; i < numcolumn; i ++){ //按行来排列
            for( int j = 0; j < numRows; j++ ){

                if( (j == 0 || j == numRows-1) && zRow )
                    continue;
                else if( zRow ){
                    save[numRows-j-1][i] = s[k++];
                }else
                    save[j][i] = s[k++];
            }
            zRow = !zRow ;

        }

        for( auto it : save ){
            for( auto item : it ){
                if( item != ' ' )
                    res += item;
            }
        }

        return res;


    }
};

int main(){

    string s = "PAYPALISHIRING";

    cout << Solution(). convert(s, 3) << endl;


    return 0;
}

