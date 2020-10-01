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
#include <list>

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {


        list<char> l = {'a','e','i','o','u','A','E','I','O','U'};

        int i = 0, j = s.size() - 1;

        while( i < j ){
            if( find(l.begin(), l.end(),s[i]) == l.end() ) i++;
            else if( find(l.begin(), l.end(),s[j]) == l.end() ) j--;
            else if( (find(l.begin(), l.end(),s[i]) != l.end())  &&
                     (find(l.begin(), l.end(),s[j]) != l.end()) ){
                swap(s[i],s[j]);
                i ++; j --;
            }
        }

        return s;

    }
};

int main(){

    string s { "Aa" };
    string newstr = Solution().reverseVowels(s);

    vector<char> :: iterator it;
    for( it = newstr.begin(); it != newstr.end(); it++ )

        cout << (*it) << " ";

    cout << endl;


    return 0;
}