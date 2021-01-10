//
// Created by Yannie Lee on 1/10/21.
//

//
// Created by Yannie Lee on 1/1/21.
//


#include <iostream>
#include <vector>

#include<set>
#include <numeric>

using namespace std;

//最开始自己的超长代码

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> res;
        int n = nums.size();
        if( n == 0 )  return res;
        else if( n == 1 )
            res.push_back( to_string(nums[0]) );
        else{
            string tmp = to_string(nums[0]);
            for( int i = 1; i < n; i ++ ){
                if( nums[i] != nums[i-1] + 1 ) {
                    if( stoi(tmp) == nums[i-1] )
                        res.push_back(tmp);
                    else
                        res.push_back( tmp + "->" + to_string(nums[i-1]) );

                    tmp = to_string(nums[i]);
                }else{
                    if( i == n-1 )
                        res.push_back(tmp + "->" + to_string(nums[n-1]));
                }
            }

            if( stoi(tmp) == nums[n-1] )
                res.push_back(tmp);


        }


        return  res;

    }
};


//

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        for( int i = 0 ; i < nums.size(); ){
            int j = i++;
            while( i > 0 && i < nums.size() && nums[i] == (nums[i-1] + 1) ) ++ i;
            string intv;
            if( i == j + 1 ) intv += to_string( nums[j] );
            else intv = to_string(nums[j]) + "->" + to_string(nums[i-1]);

            ans.push_back(intv);
        }
        return ans;
    }
};

int main(){


    vector<int> nums {0,1,2,4,5,7};

    vector<string> res = Solution().summaryRanges( nums );

    for( auto it : res )
        cout << it << " " ;

    return 0;
}
