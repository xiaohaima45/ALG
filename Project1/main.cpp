#include<iostream>

//�ж�40�ڸ������У��Ƿ���desNum
	//һ���ֽ�ռ��λ
#define LEN 4000000/8

using namespace std;

//��ʼ������
void initStr(char str[])
{
	//����������������װ��ȫ��������3����
	for (int i = 0; i < 4000000; i++)
	{
		if (i % 3 == 0)
		{
			//�õ��ڵڼ����ֽ�����һ��λ��������Ϊ1
			str[i / 8] = str[i / 8] | (1 << i % 8);
		}
	}

}
//�㷨ʵ��   //�㷨֮��--λͼ�㷨     �ÿռ任�ٶ�
bool PanDuan( char str[],int desNum)
{
	int desA = desNum / 8;//���Ǹ��ֽ�
	int desB = desNum % 8;//���Ǹ�λ
	//�ж�����ֽڵ����λ�ǲ���Ϊ1
	if (str[desA] & (1 << desB))
	{
		cout << "����" << desNum << "��������" << endl;
		return true;
	}
	else {
		cout << "����" << desNum << "����������" << endl;
		return false;
	}
}
int main(void)
{
	char str[LEN] = { '0' };
	memset(str, 0, LEN);//��0
	initStr(str);
	int desNum;
	cout << "��������Ҫ��ѯ������" << endl;
	scanf_s("%d", &desNum);
	PanDuan(str, desNum);
	return 0;
}