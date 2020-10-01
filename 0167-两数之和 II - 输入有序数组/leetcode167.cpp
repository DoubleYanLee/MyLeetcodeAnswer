//
// Created by Yannie Lee on 2020-10-01.
//

//利用对撞指针做的

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        //从[i,j]这个区间去寻找目标的两个数

        vector<int> result;
        int i = 0, j = numbers.size() - 1;
        while( i < j){
            if( numbers[i] + numbers[j] > target )
                j --;
            else if( numbers[i] + numbers[j] < target )
                i ++;
            else{
                int res[2] = {i + 1, j + 1};
                return vector<int>(res, res+2);
            }
        }

        return result;

    }
};

int main() {

    vector<int> numbers = {2, 7, 11, 15};
    vector<int> result;
    result = Solution().twoSum(numbers, 9);

    vector<int> :: iterator it;
    for(it = result.begin(); it != result.end(); it ++)
        cout << (*it) << " ";

    cout << endl;

    return 0;
}