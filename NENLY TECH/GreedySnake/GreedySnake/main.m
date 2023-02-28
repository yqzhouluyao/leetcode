//
//  main.m
//  GreedySnake
//
//  Created by zhouluyao on 2/28/23.
//

#import <Foundation/Foundation.h>
#include <Foundation/Foundation.h>
/************************** 题解 **********************
 
 题目大意：
 
 输入m 行 n列的 ，输出一个二维数组，按照上面的规律打印，类似一个贪吃蛇的规律
 
 样例数据：
 1      2     3    4    5
 14   15   16   17   6
 13   20   19   18  7
 12   11   10   9    8
 
 题目解析：
 1、首先初始化一个元素全为0的二维数组，逐行赋值为0
 2、然后按照贪吃蛇走过的路径  右 - >  下  ->  左  ->  上  -> 右，逐个的访问二维数组对应的二维下标(row,col),对相应的位置进行赋值，从1到 m*n
 3、问题的核心在于贪吃蛇经过的路径方向改变时，怎么找到对应的下标，然后赋值
 4、完成赋值后，打印对应的结果
 
 */

void greedySnake(int m,int n) {
    int arr[m][n];
    int row = 0;
    int col = 0;
    int count = 1;
    int direction = 1;

    //1、首先初始化一个元素全为0的二维数组
    for (int i = 0; i < m  ; i ++){
        for (int j = 0; j < n ;j ++ ){
            arr[i][j] = 0;
        }
    }

    //2、然后按照贪吃蛇走过的路径，逐个的访问二维数组对应的二维下标(row,col),对相应的位置进行赋值，从1到 m*n
    while (count <= m*n) {
        arr[row][col] = count;
        count ++;

        //3、问题的核心在于贪吃蛇经过的路径方向改变时，怎么找到对应的下标，然后赋值
        switch (direction) {
            case 1: // Right
                if(col == n-1 || arr[row][col+1]!=0) {
                    //向右走到头了
                    row++;
                    direction = 2;
                } else {
                    col++;
                }
                break;
            case 2: // Down
                if(row == m-1 || arr[row+1][col]!=0) {
                    //向下走到头了
                    col--;
                    direction = 3;
                } else {
                    row++;
                }
                break;
            case 3: // Left
                if(col == 0 || arr[row][col-1]!=0) {
                    //向左走到头了
                    row--;
                    direction = 4;
                } else {
                    col--;
                }
                break;
            case 4: // Up
                if(row == 1 || arr[row-1][col]!=0) {
                    //向上走到头了
                    col++;
                    direction = 1;
                } else {
                    row--;
                }
                break;

            default:
                break;
        }
    }



    //4、完成赋值后，打印对应的结果
    for (int i = 0; i < m ; i ++ ){
        for (int j = 0; j < n;j ++  ){
            int temp = arr[i][j];
            printf("%d   ", temp);
        }
        printf("%c", '\n');
    }
}

//void greedySnake(int m, int n) {
//    int arr[m][n];
//    int count = 1;
//    int row = 0;
//    int col = 0;
//    int direction = 0;
//
//    // Fill the array with 0s
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            arr[i][j] = 0;
//        }
//    }
//
//    // Traverse the array in a greedy snake pattern and fill it with numbers
//    while (count <= m * n) {
//        arr[row][col] = count;
//        count++;
//
//        // Determine the direction to move in
//        switch (direction) {
//            case 0: // Right
//                if (col == n - 1 || arr[row][col+1] != 0) {
//                    direction = 1; // Change direction to down
//                    row++;
//                } else {
//                    col++;
//                }
//                break;
//            case 1: // Down
//                if (row == m - 1 || arr[row+1][col] != 0) {
//                    direction = 2; // Change direction to left
//                    col--;
//                } else {
//                    row++;
//                }
//                break;
//            case 2: // Left
//                if (col == 0 || arr[row][col-1] != 0) {
//                    direction = 3; // Change direction to up
//                    row--;
//                } else {
//                    col--;
//                }
//                break;
//            case 3: // Up
//                if (row == 0 || arr[row-1][col] != 0) {
//                    direction = 0; // Change direction to right
//                    col++;
//                } else {
//                    row--;
//                }
//                break;
//            default:
//                break;
//        }
//    }
//
//    // Print the array in a greedy snake pattern
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d\t", arr[i][j]);
//        }
//        printf("\n");
//    }
//}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
        greedySnake(4,4);
    }
    return 0;
}
