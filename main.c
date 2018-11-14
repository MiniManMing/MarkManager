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
                    printf("�������%d��ѧ����ѧ��:\n", i+1);
                    scanf("%s", stu.student.No);
                    printf("�������%d��ѧ��������:\n", i+1);
                    scanf("%s", stu.student.Name);
                    printf("�������%d��ѧ�����Ա�:\n", i+1);
                    scanf("%s", stu.student.Sex);
                    printf("�������%d��ѧ���İ༶:\n", i+1);
                    scanf("%s", stu.student.Class);
                    printf("�������%d��ѧ���ĵ绰\n", i+1);
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
                       printf("������%s��%s�ɼ�:\n",p->student.Name,mp->mark.ClassName);
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
       printf("�����밴Y�˳���N(Y?N)\n");
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

void OutputMark(PMNODE pHead)
{
    PMNODE p = pHead->D;

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
     PMNODE m=p->SMN;
        while(NULL !=m){
            printf("%s:          %.1f\n",m->mark.ClassName,m->mark.ClassMark);
            m=m->D;
        }
        p=p->DOWN;
    }
}
void OutputOrderByMarkDetail(DN pHead){
    DN p=pHead->DOWN;
    while (NULL !=p){
        printf("ID         ѧ��         ����\n");
        printf("%d          %s          %s\n",p->student.tempId,p->student.No,p->student.Name);
        p=p->DOWN;
    }
}

