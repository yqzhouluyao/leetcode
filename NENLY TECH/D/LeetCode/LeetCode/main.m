//
//  main.m
//  LeetCode
//
//  Created by zhouluyao on 2/22/23.
//

/************************** 题解 **********************
 题目链接：https://blog.csdn.net/Allure_heart/article/details/122642853
 题目大意：
 
 均富卡
 给定 n 个数（例如 [4, 3, 1, 7, 1]），每次操作是选择其中若 ⼲ 个数，将它们替换为它们的平均
 数。
 例如：选择第 1，2，3，5 四个数，对应的数是 4，3，1，1，它们的平均数为 2.25，所以操
 作后这 5 个数就变为了 [2.25，2.25，2.25，7，2.25]。
 假定玩家可以进 ⾏ 任意次操作（也可以为 0 次），若给定 ⼀ 个 w，问最多可以有多少个数能
 不 ⼩ 于 w。

 样例数据：
 [11, 9, 11, 9]，w = 10，输出 4
 [5, 1, 2, 1]，w = 3，输出 2
 [4, 3]，w = 5，输出 0

 (然后左移left，右移current)，如果值＞w，current指针向右移动，直到current到达末尾，或者left到达开头，此时如果区间的平均数＞w，则进行平均，left到current之间有几个数就是几，如果最后的平均数＜w，就是区间减1就是答案
 
 题目解析：
 1、先把数组元素从大到小排序
 2、找到恰好＜w的数时，用一个指针current标记一下，再用一个指针left指向w左侧的数值
 3、left和current两个指针指向的值平均，如果＜w，left指针向左移动，3个数继续平均
 4、如果平均值>=w，current指针向右移动，继续平均
 5、如果left=0时，平均终止，符合的数量就是0-current之间，如果当前平均值 < w,total = current,如果>=w，total = current + 1
 6、current = 数组数量 -1，平均终止，符合的数量就是0-current之间，如果当前平均值 < w,total = current,如果>=w，total = current + 1
 
 网上其他的做法：
 */

#import <Foundation/Foundation.h>

//计算区间元素的平均值
double calculateAverage(int nums[],int fromIndex,int toIndex) {
    if(fromIndex == toIndex) return nums[fromIndex];
    
    double total = 0;
    for (int i = fromIndex; i<= toIndex ;i++){
        total += nums[i];
    }
    return total / (toIndex - fromIndex + 1);
}

//对数组元素进行排序
void quickSort(int array[],int left ,int right){
    int i = left, j = right;
        int tmp;
        int pivot = array[(left + right) / 2];
      
        /* partition */
        while (i <= j) {
            while (array[i] > pivot)
                i++;
            while (array[j] < pivot)
                j--;
            if (i <= j) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
        }
      
        /* recursion */
        if (left < j)
            quickSort(array, left, j);
        if (i < right)
            quickSort(array, i, right);
}

int totalNumOfValidElments(int nums[],int size,double w) {
    //先把数组元素从大到小排序
    quickSort(nums,0,size);

    //找到恰好＜w的数时，用一个指针current标记一下,再用一个指针left指向w左侧的数值
    int current = 0;
    int left = 0 ;
    
    for (int i = 0; i< size; i++) {
        int temp = nums[i];
        printf("--%d--  ", temp);
        if(temp < w) {
            current = i;
            left = current -1;
            break;;
        }
    }
    //按照从大到小的顺序排，排完之后，最大值还小于w，说明没有比不小于w的元素存在
    if (left < 0) return 0;
    
    
    double average = 0;
    while (left>=0 && current < size) {
        //left和current两个指针指向的值平均，如果＜w，left指针向左移动，区间数继续平均
        //如果平均值>=w，current指针向右移动，继续平均
        
        average = calculateAverage(nums, left, current);
        if (average < w) {
            left --;
        } else {
            current ++;
        }
    }
    
    return (average < w)?current:current +1;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int nums [] = {1,10,20,30,8,8,3,32};
        double w = 20;
        int total = totalNumOfValidElments(nums,7,w);
        
        NSLog(@"符合给定⼀个%f，经过若干次平均，最多可以有%i个数能不⼩于%f",w,total,w);
    }
    return 0;
}
