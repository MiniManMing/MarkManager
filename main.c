#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//学生数据结构封装
struct Student {
    int tempId;//自增ID
    char No[13];//学生学号
    char Name[10];//学生姓名
    char Sex[4];//学生性别
    char Class[20];//学生班级
    char Tel[11];//学生电话
};

//成绩数据结构封装
struct Mark{
    char ClassName[20];//课程名称
    float ClassMark;//课程成绩
};

//学生节点结构
typedef struct StudentNode{
    struct StudentNode *UP; //前指针
    struct Student student; //学生数据
    float Total;//成绩总分
    float Avg;//成绩平均分
    struct MarkNode *SMN;
    struct StudentNode *DOWN;//后指针
}SNODE,*UN,*DN;

//成绩节点结构
typedef struct MarkNode{
    struct Mark mark;//成绩数据
    struct MarkNode *D;//下指针
}MNODE,*PMNODE;



//检查Y？N
int checkExit(char c){
    if('Y'==c||'y'==c)
        return 1;
    else
        return 0;
}

DN CreateList(void){
    DN phead =(DN)malloc(sizeof(SNODE));
    if(NULL == phead)
    {
        printf("内存分配失败,程序终止!\n");

        exit(-1);
    }
    return phead;

}
PMNODE CreateMark(void){
    PMNODE mhead =(PMNODE)malloc(sizeof(MNODE));
    if(NULL == mhead)
    {
        printf("内存分配失败,程序终止!\n");

        exit(-1);
    }
    return mhead;
}
PMNODE InputMarkInfo(PMNODE mhead){
    MNODE mark;
    if(NULL == mhead){
        printf("请执行初始化命令\n");
    }else{
        printf("欢迎进入成绩录入系统确认按Y退出按N(Y?N)\n");
        char c;
        scanf("%s",&c);
        if(checkExit(c)){
            PMNODE ptail=mhead;
            ptail->D=NULL;
            for(int i=0;;i++){
                system("cls");//清屏
                printf("请输入第%d门课的名字:", i+1);
                scanf("%s", mark.mark.ClassName);
                printf("继续按Y退出按N(Y?N)\n");
                char s;
                scanf("%s",&s);
                if(checkExit(s)){
                    PMNODE mnew =(PMNODE)malloc(sizeof(MNODE));
                    if(NULL == mnew)
                    {
                        printf("内存分配失败,程序终止!\n");

                        exit(-1);
                    }
                    mnew->mark=mark.mark;
                    ptail->D=mnew;
                    mnew->D=NULL;
                    ptail=mnew;
                } else{
                    PMNODE emnew =(PMNODE)malloc(sizeof(MNODE));
                    if(NULL == emnew)
                    {
                        printf("内存分配失败,程序终止!\n");

                        exit(-1);
                    }
                    emnew->mark=mark.mark;
                    ptail->D=emnew;
                    emnew->D=NULL;
                    return mhead;
                }
            }
        }
    }
}
PMNODE MarkNodeCopy(PMNODE mhead){
    PMNODE h,a;
   if(mhead == NULL){
       printf("复制的链表是空的");
       return NULL;
   }else if(mhead->D==NULL){
       printf("复制的链表是空的");
       return NULL;
   }
   h=a=(PMNODE)malloc(sizeof(MNODE));
   a->D=(PMNODE)malloc(sizeof(MNODE));
   a=a->D;
   while (1){
       strcpy(a->mark.ClassName,mhead->mark.ClassName);
       a->mark.ClassMark=0;
       if(mhead->D!=NULL){
           mhead=mhead->D;
           a->D=(PMNODE)malloc(sizeof(MNODE));
           a=a->D;
       } else{
           a->D=NULL;
           break;
       }
   }
    return h;

}

DN InputStudent(DN phead){
        SNODE stu;
        if(NULL == phead){
            printf("请执行初始化命令\n");
        } else{
            printf("欢迎进入学生录入系统确认按Y退出按N(Y?N)\n");
            char c;
            scanf("%s",&c);
            if(checkExit(c)){
                DN ptail = phead;
                ptail->DOWN=NULL;
                for(int i=0;;i++){
                    system("cls");//清屏
                    stu.student.tempId=i+1;
                    printf("请输入第%d个学生的学号:", i+1);
                    scanf("%s", stu.student.No);
                    printf("请输入第%d个学生的姓名:", i+1);
                    scanf("%s", stu.student.Name);
                    printf("请输入第%d个学生的性别:", i+1);
                    scanf("%s", stu.student.Sex);
                    printf("请输入第%d个学生的班级:", i+1);
                    scanf("%s", stu.student.Class);
                    printf("请输入第%d个学生的电话", i+1);
                    scanf("%s", stu.student.Tel);
                    printf("继续按Y退出按N(Y?N)\n");
                    char s;
                    scanf("%s",&s);
                    if(checkExit(s)){
                        DN pnew=(DN)malloc(sizeof(SNODE));
                        if(NULL == pnew)
                        {
                            printf("内存分配失败,程序终止!\n");

                            exit(-1);
                        }
                        pnew->student=stu.student;
                        ptail->DOWN=pnew;
                        pnew->UP=ptail;
                        pnew->DOWN=NULL;
                        ptail=pnew;

                    } else{
                        DN epnew=(DN)malloc(sizeof(SNODE));
                        if(NULL == epnew)
                        {
                            printf("内存分配失败,程序终止!\n");

                            exit(-1);
                        }
                        epnew->student=stu.student;
                        ptail->DOWN=epnew;
                        epnew->UP=ptail;
                        epnew->DOWN=NULL;
                        return phead;
                    }
                }
            }

        }

}



