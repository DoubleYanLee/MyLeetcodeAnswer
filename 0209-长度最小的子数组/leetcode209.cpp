//
// Created by Yannie Lee on 2020-10-04.
//

//vector不能用judge[j] j是变化的 这样赋值吗

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
    int minSubArrayLen(int s, vector<int>& nums) {

        //从[i,j]中寻找符合条件的字数组
        int length = 0, curlen = 0, n = nums.size() ;

        if(n == 0 ) return 0;
        if(n == 1 ){
            if(nums[0] >= s ) return 1;
            else return 0;
        }

        // 上面这个判断 自己之前就没有想到 用到数组的时候一定要想着索引下表是否会越界！！！

        int i = 0 , j = 0;
        int CurSum = nums[0];

        while( j < n && i <= j ){
            if( CurSum >= s ){
                curlen = j - i + 1;
                if( length == 0 || curlen < length ) length = curlen;
                CurSum -= nums[i];
                i ++;
            }else{
                j ++;
                if(j < n)
                    CurSum += nums[j]; //这里不能先加  因为 nums[j]可能越界了！！！
            }

        }

        return length;

    }
};




int main(){


    vector<int> nums = { 10,2,3 };
    int result = Solution().minSubArrayLen(6,nums);

    cout << result << endl;

    return 0;
}



