//
//  main.cpp
//  LeetCode
//
//  Created by zhouluyao on 2/21/23.
//

/************************** 题解 **********************
 题目链接：https://leetcode.cn/problems/merge-sorted-array/
 题目大意：
 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 
 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

 
 示例 1：

 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 输出：[1,2,2,3,5,6]
 解释：需要合并 [1,2,3] 和 [2,5,6] 。
 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
 
 示例 2：

 输入：nums1 = [1], m = 1, nums2 = [], n = 0
 输出：[1]
 解释：需要合并 [1] 和 [] 。
 合并结果是 [1] 。
 
 示例 3：

 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
 输出：[1]
 解释：需要合并的数组是 [] 和 [1] 。
 合并结果是 [1] 。
 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

 题目解析：
 nums1 [ 1   3   5   0   0   0]
 nums2 [ 2   4   6]
可以从数组的尾部元素进行比较，使用一个下标进行标记，比如 5 和 6，再用一个下标标记nums1的尾部
 第一次比较 5 ，6,  6比较大，把6这个元素放到num1的尾部，把指向num1尾部的下标向前移动
 把之前指向6元素的下标向前移动，指向4
 
 再次比较指向num1，再比较num2的4（下标对应位置）与num1中的5（下标对应位置），5比较大，把元素5移动到num1数组尾下标位置
 再把num1中5位置对应的下标前移
 
 下标位置为0时，结束，合并完成
 
 网上其他的做法：

 
 ************************* 题解 ***********************/
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
using namespace std;
#define LYTEST  1



typedef long long lld;
const int N = 50000;


class MergeSortedArray{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int tailIndex = m + n -1;
        int num1TailIndex = m - 1;
        int num2TailIndex = n - 1;
        
        while (num2TailIndex >= 0) {
            if(num1TailIndex >= 0 && nums1[num1TailIndex] > nums2[num2TailIndex]) {
                nums1[tailIndex] = nums1[num1TailIndex];
                num1TailIndex --;
                tailIndex --;
            } else {
                //num1TailIndex < 0 || num1 <= num2
//                num1TailIndex < 0
                if (num1TailIndex < 0) {
                    nums1[tailIndex] = nums2[num2TailIndex];
                    num2TailIndex --;
                    tailIndex --;
                } else {
                    // num1 <= num2
                    nums1[tailIndex] = nums2[num2TailIndex];
                    num2TailIndex --;
                    tailIndex --;
                }
                
                //if else 执行逻辑一样可合并
            }
        }
    }
}solution;


int main(int argc, const char * argv[]) {
    
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    solution.merge(nums1, 3, nums2, 3);
    
    //打印数组中的元素
    for (auto i : nums1)
        std::cout << i << ' ';
    
    return 0;
}
