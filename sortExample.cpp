#include "Lab6_sort.h"
#include <stdio.h>
#include <malloc.h>
#include "Lab5_data.h"

int record_num;
int * Array2D;
struct DataItem * StructArray;
struct DataItem * * ArrayPointerStruct;
struct LinkNode * LinkHead;

void main()
{
	int i, j;

	printf("Please input record_num:\n");
	scanf("%d", &record_num);
	/*
	//***********************  Array2D Sort Test *************************************

	Array2D =(int *)  malloc(sizeof(int)*3*record_num);

	for(i = 0; i < record_num; i++)
		for(j=0; j<3; j++)
			scanf("%d", &Array2D[i*3+j]);

	printf("Before sort:\n");

	for(i = 0; i < record_num; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d\t", Array2D[i*3+j]);
		}
		printf("\n");
	}

	sort2DArray();
	
	printf("after sort:\n");

	for(i = 0; i < record_num; i++)
	{	
		for(j=0; j<3; j++)
		{
			printf("%d\t", Array2D[i*3+j]);
		}
		printf("\n");
	}
	free(Array2D);
	
*/
	//**************************** StructArray Sort Test **************************************************
/*	StructArray =(struct DataItem *)  malloc(sizeof(struct DataItem)*record_num);

	for(i = 0; i < record_num; i++)
		scanf("%d%d%d", &StructArray[i].item1, &StructArray[i].item2, &StructArray[i].item3);

	printf("Before sort:\n");

	for(i = 0; i < record_num; i++)
	{
		printf("%d\t%d\t%d\t", StructArray[i].item1, StructArray[i].item2, StructArray[i].item3);
		printf("\n");
	}

	sortStructArray();
	
	printf("after sort:\n");

	for(i = 0; i < record_num; i++)
	{	
		printf("%d\t%d\t%d\t", StructArray[i].item1, StructArray[i].item2, StructArray[i].item3);
		printf("\n");
	}
	free(StructArray);
	*/

	//*************************************************************************************************

	//**************************** ArrayPointerStruct Sort Test **************************************************
	
	ArrayPointerStruct =(struct DataItem **)  malloc(sizeof(struct DataItem *)*record_num);
	for(i = 0; i < record_num; i++)
	{
		ArrayPointerStruct[i] = (struct DataItem *)  malloc(sizeof(struct DataItem) );
		scanf("%d%d%d", &(ArrayPointerStruct[i]->item1), &(ArrayPointerStruct[i]->item2), &(ArrayPointerStruct[i]->item3));
	}

	printf("Before sort:\n");

	for(i = 0; i < record_num; i++)
	{
		printf("%d\t%d\t%d\t", ArrayPointerStruct[i]->item1, ArrayPointerStruct[i]->item2, ArrayPointerStruct[i]->item3);
		printf("\n");
	}

	sortFingerArray();
	
	printf("after sort:\n");
	for(i = 0; i < record_num; i++)
	{
		printf("%d\t%d\t%d\t", ArrayPointerStruct[i]->item1, ArrayPointerStruct[i]->item2, ArrayPointerStruct[i]->item3);
		printf("\n");
	}

	for(i = 0; i < record_num; i++)
		free(ArrayPointerStruct[i]);

	free(ArrayPointerStruct);

}