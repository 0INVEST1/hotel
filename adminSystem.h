#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
user *read();
void display_user(user *head);
void write();
void deleteUser();
void initPassWord();
void amendPassWord(user *r);
void backupUser();
void backupRoom();
void backupBill();
void backupCustomer();
void showTime(int k);
room *readRoom();
bill *readBill();
customer *readCustomer();
void clear(user *head);
void clearRoom(room *head);
void clearBill(bill *head);
void clearCustomer(customer *head);
void adminSystem(user *r)
{//ϵͳ����Ա����
    int c,loop=1;
    while(loop==1)
    {

        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  �ùݹ���ϵͳ---ϵͳ����\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1 ����û�\n");
        printf("\t\t\t  * 2 �����û�\n");
        printf("\t\t\t  * 3 ɾ���û�\n");
        printf("\t\t\t  * 4 ��ʼ���û�����\n");
        printf("\t\t\t  * 5 �޸ĸ�����Ϣ\n");
        printf("\t\t\t  * 6 ϵͳ����\n");
        printf("\t\t\t  * 0 ע��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&c);
        while(c<0||c>6)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {

            case 1:
                printf("\n\t\t\t\t\t#����û�#\n");
                display_user(read());
                break;
            case 2:
                printf("\n\t\t\t\t\t#�����û�#\n");
                write();
                break;
            case 3:
                printf("\n\t\t\t\t\t#ɾ���û�#\n");
                deleteUser();
                break;
            case 4:
                printf("\n\t\t\t\t\t#��ʼ���û�����#\n");
                initPassWord();
                break;
            case 5:
                printf("\n\t\t\t\t\t#�޸ĸ�����Ϣ#\n");
                amendPassWord(r);
                break;
            case 6:
                printf("\n\t\t\t\t\t#ϵͳ����#\n");
                backupUser();
                backupRoom();
                backupBill();
                backupCustomer();
                break;
            default:
                loop=0;
                break;
        }
    }
}
void initPassWord()
{//��ʼ���û�����
    int pos;
    char id[12],ans;
    user *head,*p;
    head=read();
    p=head->next;
    display_user(head);
    printf("�������û��˺ţ����˺Ų����ڷ��أ���");
    scanf("%s",&id);
    while(p)
    {
        if(strcmp(id,p->userId)==0)
        {
            printf("%s\n",p->name);
            printf("ȷ����ʼ�����û����룿(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                strcpy(p->password,"000000");
                printf("%s���˺���������Ϊ000000\n",p->name);
                p=head->next->next;
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
void backupUser()
{//�û��ļ�����
    user *head,*p;
    char filename[30]="user_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("�û����ݳɹ����ݵ���%s\n",filename);
    head=read();
    p=head->next->next;
    FILE *f = fopen(filename,"w");//�ԡ�w����д����ʽ��user.txt
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
}
void backupRoom()
{//�ͷ��ļ�����
    room *head,*p;
    char filename[30]="room_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("�ͷ����ݳɹ����ݵ���%s\n",filename);
    head=readRoom();
    p=head->next->next;
    FILE *f = fopen(filename,"w");
    while(p)
    {
        fprintf(f,"%-5d",p->roomId);
        fprintf(f,"%-15s",p->name);
        fprintf(f,"%-6d",p->price);
        fprintf(f,"%-6d",p->cashPledge);
        fprintf(f,"%-3d",p->discount);
        fprintf(f,"%-d\n",p->status);
        p=p->next;
    }
    fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
    clearRoom(head);
}
void backupBill()
{//�˵��ļ�����
    bill *head,*p;
    char filename[30]="bill_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("�˵����ݳɹ����ݵ���%s\n",filename);
    head=readBill();
    p=head->next->next;
    FILE *f = fopen(filename,"w");
    while(p)
    {
        fprintf(f,"%-5d",p->roomId);
        fprintf(f,"%-5d",p->price);
        fprintf(f,"%-5d",p->cashPledge);
        fprintf(f,"%-5d",p->yingPrice);
        fprintf(f,"%-5d",p->realPrice);
        fprintf(f,"%-5d",p->change);
        fprintf(f,"%-3d",p->status);
        fprintf(f,"%-12s",p->inDay);
        fprintf(f,"%-12s\n",p->outDay);
        p=p->next;
    }
    fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
    clearBill(head);
}
void backupCustomer()
{//�ÿ���Ϣ�ļ�����
    customer *head,*p;
    char filename[30]="customer_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("�ÿ���Ϣ�ɹ����ݵ���%s\n",filename);
    head=readCustomer();
    p=head->next->next;
    FILE *f = fopen(filename,"w");
    while(p)
    {
        fprintf(f,"%-5d",p->roomId);
        fprintf(f,"%-20s",p->m_ID);
        fprintf(f,"%-9s",p->m_name);
        fprintf(f,"%-4s",p->m_sex);
        fprintf(f,"%-4d",p->m_age);
        fprintf(f,"%-12s",p->phone);
        fprintf(f,"%-12s",p->inDay);
        fprintf(f,"%-12s",p->outDay);
        fprintf(f,"%d\n",p->status);
        p=p->next;
    }
    fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
    clearCustomer(head);
}
