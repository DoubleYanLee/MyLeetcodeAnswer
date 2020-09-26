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

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if(nums.size() <= 0 ) return 0;


        int first = 0, end = nums.size() - 1;
        //first表示当前要判断的元素 end表示其后面的元素都是重复的


        while(first <= end ){ //没有考虑数组长度为1的情况 没有考虑[3,3]这种
            //不能越界了
            if(end >= nums.size() || end < 0) break;
            if(first >= nums.size() || first < 0) break;

            if( nums[first] == val ){

                //不用交换，直接就可以不管了 反正只要长度(这样不行，后面的元素就漏扫描了，还是要交换)
                //题目中除val的元素要求的必须都在 不能没有啊 也就是不能覆盖

                nums[first] = nums[end];
                end --;

            }

            else
                first ++;
        }

        return end + 1;


    }
};


int main() {

    vector<int> nums ={3,3};

    int length = Solution().removeElement(nums, 3);

    cout << length << endl;

}