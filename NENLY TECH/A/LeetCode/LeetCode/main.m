//
//  main.m
//  LeetCode
//
//  Created by zhouluyao on 2/22/23.
//

/************************** 题解 **********************
 题目链接：https://blog.csdn.net/m0_59646156/article/details/128383465
 题目大意：
 三连得分 给定⼀个10×10的棋盘，上⾯有两个玩家玩棋盘游戏的局⾯。其中玩家A的棋⼦⽤O表⽰，玩家B的棋 ⼦⽤X表⽰。请计算这个局⾯下两个玩家的得分。 得分计算规则如下：
 
 1. 如果有三个相同棋⼦在连续相邻的格⼦上，称为三连，计⼀分。
 2. 相邻是包括横竖斜⽅向上的相邻。
 3. 两组三连只要不完全重复，可以分别计⼀分。
 
 
 
 示例 1：
 10×10的棋盘局⾯，玩家A棋⼦是O，玩家B棋⼦是X，空地⽤"."表⽰ 输出：两⾏，第⼀⾏是玩家A得分，第⼆⾏是玩家B得分 样例输⼊ Plain Text ........XX X....X.... ......X... ...OOO.... ...OOOOX.. ...OOO.... ....O..... .X....X.X. ........X. .......... 1 2 3 4 5 6 7 8 9 10 样例输出 11 0
 ————————————————
 
 
 题目解析：
 在一个N*N 的棋盘上，同一个棋子3个相同的相连接的情况无非有4种情况
 情况1：
 OOO
 
 情况2：
 O
 O
 O
 
 情况3：
 O
 O
 O
 
 情况4：
 O
 O
 O
 找到这4种情况的边界条件即可
 
 首先判断传入的3个字符串是不是一致的，然后再判断这4种边界情况
 
 网上其他的做法：
 */

#import <Foundation/Foundation.h>

BOOL isValidEqualSymbols(char a,char b,char c) {
    return  a != '.' && a==b && b==c ;
}

void calculateScore(char board[10][10],int *scoreA,int *scoreB){
    
    //横轴检查,一行一行的扫描
    for(int row = 0;row < 10;row++) {
        for(int col = 0;col < 8;col++) {
            //判断3个是否相等
            if(isValidEqualSymbols(board[row][col], board[row][col+1], board[row][col+2])){
                
                if(board[row][col] == 'O') {
                    (*scoreA)++;
                }else {
                    (*scoreB)++;
                }
            }
        }
    }
    
    //纵轴检查,一列一列的检查
    for(int col = 0;col < 10;col++) {
        for(int row = 0;row < 8;row++) {
            //判断3个是否相等
            if(isValidEqualSymbols(board[row][col], board[row+1][col], board[row+2][col])){
                
                if(board[row][col] == 'O') {
                    (*scoreA)++;
                }else {
                    (*scoreB)++;
                }
            }
        }
    }
    
    //对角线检查（左上 -> 右下）
    for(int col = 0;col < 8;col++) {
        for(int row = 0;row < 8;row++) {
            //判断3个是否相等
            if(isValidEqualSymbols(board[row][col], board[row+1][col+1], board[row+2][col+2])) {
                
                if(board[row][col] == 'O'){
                    (*scoreA)++;
                }else {
                    (*scoreB)++;
                }
            }
        }
    }
    
    //对角线检查（左下 -> 右上）
    for(int row = 9;row >= 2;row--) {
        for(int col = 0;col < 8;col++) {
            //判断3个是否相等
            if(isValidEqualSymbols(board[row][col], board[row-1][col+1], board[row-2][col+2])){
                
                if(board[row][col] == 'O'){
                    (*scoreA)++;
                }else {
                    (*scoreB)++;
                }
            }
        }
    };
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        //声明一个二维数组
        char board [10][10] =
        {
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','O','.','O','X','.','O','X','.','O',},
            {'O','X','O','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
            {'O','X','.','O','X','.','O','X','.','O',},
        };
        
        int scoreA = 0;
        int scoreB = 0;
        calculateScore(board, &scoreA, &scoreB);
        NSLog(@"A选手的得分：%i,B选手的得分：%i",scoreA,scoreB);
        
    }
    return 0;
}
