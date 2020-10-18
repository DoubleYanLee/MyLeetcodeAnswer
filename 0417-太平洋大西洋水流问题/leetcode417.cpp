//
// Created by Yannie Lee on 2020-10-15.
//


//
// Created by Yannie Lee on 2020-10-14.
//


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <list>


using namespace std;

class Solution {

private:
    // vector< vector<bool> > visited;  //但是这样的话就没法在外部访问了

    vector< vector<int> > result;
    vector< vector<bool> > pacific, atlantic;

    int m,n;

    int direction [4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }


    void FindPoint( vector<vector<int>>& matrix, vector<vector<bool>>& visited, int startx, int starty ){

        //递归到底的情况 如何保存答案呢?

        visited[startx][starty] = true;

        for(int i = 0; i < 4; i ++ ){

            int nextx = startx + direction[i][0];
            int nexty = starty + direction[i][1];

            if( inArea(nextx, nexty) &&  matrix[nextx][nexty] >= matrix[startx][starty]
                && !visited[nextx][nexty] ) //判断是否在边界内要放在最前面

                FindPoint( matrix, visited, nextx, nexty);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        m = matrix.size();
        result.clear();
        if( m == 0 ) return result;
        n = matrix[0].size();

        pacific = vector< vector<bool> > ( m, vector<bool>(n, false));
        atlantic = vector< vector<bool> > ( m, vector<bool>(n, false));

        for(int i = 0 ; i < m; i ++){
            FindPoint( matrix, pacific, i, 0);
            FindPoint( matrix, atlantic, i, n - 1);
        }


        for(int j = 0 ; j < n; j ++){
            FindPoint( matrix, pacific, 0, j);
            FindPoint( matrix, atlantic, m - 1, j);
        }


        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vector<int> temp; temp.push_back(i); temp.push_back(j);
                    result.push_back (temp);
                }
            }
        }

        return result;
    }
};

int main(){


    vector<vector<int>> matrix = {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
    };

    vector< vector<int> > result;

    result =  Solution().pacificAtlantic( matrix );

    for(int i = 0 ; i < result.size() ; i ++ ){
        cout << "[" << result[i][0] << "," << result[i][1] << "]" << endl;
    }

    cout << endl;

}