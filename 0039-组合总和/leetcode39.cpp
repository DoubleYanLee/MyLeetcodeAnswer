//
// Created by Yannie Lee on 2020-10-08.
//

class Solution {

private:

    vector<vector<int>> result;

    void findCombination( vector<int>& candidates, int target, int sum,int index, vector<int>& p){

        if(sum == target){
            result.emplace_back(p);
            return ;
        }

        if(sum > target || (target-sum) < candidates[0] ) return;

        //还要不能包含重复的组合  如何剪枝呢

        for( int i = index ; i < candidates.size(); i ++){  //每一次只从当前的元素之后开始搜索

            p.emplace_back( candidates[i] );
            findCombination( candidates, target, sum+candidates[i], i, p );
            p.pop_back();

        }


    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int sum = 0;

        vector<int> p;

        result.clear();

        sort( candidates.begin(), candidates.end() );
        // 剪枝操作只能想到找到最小元素 然后每一轮如果所剩sum比最小元素都小 则提前终止
        //但是这里剪枝的排序操作使得时间复杂度变得更高

        findCombination( candidates, target, sum, 0, p);

        return result;

    }
};

