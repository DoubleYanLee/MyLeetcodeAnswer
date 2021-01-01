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

class Solution{

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *p1 = l1, *p2 = l2;
        ListNode * dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;

        int carried = 0;
        while( p1 || p2){
            int a = p1 ? p1->val : 0;  //这种方法巧妙
            int b = p2 ? p2->val : 0;
            cur -> next = new ListNode((a + b + carried) % 10);
            carried = (a+b+carried) / 10;

            cur = cur -> next;
            p1 = p1 ? p1 -> next : NULL;
            p2 = p2 ? p2 -> next : NULL;
        }

        cur->next = carried ? new ListNode(1) : NULL; //嗷 进位只可能为1 我傻逼了
        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

};

int main(){

    int arr[] = {2,4,3}; int arr2[] = {5,6,4};
    int n = sizeof(arr)/ sizeof(int); int n2 = sizeof(arr2)/ sizeof(int);
    ListNode* head = createLinkedList(arr,n); //要手动的对内存进行释放
    ListNode* head1 = createLinkedList(arr2,n2);
    //printLinkedList(head);

    ListNode* head2 = Solution().addTwoNumbers( head , head1 );
    printLinkedList( head2 );

    deleteLinkedList( head2 );

    return 0;
}
