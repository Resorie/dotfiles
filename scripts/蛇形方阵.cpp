#include <cstdio>

int n,t,map[10][10];
// n是边长，t是计数器，map数组存方阵

void matrix() { // 构造矩阵
    for(register int i = 1;i <= n / 2;i ++) {
        /*
         * 不要管register，习惯性的东西
         * 这里把矩阵分成n / 2层来处理
         * 每层四个部分
         */
        for(register int j = 1;j <= n + 1 - 2 * i;j ++)
            // 第i层每部分有（n + 1 - 2i）个数
            map[i][i + j - 1] = ++ t; // 第一层
        for(register int j = 1;j <= n + 1 - 2 * i;j ++)
            map[i + j - 1][n - i + 1] = ++ t; // 第二层
        for(register int j = 1;j <= n + 1 - 2 * i;j ++)
            map[n - i + 1][n - i - j + 2] = ++ t; // 第三层
        for(register int j = 1;j <= n + 1 - 2 * i;j ++)
            map[n - i - j + 2][i] = ++ t; // 第四层
    }
    if(n & 1) // 如果n是奇数
        map[n / 2 + 1][n / 2 + 1] = n * n; // 最中间的特例
}

void print() { // 输出 不解释
    for(register int i = 1;i <= n;i ++) {
        for(register int j = 1;j <= n;j ++)
            printf("%3d",map[i][j]);
        puts("");
    }
}

int main() {
#ifndef ONLINE_JUDGE /* 不要管这一行 */
#define register     /* 也不要管这一行 */
#endif               /* 更不要管这一行 */
    scanf("%d",&n); // 读入
    matrix(); // 构造
    print(); // 输出
    return 0;
}