//
// Created by Yannie Lee on 1/10/21.
//

//
// Created by Yannie Lee on 1/1/21.
//


#include <iostream>
#include <vector>

#include<set>

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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {




    }
};


int main(){


    vector<int> source {1,2,3,4};
    vector<int> target {2,1,4,5};
    vector< vector<int> > allowedSwaps {{0,1},{2,3}};

    cout << Solution().minimumHammingDistance( source, target, allowedSwaps ) << endl;

    return 0;
}
