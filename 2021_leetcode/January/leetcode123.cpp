//
// Created by Yannie Lee on 1/9/21.
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
public:
    int maxProfit(vector<int>& prices) {

        int fstBuy = 0xc0c0c0c0; int fstSell = 0;
        int secBuy = 0xc0c0c0c0; int secSell = 0;

        for( int p : prices ){

            fstBuy = max( fstBuy, -p );
            fstSell = max( fstSell, fstBuy + p );
            secBuy = max(secBuy, fstSell - p );
            secSell = max(secSell, secBuy + p );

        }
        return secSell > fstSell ? secSell : fstSell ;
    }
};

int main(){

    vector<int> prices{3,3,5,0,0,3,1,4};
    cout << Solution().maxProfit( prices );

    return 0;
}









