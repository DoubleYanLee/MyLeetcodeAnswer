//
// Created by Yannie Lee on 2020-09-24.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 0) return 0;

        int k = 0; //在[0,k]中保存新的数组


        int counter = 1;

        for( int i = 1; i < nums.size(); i++){
            if( nums[i] != nums[k] ){

                nums[++k] = nums[i]; //写成过双等号了。。。

                counter = 1;
            }else{
                if( counter < 2 ){

                    nums[++k] = nums[i]; //这里的之前直接写成k++了，没有考虑多个元素占位的情况
                    counter ++;
                }
            }
        }


        return k + 1;

    }
};