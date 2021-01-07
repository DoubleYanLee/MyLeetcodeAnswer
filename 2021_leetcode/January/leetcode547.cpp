//
// Created by Yannie Lee on 1/7/21.
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

class Solution {

private:
    int Find( vector<int>& parent, int index ){
        if( parent[index] != index )
            parent[index] = Find( parent, parent[index] );

        return parent[index];
    }

    void Union( vector<int>& parent, int index1, int index2 ){

        parent[Find(parent, index1)] = Find(parent, index2);

    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int provinces = isConnected.size();
        vector<int> parent(provinces);

        for( int i = 0 ; i < provinces; i ++ )
            parent[i] = i;

        for( int i = 0 ; i < provinces; i ++ ){
            for( int j = i  + 1; j < provinces; j ++ ){
                if( isConnected[i][j] == 1 )
                    Union(parent, i, j);
            }
        }

        int circles = 0;
        for( int i = 0 ; i < provinces; i ++ )
            if( parent[i] == i )
                circles ++;

        return circles;
    }
};

int main(){

    vector< vector<int> > isconnected = {{1,1,0},{1,1,0},{0,0,1}};

    cout <<  Solution().findCircleNum( isconnected ) << endl;



    return 0;
}









