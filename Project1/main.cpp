#include<iostream>

//判断40亿个数据中，是否有desNum
	//一个字节占八位
#define LEN 4000000/8

using namespace std;

//初始化数组
void initStr(char str[])
{
	//假设需求是数组中装的全是能整除3的数
	for (int i = 0; i < 4000000; i++)
	{
		if (i % 3 == 0)
		{
			//得到在第几个字节里哪一个位将他设置为1
			str[i / 8] = str[i / 8] | (1 << i % 8);
		}
	}

}
//算法实现   //算法之巅--位图算法     用空间换速度
bool PanDuan( char str[],int desNum)
{
	int desA = desNum / 8;//在那个字节
	int desB = desNum % 8;//在那个位
	//判断这个字节的这个位是不是为1
	if (str[desA] & (1 << desB))
	{
		cout << "数据" << desNum << "在数组中" << endl;
		return true;
	}
	else {
		cout << "数据" << desNum << "不在数组中" << endl;
		return false;
	}
}
int main(void)
{
	char str[LEN] = { '0' };
	memset(str, 0, LEN);//清0
	initStr(str);
	int desNum;
	cout << "请输入你要查询的数字" << endl;
	scanf_s("%d", &desNum);
	PanDuan(str, desNum);
	return 0;
}