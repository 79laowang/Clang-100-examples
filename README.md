# C语言趣味100例
## 最简单的问题与算法
![#157500](https://placehold.it/15/157500?text=+)  [1.绘制余弦曲线](#例1)

### 例1.绘制余弦曲线.
在屏幕上用"\*"显示0°～360°的余弦cos(x)曲线
### *问题分析与解答设计:* 
```C
#include <stdio.h>
#include <math.h>

#define WIDTH 62

 /* Compile with  gcc -o cos-diagram cos-diagram.c -lm */
int main()
{
    double y;   /* 列 */
    int x, m;   /* x为行 */
    for (y=1;y>=-1;y-=0.1)
    {
        m=acos(y)*10;
        for (x=1;x<m;x++) printf(" ");
        printf("*");   /* 控制打印左侧的*号 */
        for(;x<WIDTH-m;x++) printf(" ");
        printf("*\n"); /* 控制打印同一行对应右侧的*号 */
    }
    return (0);
}
```
---
