//
// Created by Yannie Lee on 2020-10-08.
//


class Solution {

private:
    vector< vector<int> > result;
    vector<bool> used;


    void findSubset(vector<int>& nums, int index, vector<int>& save){

        result.emplace_back( save );

        if( index == nums.size() ) return;


        for(int i = index; i < nums.size(); i++){

            if(used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1]) ) continue;

            save.emplace_back( nums[i] );
            used[i] = true;

            findSubset(nums, i+1, save);
            save.pop_back();
            used[i] = false;


        }

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> p ;

        used = vector<bool>(nums.size(), false);
        sort( nums.begin(), nums.end() );

        findSubset( nums, 0, p );

        return result;


    }
};

int main() {

    vector<int> nums = {1,2,2};

    vector<vector<int>> result = Solution().subsetsWithDup(nums);


    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto iter = it->begin(); iter != it->end(); iter++)
            cout << (*iter) << ",";
        cout << endl;
    }
}
