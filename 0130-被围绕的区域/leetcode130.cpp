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

    vector< vector<bool> > visited;
    int m, n;

    int direction[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

    //找在边缘的o 将其标记为true 然后将标记为false的o都变成x
    void FindMarginO( vector<vector<char>>& board, int startx, int starty){

        if(startx < 0 || startx >= m || starty < 0 || starty >= n
           || board[startx][starty] == 'X' || visited[startx][starty]) return ;

        if( board[startx][starty] == 'O' ) visited[startx][starty] = true;

        for(int i = 0; i < 4; i ++ ){
            FindMarginO( board, startx + direction[i][0], starty + direction[i][1] );
        }


    }

public:
    void solve(vector<vector<char>>& board) {

        m = board.size();
        if( m == 0) return;
        n = board[0].size();

        visited = vector< vector<bool> >( m, vector<bool>(n,false) ) ;

        for( int i = 0; i < m ; i ++ ){
            for( int j = 0; j < n; j ++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1 )
                    FindMarginO( board, i, j );
            }
        }

        for( int i = 0; i < m ; i ++ ) {
            for (int j = 0; j < n; j++) {

                if( board[i][j] == 'O' && !visited[i][j] )

                    board[i][j] = 'X';
            }

        }
    }
};


int main(){

    vector<vector<char>> board = {
            {'O','O'},
            {'O','O'},

    };

    Solution().solve( board );

    for( int i = 0; i < board.size() ; i ++ ) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}