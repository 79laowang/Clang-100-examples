# C语言趣味100例
## 最简单的问题与算法
**小问题，大智慧**

![#157500](https://placehold.it/15/157500?text=+)  [1.绘制余弦曲线](#例1)  
![#98DEDE](https://placehold.it/15/98DEDE?text=+)  [2.绘制余弦曲线和直线](#例2)  
![#157500](https://placehold.it/15/157500?text=+)  [3.绘制圆](#例3)  
![#98DEDE](https://placehold.it/15/98DEDE?text=+)  [4.歌星大奖赛](#例4)  
![#157500](https://placehold.it/15/157500?text=+)  [5.求最大约数](#例5)  

###  例1.
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

###  例2.
**绘制余弦曲线和直线.**
   
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

###  例3.
**绘制圆.**
   
　　在屏幕上用"\*"画一个空心圆
### *问题分析与解答设计:*   
　　打印圆可利用图形的左右对称性。根据圆的方程：  
　　　　　　　　　　　　　　　　　　　　　　　　R\*R=X\*X + Y\*Y  
　　可以计算出圆上的每一个点的行和列的对应关系
  
**程序说明与注释**

```C
#include <stdio.h>
#include <math.h>
/* Compile with gcc -o draw-circle draw-circle.c -lm */
int main()
{
   double y;
   int x, m;

   for (y=10; y>=-10; y--){ /* 圆的半径为10 */
   /* 计算行y对应的列坐标m。需要调整2.5是屏幕纵横比例调节系数，因为屏幕的行距大于列距，不进行调整显示出来的将是椭圆 */
       m = 2 * sqrt(100-y*y);    
       for (x=1; x<30-m; x++) printf(" ");    /* 图形左侧空白控制 */ 
       printf("*");                     /* 圆左侧打印*/ 
       for (; x<30+m; x++) printf(" ");     /* 圆形空心部分控制 */   
       printf("*\n");     /* 圆右侧打印 */ 
}

```
**运行结果**

![Image of circle](https://github.com/79laowang/Clang-100-examples/blob/master/imgs/draw-circle.png)

**思考题**  

　　如何实现函数y=x^2图形和圆的图形叠加显示。
  
---

###  例4.
歌星大奖赛.

　　在歌星大奖赛中，有10个评委为参赛的选手打分，分数从1到100分。选手最后得分为：去掉一个最高分和一个最低分后，其余8个分数的平均值。编程实现。 
### 问题分析与解答设计:
　　算法比较简单，程序中判断最大、最小值的变量赋初值有些技巧。

**程序说明与注释**

```C
#include <stdio.h>

int main()
{
    int integer, i, max, min, sum;
    max=-32768;
    min=32768;
    sum=0;
    for (i=1; i<=10; i++){
         printf("Input number %d=",i);
         scanf("%d",&integer);
         sum+=integer;
         if (integer > max) max = integer;  /* 比大小，筛选出最高分 */
         if (integer < min) min = integer;  /* 比大小，筛选出最低分 */
    }
    printf("Canceled max score: %d\nCanceled min score: %d\n", max, min);
    printf("Average score: %d\n",(sum - max - min)/8);    /* 输出结果 */
    return (0);
}
```
**运行结果**
```Bash
$ ./singer-contest 
Input number 1=67
Input number 2=89
Input number 3=90
Input number 4=92
Input number 5=93
Input number 6=95
Input number 7=96
Input number 8=99
Input number 9=78
Input number 10=88
Canceled max score: 99
Canceled min score: 67
Average score: 90
```

**思考题**  
对评委的分数，找出最优（最接近平均分）和最差（和平均分差距最大）打分选择。  

---

###  例5.
输入一个数，求其中约数最大的三位是多少？  
 
### 问题分析与解答设计:
　　根据约数的定义，对于一个整数N，除去1和它自身之外，凡能整除N的数即为N的约数。因此，最简单的方法是用2到N-1之间的所有数去除N，即可以求出N的全部约数。本题只要求取约数中最大的三位数，则其取值范围可限定在100到999之间。

**程序说明与注释**

```C
#include <stdio.h>

int main()
{
    long i;
    int j;
    printf("Please input number >100:");
    scanf("%ld",&i);
    for(j=999;j>=100;j--)
        if(i%j==0){
            printf("The max factor with 3 digits in %ld is:%d.\n",i,j);
            break;
        }   
    return (0);
}
```
**运行结果**
```Bash
$ ./get-max-divisor 
Please input number >100:456
The max factor with 3 digits in 456 is:456.

$ ./get-max-divisor 
Please input number >100:99999
The max factor with 3 digits in 99999 is:813.

$ ./get-max-divisor 
Please input number >100:888888
The max factor with 3 digits in 888888 is:962.

$ ./get-max-divisor 
Please input number >100:123456
The max factor with 3 digits in 123456 is:643.
```
---

