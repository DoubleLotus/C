#ifndef _LabData
#define _LabData
#define MAX_ARRAY_LEN 4000

typedef struct configinfo {
	char  filesavepath[MAX_ARRAY_LEN] ;     	//用于存放数据记录文件的存储目录
	char  filename[MAX_ARRAY_LEN] ;           //用于存储数据记录文件的文件名信息
	int  number;		//用于存放生成的记录条数
	int  maxvalue1;   		//用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
	int  minvalue1; 		//用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
	int  maxvalue2;   		//用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
	int  minvalue2; 		//用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
	int  recordcount1;	//用于存放数据记录文件需要随机生成记录条数时条数值的上限
	int  recordcount2;	//用于存放数据记录文件需要随机生成记录条数时条数值的下限
	int  format;        //用于标识生成文件的格式信息，1表示生成文本文件，2表示生成二进制文件，3表示同时生成文本文件和二进制文件
} CONF;

typedef struct DataItem{
	int  item1 ;     //数据记录三元组第一个元素
	int  item2 ;     //数据记录三元组第二个元素
	int  item3 ;     //数据记录三元组第三个元素
} DATAITEM;

typedef struct LinkNode{
	DATAITEM record;
	struct LinkNode *next;
} LINKNODE;

//全局变量声明
extern int record_num;        //交互模式下存储用户输入的数据记录条数

extern int* Array2D;  //二维数组
extern DATAITEM *StructArray;          //结构体数组首指针
extern DATAITEM **ArrayPointerStruct;        //指针数组首指针
extern LINKNODE *LinkHead;             //链表头指针

#endif
