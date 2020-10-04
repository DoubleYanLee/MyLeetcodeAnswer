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

        int MaxArea = 0;
        //在[i,j]中间寻找最大面积
        int i = 0, j =  height.size()-1;

        while( i < j ){
            int CurArea = ( height[i] > height[j] ? height[j] : height[i]) * (j - i);
            if( CurArea > MaxArea ) MaxArea = CurArea;
            height[i] > height[j] ? j-- : i++;
        }

        return MaxArea;

    }
};