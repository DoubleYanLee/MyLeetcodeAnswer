//
// Created by Yannie Lee on 2020-09-26.
//


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> nums3;

        int i = 0, j = 0;

        while( i < m && j < n){  //这里不能用 ｜｜
            if( nums1[i] <= nums2[j] ){
                nums3.push_back( nums1[i] );
                i++;
            }else{
                nums3.push_back( nums2[j] );
                j++;
            }

        }

        if(i < m){ //不能用 m > n这样判断，即使有的长度相等，也有可能有没走完的情况
            for(; i < m; i++)
                nums3.push_back(nums1[i]);

        }else if(j < n){
            for(; j < n; j++)
                nums3.push_back(nums2[j]);
        }


        // nums1.assign(nums3.begin(), nums3.end());

        nums1 = nums3;

        for(int p = 0; p < m+n; p++)
            cout << nums1[p] << " ";

        cout << endl;


    }
};

int main() {

    vector<int> nums1 ={1,2,3,0,0,0};
    vector<int> nums2 ={2,5,6};

    Solution().merge(nums1, 3, nums2,3);

}