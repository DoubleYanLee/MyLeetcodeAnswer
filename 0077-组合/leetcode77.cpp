//
// Created by Yannie Lee on 2020-10-08.
//


class Solution {

private:

    vector<vector<int>> result;

    void findCombination( int n, int k, int startIndex, vector<int>& nums){

        if( nums.size() == k){
            result.emplace_back( nums );
            return;
        }

        for(int i = startIndex; i <= n; i++ ){

            nums.emplace_back( i ); //这里是i 不是startIndex
            findCombination(n, k, i+1, nums); //这里也是i 不是startIndex
            nums.pop_back();
        }

    }

public:
    vector<vector<int>> combine(int n, int k) {

        result.clear();
        if( n <= 0 || k <= 0 || k > n) //又忘记这个了
            return result;

        vector<int> nums;
        findCombination(n, k, 1, nums);

        return result;
    }
};



int main() {

    vector<vector<int>> result = Solution().combine(4,2);


    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto iter = it->begin(); iter != it->end(); iter++)
            cout << (*iter) << ",";
        cout << endl;
    }
}
