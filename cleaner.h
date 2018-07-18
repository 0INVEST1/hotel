#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void chaRoom();
void dasaoRoom();
void releaseRoom();
void cleaner(user *r)
{//���ຯ��
    int c,loop=1;
    while(loop==1)
    {
        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  �ùݹ���ϵͳ---����ģ��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  ��ѯδ��ɨ����\n");
        printf("\t\t\t  * 2  ȷ�Ϸ����ɨ���\n");
        printf("\t\t\t  * 3  �޸ĸ�����Ϣ\n");
        printf("\t\t\t  * 0  ע��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&c);
        while(c<0||c>3)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
            case 1:
                printf("\t\t\t\t\t#��ѯδ��ɨ����#\n");
                dasaoRoom();
                break;
            case 2:
                printf("\t\t\t\t\t#ȷ�Ϸ����ɨ���#\n");
                releaseRoom();
                break;
            case 3:
                printf("\t\t\t\t\t#�޸ĸ�����Ϣ#\n");
                amendPassWord(r);
                break;
            default:
                loop=0;
                break;
        }
    }
}
void dasaoRoom()
{
    room *head,*p;
    int id,n=0,c=1;
    char ans;
    head=readRoom();
    p=head->next;
    while(c)
    {
        printf("**************************************************************************** \n");
        while(p)
        {
            if(p->status==2)
            {
                n++;
                printf("NO%d:\n",n);
                printf("����: %d\t",p->roomId);
                printf("��������: %s\t",p->name);
                if(p->status==0)
                    printf("״̬: ��\n");
                else if(p->status==1)
                    printf("״̬: �ǿ�\n");
                else if(p->status==2)
                    printf("״̬: δ��ɨ\n");
                else
                    printf("״̬: ���ڴ�ɨ\n");

                p=p->next;
            }
            else p=p->next;
        }
        printf("***************************************************************************\n");
        printf("��ѯ��%d��δ��ɨ�ķ���\n",n);
        getch();
        p=head->next;
        printf("������Ҫ��ɨ����ţ�");
        scanf("%d",&id);
        while(p)
        {
            if(p->roomId==id)
            {
                printf("����: %d\t",p->roomId);
                printf("��������: %s\t",p->name);
                if(p->status==0)
                    printf("״̬: ��\n");
                else if(p->status==1)
                    printf("״̬: �ǿ�\n");
                else if(p->status==2)
                    printf("״̬: δ��ɨ\n");
                else
                    printf("״̬: ���ڴ�ɨ\n");
                printf("ȷ��ǰȥ��ɨ��(y/n):");
                scanf(" %c",&ans);
                if(ans=='y'||ans=='Y')
                {
                    p->status=3;      //������Ϊ���ڴ�ɨ
                    p=head->next->next;
                    FILE *f = fopen("room.txt","w");//�ԡ�w����д����ʽ��
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
                    printf("������ɣ�");
                    clearRoom(head);
                    c=0;
                    return;
                }
                else
                {
                    p=head->next;
                    c=0;
                    break;
                }
            }
            else p=p->next;
        }
        if(!p)
        {
            printf("\n�޴˿ͷ������������룡\n");
            p=head->next;
            n=0;
            c=1;
        }
    }
    clearRoom(head);
}
void releaseRoom()
{
    room *head,*p;
    int id;
    char ans;
    head=readRoom();
    p=head->next;
    printf("�������ɨ��ɵķ���ţ�");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id&&p->status==3)
        {
            printf("����: %d\t",p->roomId);
            printf("��������: %s\t",p->name);
            if(p->status==0)
                printf("״̬: ��\n");
            else if(p->status==1)
                printf("״̬: �ǿ�\n");
            else if(p->status==2)
                printf("״̬: δ��ɨ\n");
            else
                printf("״̬: ���ڴ�ɨ\n");
            printf("ȷ����ɨ��ɣ�(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                p->status=0;      //������Ϊ��
                p=head->next->next;
                FILE *f = fopen("room.txt","w");//�ԡ�w����д����ʽ��
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
                printf("��ɨ��ɣ�\n");
                clearRoom(head);
                return;
            }
            return;
        }
        else p=p->next;
    }
}

