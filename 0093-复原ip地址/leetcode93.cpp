//
// Created by Yannie Lee on 2020-10-07.
//



class Solution {

private:

    vector<string> resArray;
    vector<int> curArray;

    string getString( vector<int>& nums ){

        string res = to_string(nums[0]);
        for(int i = 1; i < curArray.size(); i++)
            res += "." + to_string(curArray[i]);

        return res;

    }

    //findIpAddresses函数的意义就是 处理s的index位置的元素,之前的元素保存在数组p中
    void findIpAddresses(string s , int index){

        if( index == s.size() ){
            if( curArray.size() == 4)
                resArray.push_back(getString(curArray));
            return ;
        }

        if( index == 0 ){
            curArray.push_back(s[index] - '0'); //这个减 '0'又忘记了 不然就又push进去字符串了
            findIpAddresses(s, index + 1); //这里能不能用 1呢  1也是可以的
        }else{  //这里用else连接诶。。

            int nextEle = curArray.back() * 10 + (s[index] - '0'); //往下寻找
            if( nextEle <= 255 && nextEle >= 10){ //确保第一个元素不为0  curArray.back() != 0 如果为0就开启新一轮搜索
                //将旧的弹出来 将新的放进去 ==> 可以直接用一步赋值 搞定
                curArray.pop_back();
                curArray.push_back( nextEle );
                findIpAddresses(s, index + 1);
                //回溯的这一步刚开始不会了
                curArray.back() /= 10;
            }

            //这一步是当其大于255的时候 不覆盖数组值，然后开启新一轮的查找
            if(curArray.size() < 4){
                curArray.push_back( s[index] - '0' );
                findIpAddresses(s, index + 1);
                curArray.pop_back(); //查完之后恢复成原来的
            }

        }





    }

public:
    vector<string> restoreIpAddresses(string s) {

        resArray.clear();
        curArray.clear();

        findIpAddresses(s, 0);

        return resArray;

    }
};



















//  老师的代码
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> res;
        vector<int> ip;
        dfs(s, 0, ip, res);
        return res;
    }

private:
    void dfs(const string& s, int index, vector<int>& ip, vector<string>& res){

        if(index == s.size()){
            if(ip.size() == 4)
                res.push_back(get_string(ip));
            return;
        }

        if(index == 0){

            ip.push_back(s[0] - '0');
            dfs(s, index + 1, ip, res); //1
        }
        else{
            int next = ip.back() * 10 + (s[index] - '0');
            if(next <= 255 && ip.back() != 0){
                ip.back() = next;

                dfs(s, index + 1, ip, res);  //3  4  6
                ip.back() /= 10;  //当一个地址找到之后 回到这一步  //返回第一步 0.100.10的时候返回 返回4 5  8
            }

            //如果还不够的话 再往ip数组中加入

            if(ip.size() < 4){
                ip.push_back(s[index] - '0');
                dfs(s, index + 1, ip, res); // 2 5 新6 返4后7 8  返8后9
                ip.pop_back();  //返回第二步  找到一个之后删除ip中的最后一个元素 又是一种回溯 ip 返回3 6 7
            }
        }
    }

    string get_string(const vector<int>& ip){
        string res = to_string(ip[0]);
        for(int i = 1; i < ip.size(); i ++)
            res += "." + to_string(ip[i]);
        return res;
    }
};


// 自己的代码不知道如何清空回去

class Solution {

private:

    vector<string> result;

    void findIpAddresses( string s, int index, int times , string saveString){


        if( times == 4){
            result.push_back(saveString);
            return ;
        }

        //i用来表示分成几位  这样搜索有很多不必要 也是可以剪枝的
        //当times=3的时候 后面还有远远超过的数字 如何将其清空返回呢？
        for(int i = 1; i <=3; i++){

            string curString = s.substr(index, i);

            int a = atoi( curString.c_str() );

            if( a >= 0 && a <= 255 )
                findIpAddresses(s, index + i + 1, times+1, saveString + curString + '.' );
            else{
                //如何在递归的时候跳出来呢？
                if( i == 3 ) return;
                else continue;
            }

        }



    }


public:
    vector<string> restoreIpAddresses(string s) {

        // 可分一位：4-10  可分两位：5-11  可分三位：6-12   这样的就没有利用递归和回溯了

        int length_s = s.size();
        if( length_s < 4 || length_s > 12 )  return result;

        findIpAddresses(s, 0, 0, "");



    }
};
