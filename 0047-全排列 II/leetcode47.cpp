//
// Created by Yannie Lee on 2020-10-08.
//

class Solution {

private:
    vector<vector<int>> result;
    vector<bool> used;

    //这个函数的意义是：检测index处的数字的序列
    void findPermute(vector<int>& nums, int index, vector<int>& saveArray){

        if( index == nums.size()){
            result.emplace_back(saveArray);
            return ;
        }

        for(int i = 0 ; i < nums.size(); i++) {

            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {  //没有访问过 但是和前面的元素是一样的 并且前面元素没访问过
                continue;
            }
            saveArray.push_back(nums[i]);
            used[i] = true;
            findPermute(nums, index + 1, saveArray);
            used[i] = false;
            saveArray.pop_back();


        }


    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        result.clear();
        if(nums.size() == 0) return result;

        sort(nums.begin(), nums.end());

        vector<int> saveArray;
        used = vector<bool>(nums.size(), false);

        findPermute(nums, 0, saveArray);

        return result;

    }
};

