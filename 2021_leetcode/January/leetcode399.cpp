//
// Created by Yannie Lee on 1/6/21.
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

//并查集的方法

class Solution {

private:
    int findf( vector<int> &f, vector<double>& w, int x ){
        if( f[x] != x ){
            int father = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }

        return f[x];

    }

    void merge( vector<int>& f, vector<double>& w, int x, int y, double val ){

        int fx = findf(f, w, x);
        int fy = findf(f, w, y);
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];

    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        //因为这里是一个无向图 所以两个方向都要考虑到
        int nvars = 0;
        unordered_map<string , int> variables;

        int n = equations.size();

        for( int i = 0 ; i < n ; i ++ ){ //如果节点不存在 也是显示0
            if( variables.find(equations[i][0]) == variables.end() )
                variables[ equations[i][0] ]  = nvars ++;
            if( variables.find(equations[i][1]) == variables.end() )
                variables[ equations[i][1] ] = nvars ++;
        }

        // cout << nvars << endl;

        vector<int> f(nvars);
        vector<double> w(nvars, 1.0);
        for( int i = 0 ; i < nvars; i ++ )
            f[i] = i;

        for( int i = 0; i < n ; i ++ ){
            int va = variables[equations[i][0]];
            int vb = variables[equations[i][1]]; //通过比较是否是同一个元素确定是否有共同父节点
            merge(f, w, va, vb, values[i]);
        }

        vector<double> ret;
        for( const auto& q : queries ){
            double result = -1.0;
            if( variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end() ){
                int ia = variables[q[0]];  int ib = variables[q[1]];
                int fa = findf(f, w, ia);  int fb = findf( f, w, ib);
                if( fa == fb )
                    result = w[ia] / w[ib];
            }

            ret.push_back(result);
        }
        return ret;
    }
};

int main(){

    vector<double> values {1.5,2.5,5.0};
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}} ;
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

    vector< double > result = Solution().calcEquation( equations, values, queries );

    for( auto &it : result ) {
        cout << it << " ";
    }

    return 0;
}