void OutputStudentToolOfMark(DN pHead)
{
    //定义一个指针用于遍历学生信息

    int count=1;
    printf("ID   学号  姓名\n");

    while(NULL != pHead)
    {
        printf("%d  %s  %s       ", pHead->student.tempId, pHead->student.No, pHead->student.Name);
        pHead = pHead->DOWN;
        count++;
        if(count>5){
            printf("\n");
            count=1;
        }

    }


}
DN InputStudentMark(DN pHead,PMNODE mHead){
    if(pHead==NULL||mHead==NULL){
        printf("没有学生或课程数据请录入\n");
        return 0;
    }
    DN pp=pHead->DOWN;
    DN re=pp;
   while (1){
       int i=0;
       DN p=pHead->DOWN;
       OutputStudentToolOfMark(p);
       printf("请输入你要录入成绩的学生序号:\n");
       scanf("%d",&i);
       while (p!=NULL){
           if(p->student.tempId==i){
               PMNODE copy=MarkNodeCopy(mHead);
               PMNODE mp=copy->D->D;
               int mcount=0;
               float sum=0;
               while (mp!=NULL){
                   int flag=1;
                   while(flag){
                       printf("请输入%s的%s成绩:",p->student.Name,mp->mark.ClassName);
                       float mark;
                       scanf("%f",&mark);
                       if(mark>=0&&mark<=100){
                           mp->mark.ClassMark=mark;
                           sum=sum+mark;
                           mcount++;
                           flag=0;
                       }else{
                           printf("成绩校验失败！请重新输入！\n");
                       }

                   }
                   mp=mp->D;
               }
               p->Total=sum;
               p->Avg=sum/mcount;
               p->SMN=copy->D->D;
               //printf("%.1f %.1f",p->Total,p->Avg);
               //printf("%s,%f",p->SMN->mark.ClassName,p->SMN->mark.ClassMark);
           }
           p=p->DOWN;
       }
       printf("继续请按Y退出按N(Y?N)");
       char c;
       scanf("%s",&c);
       if(checkExit(c)){
           continue;
       } else{
           return re;
       }
   }


}
void OutputStudent(DN pHead)
{
    //定义一个指针用于遍历学生信息
    DN p = pHead->DOWN;

    printf("ID 学号  姓名  性别  班级  电话\n");

    while(NULL != p)
    {
        printf("%d  %s  %s  %s  %s  %s\n", p->student.tempId, p->student.No, p->student.Name, p->student.Sex, p->student.Class, p->student.Tel);

        p = p->DOWN;

    }


}
void OutputMarkInfo(PMNODE pHead)
{
    //定义一个指针用于遍历学生信息
    PMNODE p = pHead->D->D;

    printf("课程名\n");

    while(NULL != p)
    {
        printf("%s  \n", p->mark.ClassName);

        p = p->D;

    }


}
void OutputMarkDetail(DN pHead){
    DN p=pHead;
    while (NULL !=p){
        printf("ID         学号         姓名         总分         平均分\n");
        printf("%d          %s          %s          %.1f          %.1f\n",p->student.tempId,p->student.No,p->student.Name,p->Total,p->Avg);
     PMNODE m=pHead->SMN;
        while(NULL !=m){
            printf("%s:          %.1f\n",m->mark.ClassName,m->mark.ClassMark);
            m=m->D;
        }
        p=p->DOWN;
    }
}

void DeleteStudent(DN pHead){
    OutputStudent(pHead);
    DN d=pHead;
    printf("请输入你要删除的学生的ID:");
    int flag=0;
    scanf("%d",&flag);
    while(NULL!=d->DOWN){
        if(flag==d->student.tempId){
            DN t=d->DOWN;
            DN h=d->UP;
            h->DOWN=t;
            t->UP=h;
            free(d);
        }
        d=d->DOWN;
    }

    OutputStudent(pHead);

}
void InsertStudent(DN pHead){
    OutputStudent(pHead);
    printf("请输入你要插入的位置！");
    int flag=0;
    scanf("%d",&flag);
    DN pnew=(DN)malloc(sizeof(SNODE));
    DN temp=pHead;
    while (NULL!=temp->DOWN){
        if(temp->student.tempId==flag){
            SNODE stu;
            stu.student.tempId=flag;
            printf("请输入第%d个学生的学号:", flag);
            scanf("%s", stu.student.No);
            printf("请输入第%d个学生的姓名:", flag);
            scanf("%s", stu.student.Name);
            printf("请输入第%d个学生的性别:", flag);
            scanf("%s", stu.student.Sex);
            printf("请输入第%d个学生的班级:", flag);
            scanf("%s", stu.student.Class);
            printf("请输入第%d个学生的电话", flag);
            scanf("%s", stu.student.Tel);
            pnew->student=stu.student;
            DN d=temp->DOWN;
            DN u=temp->UP;
            u->DOWN=pnew;
            pnew->UP=u;
            pnew->DOWN=temp;
            temp->UP=pnew;
            while (NULL!=pnew->DOWN){
                pnew->DOWN->student.tempId++;
                pnew=pnew->DOWN;
            }

        }
        temp=temp->DOWN;
    }

    OutputStudent(pHead);


}



DN CreateList(void);
DN InputStudent(DN phead);
void OutputMarkInfo(PMNODE pHead);
PMNODE CreateMark(void);
PMNODE MarkNodeCopy(PMNODE mhead);
DN InputStudentMark(DN pHead,PMNODE mHead);
void OutputMarkDetail(DN pHead);
void main(){
    DN p =CreateList();
    p=InputStudent(p);
    DeleteStudent(p);
    InsertStudent(p);
    OutputStudent(p);
    PMNODE pm=CreateMark();
    pm=InputMarkInfo(pm);
    OutputMarkInfo(pm);
    DN pp=InputStudentMark(p,pm);
    OutputMarkDetail(pp);
}