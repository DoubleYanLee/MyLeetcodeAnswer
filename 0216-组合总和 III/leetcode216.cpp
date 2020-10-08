//
// Created by Yannie Lee on 2020-10-08.
//


class Solution {

private:

    vector<vector<int>> result;

    void findCombination(int k, int n, int index, int sum, vector<int>& p){

        if( p.size() == k ){
            if( sum == n ){
                result.emplace_back( p );
            }

            return ;
        }

        for( int i = index; i <= 9; i++ ){

            if( sum + i > n ) break;

            p.emplace_back( i );

            findCombination(k, n, i+1, sum + i, p);

            p.pop_back();

        }



    }



public:
    vector< vector<int> > combinationSum3(int k, int n) {

        result.clear();
        int sum = 0;

        vector<int> p;
        findCombination(k, n, 1, 0, p);

        return result;


    }
};

int main() {

    vector<vector<int>> result = Solution().combinationSum3(3, 9);


    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto iter = it->begin(); iter != it->end(); iter++)
            cout << (*iter) << ",";
        cout << endl;
    }
}
