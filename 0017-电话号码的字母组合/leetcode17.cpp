//
// Created by Yannie Lee on 2020-10-07.
//

//第一次空字符串没有处理好

class Solution {

private:

    string LetterMap[10] = {
            " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> result;

    //每次处理digits中index位置的数字  s保存的是[0..index]中处理过的字符串
    void findCombination( string digits, int index ,string s ){

        if( index == digits.size() ){
            result.push_back(s);
            return ;

        }

        char c = digits[index]; //取出该位的数字
        int LetterIndex = c - '0';
        string CurString = LetterMap[ LetterIndex ];

        for( int i = 0; i < CurString.size(); i ++ ){
            findCombination(digits, index + 1, s + CurString[i]);
        }


    }


public:
    vector<string> letterCombinations(string digits) {

        result.clear();

        if( digits.size() == 0 ) return result;

        findCombination(digits, 0, "");

        return result;
    }
};

int main(){

    string digits = "23";

    vector<string> result = Solution().letterCombinations(digits);

    vector<string>::iterator it;
    for( it = result.begin(); it != result.end(); it++)
        cout << (*it) << endl;


    return 0;
}