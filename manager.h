#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
bill *readBill();
customer *readCustomer();
void display_room(room *head);
void display_customer(customer *head);
void display_bill(bill *head);
customer *readCustomer();
void writeRoom();
void deleteRoom();
void amendRoom();
void checkBill();
int index(char t[],char s[]);
void manager(user *r)
{//������
    int c,loop=1;
    while(loop==1)
    {
        //system("cls");
        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  �ùݹ���ϵͳ---����ģ��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  ����û�\n");
        printf("\t\t\t  * 2  �����û�\n");
        printf("\t\t\t  * 3  ɾ���û�\n");
        printf("\t\t\t  * 4  ����ͷ�\n");
        printf("\t\t\t  * 5  �޸Ŀͷ�\n");
        printf("\t\t\t  * 6  ���ӿͷ�\n");
        printf("\t\t\t  * 7  ɾ���ͷ�\n");
        printf("\t\t\t  * 8  �鿴��֧\n");
        printf("\t\t\t  * 9  �޸ĸ�����Ϣ\n");
        printf("\t\t\t  * 0  ע��\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&c);
        while(c<0||c>9)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
            case 1:
                printf("\t\t\t\t\t#����û�#\n");
                display_user(read());
                break;
            case 2:
                printf("\t\t\t\t\t#�����û�#\n");
                write();
                break;
            case 3:
                printf("\t\t\t\t\t#ɾ���û�#\n");
                deleteUser();
                break;
            case 4:
                printf("\t\t\t\t\t#����ͷ�#\n");
                display_room(readRoom());
                break;
            case 5:
                printf("\t\t\t\t\t#�޸Ŀͷ�#\n");
                amendRoom();
                break;
            case 6:
                printf("\t\t\t\t\t#���ӿͼ�#\n");
                writeRoom();
                break;
            case 7:
                printf("\t\t\t\t\t#ɾ���ͼ�#\n");
                deleteRoom();
                break;
            case 8:
                printf("\t\t\t\t\t#�鿴��֧#\n");
                checkBill();
                break;
            case 9:
                printf("\t\t\t\t\t#�޸ĸ�����Ϣ#\n");
                amendPassWord(r);
                break;
            default:
                loop=0;
                break;
        }
    }
}
void checkBill()
{//�鿴�˵�
    bill *head,*p;
    int id,n=0,c=1,s,num=0;
    char day[12];                     //����ʱ��
    head=readBill();
    p=head->next->next;
    while(c)
    {
        printf("\t\t\t      #�鿴�˵�#\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t      1:  ���·ݲ�ѯ\n");
        printf("\t\t\t      2�� �������ѯ\n");
        printf("\t\t\t      3�� �鿴ȫ��\n");
        printf("\t\t\t      0�� �˳�\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t������ѡ��:");
        scanf("%d",&s);
        while(s<0||s>3)
        {
            printf("����ѡ��������������룺");
            scanf("%d",&s);
        }
        if(s==1)
        {
            n=0;
            num=0;
            printf("����������·ݣ��磺2017.05����");
            scanf("%s",day);
            printf("*************************************************************************************************************** \n");
            while(p)
            {
                if(index(p->inDay,day)!=-1)
                {
                    n++;
                    printf("NO%d:\n",n);
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
                    printf("\n��סʱ��: %s\t",p->inDay);
                    printf("�˷�ʱ��: %s\n",p->outDay);
                    num=num+p->yingPrice-p->cashPledge;
                    p=p->next;
                }
                else p=p->next;
            }
            printf("*************************************************************************************************************** \n");
            printf("��ѯ��%d����¼\n",n);
            printf("%s��������=%d\n",day,num);
            p=head->next->next;
            getch();
        }
        else if(s==2)
        {
            n=0;
            num=0;
            printf("�����뷿��ţ���");
            scanf("%d",&id);
            printf("*************************************************************************************************************** \n");
            while(p)
            {
                if(p->roomId==id)
                {
                    n++;
                    printf("NO%d:\n",n);
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
                    num=num+p->yingPrice-p->cashPledge;
                    p=p->next;
                }
                else p=p->next;
            }
            printf("*************************************************************************************************************** \n");
            printf("��ѯ��%d����¼\n",n);
            printf("%d�ŷ�������=%d\n",id,num);
            p=head->next->next;
            getch();
        }
        else if(s==3)
            display_bill(head);
        else
            c=0;
    }
}
void deleteRoom()
{//ɾ������
    int pos,id;
    char ans;
    room *head,*p,*pa;
    head=readRoom();
    p=head->next;
    pa=head;
    display_room(readRoom());
    printf("������Ҫɾ���ķ���ţ����˺Ų����ڷ��أ���");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
            printf("����ɾ����(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                pa->next=p->next;
                free(p);
                p=head->next;
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
                printf("ɾ���ɹ���\n");
                display_room(readRoom());
                clearRoom(head);
                return;
            }
            else clearRoom(head);return;
        }
        else p=p->next;
    }
    if(!p)
    {
        printf("�޴˷��䣡\n");
        clearRoom(head);
        return;
    }
}
void amendRoom()
{//�޸ķ���
    int pos,id;
    char ans,name[15];
    room *head,*p,*pa;
    head=readRoom();
    p=head->next;
    pa=head;
    display_room(readRoom());
    printf("������Ҫ�޸���Ϣ�ķ���ţ�������Ų����ڷ��أ���");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
            printf("���ӵ�ǰ��Ϣ���£�\n");
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
            printf("ȷ���޸ģ�(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("���뷿�ţ�\n");
                scanf("%d",&p->roomId);
                printf("���뷿�����ͣ�\n");
                scanf("%s",&name);
                strcpy(p->name,name);
                printf("���뷿�ۣ�\n");
                scanf("%d",&p->price);
                printf("����Ѻ��\n");
                scanf("%d",&p->cashPledge);
                printf("���뷿������(0��ʾ�����ۣ�1��ʾ�Żݼ�)��\n");
                scanf("%d",&p->discount);
                printf("���뷿��״̬��0��ʾ�գ�1��ʾ�ǿգ�2��ʾ����ɨ����\n");
                scanf("%d",&p->status);
                pa=p;
                p=head->next->next;
                FILE *f = fopen("room.txt","w");//�ԡ�r����д����ʽ��
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
                printf("�޸ĳɹ���\n");
                printf("���ӵ�ǰ��Ϣ���£�\n");
                printf("����: %d\t",pa->roomId);
                printf("��������: %s\t",pa->name);
                printf("����(Ԫ): %d\t",pa->price);
                printf("Ѻ��(Ԫ): %d\t",pa->cashPledge);
                if(pa->discount==0)
                    printf("�Ż�: ��\t");
                else
                    printf("�Ż�: ��\t");
                if(pa->status==0)
                    printf("״̬: ��\n");
                else if(pa->status==1)
                    printf("״̬: �ǿ�\n");
                else if(pa->status==2)
                    printf("״̬: δ��ɨ\n");
                else
                    printf("״̬: ��ɨ��\n");
                clearRoom(head);
                return;
            }
            else clearRoom(head);return;
        }
        else p=p->next;
    }
    if(!p)
    {
        printf("�޴˷��䣡\n");
        clearRoom(head);
        return;
    }
}
void writeRoom()
{//���ӷ���
    int roomId;         //����
    char name[15];      //��������
    int price;          //����
    int cashPledge;     //Ѻ��
    int discount;       //0��ʾ�����ۣ�1��ʾ�Żݼۡ�
    int status;         //����״̬��0��ʾ�գ�1��ʾ�ǿգ�2��ʾ����ɨ
    int select;         //д���ݿ�����
    printf("��\"1\"������\"0\"�˳�:\n");
    scanf("%d",&select);
    while(1==select)
    {
        FILE *f = fopen("room.txt","a");//�ԡ�a����д����ʽ��user.txt
        printf("���뷿�ţ�\n");
        scanf("%d",&roomId);
        fprintf(f,"%-5d",roomId);
        printf("���뷿�����ͣ�\n");
        scanf("%s",&name);
        fprintf(f,"%-15s",name);
        printf("���뷿�ۣ�\n");
        scanf("%d",&price);
        fprintf(f,"%-6d",price);
        printf("����Ѻ��\n");
        scanf("%d",&cashPledge);
        fprintf(f,"%-6d",cashPledge);
        printf("���뷿������(0��ʾ�����ۣ�1��ʾ�Żݼ�)��\n");
        scanf("%d",&discount);
        fprintf(f,"%-3d",discount);
        printf("���뷿��״̬��0��ʾ�գ�1��ʾ�ǿգ�2��ʾ����ɨ����\n");
        scanf("%d",&status);
        fprintf(f,"%d\n",status);
        fclose(f);//��ǰ�ļ���д����ִ����ϣ���Ҫ�رոò��������Ӱ��Ե�ǰ�ļ�����������
        printf("��\"1\"������\"0\"�˳�:\n");
        scanf("%d",&select);
    }
}
