//
//  main.cpp
//  LeetCode
//
//  Created by zhouluyao on 3/11/23.
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
 题目链接：https://leetcode.cn/problems/delete-node-in-a-linked-list/
 题目大意：
 有一个单链表的 head，我们想删除它其中的一个节点 node。

 给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。

 链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。

 删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：

 给定节点的值不应该存在于链表中。
 链表中的节点数应该减少 1。
 node 前面的所有值顺序相同。
 node 后面的所有值顺序相同。
 自定义测试：

 对于输入，你应该提供整个链表 head 和要给出的节点 node。node 不应该是链表的最后一个节点，而应该是链表中的一个实际节点。
 我们将构建链表，并将节点传递给你的函数。
 输出将是调用你函数后的整个链表。

 
 
 示例 1：
 4->5->1->9  delete 5
 输入: head = [4,5,1,9], node = 5
 输出：[4,1,9]
 解释：指定链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9

 
 示例 2：
 4->5->1->9  delete 1
 输入：head = [4,5,1,9], node = 1
 输出：[4,5,9]
 解释：指定链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9

 

 题目解析：

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
    void deleteNode(ListNode* node) {
        //先把要删除的下一个节点找到
        ListNode *next = node->next;
        //把下一个节点的值，赋值给当前要删除的节点
        node->val = next->val;
        //把当前节点的下一个节点指向下一个节点的下一个节点
        node->next = next->next;
        //删除next节点
        delete  next;
    }
}solution;


int main(int argc, const char * argv[]) {
    //构建一个单向链表 4->5->1->9
    ListNode *head = new ListNode(4);
    head->next = new  ListNode(5);
    head->next->next = new  ListNode(1);
    head->next->next->next = new  ListNode(9);
    
    //删除指定的node
    solution.deleteNode(head->next);
    
    //打印删除后的链表节点
    ListNode *cur  = head;
    while (cur != NULL) {
        cout << cur->val << "";
        cur = cur->next;
    }
    
    //释放链表的内存
    while (head != NULL) {
        ListNode *temp = head;
        head = head->next;
        delete  temp;
    }
    
    return 0;
}

