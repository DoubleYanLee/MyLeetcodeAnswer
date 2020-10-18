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
public:
    void solveSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> row(9, vector<bool>(10, false)); //这里必须为10才能AC过去，为9就不能AC
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> block(9, vector<bool>(10, false)); //记录某 3x3 宫格内，某位数字是否已经被摆放

        //先都将数独中有的元素标记一下
        for(int i = 0; i < 9; i ++)
            for(int j = 0; j < 9; j ++)
                if(board[i][j] != '.'){
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    block[i / 3 * 3 + j / 3][board[i][j] - '0'] = true;
                }

        for(int i = 0; i < 81; i ++)
            if(board[i / 9][i % 9] == '.'){
                if(dfs(board, i, row, col, block))
                    return;
            }
    }

private:
    bool dfs(vector<vector<char>>& board, int pos,
             vector<vector<bool>>& row, vector<vector<bool>>& col,
             vector<vector<bool>>& block){

        //递归到底的情况
        if(pos == 81)
            return true;

        int next = pos + 1;
        for(; next < 81; next ++)
            if(board[next / 9][next % 9] == '.')
                break;

        int x = pos / 9, y = pos % 9;
        for(int i = 1; i <= 9; i ++)
            if(!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i]){
                row[x][i] = true;
                col[y][i] = true;
                block[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = '0' + i;

                if(dfs(board, next, row, col, block))
                    return true;

                //状态返回
                row[x][i] = false;
                col[y][i] = false;
                block[x / 3 * 3 + y / 3][i] = false;
                board[x][y] = '.';
            }
        return false;
    }
};



int main() {


    vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };


    Solution().solveSudoku( board );

    for( auto it = board.begin(); it != board.end(); it++ ){
        for( auto iter = it->begin(); iter != it->end(); iter++)
            cout << (*iter) << " ";
        cout << endl;
    }


    return 0;


}


