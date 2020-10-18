//
// Created by Yannie Lee on 2020-10-10.
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
    int m , n;  int result = 0;
    vector<vector<bool>> visited;
    int direction[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

    void findIsland(vector<vector<char>>& grid, int startx, int starty){  //这里最后不能visited回溯 不然就重复了吧

        if( startx >= m || starty >= n || startx < 0 || starty < 0)
            return ;

        if( grid[startx][starty] - '0' == 1){

            if( visited[startx][starty] )
                return ;
            else{
                visited[startx][starty] = true;
                for(int i = 0; i < 4; i++)
                    findIsland( grid, startx+direction[i][0], starty+direction[i][1] );
            }
        }

        return ;
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if( m == 0 ) return 0;
        n = grid[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < m ; i ++){
            for(int j = 0 ; j < n; j ++ ){
                if(grid[i][j] == '1' && !visited[i][j]){
                    findIsland(grid, i, j);
                    result ++;  //什么时候加岛屿？ 这个时候判断，没有被染过色的且不是水域的 岛屿数量就增加
                }

            }
        }

        return result;

    }
};

int main() {

    vector<vector<char>> board = { {'1','1','0','0','0'},
                                   {'1','1','0','0','0'},
                                   {'0','0','1','0','0'},
                                   {'0','0','0','1','1'}
    };

    int result = Solution().numIslands(board);

    cout << result << endl;



}
