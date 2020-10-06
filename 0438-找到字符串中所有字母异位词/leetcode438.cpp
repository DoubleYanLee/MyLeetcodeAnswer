//
// Created by Yannie Lee on 2020-10-05.
//


//我在比较的时候没有想到 频率数组可以直接比较，考虑的是还要判断扫描一遍数组确定其内值为1  这就很麻烦了
//对于窗口的滑动也不清楚怎么滑动 即考虑的太多，直接每三个滑动一次就可以了

//我的代码


class Solution {
private:
    //之前用数组作为索引数组，不能直接比较 用vector就可以直接比较了 所以这个函数也就不必要了 这里就不删除了
    bool same( const vector<int>& v1, const vector<int>& v2){
        for(int i = 0 ; i < 256; i++){
            if( v1[i] != v2[i] ) return false;
        }

        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {


        vector<int> result;
        if( p.size() > s.size() ) return result;

        //先用一个索引数组记录p
        vector<int>freq_p (256, 0);
        vector<int>freq_s (256, 0);

        for( int i = 0; i < p.size(); i ++ ){
            freq_p[ p[i] ] ++;
            freq_s[ s[i] ] ++;
        }

        if( freq_p == freq_s ) result.push_back(0); //vector可以这样比较 数组就不能这样比较了

        freq_s[ s[0] ] --;

        int r = p.size();  int l = 1;

        while( r < s.size() ){

            freq_s[ s[r] ] ++;

            if( same(freq_s, freq_p) )
                result.push_back(l);

            freq_s[ s[l] ] --;
            l ++; r++;
        }

        return result;

    }
};



int main(){

    string s = "cbaebabacd";
    string p = "abc";

    vector<int> result = Solution().findAnagrams(s,p);

    vector<int> :: iterator it;
    for( it = result.begin(); it != result.end(); it ++)
        cout << (*it) << endl;

    return 0;
}









// 别人优雅的代码

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(s.size()<p.size())
            return {};

        int l = 0, r = -1;
        vector<int> freq_s(26, 0), freq_p(26, 0), res;

        // 初始化代码值
        for( int i = 0 ; i < p.size() ; i++ ){
            freq_p[p[i] - 'a' ]++;   //记录p的频率数组
            freq_s[s[++r] - 'a' ]++;
        }

        if ( freq_s == freq_p )
            res.push_back( l );

        // 固定长度的滑动窗口
        while( r < s.size()-1 ){

            freq_s[s[++r] - 'a' ]++;
            freq_s[s[l++] - 'a' ]--;
            if ( freq_s == freq_p )
                res.push_back( l );
        }

        return res;
    }
};





//写到这里不会写了。。。。 不知道如何滑动窗口了

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        //统计P中的元素  也没说p中是否有重复元素。。。

        vector<int> result;

        int pSize = p.size();

        if(pSize == 0) return result;

        vector<int> pArray (256 , 0);
        for( int i = 0; i < pSize; i++ )
            pArray[ p[i] ] ++; //统计数据

        vector<int> SaveArray = pArray;

        //在[i,j]里面寻找

        int i = 0, j = -1;
        while( i < s.size() ){
            if( pArray[ s[j+1] ]  == 0 ) {   //表示p中没有这个元素
                //i就要挪到这个元素的下一个位置

            }
        }


    }
};