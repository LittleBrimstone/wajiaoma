#include<stdio.h>
#include<math.h>
#include<string.h>
struct words
{
    int n;
    char c[30];
}w[10000];
int main()
{
    FILE *fp;
    char b[30], ch;
    int i = 0, m = 1, j = 0, k = 0, t = 0, flag = 0;
    fp = fopen("aaa.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        if ('A' <= ch&&ch <= 'Z') ch = ch + 32;//转小写
        if ('a' <= ch && ch <= 'z')                //字母
        {
            b[i] = ch; i++; flag = 1;//开始写入b
        }
        else
        {
            if (ch == '-' && (ch = fgetc(fp)) == '\n')//非字母 非空格
            {
                flag = 0;
            }
            else
            {
                if (flag == 1)                       //空格
                {
                    b[i] = '\0'; i = 0; flag = 0; m = 0;//写入b完成+'\0'
                    for (j = 0; j < k; j++)
                    {
                        if (strcmp(b, w[j].c) == 0)
                        {
                            m = 1;//标志 前有单词相同
                            break;
                        }
                    }
                    if (m) w[j].n++;//数量加1
                    else  //存入结构体
                    {
                        w[k].n = 1; strcpy(w[k].c, b); k++;
                    }
                }
            }
        }
    }
    /*输入 前5 */
    for (i = 0; i < k&&i < 5; i++)
    {
        t = 0;
        while (w[t].n == 0) t++;
        for (j = 1; j<k; j++)
        {
            if (w[j].n>w[t].n) t = j;//选 大的
            else
            if (w[j].n == w[t].n)
            {
                if (strcmp(w[j].c, w[t].c) < 0)
                    t = j;
            }
        }
        printf("%s %d\n", w[t].c, w[t].n);
        w[t].n = 0;//t 已输出，令n=0;
    }
}
