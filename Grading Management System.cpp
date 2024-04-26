#include<stdio.h>
#include<iostream>
#include<string.h>
typedef struct Student
{
	char m_Name[20]; //����
	char m_Id[20]; //ѧ��
	char m_Class[20];//�༶��
	double Math; //����
	double English; //��ѧӢ��
	double Physic; //��ѧ����
	double Computer; //�����
	double Sum; //�ɼ��ܺ�
}ElementType;
typedef struct Lnode
{
	ElementType data;
	struct Lnode* next;
}Lnode, * LinkList;
void showMenu();//�˵�
void InitList(LinkList& list);//��ʼ������
int ListLength(LinkList list);//��������,,�����䳤��
void ListInsert(LinkList& list, ElementType e, int length);//¼��ѧ����Ϣ
void ListPrint(LinkList list);//��ӡ����
Lnode* IsLocateElem(LinkList list, char* Id);//���ѧ���Ƿ����,�����ڷ��ظ�ѧ�ŵĽ��,���򷵻� NULL
void DestroyList(LinkList& list);//���ٵ�����
void addStudent(LinkList list);
void showStudent(LinkList list);//��ʾѧ����Ϣ
void deleteStudent(LinkList& list);//ɾ��ĳѧ����Ϣ
void findStudent(LinkList list);//����ѧ�Ų���ĳλѧ����Ϣ
void modifyStudent(LinkList list);//�޸�ѧ����Ϣ
void sordStudent(LinkList& list);//��ѧ���ܷ�����
void studentScholarship(LinkList list);//�����ѧ�������

void showMenu()//�˵�
{
	printf("					*******��ӭ��¼ѧ����ѧ������ϵͳ**********\n\n");
	printf("					*********1��¼��ѧ����Ϣ *********\n");
	printf("					*********2������ѧ��(����ѧ�Ų���)*********\n");
	printf("					*********3���������ѧ����Ϣ(�Ѿ�����) ******\n");
	printf("					*********4���޸�ѧ����Ϣ(����ѧ��) ********\n");
	printf("					*********5��ɾ��ѧ����Ϣ(����ѧ��)*********\n");
	printf("					*********6�������ѧ������� *********\n");
	printf("					*********0���˳���ѧ���������� *********\n");
	printf("					*******************************************\n\n");
}

void InitList(LinkList& list)//��ʼ������
{
	list = (LinkList)malloc(sizeof(Lnode));
	list->next = NULL;
}

int ListLength(LinkList list)//��������,�����䳤��
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

void ListInsert(LinkList& list, ElementType e, int length)//¼��ѧ����Ϣ
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

void ListPrint(LinkList list)//��ӡ����
{
	Lnode* node = list->next;
	printf("����Ϊ����ѧ����Ϣ:\n");
	printf("---------------------------STUDENT------------------------------------\n");
	printf("|ѧ��|�༶ |���� |���� |Ӣ�� |���� |����� | �ܷ� \n");
	printf("----------------------------------------------------------------------\n");
	while (node)
	{
		printf("%s %s %s %.2f %.2f %.2f %.2f %.2f\n", node->data.m_Id, node->data.m_Class, node->data.m_Name, node->data.Math, node->data.English, node->data.Physic, node->data.Computer, node->data.Sum);
		node = node->next;
	}
}

Lnode* IsLocateElem(LinkList list, char* Id)//���ѧ���Ƿ����,�����ڷ��ظ�ѧ�ŵĽ��,���򷵻� NULL
{
Lnode * node = list->next;
while (node && strcmp(node->data.m_Id, Id))
{
node = node->next;
}
return node;
}

void DestroyList(LinkList& list)//���ٵ�����
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
	char m_Name[20]; //����
	char m_Id[20]; //ѧ��
	char m_Class[20];//�༶��
	double Math; //����
	double English; //��ѧӢ��
	double Physic; //��ѧ����
	double Computer; //�����
	double Sum; //�ɼ��ܺ�
	int num;//����
	ElementType e;
	printf("����������Ҫ¼���ѧ������(����¼������������ 15 ��):\n");
	scanf("%d", &num);
	printf("�밴�����¸�ʽ������д��Ӧ����\n");
	printf("---------------------------STUDENT------------------------------------\n");
	printf("|ѧ��|�༶ |���� |���� |Ӣ�� |���� |����� | \n");
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
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");//����
}

void showStudent(LinkList list)//��ʾѧ����Ϣ
{
	sordStudent(list);//��ѧ���ܷ�����
	//�ж������Ƿ�Ϊ 0
	if (!ListLength(list))
	{
		printf("��ǰ��¼Ϊ��,�����ѧ��\n");
	}
	else
	{
		ListPrint(list);
	}
	system("pause");
	system("cls");//����
}

void deleteStudent(LinkList& list)//ɾ��ĳѧ����Ϣ
{
	printf("��������Ҫɾ����ѧ��ѧ��:\n");
	char Id[20]; //ѧ��
	scanf("%s", &Id);
	Lnode* crnode = IsLocateElem(list, Id);
	if (!crnode)//δ�鵽
	{
		printf("���޴���,���������ѧ���Ƿ�����\n");
	}
	else//�鵽,Ҫ����ɾ��������
	{
		Lnode* prnode = list;
		while (prnode->next != crnode)
		{
			prnode = prnode->next;
		}
		prnode->next = crnode->next;
		free(crnode);
		printf("ɾ���ɹ�\n");
	}
	system("pause");
	system("cls");//����
}

