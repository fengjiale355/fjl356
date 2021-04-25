#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
/**
进制转换：利用栈的先进后出特性，定义栈顶base和栈底top两个指针，
**/
typedef char ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqstack;

//初始化栈
void Initstack(sqstack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));//申请空间
    if(!s->base)//检验地址是否申请成功
    {
        exit(0);
    }

    s->top = s->base;//空栈
    s->stacksize =STACK_INIT_SIZE;//栈的长度
}
//入栈
void Push(sqstack *s,ElemType e)
{
    if(s->top - s->base >= s->stacksize)//检验栈是否已满，已满就申请空间
    {
        s->base = (ElemType *)realloc(s->base,(STACKINCREMENT+STACK_INIT_SIZE )* sizeof(ElemType));
        if(!s->base)
        {
            exit(0);
        }
    }
    *(s->top) = e;//将e入栈
    s->top++;
}
//出栈
void Pop(sqstack *s,ElemType *e)
{
    if(s->top==s->base)//空栈退出
    {
        return;
    }
    *e =*--(s->top);//将栈顶元素赋给e出栈
}
//计算栈的元素个数
int Stacklen(sqstack s)
{
    return (s.top - s.base);
}
int main()
{
    ElemType c;
    sqstack s;
    int i,sum=0,len;
    Initstack(&s);
    printf("请输入二进制数，输入#符号表示结束！\n");
    scanf("%c",&c);
    while(c != '#')
    {
        Push(&s,c);
        scanf("%c",&c);
    }
    getchar();//接受回车

    len = Stacklen(s);
    printf("栈的当前容量:%d\n",len);
    for(i=0;i<len;i++)
    {
        Pop(&s,&c);
        sum = sum + (c-48)*pow(2,i);
    }
    printf("转换后的值为：%d\n",sum);
    return 0;
}
