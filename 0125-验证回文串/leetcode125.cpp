//
// Created by Yannie Lee on 2020-10-01.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>
#include <queue>
#include <ctime>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {

        if( s.size() == 0 ) return true;

        //如何除掉字符串中的非字母和数字字符
        //先预处理一下字符串

        string newstr;

        for(int i = 0 ; i < s.size(); i++){
            if( (s[i] >= 65 && s[i] <= 90 ) || ( s[i] >= 97 && s[i] <= 122 ) )
                newstr += tolower(s[i]) ;

            else if(s[i] >= 48 && s[i] <= 57 ) newstr += s[i];
        }

        int j = 0, k = newstr.size()-1; //在[j,k]之间判断
        while( j <= k){
            if(newstr[j] != newstr[k]) return false;
            else{
                j++; k--;
            }
        }

        return true;

    }
};



int main(){

    string s = "A man, a plan, a canal: Panama";
    bool result = Solution().isPalindrome(s);

    cout << result << endl;

    return 0;
}