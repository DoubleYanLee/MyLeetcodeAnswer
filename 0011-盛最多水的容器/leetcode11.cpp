//
// Created by Yannie Lee on 2020-10-01.
//

//暴力解法超时

class Solution {
public:
    int maxArea(vector<int>& height) {

        //先用双重循环解决一下
        int MaxArea = 0;
        for(int i = 0 ; i < height.size() ; i++){
            for(int j = i + 1; j < height.size(); j++ ){
                int Now_area = (j-i) * (height[i] < height[j] ? height[i] : height[j]);
                if( Now_area > MaxArea) MaxArea = Now_area;
            }
        }

        return MaxArea;

    }
};


//值小的指针往内移

class Solution {
public:
    int maxArea(vector<int>& height) {

        if(height.size() <= 1) return -1;
        int i = 0, j = height.size()-1, res = 0;
        while( i < j){
            int h = min(height[i],height[j]);
            res = max(res, h * (j - i));
            if(height[i] < height[j]) i++;
            else j--;
        }

        return res;

    }
};
