#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lg.h"                 //�ṹ��
#include "adminSystem.h"        //ϵͳ����Ա
#include "manager.h"            //����
#include "receptionist.h"       //ǰ̨�Ӵ�
#include "visitor.h"            //����
#include "cleaner.h"            //�ÿ�
void inputPassWord(char password[],int n);
void display_user(user *head);
void display_room(room *head);
void display_customer(customer *head);
void display_bill(bill *head);
user *read();
room *readRoom();
bill *readBill();
customer *readCustomer();
void write();
void writeRoom();
void adminSystem(user *r);
void manager(user *r);
void receptionist(user *r);
void deleteUser();
void deleteRoom();
void initPassWord();
void amendPassWord(user *r);
void amendRoom();
void clear(user *head);
void clearRoom(room *head);
void clearCustomer(customer *head);
void clearBill(bill *head);
void backupUser();
void backupRoom();
void showRoom();
int reserveRoom();
int index(char t[],char s[]);
void inRoom(int id);
void payment(int id,char inDay[],char outDay[]);
void outRoom();
void changeRoom();
void keepRoom();
void showTime(int k)
{//��ʾ��ǰʱ��
    //system("cls");
    struct tm *ptr;
    time_t it;
    it=time(NULL);
    ptr=localtime(&it);
    if(ptr->tm_hour>=5&&ptr->tm_hour<9)
        printf("���Ϻã�\n");
    else if(ptr->tm_hour>=9&&ptr->tm_hour<12)
        printf("����ã�\n");
    else if(ptr->tm_hour>=12&&ptr->tm_hour<14)
        printf("����ã�\n");
    else if(ptr->tm_hour>=14&&ptr->tm_hour<18)
        printf("����ã�\n");
    else
        printf("���Ϻã�\n");
    printf("������%4d��%02d��%02d�� %d:%d:%d\n",ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
    switch(k)
    {
        case 1:
            printf("��ӭʹ���ùݹ���ϵͳ��\n");
            break;
        case 0:
            printf("ллʹ���ùݹ���ϵͳ��\n");
            break;
    }
}
int mainMenu()
{//���˵�����
    int c;
    printf("\t\t\t      �ùݹ���ϵͳ\n");
    printf("\t\t\t==========================\n");
    printf("\t\t\t      1:  �û���¼\n");
    printf("\t\t\t      2�� �ÿ�\n");
    printf("\t\t\t      0�� �˳�ϵͳ\n");
    printf("\t\t\t==========================\n");
    printf("\t\t\t������ѡ��:");
    scanf("%d",&c);
    while(c<0||c>2)
    {
        printf("����ѡ��������������룺");
        scanf("%d",&c);
    }
    return c;
}

user* login()
{//ͳһ��½����
    int i,counter=3;      //��֤����
    int pos=-1;
    char userId[12];    //���
    char password[7];   //����
    user *head,*s;
    head=read();                        //�ļ���ȡ����
    while(counter>0)
    {
        s=head->next;
        system("cls");
        counter--;
        printf("\t\t\t�ùݹ���ϵͳ---�û���¼\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t�û��˺ţ�");
        scanf("%s",userId);
        printf("\t\t\t���룺");
        for(i=0;i<6;i++)
        {
            password[i]=getch();
            printf("*");
        }
        password[i]='\0';
        getch();
        while(s)
        {
            if(strcmp(userId, s->userId)==0)
            {//ƥ���˺ųɹ�
                pos=0;
                break;
            }
            else
                s=s->next;
        }
        if(pos==-1)
        {
            printf("�û������ڣ�����%d�ε�¼���ᡣ\n",counter);
            getch();
            continue;
        }
        else
        {
            if(strcmp(password, s->password)!=0)  //�Ƚ�����
            {//����ƥ�����
                printf("����������󣡻���%d�ε�¼���ᡣ\n",counter);
                getch();
                continue;
            }
            else
            {//����ƥ����ȷ
                return s;               // �����û��ڵ�
            }
        }
    }
    return NULL;   //��¼ʧ��
}
void enterSystem(user *r)
{//��ɫ���ú���
    system("cls");
    if(strcmp(r->role,"����Ա")==0)
    {
        adminSystem(r);
    }
    else if(strcmp(r->role,"����")==0)
    {
        manager(r);
    }
    else if(strcmp(r->role,"ǰ̨")==0)
    {
        receptionist(r);
    }
    else if(strcmp(r->role,"����")==0)
    {
        cleaner(r);
    }
    else
        printf("\n��ɫ���󣡣�\n");
}
int index(char t[],char s[])
{
    int i,j,k;
    int tLength=strlen(t),sLength=strlen(s);
    i=0;
    while(i<=tLength-sLength)
    {
        k=i;
        j=0;
        while(s[j]&&t[i]==s[j])
        {
            i++;
            j++;
        }
        if(j==sLength) return k;
        i++;
    }
    return -1;
}
void amendPassWord(user *r)
{//�޸ĸ�����Ϣ
    int pos;
    char ans;
    char userId[12];                    //���
    char name[9];                       //����
    char email[20];                     //email
    char password[7];                   //����
    user *head,*p,*pa;
    head=read();
    p=head->next;
    while(p)
    {
        if(strcmp(r->userId,p->userId)==0)
        {
            printf("%s\n",p->name);
            printf("ȷ���޸ĸ�����Ϣ��(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("������ԭ���룺");
                scanf("%s",&password);
                if(strcmp(password,p->password)==0)
                {
                    printf("�������˺ţ�\n");
                    scanf("%s",&userId);
                    strcpy(p->userId,userId);
                    printf("���������룺\n");
                    scanf("%s",&password);
                    strcpy(p->password,password);
                    printf("�������û�����\n");
                    scanf("%s",&name);
                    strcpy(p->name,name);
                    printf("���������䣺\n");
                    scanf("%s",&email);
                    strcpy(p->email,email);
                    printf("�޸���Ϣ�ɹ���\n");
                    printf("ID: %s\t",p->userId);
                    printf("����: %s\t",p->password);
                    printf("�û���: %s\t",p->name);
                    printf("�Ա�: %s\t",p->sex);
                    printf("ְλ: %s\t",p->role);
                    printf("����: %s\n",p->email);
                }
                else
                {
                    printf("������󣡽�ֹ�޸ĸ�����Ϣ��\n");
                }
                p=head->next->next;
                FILE *f = fopen("user.txt","w");//�ԡ�r����д����ʽ��user.txt
                while(p)
                {
                    fprintf(f,"%-12s",p->userId);
                    fprintf(f,"%-7s",p->password);
                    fprintf(f,"%-9s",p->name);
                    fprintf(f,"%-4s",p->sex);
                    fprintf(f,"%-8s",p->role);
                    fprintf(f,"%-8s\n",p->email);
                    p=p->next;
                }
                fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
                clear(head);
                return;
            }
            else clear(head);return;
        }
        else p=p->next;
    }
}
void deleteUser()
{//ɾ���û�
    int pos;
    char id[12],ans;
    user *head,*p,*pa;
    head=read();
    p=head->next;
    pa=head;
    display_user(read());
    printf("������Ҫɾ�����û��˺ţ����˺Ų����ڷ��أ���");
    scanf("%s",&id);
    while(p)
    {
        if(strcmp(id,p->userId)==0)
        {
            printf("����ɾ����(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                pa->next=p->next;
                free(p);
                p=head->next;
                FILE *f = fopen("user.txt","w");//�ԡ�w����д����ʽ��user.txt
                while(p)
                {
                    fprintf(f,"%-12s",p->userId);
                    fprintf(f,"%-7s",p->password);
                    fprintf(f,"%-9s",p->name);
                    fprintf(f,"%-4s",p->sex);
                    fprintf(f,"%-8s",p->role);
                    fprintf(f,"%-8s\n",p->email);
                    p=p->next;
                }
                fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
                printf("ɾ���ɹ���\n");
                display_user(read());
                clear(head);
                return;
            }
            else clear(head);return;
        }
        else p=p->next;
    }
    if(!p)
    {
        printf("�޴��û���\n");
        clear(head);
        return;
    }
}
void write()
{//�����û�
    char userId[12];                    //���
    char name[9];                       //����
    char sex[4];                        //�Ա�
    char role[8];                       //��ɫ
    char email[20];                     //email
    char password[7];                   //����
    int select;//д���ݿ�����
    printf("��\"1\"������\"0\"�˳�:\n");
    scanf("%d",&select);
    while(1==select)
    {
        FILE *f = fopen("user.txt","a");//�ԡ�a����д����ʽ��user.txt
        printf("�����˺ţ�\n");
        scanf("%s",&userId);
        fprintf(f,"%-12s",userId);
        printf("�������룺\n");
        scanf("%s",&password);
        fprintf(f,"%-7s",password);
        printf("�����û�����\n");
        scanf("%s",&name);
        fprintf(f,"%-9s",name);
        printf("�����Ա�\n");
        scanf("%s",&sex);
        fprintf(f,"%-4s",sex);
        printf("�����ɫ��\n");
        scanf("%s",&role);
        fprintf(f,"%-8s",role);
        printf("�������䣺\n");
        scanf("%s",&email);
        fprintf(f,"%-8s\n",email);
        fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
        printf("��\"1\"������\"0\"�˳�:\n");
        scanf("%d",&select);
    }
}
/*
 *���ļ��ж�ȡ�ڵ㣬���ɴ˽�������
 */
user *read()
{//�û��ļ���������
    FILE *f = fopen("user.txt","r");//��"r"����������ʽ��ȡ�ļ���!*�ļ��������
    user *head = (user *)malloc(sizeof(user));//����ͷ�ڵ�
    head->next=NULL;//����ָ�룬��������
    while(!feof(f))
    {
        user *newNode = (user *)malloc(sizeof(user));//��ʱ�ڵ�,���ļ��ж�ȡ�ڵ�
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%s",newNode->userId);
        fscanf(f,"%s",newNode->password);
        fscanf(f,"%s",newNode->name);
        fscanf(f,"%s",newNode->sex);
        fscanf(f,"%s",newNode->role);
        fscanf(f,"%s",newNode->email);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
room *readRoom()
{//�����ļ���������
    FILE *f = fopen("room.txt","r");//��"r"����������ʽ��ȡ�ļ���!*�ļ��������
    room *head = (room *)malloc(sizeof(room));//����ͷ�ڵ�
    head->next=NULL;//����ָ�룬��������
    while(!feof(f))
    {
        room *newNode = (room *)malloc(sizeof(room));//��ʱ�ڵ�,���ļ��ж�ȡ�ڵ�
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%d",&newNode->roomId);
        fscanf(f,"%s",newNode->name);
        fscanf(f,"%d",&newNode->price);
        fscanf(f,"%d",&newNode->cashPledge);
        fscanf(f,"%d",&newNode->discount);
        fscanf(f,"%d",&newNode->status);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
bill *readBill()
{//�˵��ļ���������
    FILE *f = fopen("bill.txt","r");//��"r"����������ʽ��ȡ�ļ���!*�ļ��������
    bill *head = (bill *)malloc(sizeof(bill));//����ͷ�ڵ�
    head->next=NULL;//����ָ�룬��������
    while(!feof(f))
    {
        bill *newNode = (bill *)malloc(sizeof(bill));//��ʱ�ڵ�,���ļ��ж�ȡ�ڵ�
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%d",&newNode->roomId);
        fscanf(f,"%d",&newNode->price);
        fscanf(f,"%d",&newNode->cashPledge);
        fscanf(f,"%d",&newNode->yingPrice);
        fscanf(f,"%d",&newNode->realPrice);
        fscanf(f,"%d",&newNode->change);
        fscanf(f,"%d",&newNode->status);
        fscanf(f,"%s",newNode->inDay);
        fscanf(f,"%s",&newNode->outDay);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
customer *readCustomer()
{//�˵��ļ���������
    FILE *f = fopen("customer.txt","r");//��"r"����������ʽ��ȡ�ļ���!*�ļ��������
    customer *head = (customer *)malloc(sizeof(customer));//����ͷ�ڵ�
    head->next=NULL;//����ָ�룬��������
    while(!feof(f))
    {
        customer *newNode = (customer *)malloc(sizeof(customer));//��ʱ�ڵ�,���ļ��ж�ȡ�ڵ�
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%d",&newNode->roomId);
        fscanf(f,"%s",newNode->m_ID);
        fscanf(f,"%s",&newNode->m_name);
        fscanf(f,"%s",&newNode->m_sex);
        fscanf(f,"%d",&newNode->m_age);
        fscanf(f,"%s",&newNode->phone);
        fscanf(f,"%s",&newNode->inDay);
        fscanf(f,"%s",&newNode->outDay);
        fscanf(f,"%d",&newNode->status);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
/*
 *�������
 */
void display_user(user *head)
{//����û�����
    int num=0;
    user *p = head->next;//����ָ��
    printf("********************************************************************************************************* \n");
    while(p->next)
    {
        num++;
        p=p->next;
        printf("NO%d:\n",num);
        printf("ID: %s\t",p->userId);
        printf("����: %s\t",p->password);
        printf("�û���: %s\t",p->name);
        printf("�Ա�: %s\t",p->sex);
        printf("ְλ: %s\t",p->role);
        printf("����: %s\n",p->email);

    }
    printf("********************************************************************************************************* \n");
    getch();
}
void display_room(room *head)
{//����ͷ�����
    int num=0;
    room *p = head->next;//����ָ��
    printf("********************************************************************************************************* \n");
    while(p->next)
    {
        num++;
        p=p->next;
        printf("NO%d:\n",num);
        printf("����: %d\t",p->roomId);
        printf("��������: %s\t",p->name);
        printf("����(Ԫ): %d\t",p->price);
        printf("Ѻ��(Ԫ): %d\t",p->cashPledge);
        if(p->discount==0)
            printf("�Ż�: ��\t");
        else
            printf("�Ż�: ��\t");
        if(p->status==0)
            printf("״̬: ��\n");
        else if(p->status==1)
            printf("״̬: �ǿ�\n");
        else if(p->status==2)
            printf("״̬: δ��ɨ\n");
        else
            printf("״̬: ��ɨ��\n");

    }
    printf("********************************************************************************************************* \n");
    printf("��ѯ��%d����¼\n",num);
    getch();
}
void display_bill(bill *head)
{//����˵�����
    int num=0,zong=0;
    bill *p = head->next->next;//����ָ��
    printf("************************************************************************************************************ \n");
    while(p)
    {
        num++;
        printf("NO%d:\n",num);
        printf("����: %d\t",p->roomId);
        printf("����(Ԫ): %d\t",p->price);
        printf("Ѻ��(Ԫ): %d\t",p->cashPledge);
        printf("Ӧ�շ���(Ԫ): %d\t",p->yingPrice);
        printf("ʵ�շ���(Ԫ): %d\t",p->realPrice);
        printf("����(Ԫ): %d\n",p->change);
        if(p->status==0)
            printf("״̬: ���˷�\t");
        else if(p->status==1)
            printf("״̬: ��ס\t");
        else
            printf("״̬: ԤԼ\t");
        printf("��סʱ��: %s\t",p->inDay);
        printf("�˷�ʱ��: %s\n",p->outDay);

        zong=zong+p->yingPrice-p->cashPledge;
        p=p->next;
    }
    printf("************************************************************************************************************ \n");
    printf("��ѯ��%d����¼\n",num);
    printf("������=%d\n",zong);
    getch();
}
void display_customer(customer *head)
{//����ÿ���Ϣ����
    int num=0;
    customer *p = head->next;//����ָ��
    printf("********************************************************************************************************************** \n");
    while(p->next)
    {
        num++;
        p=p->next;
        printf("NO%d:\n",num);
        printf("����: %d\t",p->roomId);
        printf("���֤��: %s\t",p->m_ID);
        printf("����: %s\t",p->m_name);
        printf("�Ա�: %s\t",p->m_sex);
        printf("����: %d\t",p->m_age);
        printf("�绰����: %s\n",p->phone);
        printf("��סʱ��: %s\t",p->inDay);
        printf("�˷�ʱ��: %s\t",p->outDay);
        if(p->status==0)
            printf("״̬: ���˷�\n");
        else if(p->status==1)
            printf("״̬: ��ס\n");
        else
            printf("״̬: ԤԼ\n");

    }
    printf("********************************************************************************************************************** \n");
    printf("��ѯ��%d����¼\n",num);
    getch();
}
void clear(user *head)
{//����û�����
    user *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
void clearRoom(room *head)
{//�����������
    room *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
void clearCustomer(customer *head)
{//����ÿ�����
    customer *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
void clearBill(bill *head)
{//����˵�����
    bill *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
int main()
{
    user *r;
    int c,loop=1;
    while(loop==1)
    {
        system("cls");
        c=mainMenu();
        switch(c)
        {
            case 1:
                r=login();
                if(r==NULL)
                    loop=0;
                else
                    enterSystem(r);
                break;
            case 2:
                visitor();
                break;
            default:
                loop=0;
                break;
        }
        showTime(loop);
    }
    return 0;
}
