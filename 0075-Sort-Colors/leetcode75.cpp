//
// Created by Yannie Lee on 2020-09-25.
//


class Solution {
public:
    void sortColors(vector<int>& nums) {

        //[0,i)中保存0  (j,nums.size()]保存2
        //这个k++ 并不是什么时候都有的！！！

        int i = 0, j = nums.size()-1;

        int k = 0;

        while( k <= j){
            if(nums[k] == 2){
                swap(nums[k], nums[j]);
                j --;
            }else if(nums[k] == 0){
                swap(nums[i], nums[k]);
                i ++; k ++;
            } else
                k ++;
        }

        for(int p = 0; p < nums.size(); p ++)
            cout << nums[p] << " ";

        cout << endl;


    }
};
