//
//  main.m
//  LeetCode
//
//  Created by zhouluyao on 2/22/23.
//

/************************** 题解 **********************
 题目链接：
 题目大意：
 规范文本
 给定一个只包含英文字母，半角标点(仅包括逗号，句号)和空格的字符串。请按如下规则将字符串规范化:
 1.单词之间的空格只保留一个(需要删除多余的空格)
 
 2，标点之前的空格需要删除
 
 3. 标点之后仅保留一个空格，若没有需要添加，若有两个或以上空格需要删除多余空格
 
 4.句子(以句号分割的字符串)首字母需要修正为大写，其他字母需要修正为小写
 
 5.多余的标点需要删除(比如连续重复逗号/句号仅保留一个)
 
 给定的字符串保证满足以下几个条件:
 1.单词是由连续字母组成，以标点或空格分割。不用考虑是否是实际存在的单词。
 2.保证不会有连续混合的标点符号。
 3.给定的字符串一定是以字母开始。

 
 
 示例 1：
 Plain Text

 样例1
 when a father gives to his son,,, Both laugh, When a son gives to his father,
 , , Both cry...shakespeare

 Plain Text
 样例1输出
 When a father gives to his son, both laugh, when a son gives to his father
 both cry. Shakespeare

 Plain Text
 样例2
 one,two,three.

 Plain Text
 样例2输出
 One,two, three.
 ————————————————

 
 题目解析：

 
 网上其他的做法：
 */

#import <Foundation/Foundation.h>


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
