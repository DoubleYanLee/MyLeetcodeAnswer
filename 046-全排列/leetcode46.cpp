//
// Created by Yannie Lee on 2020-10-07.
//


class Solution {

private:
    vector<vector<int>> result;
    vector<bool> used;

    //这个函数的意义是：检测index处的数字的序列
    void findPermute(vector<int>& nums, int index, vector<int>& saveArray){

        if( index == nums.size()){
            result.push_back(saveArray);
            return ;
        }

        for(int i = 0 ; i < nums.size(); i++) {

            if(!used[i]){
                saveArray.push_back(nums[i]);
                used[i] = true;
                findPermute(nums, index + 1, saveArray);
                used[i] = false;
                saveArray.pop_back();
            }

        }


    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        result.clear();
        if(nums.size() == 0) return result;

        vector<int> saveArray;
        used = vector<bool>(nums.size(), false);
       
        findPermute(nums, 0, saveArray);

        return result;

    }
};

int main() {

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = Solution().permute(nums);


    //双重vector的遍历方法 还没写
    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto iter = it->begin(); iter != it->end(); iter++)
            cout << (*iter) << ",";
        cout << endl;
    }
}

//    vector<int> used; //vector<bool> 慎用
//    for(int i = 0; i < 5; i++)
//            used[i] = i; //错误的写法！
//push_back就可以 但是used[i]就不可以  看来无论是bool还是不是bool类型都不可以
//vector<int> a;
//并没有开辟一段存放数据的空间，这时候 a.size() 为0，换个角度，如果一个数组大小为0，必然不能往这个数组里写数据

//    首先vector< bool> 并不是一个通常意义上的vector容器，这个源自于历史遗留问题。
//
//    早在C++98的时候，就有vector< bool>这个类型了，但是因为当时为了考虑到节省空间的想法，所以vector< bool>里面不是一个Byte一个Byte储存的，它是一个bit一个bit储存的！
//
//    因为C++没有直接去给一个bit来操作
//
//    for(int i = 0; i < 5; i++)
//        cout << used[i] << endl;
//
//    return 0;
//}