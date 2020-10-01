//
// Created by Yannie Lee on 2020-10-01.
//

//利用二分查找法做的

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

private:
    int BinarySearch(vector<int>& numbers, int l, int r, int target) {

        //在[l,r]之间寻找target

        while( l <= r) {

            int middle = l + (r-l) / 2;

            if (numbers[middle] > target)     r = middle - 1;
            else if(numbers[middle] < target) l = middle + 1;
            else
                return middle;
        }

        return -1;
    }


public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> result;

        for(int i = 0; i < numbers.size(); i++) {

            int findvalue = BinarySearch( numbers, i+1, numbers.size()-1, target-numbers[i] );
            if( findvalue == -1 ) continue;
            else {
                int res[2] = { i + 1, findvalue + 1};
                return vector<int>(res, res+2);
            }

        }

        return result;

    }
};



  int main(){

    vector<int> numbers = {2, 7, 11, 15};
    vector<int> result;
    result = Solution().twoSum(numbers, 9);

    vector<int> :: iterator it;
    for(it = result.begin(); it != result.end(); it ++)
        cout << (*it) << " ";

    cout << endl;

    return 0;
}