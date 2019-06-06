/****************************************************\
作者信息：
    姓名：韩升
版权声明：
    版权由北京交通大学计算机与信息技术学院程序设计基础训练课程组所有
模块名称: 
    排序模块
摘要:
    教学例程代码，对应实验6
其它说明:
    本模块实现实验6的排序功能
模块历史:
    韩升于2018年12月20日创建本模块，email：shhan@bjtu.edu.cn

**********************************************************/

#include "Lab5_data.h"
#include "stdio.h"
#include "stdlib.h"

/*
*函数名称：cmp2DArray
*函数功能：供二维数组排序函数调用的比较函数，升序排序
*输入参数：const void *a：qsort函数传来的用于比较的第一个元素指针
           const void *b：qsort函数传来的用于比较的第二个元素指针
*返回值：整型，当a指针所指空间中a+2位置的值比b+2指针指示位置的值大，返回正值
               当a指针所指空间中a+2位置的值与b+2指针指示位置的值相同，返回0
			   当a指针所指空间中a+2位置的值比b+2指针指示位置的值小，返回负值
*版本信息：create by hansheng,2018-12-20
*/
int cmp2DArray(const void *a, const void *b)
{
	int *cmp1 = (int*)a;
	int *cmp2 = (int*)b;

	return *(cmp1+2) - *(cmp2+2);//升序
}

/*
*函数名称：cmpStructArray
*函数功能：供结构体数组排序函数调用的比较函数，升序排序
*输入参数：const void *a：qsort函数传来的用于比较的第一个元素指针
           const void *b：qsort函数传来的用于比较的第二个元素指针
*返回值：整型，当a指针所指结构体的item3值比b指针指示结构体的item3值大，返回正值
               当a指针所指结构体的item3值与b指针指示结构体的item3值相同，返回0
			   当a指针所指结构体的item3值比b指针指示结构体的item3值小，返回负值
*版本信息：create by hansheng,2018-12-20
*/
int cmpStructArray(const void *a, const void *b)
{
	DATAITEM *cmp1 = (DATAITEM*)a;
	DATAITEM *cmp2 = (DATAITEM*)b;

	return cmp1->item3 - cmp2->item3;//升序
}

/*
*函数名称：cmpFingerArray
*函数功能：供指向结构体的指针数组排序函数调用的比较函数，升序排序
*输入参数：const void *a：qsort函数传来的用于比较的第一个元素指针
           const void *b：qsort函数传来的用于比较的第二个元素指针
*返回值：整型，当a指针所指元素指向的结构体的item3值比b指针所指元素指向的结构体的item3值大，返回正值
               当a指针所指元素指向的结构体的item3值与b指针所指元素指向的结构体的item3值相同，返回0
			   当a指针所指元素指向的结构体的item3值比b指针所指元素指向的结构体的item3值小，返回负值
*版本信息：create by hansheng,2018-12-20
*/
int cmpFingerArray(const void *a, const void *b)
{
	DATAITEM **cmp1 = (DATAITEM**)a;
	DATAITEM **cmp2 = (DATAITEM**)b;

	return (*cmp1)->item3 - (*cmp2)->item3;
}

/*
*函数名称：sort2DArray
*函数功能：对二维数组进行排序
*输入参数：无
*返回值：无
*版本信息：create by hansheng,2018-12-20
*/
void sort2DArray()
{
	if(Array2D != NULL && record_num > 0)
	{
		qsort(Array2D,record_num,sizeof(int)*3,cmp2DArray);
	}
	else
	{
		printf("对二维数组排序失败，二维数组为空！\n");
	}
}

/*
*函数名称：sortStructArray
*函数功能：对结构体数组进行排序
*输入参数：无
*返回值：无
*版本信息：create by hansheng,2018-12-20
*/
void sortStructArray()
{
	if(StructArray != NULL && record_num > 0)
	{
		qsort(StructArray,record_num,sizeof(DATAITEM),cmpStructArray);
	}
	else
	{
		printf("对结构体数组排序失败，结构体数组为空！\n");
	}
}

/*
*函数名称：sortFingerArray
*函数功能：对指向结构体的指针数组进行排序
*输入参数：无
*返回值：无
*版本信息：create by hansheng,2018-12-20
*/
void sortFingerArray()
{
	if(ArrayPointerStruct != NULL && record_num > 0)
	{
		qsort(ArrayPointerStruct,record_num,sizeof(DATAITEM*),cmpFingerArray);
	}
	else
	{
		printf("对指向结构体的指针数组排序失败，指针数组为空！\n");
	}
}

/*
*函数名称：sortLink
*函数功能：对链表进行排序，采用冒泡排序法
*输入参数：无
*返回值：无
*版本信息：create by hansheng,2018-12-20
*/
void sortLink()
{
	if(LinkHead != NULL && record_num > 0)
	{
		LINKNODE *p,*q;

		//初始化工作指针
		p=LinkHead;
		q=p->next;

		while(q != NULL)
		{
			while(q != NULL)
			{
				if(p->record.item3 > q->record.item3)
				{
					//结点内容交换
					DATAITEM temp;
					temp = p->record;
					p->record = q->record;
					q->record = temp;
				}

				//工作指针q后移
				q = q->next;
			}

			//工作指针p后移
			p=p->next;

			//重置工作指针q
			q=p->next;
		}
	}
	else
	{
		printf("对链表排序失败，链表为空！\n");
	}
}
