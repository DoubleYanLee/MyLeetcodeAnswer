//
// Created by Yannie Lee on 2020-10-08.
//


class Solution {

private:
    vector< vector<int> > result;


    void findSubset(vector<int>& nums, int index, vector<int>& save){

        result.emplace_back( save );

        if( index == nums.size() ) return;


        for(int i = index; i < nums.size(); i++){

            save.emplace_back( nums[i] );

            findSubset(nums, i+1, save);
            save.pop_back();


        }

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> p ;

        findSubset( nums, 0, p );

        return result;


    }
};

int main() {

    vector<int> nums = {1,2,3};

    vector<vector<int>> result = Solution().subsets(nums);


    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto iter = it->begin(); iter != it->end(); iter++)
            cout << (*iter) << ",";
        cout << endl;
    }
}
