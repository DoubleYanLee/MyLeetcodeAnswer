//
// Created by Yannie Lee on 2020-09-24.
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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if( nums.size() ==0 ) return 0;  //这个最开始忘记了

        int k = 0, i = 1; //在[0...k]中保存的是未重复的元素

        while( i < nums.size() ){

            if( nums[i] == nums[k] )
                i ++;
            else{
                k ++;
                nums[k] = nums[i++];
            }

        }

        return k + 1;  //要返回数组的长度  k不是长度，也忘记了

    }
};

int main() {

    vector<int> nums ={0,0,1,1,1,2,2,3,3,4};

    int result = Solution().removeDuplicates(nums);

    cout << result << endl;


}
