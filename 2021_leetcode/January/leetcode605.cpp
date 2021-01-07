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

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int FlowerNum = 0;
        for( int i = 0 ; i < flowerbed.size(); i++ ){

            if( flowerbed[i] == 0 ){
                if( (i==0 || flowerbed[i-1] != 1) && (i == flowerbed.size()-1 || flowerbed[i+1] != 1) ){
                    flowerbed[i] = 1;
                    FlowerNum ++;
                }
            }

        }

        return FlowerNum >= n;
    }
};

int main(){

    vector<int> flowerbed = {1,0,0,0,1};

    cout << Solution().canPlaceFlowers(flowerbed, 2) << endl;


    return 0;
}








