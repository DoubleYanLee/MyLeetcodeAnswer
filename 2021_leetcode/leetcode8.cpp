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

//有限状态自动机

class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};


//正常操作
class Solution{

public:
    int myAtoi(string str){

        int res = 0; int i = 0; int flag = 1;
        while( str[i] == ' ')
            i ++; //跳过空格

        if( str[i] == '-' )
            flag = -1;
        if( str[i] == '+' || str[i] == '-')
            i ++;

        while( i < str.size() && isdigit(str[i]) ){
            int r = str[i] - '0';
            if( res > INT32_MAX/10 || (res == INT32_MAX/10 && r > 7) )
                return flag > 0 ? INT32_MAX : INT32_MIN;
            res = res * 10 + r;
            i ++;
        }

        return flag > 0 ? res : -res;

    }

};