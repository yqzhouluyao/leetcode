//
//  main.cpp
//  LeetCode
//
//  Created by zhouluyao on 3/15/23.
//

#include <iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<algorithm>

/************************** 题解 **********************
 题目链接：https://leetcode.cn/problems/reverse-linked-list/
 题目大意：
 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 
 
 示例 1：
 输入：head = [1,2,3,4,5]
 输出：[5,4,3,2,1]
 
 示例 2：
 输入：head = [1,2]
 输出：[2,1]

 
 示例 3：
 
 输入：head = []
 输出：[]
 
 题目解析：
 1、初始化prev节点为null,初始化next节点为head->next
 2、head->next指向prev
 3、prev指向head
 4、head指向next
 5、next指向head->next
 
 终止条件：
 head->next ==null
 
 网上其他的做法：
 
 
 ************************* 题解 ***********************/
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        if (head== NULL || head->next == NULL) {
            return head;
        }

//        1、初始化prev节点为null,初始化next节点为head->next
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            //保证链表不断，先用指针保存next
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
}solution;


int main(int argc, const char * argv[]) {
    
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    
    ListNode * newHead = solution.reverseList(head);
    
    //打印链表中的元素
    ListNode *curNode = newHead;
    while (curNode != NULL) {
        std::cout << curNode->val << ' ';
        curNode = curNode->next;
        
    }
    
    return 0;
}

