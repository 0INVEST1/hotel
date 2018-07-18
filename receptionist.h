#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void keepRoom();
void changeRoom();
int index(char t[],char s[]);
void showRoom();
void outRoom();
void clearCustomer(customer *head);
void clearBill(bill *head);
void inRoom(int id);
void payment(int id,char inDay[],char outDay[]);
void checkCustomer();
void receptionist(user *r)
{//ǰ̨�Ӵ�ģ��
    int c,loop=1;
    while(loop==1)
    {
        //system("cls");
        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  �ùݹ���ϵͳ---ǰ̨ģ��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  ��ѯ����\n");
        printf("\t\t\t  * 2  �˷�\n");
        printf("\t\t\t  * 3  ����\n");
        printf("\t\t\t  * 4  ��ס\n");
        printf("\t\t\t  * 5  �鿴������Ϣ\n");
        printf("\t\t\t  * 6  �޸ĸ�����Ϣ\n");
        printf("\t\t\t  * 0  ע��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&c);
        while(c<0||c>8)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
             case 1:
                printf("\t\t\t#��ѯ����#\n");
                showRoom();
                break;
            case 2:
                printf("\t\t\t#�˷�#\n");
                outRoom();
                break;
            case 3:
                printf("\t\t\t#����#\n");
                changeRoom();
                break;
            case 4:
                printf("\t\t\t#��ס#\n");
                keepRoom();
                break;
            case 5:
                printf("\t\t\t#�鿴������Ϣ#\n");
                checkCustomer();
                break;
            case 6:
                printf("\t\t\t#�޸ĸ�����Ϣ#\n");
                amendPassWord(r);
                break;
            default:
                loop=0;
                break;
        }
    }
}
void checkCustomer()
{//�鿴�ÿ���Ϣ
    customer *head,*p;
    int id,n=0,c=1,s,num=0;
    char day[12];                     //����ʱ��
    char name[9];                      //����
    head=readCustomer();
    p=head->next->next;
    while(c)
    {
        printf("\t\t\t      #�ÿ���Ϣ#\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t      1:  ���·ݲ�ѯ\n");
        printf("\t\t\t      2�� ������Ų�ѯ\n");
        printf("\t\t\t      3�� ��������ѯ\n");
        printf("\t\t\t      4�� �鿴ȫ��\n");
        printf("\t\t\t      0�� �˳�\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&s);
        while(s<0||s>4)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&s);
        }
        if(s==1)
        {
            n=0;
            printf("����������·ݣ��磺2017.05����");
            scanf("%s",day);
            printf("********************************************************************************************************************** \n");
            while(p)
            {
                if(index(p->inDay,day)!=-1)
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
            printf("��ѯ��%d����¼\n",n);
            p=head->next->next;
        }
        else if(s==2)
        {
            n=0;
            num=0;
            printf("�����뷿��ţ���");
            scanf("%d",&id);
            printf("********************************************************************************************************************** \n");
            while(p)
            {
                if(p->roomId==id)
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
            printf("��ѯ��%d����¼\n",n);
            p=head->next->next;
        }
        else if(s==3)
        {
            n=0;
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
            printf("��ѯ��%d����¼\n",n);
            p=head->next->next;
        }
        else if(s==4)
            display_customer(head);
        else c=0;
    }
    clearCustomer(head);
}
void keepRoom()
{//��ס����
    customer *head,*p,*pa;
    bill *head1,*q;
    int id,m,rm,c;
    char m_name[9];     //�˿�����
    char outDay[12];
    char ans;
    head=readCustomer();
    p=head->next;
    head1=readBill();
    q=head1->next;
    printf("��������ס����ķ��ţ�\n");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
            if(p->status==1)
            {
                printf("\n����: %d\t",p->roomId);
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
                pa=p;
            }
            else if(p->status==3)
            {
                printf("��ǰ��������ԤԼ\n");
                printf("ԤԼʱ��%s��%s\n",p->inDay,p->outDay);
            }
            p=p->next;
        }
        else p=p->next;
    }
    printf("ȷ����ס��(y/n):");
    scanf(" %c",&ans);
    if(ans=='y'||ans=='Y')
    {
        printf("������ס�˷�ʱ�䣺");
        scanf("%s",outDay);
        strcpy(pa->outDay,outDay);
        while(q)
        {
            if(q->roomId==pa->roomId&&q->status==1)
            {
                printf("����=%d\n",q->roomId);
                printf("����=%d\n",q->price);
                strcpy(q->outDay,outDay);
                printf("Ӧ��������=");
                scanf("%d",&m);
                q->yingPrice=q->yingPrice+m;
                printf("\nʵ������=");
                scanf("%d",&rm);
                q->realPrice=q->realPrice+rm;
                c=rm-m;
                printf("\n����=%d",c);
                q->change=q->change+c;
                q=head1->next->next;
                break;
            }
            else q=q->next;
        }
        p=head->next->next;
        FILE *f = fopen("customer.txt","w");//�ԡ�w����д����ʽ��
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
        FILE *f1 = fopen("bill.txt","w");//�ԡ�w����д����ʽ��
        while(q)
        {
            fprintf(f1,"%-5d",q->roomId);
            fprintf(f1,"%-5d",q->price);
            fprintf(f1,"%-5d",q->cashPledge);
            fprintf(f1,"%-5d",q->yingPrice);
            fprintf(f1,"%-5d",q->realPrice);
            fprintf(f1,"%-5d",q->change);
            fprintf(f1,"%-3d",q->status);
            fprintf(f1,"%-12s",q->inDay);
            fprintf(f1,"%-12s\n",q->outDay);
            q=q->next;
        }
        fclose(f1);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
        printf("\n��ס��ɣ�\n");
        getch();
        clearCustomer(head);
        clearBill(head1);
    }
}

