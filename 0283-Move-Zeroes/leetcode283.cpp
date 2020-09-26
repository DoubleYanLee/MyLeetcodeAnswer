//
// Created by Yannie Lee on 2020-09-23.
//

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//时间复杂度 o(n)
//空间复杂度 o(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int CurChange = 0, CurNum = 0;
        while( CurNum < nums.size() ){
            if( nums[CurNum] != 0 ) {
                nums[CurChange] = nums[CurNum];
                CurChange++;
            }

            CurNum ++;
        }

        while( CurChange < nums.size() ){
            nums[CurChange] = 0;
            CurChange ++;
        }

    }
};

int main() {

    vector<int> nums ={0,1,0,3,12};

    Solution().moveZeroes(nums);

    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << endl;


}
