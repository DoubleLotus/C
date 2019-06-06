/****************************************************\
������Ϣ��
    ����������
��Ȩ������
    ��Ȩ�ɱ�����ͨ��ѧ���������Ϣ����ѧԺ������ƻ���ѵ���γ�������
ģ������: 
    ����ģ��
ժҪ:
    ��ѧ���̴��룬��Ӧʵ��6
����˵��:
    ��ģ��ʵ��ʵ��6��������
ģ����ʷ:
    ������2018��12��20�մ�����ģ�飬email��shhan@bjtu.edu.cn

**********************************************************/

#include "Lab5_data.h"
#include "stdio.h"
#include "stdlib.h"

/*
*�������ƣ�cmp2DArray
*�������ܣ�����ά�������������õıȽϺ�������������
*���������const void *a��qsort�������������ڱȽϵĵ�һ��Ԫ��ָ��
           const void *b��qsort�������������ڱȽϵĵڶ���Ԫ��ָ��
*����ֵ�����ͣ���aָ����ָ�ռ���a+2λ�õ�ֵ��b+2ָ��ָʾλ�õ�ֵ�󣬷�����ֵ
               ��aָ����ָ�ռ���a+2λ�õ�ֵ��b+2ָ��ָʾλ�õ�ֵ��ͬ������0
			   ��aָ����ָ�ռ���a+2λ�õ�ֵ��b+2ָ��ָʾλ�õ�ֵС�����ظ�ֵ
*�汾��Ϣ��create by hansheng,2018-12-20
*/
int cmp2DArray(const void *a, const void *b)
{
	int *cmp1 = (int*)a;
	int *cmp2 = (int*)b;

	return *(cmp1+2) - *(cmp2+2);//����
}

/*
*�������ƣ�cmpStructArray
*�������ܣ����ṹ���������������õıȽϺ�������������
*���������const void *a��qsort�������������ڱȽϵĵ�һ��Ԫ��ָ��
           const void *b��qsort�������������ڱȽϵĵڶ���Ԫ��ָ��
*����ֵ�����ͣ���aָ����ָ�ṹ���item3ֵ��bָ��ָʾ�ṹ���item3ֵ�󣬷�����ֵ
               ��aָ����ָ�ṹ���item3ֵ��bָ��ָʾ�ṹ���item3ֵ��ͬ������0
			   ��aָ����ָ�ṹ���item3ֵ��bָ��ָʾ�ṹ���item3ֵС�����ظ�ֵ
*�汾��Ϣ��create by hansheng,2018-12-20
*/
int cmpStructArray(const void *a, const void *b)
{
	DATAITEM *cmp1 = (DATAITEM*)a;
	DATAITEM *cmp2 = (DATAITEM*)b;

	return cmp1->item3 - cmp2->item3;//����
}

/*
*�������ƣ�cmpFingerArray
*�������ܣ���ָ��ṹ���ָ���������������õıȽϺ�������������
*���������const void *a��qsort�������������ڱȽϵĵ�һ��Ԫ��ָ��
           const void *b��qsort�������������ڱȽϵĵڶ���Ԫ��ָ��
*����ֵ�����ͣ���aָ����ָԪ��ָ��Ľṹ���item3ֵ��bָ����ָԪ��ָ��Ľṹ���item3ֵ�󣬷�����ֵ
               ��aָ����ָԪ��ָ��Ľṹ���item3ֵ��bָ����ָԪ��ָ��Ľṹ���item3ֵ��ͬ������0
			   ��aָ����ָԪ��ָ��Ľṹ���item3ֵ��bָ����ָԪ��ָ��Ľṹ���item3ֵС�����ظ�ֵ
*�汾��Ϣ��create by hansheng,2018-12-20
*/
int cmpFingerArray(const void *a, const void *b)
{
	DATAITEM **cmp1 = (DATAITEM**)a;
	DATAITEM **cmp2 = (DATAITEM**)b;

	return (*cmp1)->item3 - (*cmp2)->item3;
}

/*
*�������ƣ�sort2DArray
*�������ܣ��Զ�ά�����������
*�����������
*����ֵ����
*�汾��Ϣ��create by hansheng,2018-12-20
*/
void sort2DArray()
{
	if(Array2D != NULL && record_num > 0)
	{
		qsort(Array2D,record_num,sizeof(int)*3,cmp2DArray);
	}
	else
	{
		printf("�Զ�ά��������ʧ�ܣ���ά����Ϊ�գ�\n");
	}
}

/*
*�������ƣ�sortStructArray
*�������ܣ��Խṹ�������������
*�����������
*����ֵ����
*�汾��Ϣ��create by hansheng,2018-12-20
*/
void sortStructArray()
{
	if(StructArray != NULL && record_num > 0)
	{
		qsort(StructArray,record_num,sizeof(DATAITEM),cmpStructArray);
	}
	else
	{
		printf("�Խṹ����������ʧ�ܣ��ṹ������Ϊ�գ�\n");
	}
}

/*
*�������ƣ�sortFingerArray
*�������ܣ���ָ��ṹ���ָ�������������
*�����������
*����ֵ����
*�汾��Ϣ��create by hansheng,2018-12-20
*/
void sortFingerArray()
{
	if(ArrayPointerStruct != NULL && record_num > 0)
	{
		qsort(ArrayPointerStruct,record_num,sizeof(DATAITEM*),cmpFingerArray);
	}
	else
	{
		printf("��ָ��ṹ���ָ����������ʧ�ܣ�ָ������Ϊ�գ�\n");
	}
}

/*
*�������ƣ�sortLink
*�������ܣ�������������򣬲���ð������
*�����������
*����ֵ����
*�汾��Ϣ��create by hansheng,2018-12-20
*/
void sortLink()
{
	if(LinkHead != NULL && record_num > 0)
	{
		LINKNODE *p,*q;

		//��ʼ������ָ��
		p=LinkHead;
		q=p->next;

		while(q != NULL)
		{
			while(q != NULL)
			{
				if(p->record.item3 > q->record.item3)
				{
					//������ݽ���
					DATAITEM temp;
					temp = p->record;
					p->record = q->record;
					q->record = temp;
				}

				//����ָ��q����
				q = q->next;
			}

			//����ָ��p����
			p=p->next;

			//���ù���ָ��q
			q=p->next;
		}
	}
	else
	{
		printf("����������ʧ�ܣ�����Ϊ�գ�\n");
	}
}
