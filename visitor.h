#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void chaRoom();
void showMe();
int visitor()
{//�οͺ���
    system("cls");
    int c,loop=1;
    while(loop==1)
    {
        printf("\n�𾴵��ÿͣ�");
        showTime(1);
        printf("\t\t\t  �ùݹ���ϵͳ---�ÿ�ģ��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  ��ѯ����\n");
        printf("\t\t\t  * 2  �鿴�Լ���Ϣ\n");
        printf("\t\t\t  * 0  ע��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&c);
        while(c<0||c>2)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
            case 1:
                printf("\t\t\t#��ѯ����#\n");
                chaRoom();
                break;
            case 2:
                printf("\t\t\t#�鿴�Լ���Ϣ#\n");
                showMe();
                break;
            default:
                loop=0;
                break;

        }
    }
}
void showMe()
{//�鿴�Լ���Ϣ
    customer *head,*p;
    int n=0;
    char name[9];                      //����
    head=readCustomer();
    p=head->next->next;
    printf("������������");
    scanf("%s",name);
    printf("********************************************************************************************************************** \n");
    while(p)
    {
        if(index(p->m_name,name)!=-1)
        {
            n++;
            printf("NO%d:\n",n);
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
            p=p->next;
        }
        else p=p->next;
    }
    printf("********************************************************************************************************************** \n");
    p=head->next->next;
    clearCustomer(head);
}
void chaRoom()
{
    room *head,*p;
    int id,n=0,c=1,select;
    char name[15];
    head=readRoom();
    p=head->next;
    while(c)
    {
        n=0;
        printf("������Ҫ��ѯ�ķ������͹ؼ��֣�����all��ʾ���пͷ�����");
        scanf("%s",name);
        if(strcmp(name,"all")==0)
            display_room(head);
        else
        {
            printf("********************************************************************************************************* \n");
            while(p)
            {
                if(index(p->name,name)!=-1)
                {
                    printf("NO%d:\n",n);
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
                    n++;
                    p=p->next;
                }
                else p=p->next;
            }
            printf("********************************************************************************************************* \n");
            printf("��ѯ��%d����������ķ���\n",n);
            getch();
        }

        c=0;
    }
    clearRoom(head);
}
