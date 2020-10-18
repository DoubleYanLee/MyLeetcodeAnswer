class Solution {

private:
    vector<bool> row; //判断列
    vector<bool> dig1;
    vector<bool> dig2;

    vector<vector<string>> result;

    //每次轮到在index行来摆放

    void IsPosition( int n, int index, vector< int >& save){ //index从0开始

        if( index == n ){
            vector<string> temp = getString(save, n);
            result.emplace_back( temp );
            return ;
        }

        for(int i = 0 ; i < n; i ++){
            //将元素摆在index行i列
            if( !row[i] && !dig1[index + i] && !dig2[ index - i + n - 1 ] ){
                save.push_back(i);

                row[i] = true;
                dig1[index+i] = true;
                dig2[index-i+n-1] = true;

                IsPosition(n, index + 1, save);

                row[i] = false;
                dig1[index+i] = false;
                dig2[index-i+n-1] = false;

                save.pop_back();
            }
        }

        return;

    }

    vector<string> getString(vector< int >& save, int n){  //save中存的是啥

        assert(save.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i = 0 ; i < n ; i ++)
            board[i][save[i]] = 'Q';
        return board;

    }

public:
    vector<vector<string>> solveNQueens(int n) {

        row = vector<bool>(n);
        dig1 = vector<bool>( 2 * n - 1 );  //左边的对角线
        dig2 = vector<bool>( 2 * n - 1 ); // 右边的对角线
        vector< int > save;

        IsPosition(n, 0, save);

        return result;
    }

};