#include<stdio.h>
#include<iostream>
#include<string.h>
typedef struct Student
{
	char m_Name[20]; //姓名
	char m_Id[20]; //学号
	char m_Class[20];//班级号
	double Math; //高数
	double English; //大学英语
	double Physic; //大学物理
	double Computer; //计算机
	double Sum; //成绩总和
}ElementType;
typedef struct Lnode
{
	ElementType data;
	struct Lnode* next;
}Lnode, * LinkList;
void showMenu();//菜单
void InitList(LinkList& list);//初始化链表
int ListLength(LinkList list);//求单链表表表长,,返回其长度
void ListInsert(LinkList& list, ElementType e, int length);//录入学生信息
void ListPrint(LinkList list);//打印链表
Lnode* IsLocateElem(LinkList list, char* Id);//检测学号是否存在,若存在返回该学号的结点,否则返回 NULL
void DestroyList(LinkList& list);//销毁单链表
void addStudent(LinkList list);
void showStudent(LinkList list);//显示学生信息
void deleteStudent(LinkList& list);//删除某学生信息
void findStudent(LinkList list);//按照学号查找某位学生信息
void modifyStudent(LinkList list);//修改学生信息
void sordStudent(LinkList& list);//对学生总分排序
void studentScholarship(LinkList list);//输出奖学金获得情况

void showMenu()//菜单
{
	printf("					*******欢迎登录学生奖学金评定系统**********\n\n");
	printf("					*********1、录入学生信息 *********\n");
	printf("					*********2、查找学生(按照学号查找)*********\n");
	printf("					*********3、输出所有学生信息(已经排序) ******\n");
	printf("					*********4、修改学生信息(按照学号) ********\n");
	printf("					*********5、删除学生信息(按照学号)*********\n");
	printf("					*********6、输出奖学金获得情况 *********\n");
	printf("					*********0、退出奖学金评定程序 *********\n");
	printf("					*******************************************\n\n");
}

void InitList(LinkList& list)//初始化链表
{
	list = (LinkList)malloc(sizeof(Lnode));
	list->next = NULL;
}

int ListLength(LinkList list)//求单链表表表长,返回其长度
{
	Lnode* node = list->next;
	int length = 0;
	while (node)
	{
		length++;
		node = node->next;
	}
	return length;
}

void ListInsert(LinkList& list, ElementType e, int length)//录入学生信息
{
	Lnode* node = list;
	int i = 0;
	while (node && i < length)
	{
		node = node->next;
		i++;
	}
	Lnode* inode = (Lnode*)malloc(sizeof(Lnode));
	inode->data = e;
	inode->next = node->next;
	node->next = inode;
}

void ListPrint(LinkList list)//打印链表
{
	Lnode* node = list->next;
	printf("以下为所有学生信息:\n");
	printf("---------------------------STUDENT------------------------------------\n");
	printf("|学号|班级 |姓名 |高数 |英语 |物理 |计算机 | 总分 \n");
	printf("----------------------------------------------------------------------\n");
	while (node)
	{
		printf("%s %s %s %.2f %.2f %.2f %.2f %.2f\n", node->data.m_Id, node->data.m_Class, node->data.m_Name, node->data.Math, node->data.English, node->data.Physic, node->data.Computer, node->data.Sum);
		node = node->next;
	}
}

Lnode* IsLocateElem(LinkList list, char* Id)//检测学号是否存在,若存在返回该学号的结点,否则返回 NULL
{
Lnode * node = list->next;
while (node && strcmp(node->data.m_Id, Id))
{
node = node->next;
}
return node;
}

void DestroyList(LinkList& list)//销毁单链表
{
	Lnode* p = list;
	Lnode* q = list;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
}

void addStudent(LinkList list)
{
	char m_Name[20]; //姓名
	char m_Id[20]; //学号
	char m_Class[20];//班级号
	double Math; //高数
	double English; //大学英语
	double Physic; //大学物理
	double Computer; //计算机
	double Sum; //成绩总和
	int num;//人数
	ElementType e;
	printf("请输入您需要录入的学生人数(建议录入人数不少于 15 人):\n");
	scanf("%d", &num);
	printf("请按照以下格式依次填写对应内容\n");
	printf("---------------------------STUDENT------------------------------------\n");
	printf("|学号|班级 |姓名 |高数 |英语 |物理 |计算机 | \n");
	printf("----------------------------------------------------------------------\n");
	for (int i = 0; i < num; i++)
	{
		scanf("%s %s %s %lf %lf %lf %lf", &m_Id, &m_Class, &m_Name, &Math, &English, &Physic, &Computer);
		Sum = Math + English + Physic + Computer;
		strcpy(e.m_Id, m_Id);
		strcpy(e.m_Class, m_Class);
		strcpy(e.m_Name, m_Name);
		e.Math = Math;
		e.English = English;
		e.Physic = Physic;
		e.Computer = Computer;
		e.Sum = Sum;
		ListInsert(list, e, ListLength(list));
	}
	sordStudent(list);
	printf("添加成功\n");
	system("pause");
	system("cls");//清屏
}

void showStudent(LinkList list)//显示学生信息
{
	sordStudent(list);//对学生总分排序
	//判断人数是否为 0
	if (!ListLength(list))
	{
		printf("当前记录为空,请添加学生\n");
	}
	else
	{
		ListPrint(list);
	}
	system("pause");
	system("cls");//清屏
}

