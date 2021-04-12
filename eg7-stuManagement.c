/*
 *����:һ���򵥵�ѧ���ɼ�����ϵͳ
 *�汾��1.0
 *����:����
 *����:2007��3��29��
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define listsize 100     

/*����洢ѧ����Ϣ�Ľṹ��*/
struct student
{
    int num;      //ѧ��
    char name[10];   //����
    int mark;      //�ɼ�
    int length;   
}stu[listsize];

 void list();
 
/*�����ʾ��Ϣ*/
void print()
{
    printf("======Ҫ������ѧ�������밴N======\n");
    printf("======Ҫ����ѧ�������밴I========\n");
    printf("======Ҫɾ��ѧ�������밴D========\n");
    printf("======Ҫ��ѯѧ�������밴S========\n");
    printf("======Ҫ�˳�ѧ������ϵͳ�밴x========\n");
}

/*��ʼ��*/
void Init()
{
    struct student *p;
    p=stu;
    int i,j;
    printf("Ҫ������ٸ�ѧ��������?:");
    scanf("%d",&i);
    
    for(j=0;j<i;j++)     //����ѧ������
    {
        printf("ѧ��   ����  �ɼ�\n");
        scanf("%d ",&stu[j].num);
        scanf("%s ",stu[j].name);
        scanf("%d",&stu[j].mark);
        p->length=j;
    }
    list();      //��ʾѧ����Ϣ�嵥
}

/*����ѧ������*/
void Insert()
{
    struct student *p;
    p=stu;
    int i,j;
    printf("����Ҫ�ڵڼ���ѧ��ǰ��������?:");
    scanf("%d",&i);
    p->length++;
    for(j=p->length;j>=i-1;j--)
    {
        stu[j+1].num=stu[j].num;
        strcpy(stu[j+1].name,stu[j].name);
        stu[j+1].mark=stu[j].mark;
    }
    printf("ѧ��   ����  �ɼ�\n");
    scanf("%d ",&stu[i-1].num);
    scanf("%s ",stu[i-1].name);
    scanf("%d",&stu[i-1].mark);
    list();     //��ʾѧ����Ϣ�嵥
}

/*ɾ��ѧ������*/
void Del()
{
    struct student *p;
    p=stu;
    int i,j;
    printf("����Ҫɾ���ڼ���ѧ��������?:");
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

/*�������ַ�ʽ����ѧ������*/
void Search()
{
    struct student *p;
    p=stu;
    char xingming[5];
    int xuehao,chengji,i,flag,shuru;
    printf("=====Ҫ��ѧ�Ų�ѯ�밴'1'=====\n");
    printf("=====Ҫ��������ѯ�밴'2'=====\n");
    printf("=====Ҫ���ɼ���ѯ�밴'3'=====\n");
    scanf("%d",&shuru);
    switch(shuru)
    {
    case 1:
        printf("������ѧ��ѧ��:");
        scanf("%d",&xuehao);
        flag=0;
        for(i=0;i<=p->length;i++)
        {
            if (stu[i].num==xuehao)
            {
                printf("����ѧ���嵥����\n");
                printf("ѧ��   ����  �ɼ�\n");
                printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
                flag++;
            }
            else
                flag=flag+0;
        }
        if(flag==0)
            printf("�Ҳ������ѧ�����ϣ�");
        break;
    case 2:
        printf("������ѧ��������");
        scanf("%s",xingming);
        flag=0;
        for(i=0;i<=p->length;i++)
        {
            if (strcmp(stu[i].name,xingming)==0)
            {
                printf("����ѧ���嵥����\n");
                printf("ѧ��   ����  �ɼ�\n");
                printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
                flag++;
            }
            else
                flag=flag+0;
        }
        if(flag==0)
            printf("�Ҳ������ѧ�����ϣ�");
        break;
    case 3:
        printf("������ѧ���ɼ���");
        scanf("%d",&chengji);
        flag=0;
        for(i=0;i<=p->length;i++)
        {
            if (stu[i].mark==chengji)
            {
                printf("����ѧ���嵥����\n");
                printf("ѧ��   ����  �ɼ�\n");
                printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
                flag++;
            }
            else 
                flag=flag+0;
        }
            if(flag==0)
                printf("�Ҳ������ѧ�����ϣ�");
        break;
    default:break;
    }
}

void Exit()
{
    exit(-1);
}

/*��ʾ��Ϣ�嵥*/
void list()
{
    int i;
    struct student *p;
    p=stu;
    printf("����ѧ���嵥����\n");
    printf("ѧ��   ����  �ɼ�\n");
    for(i=0;i<=p->length;i++)
    {
        printf("%d     %s     %d\n",stu[i].num,stu[i].name,stu[i].mark);
    }
}

/*������*/
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
