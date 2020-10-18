//
// Created by Yannie Lee on 2020-10-17.
//

// 动态规划写法

class Solution {

public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        if( m == 0) return 0;
        int n = grid[0].size();

        //不另开辟一个空间  还是在原空间上存储
        // vector< vector<int> > save;


        for( int j = 1; j < n; j++ )
            grid[0][j] += grid[0][j - 1];

        for( int i = 1; i < m; i++ )
            grid[i][0] += grid[i-1][0]; //不能把这两个写在一起，因为不一定是方阵

        for(int i = 1; i < m; i++){  //这里的搞不好啊
            for(int j = 1; j < n ; j++)
                grid[i][j] += min( grid[i-1][j], grid[i][j-1] );
        }

        return grid[m-1][n-1];

    }

};


//自己写的记忆化搜索解法

class Solution {

private:

    int m, n;

    vector<vector<int>> save;


    int FindMinSum( vector<vector<int>>& grid, int i, int j){


        if( save[i][j] != -1 ) return save[i][j];

        if( i == m -1 && j == n -1 ) return save[i][j] = grid[i][j];
        else if( i == m -1 )
            return save[i][j] = grid[i][j] + FindMinSum( grid, i, j+1);
        else if( j == n - 1)
            return save[i][j] = grid[i][j] + FindMinSum( grid, i+1, j);
        else
            return  save[i][j] = grid[i][j] + min( save[i][j+1], save[i+1][j] );



    }

public:
    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size();
        if( m == 0) return 0;
        n = grid[0].size();

        save.clear();
        save = vector<vector<int>>(m, vector<int>(n, -1));


        for(int i = m-1; i >= 0 ; i --){
            for(int j = n-1; j >= 0; j --)
                FindMinSum(grid, i, j);
        }

        return save[0][0];



    }
};


//果然递归又超时了。。。
class Solution {

private:

    int m, n;
    int MinSum = INT_MAX;
    vector<int> save;

    void FindMinSum( vector<vector<int>>& grid, int i, int j){

        if( i == m -1 && j == n -1 ) {
            MinSum = min( MinSum, accumulate(save.begin(), save.end(), 0) );
            return ;
        }

        if( i > m-1 || j > n-1 ) return ;

        save.push_back(grid[i][j]);


        FindMinSum( grid, i, j+1 ); //向右走

        FindMinSum( grid, i+1, j ); //向下走

        save.pop_back();

    }

public:
    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size();
        if( m == 0) return 0;
        n = grid[0].size();

        save.clear();
        save.push_back(grid[m-1][n-1]);

        FindMinSum( grid, 0, 0);

        return MinSum;

    }
};

