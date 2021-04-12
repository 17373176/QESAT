/*
 *功能:一个简单的学生成绩管理系统
 *版本：1.0
 *作者:闫磊
 *日期:2007年3月29日
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define listsize 100     

/*定义存储学生信息的结构体*/
struct student
{
    int num;      //学号
    char name[10];   //姓名
    int mark;      //成绩
    int length;   
}stu[listsize];

 void list();
 
/*输出提示信息*/
void print()
{
    printf("======要新输入学生数据请按N======\n");
    printf("======要插入学生数据请按I========\n");
    printf("======要删除学生数据请按D========\n");
    printf("======要查询学生数据请按S========\n");
    printf("======要退出学生管理系统请按x========\n");
}

/*初始化*/
void Init()
{
    struct student *p;
    p=stu;
    int i,j;
    printf("要输入多少个学生的数据?:");
    scanf("%d",&i);
    
    for(j=0;j<i;j++)     //接受学生数据
    {
        printf("学号   姓名  成绩\n");
        scanf("%d ",&stu[j].num);
        scanf("%s ",stu[j].name);
        scanf("%d",&stu[j].mark);
        p->length=j;
    }
    list();      //显示学生信息清单
}

/*插入学生数据*/
void Insert()
{
    struct student *p;
    p=stu;
    int i,j;
    printf("请问要在第几个学生前插入数据?:");
    scanf("%d",&i);
    p->length++;
    for(j=p->length;j>=i-1;j--)
    {
        stu[j+1].num=stu[j].num;
        strcpy(stu[j+1].name,stu[j].name);
        stu[j+1].mark=stu[j].mark;
    }
    printf("学号   姓名  成绩\n");
    scanf("%d ",&stu[i-1].num);
    scanf("%s ",stu[i-1].name);
    scanf("%d",&stu[i-1].mark);
    list();     //显示学生信息清单
}

/*删除学生数据*/
void Del()
{
    struct student *p;
    p=stu;
    int i,j;
    printf("请问要删除第几个学生的资料?:");
    scanf("%d",&i);
    for(j=i-1;j<=p->length;j++)
    {
        stu[j].num=stu[j+1].num;
        strcpy(stu[j].name,stu[j+1].name);
        stu[j].mark=stu[j+1].mark;
    }
    p->length--;
    list();
}

/*按照三种方式查找学生数据*/
void Search()
{
    struct student *p;
    p=stu;
    char xingming[5];
    int xuehao,chengji,i,flag,shuru;
    printf("=====要按学号查询请按'1'=====\n");
    printf("=====要按姓名查询请按'2'=====\n");
    printf("=====要按成绩查询请按'3'=====\n");
    scanf("%d",&shuru);
    switch(shuru)
    {
    case 1:
        printf("请输入学生学号:");
        scanf("%d",&xuehao);
        flag=0;
        for(i=0;i<=p->length;i++)
        {
            if (stu[i].num==xuehao)
            {
                printf("＝＝学生清单＝＝\n");
                printf("学号   姓名  成绩\n");
                printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
                flag++;
            }
            else
                flag=flag+0;
        }
        if(flag==0)
            printf("找不到相关学生资料！");
        break;
    case 2:
        printf("请输入学生姓名：");
        scanf("%s",xingming);
        flag=0;
        for(i=0;i<=p->length;i++)
        {
            if (strcmp(stu[i].name,xingming)==0)
            {
                printf("＝＝学生清单＝＝\n");
                printf("学号   姓名  成绩\n");
                printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
                flag++;
            }
            else
                flag=flag+0;
        }
        if(flag==0)
            printf("找不到相关学生资料！");
        break;
    case 3:
        printf("请输入学生成绩：");
        scanf("%d",&chengji);
        flag=0;
        for(i=0;i<=p->length;i++)
        {
            if (stu[i].mark==chengji)
            {
                printf("＝＝学生清单＝＝\n");
                printf("学号   姓名  成绩\n");
                printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
                flag++;
            }
            else 
                flag=flag+0;
        }
            if(flag==0)
                printf("找不到相关学生资料！");
        break;
    default:break;
    }
}

void Exit()
{
    exit(-1);
}

/*显示信息清单*/
void list()
{
    int i;
    struct student *p;
    p=stu;
    printf("＝＝学生清单＝＝\n");
    printf("学号   姓名  成绩\n");
    for(i=0;i<=p->length;i++)
    {
        printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
    }
}

/*主函数*/
int main()
{
    char ch;
    print();
    while((ch=getchar())!='X'||(ch=getchar())!='x')
    {
        switch (ch)
        {
            case 'N':Init();break;
            case 'n':Init();break;
            case 'I':Insert();break;
            case 'i':Insert();break;
            case 'D':Del();break;
            case 'd':Del();break;
            case 'S':Search();break;
            case 's':Search();break;    
            case 'X':Exit();break;
            case 'x':Exit();break;
            default:break;
        }
    }
	return 0;
}
