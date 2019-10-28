# C语言趣味100例
## 最简单的问题与算法
**小问题，大智慧**

![#157500](https://placehold.it/15/157500?text=+)  [1.绘制余弦曲线](#Q1)  

![#157500](https://placehold.it/15/157500?text=+)  [2.绘制余弦曲线和直线](#Q2)

###  Q1 绘制余弦曲线
   **绘制余弦曲线.**
　　在屏幕上用"\*"显示0°～360°的余弦cos(x)曲线
### *问题分析与解答设计:*   
　　如果使用数组，这个问题十分简单，可以在数组中设定图形。但若规定不能使用数组，问题就变得不容易了。  
　　关键在于余弦曲线在0°～360°的区间内，一行要显示两个点，而对于一般的显示器来说，只能按行输出，即：输出的第一行信息后，只能向下一行输出，不能再返回到上一行，要输出图形就必须在一行中一次顺序输出两个"\*"。  
　　为了同时得到余弦函数cos(x)图形在一行上的两个点，考虑利用cos(x)的左右对称性。将屏幕的行方向定义为x，列方向定义为y，则0°～180°的图形与180°～360°的图形是左右对称的。若定义图形的总宽度为62列，计算出x行0°～180°是的y点坐标m，那么在同一行与之对称的180°～360°的y点的坐标就为62-m。程序中利用反余弦函数acos计算坐标(x,y)的对应关系。  
　　使用这种方法编出的程序短小精炼，体现了一定的技巧。  

注：  
　　反余弦函数（反三角函数之一）为余弦函数y=cosx（x∈[-½π,½π]）的反函数，记作y=arccosx或cosy=x(x∈[-1,1])。由原函数的图像和它的反函数的图像关于一三象限角平分线对称可知余弦函数的图像和反余弦函数的图像也关于一三象限角平分线对称。
  
**程序说明与注释**

```C
#include <stdio.h>
#include <math.h>

#define WIDTH 62

 /* Compile with  gcc -o cos-diagram cos-diagram.c -lm */
int main()
{
    double y;   /* 列 */
    int x, m;   /* x为行 */
    for (y=1;y>=-1;y-=0.1){   /* y为列方向，值从1到-1，步长0.1 */
        m=acos(y)*10;         /*计算出y对应的弧度m,乘10为图形放大倍数 */
        for (x=1;x<m;x++) printf(" ");
        printf("*");          /* 控制打印左侧的*号 */
        for(;x<WIDTH-m;x++) printf(" ");
        printf("*\n");        /* 控制打印同一行对应右侧的*号 */
    }
    return (0);
}
```
**运行结果**

![Image of cos-diagram](https://github.com/79laowang/Clang-100-examples/blob/master/imgs/cos-diagram.png)

**思考题**  

　　如何实现用"\*"绘制0°～360°的正弦sin(x)曲线
  
---

###  Q2 绘制余弦曲线和直线.
    绘制余弦曲线和直线.
　　在屏幕上显示0°～360°的余弦cos(x)曲线与直线f(x)=45*(y-1)+31的迭加图形，其中cos(x)图形用"\*"显示，f(x)用"+"表示，在两个图形的交接点处用(fx)图形的符号。
### *问题分析与解答设计:*   
　　本题可以在上面的题的基础上进行修改。图形迭加的关键是要在分别计算出同一行中两个图形的列方向上点的坐标后，正确判断相互的位置关系。为此可以先判定图形的交点，再分别控制打印出两个不同的图形。  

注：  
　　反余弦函数（反三角函数之一）为余弦函数y=cosx（x∈[-½π,½π]）的反函数，记作y=arccosx或cosy=x(x∈[-1,1])。由原函数的图像和它的反函数的图像关于一三象限角平分线对称可知余弦函数的图像和反余弦函数的图像也关于一三象限角平分线对称。
  
**程序说明与注释**

```C
#include <stdio.h>
#include <math.h>

#define WIDTH 62

 /* Compile with  gcc -o cos-diagram cos-diagram.c -lm */
#include <stdio.h>
#include <math.h>
int main()
{
    double y;
    int x ,m, n, yy;
    for (yy=0; y<=20;yy++){
        /* 对于每一个y坐标进行计算并在一行中打印图形 */
        y = 0.1 *yy;        /* y:屏幕行方向坐标 */
        m = acos(1-y)*10;   /* m:cos(x)曲线上y点对应的屏幕列坐标  */
        n = 45*(y-1)+WIDTH/2;    /* n:直线上y点对应的列坐标   */
        for(x=0; x<=WIDTH;x++)    /* x:屏幕列方向坐标 */
            if (x==m && x==n)  printf("+");   /* 直线与cos(x)相交时打印'+' */
            else if ( x==n )   printf("+");   /* 打印不相交时直线'+'图形  */
            else if (x==m || x==WIDTH-m)  printf("*");   /* 打印不相交时cos(x)'*'图形  */
            else  printf(" ");    /*  其他情况打印空格占位  */
            printf("\n");
    }
    return (0);
}

```
**运行结果**

![Image of cos-line-diagram](https://github.com/79laowang/Clang-100-examples/blob/master/imgs/cos-line-diagram.png)

**思考题**  

　　如何实现正弦sin(x) 和余弦cos(x)曲线同时出现显示。
  
---
