#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
struct usernode
{
    char userId[12];                    //���
    char name[9];                       //����
    char sex[4];
    char role[8];                       //��ɫ
    char email[20];                     //email
    char password[7];                   //����
    //int roomId;                       //�����
    struct usernode *next;
};
typedef struct usernode user;    //�û��ṹ������
struct roomnode
{
    int roomId;         //�����
    char name[15];      //��������
    int price;          //����
    int discount;       //0��ʾ�����ۣ�1��ʾ�Żݼۡ�
    int cashPledge;     //Ѻ��
    int status;         //����״̬��0��ʾ�գ�1��ʾ�ǿգ�2��ʾ����ɨ��3��ʾ���˴�ɨ
    struct roomnode *next;
};
typedef struct roomnode room;      //����ṹ������
struct billnode
{
    int roomId;                         //����
    int price;                          //����
    int yingPrice;                      //Ӧ�շ���
    int realPrice;                      //ʵ�շ���
    int cashPledge;                     //Ѻ��
    int change;                         //����
    int status;                         //״̬1��ʾ��סѺ��2��ʾԤԼѺ��0��ʾ�ѻ�Ѻ��
    char inDay[12];                     //����ʱ��
    char outDay[12];                    //�˷�ʱ��
    struct billnode *next;
};
typedef struct billnode bill;         //�˵��ṹ������
struct tagCustomernode
{
    int roomId;         //�����
    char m_ID[19];      //���֤����
    char m_name[9];     //�˿�����
    int  m_age;         //�˿�����
    char  m_sex[4];     //�˿��Ա�
    char phone[12];     //�绰����
    char inDay[12];     //����ʱ��
    char outDay[12];    //�˷�ʱ��
    int status;         //�ÿ�״̬��1��ʾ��ס��0��ʾ���˷���2��ʾԤԼ��
    struct tagCustomernode *next;

};
typedef struct tagCustomernode customer;/*�ÿͽṹ*/

