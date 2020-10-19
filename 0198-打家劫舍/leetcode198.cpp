//
// Created by Yannie Lee on 2020-10-18.
//


//动态规划
class Solution {


public:
    //偷取[0...index]房间的现金
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0 ) return 0;

        vector<int> memo (nums.size(), -1);

        for(int i = 0; i < n; i++ )
            //每次求解memo[i]
            for(int j = i; j >= 0; j --){
                memo[i] = max(memo[i], nums[j] + (j - 2 >= 0 ? memo[j-2] : 0));
            }
        return memo[n-1];
    }


};




//记忆化搜索的方法
class Solution {

private:

    vector<int> memo;

    //int res = 0; //用memo[i]来存[0...i]房间的最高金额
    //偷取[0...index]房间的现金
    int robMethod(vector<int>& nums, int index){

        //递归终止条件
        if(index < 0) return 0;
        if(memo[index] != -1) return memo[index];

        int res = 0; //res在这里设置

        for(int i = index; i >= 0; i --){
            res = max(res, nums[i] + robMethod(nums,i-2));
            memo[index] = res;
        }

        return res;

    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        memo = vector<int>(n+1, -1);

        return robMethod(nums, n-1);

    }
};



//递归的方法 超时
class Solution {

private:

    //int res = 0;
    //偷取[0...index]房间的现金
    int robMethod(vector<int>& nums, int index){

        //递归终止条件
        if(index < 0) return 0;

        int res = 0; //res在这里设置
        for(int i = index; i >= 0; i --){
            res = max(res, nums[i] + robMethod(nums,i-2));
        }

        return res;

    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        return robMethod(nums, n-1);

    }
};
