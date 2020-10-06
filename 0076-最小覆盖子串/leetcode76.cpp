//
// Created by Yannie Lee on 2020-10-06.
//


class Solution {
public:
    string minWindow(string s, string t) {

        if( t.size() > s.size() ) return "";

        string result = "";
        int MinLength = s.size() + 1;
        int count = 0;
        int startIndex = -1;

        vector<int> freq_t (256, 0);
        vector<int> freq_s (256, 0);

        //先统计一下t中元素的频率
        for(int i = 0 ; i < t.size(); i++)
            freq_t[ t[i] ] ++;

        int l = 0, r = -1; //在[l,r]中寻找子串
        while( l < s.size() ){

            if( r + 1 < s.size() && count < t.size() ) { //证明还没有找到所有的元素
                freq_s[ s[r+1] ] ++;
                if(freq_s[ s[r+1] ] <= freq_t[ s[r+1] ]) //先拓展再比较
                    count ++;

                r ++;

            }else{ //找到一个之后 比较记录下来。然后 让l向右边移动一位 此时进入下一个循环
                //如果l移动的是t中有的元素 这次就会进入if那一个语句中执行
                // 如果l移动过的是无关紧要的元素，则count没有改变 下一次还是会进入到else这个语句中
                assert( count <= t.size() );
                if( count == t.size() && r-l+1 < MinLength){
                    MinLength = r-l+1;
                    startIndex = l;
                }

                freq_s[ s[l] ] --;
                if( freq_s[ s[l] ] < freq_t[ s[l] ])
                    count --;

                l ++;

            }


        }

        //用这种方法取子串  而不是遍历一遍相加
        if( startIndex != -1)
            result = s.substr(startIndex, MinLength);

        return result;


    }
};


int main(){

    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = Solution().minWindow(s,t);

    cout << result << endl;

    return 0;
}



//自己第一次写的时候失败的例子
class Solution {
public:
    string minWindow(string s, string t) {

        if( t.size() > s.size() ) return "";

        string result = "";
        int MinLength = s.size() + 1;
        int count = 0;
        int startIndex = -1;

        vector<int> freq_t (256, 0);
        vector<int> freq_s (256, 0);

        //先统计一下t中元素的频率
        for(int i = 0 ; i < t.size(); i++)
            freq_t[ t[i] ] ++;

        int l = 0, r = -1; //在[l,r]中寻找子串
        while( l < s.size() ){
            if( r+1 < s.size() && freq_s[ s[r+1] ] < freq_t[ s[r+1] ] ) { //证明s中这个元素也在t中
                freq_s[ s[r+1] ] ++;
                count ++;
            }
            r ++;

            if( count == t.size()){
                if( r-l+1 < MinLength){
                    MinLength = r-l+1;
                    for(int k = l; k <= r; k++)
                        result += s[k];
                }
                //然后r怎么移动呢？ 自己想不好 如何r和l协调的移动。。。

            }

        }


    }
};
