//
//  main.cpp
//  LeetCode
//
//  Created by zhouluyao on 2/21/23.
//
/************************** 题解 **********************
 题目链接：https://leetcode.cn/problems/sort-colors
 题目大意：
 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 必须在不使用库内置的 sort 函数的情况下解决这个问题。
 你能想出一个仅使用常数空间的一趟扫描算法吗？

 
 
 
 示例 1：

 输入：nums = [2,0,2,1,1,0]
 输出：[0,0,1,1,2,2]
 示例 2：

 输入：nums = [2,0,1]
 输出：[0,1,2]

 
 题目解析：
一般针对于常数空间(空间复杂度O(1))、一趟扫描(时间复杂度O(n))的问题，一般的套路都需要借助于双指针，三指针
 
 针对这种只有0、1、2三种元素的问题，可以想到使用一个扫描指针对数组进行扫描，
 扫描到0就放到左边，扫描到2就放到右边，扫描到1就跳过，至于怎么与左边元素交换，怎么与右边元素交换，也是需要搞两个指针出来
 扫描指针遇到右边往左的指针后，整个数组就扫描了一遍，扫描结束
 
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


class SortColors{
public:
    void sortColors(vector<int>& nums) {
        
        int size = nums.size();
        
        int begin = 0;
        int cur = 0;
        int end = size - 1;
        
        while (cur <= end) {
     
            int v = nums[cur];
            //当扫描指针cur为2时，与右边指针end对应的元素调换位置，end--,再次判断cur的值
            if (v == 0) {
                //cur的值为0时，与begin元素调换位置，begin++,cur++
                swap(nums[begin], nums[cur]);
                begin ++;
                cur ++;
            }else if (v == 1) {
                //cur的只为1时，cur++
                cur ++;
            }else {
                swap(nums[cur],nums[end]);
                end --;
            }
            
      
        }
        
        }
    
}solution;


int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2,0,2,1,1,0};

    solution.sortColors(nums);
    //打印数组中的元素
    for (auto i : nums)
        std::cout << i << ' ';
    
    return 0;
}

