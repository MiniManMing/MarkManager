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


DN CreateList(void);
DN InputStudent(DN phead);
void OutputMarkInfo(PMNODE pHead);
PMNODE CreateMark(void);
PMNODE MarkNodeCopy(PMNODE mhead);
void main(){
    DN p =CreateList();
    p=InputStudent(p);
    OutputStudent(p);
    PMNODE pm=CreateMark();
    pm=InputMarkInfo(pm);
    OutputMarkInfo(pm);
    PMNODE pm2=MarkNodeCopy(pm);
    OutputMarkInfo(pm2);

}