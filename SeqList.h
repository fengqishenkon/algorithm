#define _CRT_SECURE_NO_WARNINGS 
//���嶯̬˳���Ľṹ
typedef int SLDataType;
struct SeqList
{
	SLDataType* arr;//ָ��
	int size;//Ԫ�ظ���
	int capacity;//������
};
typedef struct SeqList SL;

//��������
void SLinit(SL* ps);

void SLPushBack(SL* ps, SLDataType x);