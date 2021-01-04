//
// Created by Yannie Lee on 1/3/21.
//
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>

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


//我佛了 真的不知道哪里出错。。。 在第一个greaterhead那里就跳出了。。。
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        //使用两个链表 一个链接大于x的数 一个链接小于x的数

        auto greaterhead = new ListNode(-1);
        auto lesshead = new ListNode(-1);

        ListNode *less1 = lesshead , *great1 = greaterhead;

        while( head ){  //原来又是这里写错了 我服。。。  应该是head而不是!head

            if( head -> val <= x ){
                less1->next = head;
                less1 = less1->next;
            }else{
                great1->next = head;
                great1 = great1->next;
            }

            head = head->next;

        }

        less1->next = greaterhead->next;
        great1->next = nullptr;

        return lesshead->next;

    }
};
