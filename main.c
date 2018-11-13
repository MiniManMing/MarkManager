#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ѧ�����ݽṹ��װ
struct Student {
    int tempId;//����ID
    char No[13];//ѧ��ѧ��
    char Name[10];//ѧ������
    char Sex[4];//ѧ���Ա�
    char Class[20];//ѧ���༶
    char Tel[11];//ѧ���绰
};

//�ɼ����ݽṹ��װ
struct Mark{
    char ClassName[20];//�γ�����
    float ClassMark;//�γ̳ɼ�
};

//ѧ���ڵ�ṹ
typedef struct StudentNode{
    struct StudentNode *UP; //ǰָ��
    struct Student student; //ѧ������
    float Total;//�ɼ��ܷ�
    float Avg;//�ɼ�ƽ����
    struct MarkNode *SMN;
    struct StudentNode *DOWN;//��ָ��
}SNODE,*UN,*DN;

//�ɼ��ڵ�ṹ
typedef struct MarkNode{
    struct Mark mark;//�ɼ�����
    struct MarkNode *D;//��ָ��
}MNODE,*PMNODE;



//���Y��N
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
        printf("�ڴ����ʧ��,������ֹ!\n");

        exit(-1);
    }
    return phead;

}
PMNODE CreateMark(void){
    PMNODE mhead =(PMNODE)malloc(sizeof(MNODE));
    if(NULL == mhead)
    {
        printf("�ڴ����ʧ��,������ֹ!\n");

        exit(-1);
    }
    return mhead;
}
PMNODE InputMarkInfo(PMNODE mhead){
    MNODE mark;
    if(NULL == mhead){
        printf("��ִ�г�ʼ������\n");
    }else{
        printf("��ӭ����ɼ�¼��ϵͳȷ�ϰ�Y�˳���N(Y?N)\n");
        char c;
        scanf("%s",&c);
        if(checkExit(c)){
            PMNODE ptail=mhead;
            ptail->D=NULL;
            for(int i=0;;i++){
                system("cls");//����
                printf("�������%d�ſε�����:", i+1);
                scanf("%s", mark.mark.ClassName);
                printf("������Y�˳���N(Y?N)\n");
                char s;
                scanf("%s",&s);
                if(checkExit(s)){
                    PMNODE mnew =(PMNODE)malloc(sizeof(MNODE));
                    if(NULL == mnew)
                    {
                        printf("�ڴ����ʧ��,������ֹ!\n");

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
                        printf("�ڴ����ʧ��,������ֹ!\n");

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
       printf("���Ƶ������ǿյ�");
       return NULL;
   }else if(mhead->D==NULL){
       printf("���Ƶ������ǿյ�");
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
            printf("��ִ�г�ʼ������\n");
        } else{
            printf("��ӭ����ѧ��¼��ϵͳȷ�ϰ�Y�˳���N(Y?N)\n");
            char c;
            scanf("%s",&c);
            if(checkExit(c)){
                DN ptail = phead;
                ptail->DOWN=NULL;
                for(int i=0;;i++){
                    system("cls");//����
                    stu.student.tempId=i+1;
                    printf("�������%d��ѧ����ѧ��:", i+1);
                    scanf("%s", stu.student.No);
                    printf("�������%d��ѧ��������:", i+1);
                    scanf("%s", stu.student.Name);
                    printf("�������%d��ѧ�����Ա�:", i+1);
                    scanf("%s", stu.student.Sex);
                    printf("�������%d��ѧ���İ༶:", i+1);
                    scanf("%s", stu.student.Class);
                    printf("�������%d��ѧ���ĵ绰", i+1);
                    scanf("%s", stu.student.Tel);
                    printf("������Y�˳���N(Y?N)\n");
                    char s;
                    scanf("%s",&s);
                    if(checkExit(s)){
                        DN pnew=(DN)malloc(sizeof(SNODE));
                        if(NULL == pnew)
                        {
                            printf("�ڴ����ʧ��,������ֹ!\n");

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
                            printf("�ڴ����ʧ��,������ֹ!\n");

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
    //����һ��ָ�����ڱ���ѧ����Ϣ

    int count=1;
    printf("ID   ѧ��  ����\n");

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
        printf("û��ѧ����γ�������¼��\n");
        return 0;
    }
    DN pp=pHead->DOWN;
    DN re=pp;
   while (1){
       int i=0;
       DN p=pHead->DOWN;
       OutputStudentToolOfMark(p);
       printf("��������Ҫ¼��ɼ���ѧ�����:\n");
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
                       printf("������%s��%s�ɼ�:",p->student.Name,mp->mark.ClassName);
                       float mark;
                       scanf("%f",&mark);
                       if(mark>=0&&mark<=100){
                           mp->mark.ClassMark=mark;
                           sum=sum+mark;
                           mcount++;
                           flag=0;
                       }else{
                           printf("�ɼ�У��ʧ�ܣ����������룡\n");
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
       printf("�����밴Y�˳���N(Y?N)");
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
    //����һ��ָ�����ڱ���ѧ����Ϣ
    DN p = pHead->DOWN;

    printf("ID ѧ��  ����  �Ա�  �༶  �绰\n");

    while(NULL != p)
    {
        printf("%d  %s  %s  %s  %s  %s\n", p->student.tempId, p->student.No, p->student.Name, p->student.Sex, p->student.Class, p->student.Tel);

        p = p->DOWN;

    }


}
void OutputMarkInfo(PMNODE pHead)
{
    //����һ��ָ�����ڱ���ѧ����Ϣ
    PMNODE p = pHead->D->D;

    printf("�γ���\n");

    while(NULL != p)
    {
        printf("%s  \n", p->mark.ClassName);

        p = p->D;

    }


}
void OutputMarkDetail(DN pHead){
    DN p=pHead;
    while (NULL !=p){
        printf("ID         ѧ��         ����         �ܷ�         ƽ����\n");
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
    printf("��������Ҫɾ����ѧ����ID:");
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
    printf("��������Ҫ�����λ�ã�");
    int flag=0;
    scanf("%d",&flag);
    DN pnew=(DN)malloc(sizeof(SNODE));
    DN temp=pHead;
    while (NULL!=temp->DOWN){
        if(temp->student.tempId==flag){
            SNODE stu;
            stu.student.tempId=flag;
            printf("�������%d��ѧ����ѧ��:", flag);
            scanf("%s", stu.student.No);
            printf("�������%d��ѧ��������:", flag);
            scanf("%s", stu.student.Name);
            printf("�������%d��ѧ�����Ա�:", flag);
            scanf("%s", stu.student.Sex);
            printf("�������%d��ѧ���İ༶:", flag);
            scanf("%s", stu.student.Class);
            printf("�������%d��ѧ���ĵ绰", flag);
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