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
    void reverseString(vector<char>& s) {

        //在[i,j]中反转字符
        int i = 0, j = s.size() - 1;
        while (i < j){
            swap(s[i], s[j]);
            i ++; j --;
        }

    }
};


int main(){

    vector<char> s {'h', 'e', 'l', 'l', 'o' };
    Solution().reverseString(s);

    vector<char> :: iterator it;
    for( it = s.begin(); it != s.end(); it++ )

        cout << (*it) << " ";

    cout << endl;


    return 0;
}