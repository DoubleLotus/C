/****************************************************\
������Ϣ��
    ����������
��Ȩ������
    ��Ȩ�ɱ�����ͨ��ѧ���������Ϣ����ѧԺ������ƻ���ѵ���γ�������
ģ������: 
    ����ģ��
ժҪ:
    ��ѧ���̴��룬��Ӧʵ��5
����˵��:
    ��ģ��洢ʵ��5�ĳ�����ȫ�ֱ����ͽṹ������
ģ����ʷ:
    ������2018��12��19�մ�����ģ�飬email��shhan@bjtu.edu.cn

**********************************************************/

#ifndef _LabData
#define _LabData
#define MAX_ARRAY_LEN 4000

typedef struct configinfo {
	char  filesavepath[MAX_ARRAY_LEN] ;     	//���ڴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼
	char  filename[MAX_ARRAY_LEN] ;           //���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
	int  number;		//���ڴ�����ɵļ�¼����
	int  maxvalue1;   		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int  minvalue1; 		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
	int  maxvalue2;   		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int  minvalue2; 		//���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
	int  recordcount1;	//���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
	int  recordcount2;	//���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
	int  format;        //���ڱ�ʶ�����ļ��ĸ�ʽ��Ϣ��1��ʾ�����ı��ļ���2��ʾ���ɶ������ļ���3��ʾͬʱ�����ı��ļ��Ͷ������ļ�
} CONF;

typedef struct DataItem{
	int  item1 ;     //���ݼ�¼��Ԫ���һ��Ԫ��
	int  item2 ;     //���ݼ�¼��Ԫ��ڶ���Ԫ��
	int  item3 ;     //���ݼ�¼��Ԫ�������Ԫ��
} DATAITEM;

typedef struct LinkNode{
	DATAITEM record;
	struct LinkNode *next;
} LINKNODE;

//ȫ�ֱ�������
extern int record_num;        //����ģʽ�´洢�û���������ݼ�¼����

extern int* Array2D;  //��ά����
extern DATAITEM *StructArray;          //�ṹ��������ָ��
extern DATAITEM **ArrayPointerStruct;        //ָ��������ָ��
extern LINKNODE *LinkHead;             //����ͷָ��

#endif