void DeleteStudent(DN pHead){
    OutputStudent(pHead);
    DN temp;
    DN d=pHead;
    printf("��������Ҫɾ����ѧ����ID:\n");
    int flag=0;
    scanf("%d",&flag);
    while(NULL!=d->DOWN){
        if(flag==d->student.tempId){
            DN t=d->DOWN;
            DN h=d->UP;
            h->DOWN=t;
            t->UP=h;
            temp=t;
            free(d);
        }
        d=d->DOWN;
    }
    while (temp!=NULL){
        temp->student.tempId--;
        temp=temp->DOWN;
    }

    OutputStudent(pHead);

}
void InsertStudent(DN pHead){
    OutputStudent(pHead);
    printf("��������Ҫ�����λ�ã�\n");
    int flag=0;
    scanf("%d",&flag);
    DN pnew=(DN)malloc(sizeof(SNODE));
    DN temp=pHead;
    while (NULL!=temp->DOWN){
        if(temp->student.tempId==flag){
            SNODE stu;
            stu.student.tempId=flag;
            printf("�������%d��ѧ����ѧ��:\n", flag);
            scanf("%s", stu.student.No);
            printf("�������%d��ѧ��������:\n", flag);
            scanf("%s", stu.student.Name);
            printf("�������%d��ѧ�����Ա�:\n", flag);
            scanf("%s", stu.student.Sex);
            printf("�������%d��ѧ���İ༶:\n", flag);
            scanf("%s", stu.student.Class);
            printf("�������%d��ѧ���ĵ绰\n", flag);
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
void InsertMark(PMNODE mhead){

    while (NULL!=mhead){
        if(mhead->D==NULL){
            PMNODE pnew=(PMNODE)malloc(sizeof(MNODE));
            MNODE mnode;
            printf("������γ�����:\n");
            scanf("%s", mnode.mark.ClassName);
            pnew->mark=mnode.mark;
            pnew->D=NULL;
            printf("%s",mhead->mark.ClassName);
            mhead->D=pnew;
            printf("�����밴Y�˳���N(Y?N)\n");
            char c;
            scanf("%s",&c);
            if(checkExit(c)){
                continue;
            } else{
                break;
            }

        }
        mhead=mhead->D;
    }
}
void ChangeStudent(DN pHead){
    OutputMarkDetail(pHead->DOWN);
    printf("������Ҫ�޸ĵ�ѧ����ID\n");
    int tempId;
    scanf("%d",&tempId);
    while(pHead!=NULL){
        if(pHead->student.tempId==tempId){
            printf("�������%d��ѧ����ѧ��:\n", pHead->student.tempId);
            scanf("%s", pHead->student.No);
            printf("�������%d��ѧ��������:\n", pHead->student.tempId);
            scanf("%s", pHead->student.Name);
            printf("�������%d��ѧ�����Ա�:\n", pHead->student.tempId);
            scanf("%s", pHead->student.Sex);
            printf("�������%d��ѧ���İ༶:\n", pHead->student.tempId);
            scanf("%s", pHead->student.Class);
            printf("�������%d��ѧ���ĵ绰\n", pHead->student.tempId);
            scanf("%s", pHead->student.Tel);
            printf("�Ƿ�Ҫ�޸ĳɼ���Ϣȷ�ϰ�Y�˳���N(Y?N)\n");
            char ch;
            scanf("%s",&ch);
            if(checkExit(ch)){
                PMNODE pm=pHead->SMN;
                int count=0;
                float sum=0;
                while (pm!=NULL){
                    printf("������%s��%s�ɼ�\n",pHead->student.Name,pm->mark.ClassName);
                    scanf("%f",&pm->mark.ClassMark);
                    count++;
                    sum=sum+pm->mark.ClassMark;
                    pm=pm->D;
                }
                pHead->Total=sum;
                pHead->Avg=sum/count;
                printf("�޸���ɣ�\n");
            }
        }
        pHead=pHead->DOWN;
    }

}
void ScortByAVG(DN pHead) {
    DN p, q;//��������ָ��

    SNODE temp;

    for (p = pHead->DOWN; NULL != p; p = p->DOWN) {
        for (q = p->DOWN; NULL != q; q = q->DOWN) {
            if (p->Avg < q->Avg)//��ǰһ��ѧ�������ĳɼ�С�ں�һ��ѧ�������ĳɼ�ʱ
            {
                printf("%.1f<%.1f\n",p->Avg,q->Avg);
                temp.student = p->student;//����ѧ����λ��
                p->student = q->student;
                q->student = temp.student;
            }
        }
    }
}

void ScortBySUM(DN pHead) {
    DN p, q;//��������ָ��

    SNODE temp;

    for (p = pHead->DOWN; NULL != p; p = p->DOWN) {
        for (q = p->DOWN; NULL != q; q = q->DOWN) {
            if (p->Total < q->Total)//��ǰһ��ѧ�������ĳɼ�С�ں�һ��ѧ�������ĳɼ�ʱ
            {
                printf("%.1f<%.1f\n",p->Total,q->Total);
                temp.student = p->student;//����ѧ����λ��
                p->student = q->student;
                q->student = temp.student;
            }
        }
    }
}

void ScortByClass(DN pHead, char name[20]) {
    DN p, q;//��������ָ��
    PMNODE d,b;
    SNODE temp;
    printf("%s", name);
    for (p = pHead->DOWN; NULL != p; p = p->DOWN) {
        for (q = p->DOWN; NULL != q; q = q->DOWN) {
            for(d=p->SMN;NULL!=d;d=d->D){
                for(b=q->SMN;NULL!=b;b=b->D){
//                    printf("����%s",name);
//                    printf("flag��1\n");
//                    printf("d��%s\n",d->mark.ClassName);
//                    printf("b��%s\n",b->mark.ClassName);
//                    printf("flag��3%d",strcmp(d->mark.ClassName,name));
//                    printf("flag��4%d",strcmp(b->mark.ClassName,name));
                    if(strcmp(d->mark.ClassName,name)==0&&strcmp(b->mark.ClassName,name)==0){
                       // printf("2\n");
                        if(d->mark.ClassMark < b->mark.ClassMark){
                           // printf("3\n");
                           // printf("%.1f < %.1f\n",d->mark.ClassMark,b->mark.ClassMark);
                            temp.student = p->student;//����ѧ����λ��
                            p->student = q->student;
                            q->student = temp.student;

                        }
                    }

                }
            }


        }



    }
}




void UnityOrderBy(DN pHead){
    PMNODE pmnode=pHead->DOWN->SMN;
    int i=0;
    int k=1;
    printf("����һ��ͨ����������������ʲô����\n");
    printf("---1.�ۺ�����---\n");
    printf("---2.��Ŀ����---\n");
    scanf("%d",&i);
    switch(i){
        case 1:
        {
            printf("-----1.AVG-----\n");
            printf("-----2.SUM-----\n");
            int j=0;
            scanf("%d",&j);
            if(j==1){
                ScortByAVG(pHead);
                OutputOrderByMarkDetail(pHead);
            } else if(j==2){
                ScortBySUM(pHead);
                OutputOrderByMarkDetail(pHead);
            }
        }

            break;
        case 2:
        {
            while (pmnode!=NULL){
                printf("-----%d.%s-----\n",k,pmnode->mark.ClassName);
                k++;
                pmnode=pmnode->D;
            }
            printf("������Ҫ����Ŀ���\n");
            char mname [20] ;
            scanf("%s",mname);
            ScortByClass(pHead,mname);
            OutputOrderByMarkDetail(pHead);
        }
            break;


    }

    }




DN CreateList(void);
DN InputStudent(DN phead);
void OutputMarkInfo(PMNODE pHead);
PMNODE CreateMark(void);
PMNODE MarkNodeCopy(PMNODE mhead);
DN InputStudentMark(DN pHead,PMNODE mHead);
void OutputMarkDetail(DN pHead);
void ChangeStudent(DN pHead);
void main(){
    DN p =CreateList();
    p=InputStudent(p);
    OutputStudent(p);
    DeleteStudent(p);
    InsertStudent(p);
    OutputStudent(p);
    PMNODE pm=CreateMark();
    pm=InputMarkInfo(pm);
    DN pp=InputStudentMark(p,pm);
    OutputMarkDetail(pp);
    OutputMark(pm);
    UnityOrderBy(p);
    ChangeStudent(p);
    OutputStudent(p);
}