void changeRoom()
{//����
    customer *head,*p;
    bill *head1,*q;
    room *head2,*s,*sa;
    int id,n=0;
    char name[15],ans;
    head=readCustomer();
    p=head->next;
    head1=readBill();
    q=head1->next;
    head2=readRoom();
    s=head2->next;
    printf("������ԭ����ķ��ţ�\n");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id&&p->status==1)
        {
            printf("\n����: %d\t",p->roomId);
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
            while(s)
            {
                if(s->roomId==id)
                {
                    printf("�÷�������=%s\n",s->name);
                    strcpy(name,s->name);
                    sa=s;
                    s=head2->next;
                    break;
                }
                else s=s->next;
            }
            printf("********************************************************************************************************* \n");
            while(s)
            {
                if(index(s->name,name)!=-1&&s->status!=1)
                {
                    printf("NO%d:\n",n);
                    printf("����: %d\t",s->roomId);
                    printf("��������: %s\t",s->name);
                    printf("����(Ԫ): %d\t",s->price);
                    printf("Ѻ��(Ԫ): %d\t",s->cashPledge);
                    if(s->discount==0)
                        printf("�Ż�: ��\t");
                    else
                        printf("�Ż�: ��\t");
                    if(s->status==0)
                        printf("״̬: ��\n");
                    else if(s->status==1)
                        printf("״̬: �ǿ�\n");
                    else if(s->status==2)
                        printf("״̬: δ��ɨ\n");
                    else
                        printf("״̬: ��ɨ��\n");
                    n++;
                    s=s->next;
                }
                else s=s->next;
            }
            s=head2->next;
            printf("********************************************************************************************************* \n");
            printf("��ѯ��%d����ϻ��������ķ���\n",n);
            printf("ȷ��������(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                while(q)
                {
                    if(q->roomId==id) break;
                    else q=q->next;
                }
                printf("������Ҫ�����Ǹ����䣺\n");
                scanf("%d",&id);
                p->roomId=id;      //�����ÿͷ����
                while(s)
                {
                    if(s->roomId==id) break;
                    else s=s->next;
                }
                sa->status=2;       //ԭ������Ϊδ��ɨ
                q->roomId=id;      //�˵����ķ����
                q=head1->next->next;
                p=head->next->next;
                s=head2->next->next;
                FILE *f = fopen("customer.txt","w");//�ԡ�w����д����ʽ��
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
                while(s)
                {
                    if(s->roomId==id)
                    {
                        s->status=1;   //���󷿼���Ϊ�ǿ�
                        s=head2->next->next;
                        break;
                    }
                    else s=s->next;
                }
                FILE *f2 = fopen("room.txt","w");//�ԡ�w����д����ʽ��
                while(s)
                {
                    fprintf(f2,"%-5d",s->roomId);
                    fprintf(f2,"%-15s",s->name);
                    fprintf(f2,"%-6d",s->price);
                    fprintf(f2,"%-6d",s->cashPledge);
                    fprintf(f2,"%-3d",s->discount);
                    fprintf(f2,"%-d\n",s->status);
                    s=s->next;
                }
                fclose(f2);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
                FILE *f1 = fopen("bill.txt","w");//�ԡ�w����д����ʽ��
                while(q)
                {

                    fprintf(f1,"%-5d",q->roomId);
                    fprintf(f1,"%-5d",q->price);
                    fprintf(f1,"%-5d",q->cashPledge);
                    fprintf(f1,"%-5d",q->yingPrice);
                    fprintf(f1,"%-5d",q->realPrice);
                    fprintf(f1,"%-5d",q->change);
                    fprintf(f1,"%-3d",q->status);
                    fprintf(f1,"%-12s",q->inDay);
                    fprintf(f1,"%-12s\n",q->outDay);
                    q=q->next;
                }
                fclose(f1);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
                printf("������ɣ�\n");
                getch();
                clearCustomer(head);
                clearBill(head1);
                clearRoom(head2);
                break;
            }
            else break;
        }
        else p=p->next;
    }
    //printf("δ�鵽�ü�¼����ȷ�Ϸ���ţ�");
    getch();

}
void outRoom()
{//�˷�����
    customer *head,*p;
    bill *head1,*q;
    room *head2,*s;
    int id;
    char ans;
    head=readCustomer();
    p=head->next;
    head1=readBill();
    q=head1->next;
    head2=readRoom();
    s=head2->next;
    printf("�����뽫�˷��ķ��ţ�\n");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
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
            printf("ȷ���˷���(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                p->status=0;      //״̬��Ϊ���˷�
                p=head->next->next;
                FILE *f = fopen("customer.txt","w");//�ԡ�w����д����ʽ��
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
                while(q)
                {
                    if(q->roomId==id)
                    {
                        printf("Ӧ�˻�Ѻ��=%d\n",q->cashPledge);
                        getch();
                        q->status=0;           //����״̬���˻�Ѻ��
                        q=head1->next->next;
                        break;
                    }
                    else q=q->next;
                }
                FILE *f1 = fopen("bill.txt","w");//�ԡ�w����д����ʽ��
                while(q)
                {

                    fprintf(f1,"%-5d",q->roomId);
                    fprintf(f1,"%-5d",q->price);
                    fprintf(f1,"%-5d",q->cashPledge);
                    fprintf(f1,"%-5d",q->yingPrice);
                    fprintf(f1,"%-5d",q->realPrice);
                    fprintf(f1,"%-5d",q->change);
                    fprintf(f1,"%-3d",q->status);
                    fprintf(f1,"%-12s",q->inDay);
                    fprintf(f1,"%-12s\n",q->outDay);
                    q=q->next;
                }
                fclose(f1);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
                while(s)
                {
                    if(s->roomId==id)
                    {
                        s->status=2;           //����״̬Ϊδ��ɨ
                        s=head2->next->next;
                        break;
                    }
                    else s=s->next;
                }
                FILE *f2 = fopen("room.txt","w");//�ԡ�w����д����ʽ��
                while(s)
                {
                    fprintf(f2,"%-5d",s->roomId);
                    fprintf(f2,"%-15s",s->name);
                    fprintf(f2,"%-6d",s->price);
                    fprintf(f2,"%-6d",s->cashPledge);
                    fprintf(f2,"%-3d",s->discount);
                    fprintf(f2,"%-d\n",s->status);
                    s=s->next;
                }
                fclose(f2);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
                printf("�˷���ɣ�\n");
                getch();
                clearCustomer(head);
                clearBill(head1);
                clearRoom(head2);
                break;
            }
            else break;
        }
        else p=p->next;
    }
}
void showRoom()
{
    room *head,*p;
    int id,n=0,c=1,select;
    char name[15];
    head=readRoom();
    p=head->next;
    while(c)
    {
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
                    n++;
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

                    p=p->next;
                }
                else p=p->next;
            }
            printf("********************************************************************************************************* \n");
            printf("��ѯ��%d����������ķ���\n",n);
        }
        printf("\t\t\t      #����#\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t      1:  ������ס\n");
        printf("\t\t\t      2�� ����ԤԼ\n");
        printf("\t\t\t      0�� �˳�\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&select);
        while(select<0||select>2)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&select);
        }
        if(select==1) c=stayRoom();
        else if(select==2) c=reserveRoom();
        else c=0;
    }
    clearRoom(head);
}
int reserveRoom()
{//ԤԼ����
    room *head,*p;
    customer *head2,*s,*t;
    int id,n=0,c=1;
    char ans;
    head=readRoom();
    head2=readCustomer();
    p=head->next->next;
    s=head2->next->next;
    printf("\n\t\t\t#ԤԼ#\n");
    while(c)
    {
        printf("������ҪԤԼ�ķ����(����0���²�ѯ)��");
        scanf("%d",&id);
        if(id==0)
        {
            clearRoom(head);
            return 1;
        }
        else
        {
            while(s)
            {
                if(s->roomId==id&&s->status==2)
                {
                    printf("����������ԤԼ��\n");
                    t=s;
                    s=head2->next->next;
                    break;
                }
                else s=s->next;
            }
            while(p)
            {
                if(p->roomId==id&t->status!=2)
                {
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
                    if(p->status==1)
                    {
                        while(s)
                        {
                            if(s->roomId==id)
                            {
                                printf("�÷����˷�ʱ��Ϊ��%s\n",s->outDay);
                                break;
                            }
                            else s=s->next;
                        }
                        s=head2->next->next;
                    }
                    printf("ȷ��ԤԼ��(y/n):");
                    scanf(" %c",&ans);
                    if(ans=='y'||ans=='Y')
                    {
                        inRoom(id);     //�Ǽǿ�����Ϣ
                        clearRoom(head);
                        return 0;
                    }
                }
                else p=p->next;
            }
        }
    }
    clearCustomer(head2);
}
int stayRoom()
{//��ס����
    room *head,*p;
    int id,n=0,c=1;
    char ans;
    head=readRoom();
    p=head->next;
    printf("\n\t\t\t#��ס#\n");
    while(c)
    {
        printf("������Ҫ��ס�����(����0���²�ѯ)��");
        scanf("%d",&id);
        if(id==0)
        {
            clearRoom(head);
            return 1;
        }
        else
        {
            while(p)
            {
                if(p->roomId==id)
                {
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
                    printf("ȷ����ס��(y/n):");
                    scanf(" %c",&ans);
                    if(ans=='y'||ans=='Y')
                    {
                        inRoom(id);     //�Ǽǿ�����Ϣ
                        p->status=1;      //������Ϊ�ǿ�
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
                        clearRoom(head);
                        return 0;
                    }
                }
                else p=p->next;
            }
            if(!p)
            {
                printf("�޴˿ͷ������������룡");
                clearRoom(head);
                return 1;

            }
        }
    }
}
void inRoom(int id)
{//������Ϣ
    char m_ID[19];     /*���֤����*/
    char m_name[9];   /*�˿�����*/
    int  m_age;        /*�˿�����*/
    char  m_sex[6];    /*�˿��Ա�*/
    char phone[12];     //�绰����
    char inDay[12];     //����ʱ��
    char outDay[12];    //�˷�ʱ��
    int status;         //�ÿ�״̬��1��ʾ��ס��2��ʾԤԼ��0��ʾ���˷���
    FILE *f = fopen("customer.txt","a");//�ԡ�a����д����ʽ��user.txt
    printf("������ǣ�%d\n",id);
    fprintf(f,"%-5d",id);
    printf("�������֤�ţ�\n");
    scanf("%s",&m_ID);
    fprintf(f,"%-20s",m_ID);
    printf("����������\n");
    scanf("%s",&m_name);
    fprintf(f,"%-9s",m_name);
    printf("�����Ա�\n");
    scanf("%s",&m_sex);
    fprintf(f,"%-4s",m_sex);
    printf("�������䣺\n");
    scanf("%d",&m_age);
    fprintf(f,"%-4d",m_age);
    printf ("����绰���룺");
    scanf ("%s",&phone);
    fprintf(f,"%-12s",phone);
    printf ("������סʱ�䣨��������.��������");
    scanf ("%s",&inDay);
    fprintf(f,"%-12s",inDay);
    printf ("����Ӧ�˷�ʱ�䣨��������.��������");
    scanf ("%s",&outDay);
    fprintf(f,"%-12s",outDay);
    printf("�����ÿ�״̬(1��ʾ��ס��2��ʾԤԼ)��\n");
    scanf("%d",&status);
    fprintf(f,"%d\n",status);
    fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
    printf("�Ǽ���ɣ�\n");
    payment(id,inDay,outDay);      //����
}
void payment(int id,char inDay[],char outDay[])
{//�˵�����
    int roomId;                         //����
    int price;                          //����
    int yingPrice;                      //Ӧ�շ���
    int realPrice;                      //ʵ�շ���
    int cashPledge;                     //Ѻ��
    int change;                         //����
    int status;                         //״̬
    room *head,*p,*pa;
    head=readRoom();
    p=head->next;
    while(p)
    {
        if(p->roomId==id)
        {
            printf("����=%d\n",p->price);
            price=p->price;
            printf("Ѻ��=%d\n",p->cashPledge);
            cashPledge=p->cashPledge;           //Ѻ��
            printf("Ӧ�ս�");
            scanf("%d",&yingPrice);
            printf("ʵ�ս�");
            scanf("%d",&realPrice);             //ʵ�շ���
            change=realPrice-yingPrice;             //����
            printf("���㣺%d\n",change);
            break;
        }
        else p=p->next;
    }
    FILE *f = fopen("bill.txt","a");//�ԡ�a����д����ʽ��
    printf("����ţ�%d\n",id);
    fprintf(f,"%-5d",id);
    printf("���ۣ�%d\n",price);
    fprintf(f,"%-5d",price);
    printf("Ѻ��%d\n",cashPledge);
    fprintf(f,"%-5d",cashPledge);
    printf("Ӧ�ս�%d\n",yingPrice);
    fprintf(f,"%-5d",yingPrice);
    printf("ʵ�ս�%d\n",realPrice);
    fprintf(f,"%-5d",realPrice);
    printf("���㣺%d\n",change);
    fprintf(f,"%-5d",change);
    printf ("����״̬��1��ʾ��סѺ��2��ʾԤԼѺ��0��ʾ�ѻ�Ѻ�𣩣�");
    scanf ("%d",&status);
    fprintf(f,"%-3d",status);
    printf("��סʱ��=%s\n",inDay);
    fprintf(f,"%-12s",inDay);
    printf("�˷�ʱ��=%s\n",outDay);
    fprintf(f,"%-12s\n",outDay);
    fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
    printf("�Ǽ���ɣ�\n");
    clearRoom(head);
}
