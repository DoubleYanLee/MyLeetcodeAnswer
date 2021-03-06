//
// Created by Yannie Lee on 1/1/21.
//


#include <iostream>
#include <vector>

#include<set>
#include <numeric>

using namespace std;



struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(int arr[],int n){

    if( n == 0 )
        return NULL;

    ListNode* head = new ListNode(arr[0]);

    ListNode* curNode = head;
    for(int i = 1; i < n; i++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void deleteLinkedList(ListNode* head){
    ListNode* curNode = head;
    while( curNode != NULL ){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

}


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> res;
        int n = nums.size();
        if( n == 0 )  return res;
        else if( n == 1 )
            res.push_back( to_string(nums[0]) );
        else{
            string tmp = to_string(nums[0]);
            for( int i = 1; i < n; i ++ ){
                if( nums[i] != nums[i-1] + 1 ) {
                    if( stoi(tmp) == nums[i-1] )
                        res.push_back(tmp);
                    else
                        res.push_back( tmp + "->" + to_string(nums[i-1]) );

                    tmp = to_string(nums[i]);
                }else{
                    if( i == n-1 )
                        res.push_back(tmp + "->" + to_string(nums[n-1]));
                }
            }

            if( stoi(tmp) == nums[n-1] )
                res.push_back(tmp);


        }


    return  res;

    }
};

int main(){


    vector<int> nums {0,1,2,4,5,7};

    vector<string> res = Solution().summaryRanges( nums );

    for( auto it : res )
        cout << it << " " ;

    return 0;
}
