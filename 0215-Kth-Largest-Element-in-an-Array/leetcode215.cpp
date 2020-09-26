//
// Created by Yannie Lee on 2020-09-25.
//

//这个是不用去重的。。。

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {


        sort(nums.begin(), nums.end());

        return nums[ nums.size()  - k ];
    }

};

//方法二


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {


        return findKthLargest(nums, 0, nums.size() - 1, k);
    }

    //在[l,r]之间寻找第k大个元素
private:
    int findKthLargest( vector<int>& nums, int l, int r, int k ){

        //递归到底的情况
        if( l > r) return -1;

        int MinIndex = nums.size() - k ;// 这里每一次下标是有变化的

        int n = partition( nums, l, r);

        if( n > MinIndex )
            return findKthLargest(nums, 0, n-1, k);
        else if( n < MinIndex)
            return findKthLargest(nums, n+1, nums.size()-1, k);
        else
            return nums[n];


    }

    //返回p使得 [0,p]都小于/等于nums[0], (p,r] 都大于nums[0]

    int partition( vector<int>& nums, int l, int r){


        //(l,j]中保存小于/等于的， (j,i）中保存大于的

        int j = l;

        for( int i = j + 1; i <= r; i++){

            if( nums[i] < nums[l] ){
                swap( nums[i], nums[++j] );
            }

        }

        swap( nums[l], nums[j] );

        return j;
    }

};



int main() {

    vector<int> nums ={3,2,1,5,6,4};

    int result = Solution().findKthLargest(nums, 2);

    cout << result << endl;


}