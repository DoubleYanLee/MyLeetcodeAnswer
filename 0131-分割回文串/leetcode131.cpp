//
// Created by Yannie Lee on 2020-10-07.
//




class Solution {

private:

    vector< vector<string> > res;

    bool isplalindrome(string s){
        //使用双指针判断
        int i = 0, j = s.size()-1;
        while( i <= j){
            if(s[i] != s[j]) return false;
            else{
                i++; j--;
            }
        }

        return true;
    }


    //index为切割点
    void findString(string s, int index , vector<string>& cur){

        if( index == s.size() ){
            res.push_back(cur);
            return ;
        }

        for(int i = index; i < s.size(); i++){

            //这里一个元素的装不进去啊 s.substr(index, i); 写成这样就肯定加不进去了
            string curString =  s.substr(index, i-index+1);

            if( isplalindrome( curString ) ){
                cur.push_back( curString );
                findString(s, i+1, cur);
                cur.pop_back(); //回溯一下
            }else{
                continue;
            }
        }


    }
public:
    vector< vector<string> > partition(string s) {

        vector<string> cur;
        findString( s, 0, cur);

        return res;

    }
};










//

//画一下递归树来理解代码走到了递归树的哪里

class Solution {
private:

    vector<vector<int>> res;
    vector<bool> used;

    void generatePermutation( const vector<int>& nums, int index, vector<int>& p){

        if( index == nums.size() ){
            res.push_back(p);
            return;
        }

        for( int i = 0 ; i < nums.size(); i++ )
            if( !used[i] ){
                p.push_back( nums[i] );
                used[i] = true;
                generatePermutation(nums, index+1, p); //循环1
                p.pop_back();
                used[i] = false;
            }

        return ;
    }

public:
    vector<vector<int>> permute( vector<int>& nums) {

        res.clear();
        if( nums.size() == 0)
            return res;

        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation( nums, 0 , p);

        return res;

    }
};
