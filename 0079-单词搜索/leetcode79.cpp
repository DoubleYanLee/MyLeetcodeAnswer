//
// Created by Yannie Lee on 2020-10-09.
//



class Solution {

    //搜索的顺序为：上右下左
    vector< vector<bool> > visited;
    vector<char> save;
    int direction[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    int m = 0,n = 0;

private:

    bool findWord( vector<vector<char>>& board, string word, int index, int startx, int starty, vector<char>& save ){

        if( startx >= m || starty >= n || startx < 0 || starty < 0 || visited[startx][starty] || index >= word.size() )
            return false;     //数组越界则退出循环
        if( board[startx][starty] == word[index]){
            save.emplace_back( word[index] );
            visited[startx][starty] = true;
        }else
            return false;

        if( save.size() == word.size() ) //原来错误出现在这里 每一次回溯save也要复原 不然在这里判断的时候就会出错
            return true;  //这里也可以用index与word的size大小进行比较
        else{
            for( int i = 0 ; i < 4; i ++ ){

                if( findWord(board, word, index+1, startx+direction[i][0], starty+direction[i][1], save) )
                    return true;
            }
            //因为要将这个元素的上下左右都遍历后才能将它回溯回去
            visited[startx][starty] = false;
            save.pop_back();
        }

        return false;

    }


public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        assert( m > 0 );
        n = board[0].size();

        visited = vector< vector<bool> > ( board.size(), vector<bool>(board[0].size(), false) );

        for( int i = 0; i < board.size(); i ++ ){
            for( int j = 0; j < board[0].size(); j ++)
                if( findWord( board, word, 0, i, j, save ) )
                    return true;
        }

        return false;

    }
};

int main() {

    vector<vector<char>> board = { {'A','B','C','E'},
                                   {'S','F','C','S'},
                                   {'A','D','E','E'} };
    string word = "ABCB";

    bool result = Solution().exist(board, word);

    cout << result << endl;



}