void deleteStudent(LinkList& list)//删除某学生信息
{
	printf("请输入您要删除的学生学号:\n");
	char Id[20]; //学号
	scanf("%s", &Id);
	Lnode* crnode = IsLocateElem(list, Id);
	if (!crnode)//未查到
	{
		printf("查无此人,请检查输入的学号是否有误\n");
	}
	else//查到,要进行删除操作了
	{
		Lnode* prnode = list;
		while (prnode->next != crnode)
		{
			prnode = prnode->next;
		}
		prnode->next = crnode->next;
		free(crnode);
		printf("删除成功\n");
	}
	system("pause");
	system("cls");//清屏
}

void findStudent(LinkList list)//按照学号查找某位学生信息
{
	printf("请输入您要查找的学生学号:\n");
	char Id[20]; //学号
	scanf("%s", &Id);
	Lnode* crnode = IsLocateElem(list, Id);
	if (!crnode)//未查到
	{
		printf("查无此人,请检查输入的学号是否有误\n");
	}
	else
	{
		printf("学号: %s 班级: %s 姓名: %s 高数: %.2f 英语: %.2f 物理: %.2f 计算机: % .2f 总分 : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English,
			crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
	}
	system("pause");
	system("cls");//清屏
}

void modifyStudent(LinkList list)//修改学生信息
{
	printf("请输入您要修改的学生学号:\n");
	char Id[20]; //学号
	scanf("%s", &Id);
	Lnode* crnode = IsLocateElem(list, Id);
	if (!crnode)
	{
		printf("查无此人,请检查输入的学号是否有误\n");
	}
	else
	{
		printf("请输入此人的所有信息:\n");
		char m_Name[20]; //姓名
		char m_Id[20]; //学号
		char m_Class[20];//班级号
		double Math; //高数
		double English; //大学英语
		double Physic; //大学物理
		double Computer; //计算机
		double Sum; //成绩总和
		printf("---------------------------STUDENT------------------------------------\n");
		printf("|学号|班级 |姓名 |高数 |英语 |物理 |计算机 | \n");
		printf("----------------------------------------------------------------------\n");
		scanf("%s %s %s %lf %lf %lf %lf", &m_Id, &m_Class, &m_Name, &Math, &English, &Physic, &Computer);
		Sum = Math + English + Physic + Computer;
		strcpy(crnode->data.m_Id, m_Id);
		strcpy(crnode->data.m_Class, m_Class);
		strcpy(crnode->data.m_Name, m_Name);
		crnode->data.Math = Math;
		crnode->data.English = English;
		crnode->data.Physic = Physic;
		crnode->data.Computer = Computer;
		crnode->data.Sum = Sum;
		printf("修改学生信息成功\n");
	}
	system("pause");
		system("cls");//清屏
}

void sordStudent(LinkList& list)//对学生总分排序
{
	Lnode* p = NULL;
	Lnode* q = NULL;
	for (p = list->next; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data.Sum < q->data.Sum)
			{
				ElementType temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}

void studentScholarship(LinkList list)//输出奖学金获得情况
{
	//判断人数是否为 0
	if (!ListLength(list))
	{
		printf("当前记录为空,请添加学生信息后再使用此功能\n");
	}
	else
	{
		//奖学金共分为三级,一级奖学金 2 名,二等奖学金 5 名,三等奖学金 7 名
		Lnode* crnode = list->next;
		printf("一等奖学金获得者情况:\n");
		for (int i = 0; i < 3 && crnode; i++)
		{
			printf("学号: %s 班级: %s 姓名: %s 高数: %.2f 英语: %.2f 物理: % .2f 计算机 : % .2f 总分 : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English, crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
				crnode = crnode->next;
		}
		if (!crnode)
		{

				printf("无二等奖学金获得者(您录入学生的信息太少,建议您录入学生人数不少于 15 人)\n");
		}
		else
		{
			printf("二等奖学金获得者情况:\n");
			for (int i = 0; i < 5 && crnode; i++)
			{
				printf("学号: %s 班级: %s 姓名: %s 高数: %.2f 英语: %.2f 物理: % .2f 计算机 : % .2f 总分 : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English, crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
					crnode = crnode->next;
			}
		}
		if (!crnode)
		{
			printf("无三等奖学金获得者(您录入学生的信息太少,建议您录入学生人数不少于 15 人)\n");
		}
		else
		{
			printf("三等奖学金获得者情况:\n");
			for (int i = 0; i < 7 && crnode; i++)
			{
				printf("学号: %s 班级: %s 姓名: %s 高数: %.2f 英语: %.2f 物理: % .2f 计算机 : % .2f 总分 : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English, crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
					crnode = crnode->next;
			}
		}
	}
	system("pause");
	system("cls");//清屏
}

int main(void)
{
	int select = 0;//创建用户选择输入的变量
	LinkList list;
	InitList(list);
	while (true)
	{
			//菜单调用
			showMenu();
		printf("需要使用某项功能时只需输入其对应的序号即可!\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1: //1、录入学生信息
			addStudent(list);
			break;
		case 2: //2、查找学生(按照学号查找)
			findStudent(list);
			break;
		case 3: //3、输出所有学生信息(未排序)
			showStudent(list);
			break;
		case 4: //4、按照学号修改学生信息
			modifyStudent(list);
			break;
		case 5: //5、按照学号删除学生信息
			deleteStudent(list);
			break;
		case 6: //6、输出奖学金获得情况
			studentScholarship(list);
			break;
		case 0: //0、退出奖学金评定程序,记得在之前销毁链表
			printf("欢迎下次使用\n");
			DestroyList(list);
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}