//
//  main.cpp
//  Leetcode
//
//  Created by zhouluyao on 3/4/23.
//

#include <iostream>

/************************** 题解 **********************
 题目链接：https://leetcode.cn/problems/sub-sort-lcci/
 题目大意：
 给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。


 
 
 示例 1：
 
 输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
 输出： [3,9]
 
 题目解析：
 [1,2,6,4,3,10]
 这个题目本质上是要找最后一个逆序对，
 1、用一个指针从头扫到尾，扫描的过程不停的更新最大值，
 2、往后扫描只要比最大值小，就是逆序对，记录当前扫描元素的位置
 3、直到扫描到最后，记录的位置就是最后一个逆序对
 4、然后以同样的方法从尾到头扫描
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


class Solution{
public:
    vector<int> subSort(vector<int>& array) {
        if (array.size() <=1 ) {
            return {-1, -1};
         }
        
        //左------>右扫描
        int rightReverseIndex = 0;
        int max = array[0];
        for (int i = 0; i< array.size();i++) {
            //1、往后扫描只要比最大值小，就是逆序对，记录当前扫描元素的位置
            if (array[i] < max) {
                rightReverseIndex = i;
            }
            
            //2、用一个指针从头扫到尾，扫描的过程不停的更新最大值
            if(array[i] > max) {
                max =array[i];
            }
        }
        
        //右------>左扫描
        int length = (int)array.size();
        int leftReverseIndex = length-1;
        int min = array[length-1];
        for (int i = length -1; i>=0 ;i--) {
            //1、往前扫描只要比最最值大，就是逆序对，记录当前扫描元素的位置
            if (array[i] > min) {
                leftReverseIndex = i;
            }
            
            //2、用一个指针从头扫到尾，扫描的过程不停的更新最大值
            if(array[i] < min) {
                min =array[i];
            }
        }
        //3、直到扫描到最后，记录的位置就是最后一个逆序对
        if (leftReverseIndex > rightReverseIndex) return {-1,-1};
        return {leftReverseIndex, rightReverseIndex};
    }
}solution;


int main(int argc, const char * argv[]) {
    
//    vector<int> nums = {1,2,4,7,10,11,7,12,6,7,16,18,19};
    vector<int> nums = {1,2,4,16,18,19};
    vector<int> nums2 = solution.subSort(nums);
    
    //打印数组中的元素
    for (auto i : nums2)
        std::cout << i << ' ';
    
    return 0;
}