void findStudent(LinkList list)//����ѧ�Ų���ĳλѧ����Ϣ
{
	printf("��������Ҫ���ҵ�ѧ��ѧ��:\n");
	char Id[20]; //ѧ��
	scanf("%s", &Id);
	Lnode* crnode = IsLocateElem(list, Id);
	if (!crnode)//δ�鵽
	{
		printf("���޴���,���������ѧ���Ƿ�����\n");
	}
	else
	{
		printf("ѧ��: %s �༶: %s ����: %s ����: %.2f Ӣ��: %.2f ����: %.2f �����: % .2f �ܷ� : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English,
			crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
	}
	system("pause");
	system("cls");//����
}

void modifyStudent(LinkList list)//�޸�ѧ����Ϣ
{
	printf("��������Ҫ�޸ĵ�ѧ��ѧ��:\n");
	char Id[20]; //ѧ��
	scanf("%s", &Id);
	Lnode* crnode = IsLocateElem(list, Id);
	if (!crnode)
	{
		printf("���޴���,���������ѧ���Ƿ�����\n");
	}
	else
	{
		printf("��������˵�������Ϣ:\n");
		char m_Name[20]; //����
		char m_Id[20]; //ѧ��
		char m_Class[20];//�༶��
		double Math; //����
		double English; //��ѧӢ��
		double Physic; //��ѧ����
		double Computer; //�����
		double Sum; //�ɼ��ܺ�
		printf("---------------------------STUDENT------------------------------------\n");
		printf("|ѧ��|�༶ |���� |���� |Ӣ�� |���� |����� | \n");
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
		printf("�޸�ѧ����Ϣ�ɹ�\n");
	}
	system("pause");
		system("cls");//����
}

void sordStudent(LinkList& list)//��ѧ���ܷ�����
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

void studentScholarship(LinkList list)//�����ѧ�������
{
	//�ж������Ƿ�Ϊ 0
	if (!ListLength(list))
	{
		printf("��ǰ��¼Ϊ��,�����ѧ����Ϣ����ʹ�ô˹���\n");
	}
	else
	{
		//��ѧ�𹲷�Ϊ����,һ����ѧ�� 2 ��,���Ƚ�ѧ�� 5 ��,���Ƚ�ѧ�� 7 ��
		Lnode* crnode = list->next;
		printf("һ�Ƚ�ѧ���������:\n");
		for (int i = 0; i < 3 && crnode; i++)
		{
			printf("ѧ��: %s �༶: %s ����: %s ����: %.2f Ӣ��: %.2f ����: % .2f ����� : % .2f �ܷ� : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English, crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
				crnode = crnode->next;
		}
		if (!crnode)
		{

				printf("�޶��Ƚ�ѧ������(��¼��ѧ������Ϣ̫��,������¼��ѧ������������ 15 ��)\n");
		}
		else
		{
			printf("���Ƚ�ѧ���������:\n");
			for (int i = 0; i < 5 && crnode; i++)
			{
				printf("ѧ��: %s �༶: %s ����: %s ����: %.2f Ӣ��: %.2f ����: % .2f ����� : % .2f �ܷ� : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English, crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
					crnode = crnode->next;
			}
		}
		if (!crnode)
		{
			printf("�����Ƚ�ѧ������(��¼��ѧ������Ϣ̫��,������¼��ѧ������������ 15 ��)\n");
		}
		else
		{
			printf("���Ƚ�ѧ���������:\n");
			for (int i = 0; i < 7 && crnode; i++)
			{
				printf("ѧ��: %s �༶: %s ����: %s ����: %.2f Ӣ��: %.2f ����: % .2f ����� : % .2f �ܷ� : % .2f\n", crnode->data.m_Id, crnode->data.m_Class, crnode->data.m_Name, crnode->data.Math, crnode->data.English, crnode->data.Physic, crnode->data.Computer, crnode->data.Sum);
					crnode = crnode->next;
			}
		}
	}
	system("pause");
	system("cls");//����
}

int main(void)
{
	int select = 0;//�����û�ѡ������ı���
	LinkList list;
	InitList(list);
	while (true)
	{
			//�˵�����
			showMenu();
		printf("��Ҫʹ��ĳ���ʱֻ���������Ӧ����ż���!\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1: //1��¼��ѧ����Ϣ
			addStudent(list);
			break;
		case 2: //2������ѧ��(����ѧ�Ų���)
			findStudent(list);
			break;
		case 3: //3���������ѧ����Ϣ(δ����)
			showStudent(list);
			break;
		case 4: //4������ѧ���޸�ѧ����Ϣ
			modifyStudent(list);
			break;
		case 5: //5������ѧ��ɾ��ѧ����Ϣ
			deleteStudent(list);
			break;
		case 6: //6�������ѧ�������
			studentScholarship(list);
			break;
		case 0: //0���˳���ѧ����������,�ǵ���֮ǰ��������
			printf("��ӭ�´�ʹ��\n");
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