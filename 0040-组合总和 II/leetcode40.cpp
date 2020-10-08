//
// Created by Yannie Lee on 2020-10-08.
//





class Solution {

private:

    vector<vector<int>> result;
    vector<bool> used;

    //这个函数的意思 每次先判断sum是否等于target  小于就将index处的元素弹入vector中

    void findCombination( vector<int>& candidates, int target, int sum,int index, vector<int>& p){

        if(sum == target){  //这个要放在前面先判断 不然最后一个解会被漏掉
            result.emplace_back(p);
            return ;
        }

        if(index == candidates.size()) return ;


        if( sum > target ) return;


        for( int i = index ; i < candidates.size(); i ++){  //每一次只从当前的元素之后开始搜索

            if(used[i] || (i > 0 && candidates[i] == candidates[i-1] && !used[i-1]) ) continue;

            if( sum + candidates[i] > target ) break; //加一个剪枝算法 运行时间从32ms->4ms

            p.emplace_back( candidates[i] );
            used[i] = true;

            //这里应该有一个剪枝 但是我不会。。
            findCombination( candidates, target, sum+candidates[i], i+1, p );

            used[i] = false;
            p.pop_back();



        }

        return ;

    }

public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {

        int sum = 0;

        vector<int> p;

        result.clear();

        used = vector<bool>( candidates.size(), false );

        sort( candidates.begin(), candidates.end() ); //一定要排序 不然不能去重

        findCombination( candidates, target, sum, 0, p);

        return result;

    }
};

