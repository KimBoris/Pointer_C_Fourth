#include <stdio.h>

int main(void)
{
	char szSrcBuf[12] = { "Hello" }; //0x0115f92c
	//char szDstBuf[12] = { 0 };
	
	int* a = szSrcBuf;
	
	printf("a = %d", a);
	//int a = 10;
	//int b = 0;
	////b���ٰ� a�� ��������
	//b = a;
	//

	////�׷��� �迭�� ������ �ȵȴ�.
	//szSrcBuf = szDstBuf;
	//������ ���� ���� = L-value�� ��� �̱� ������.
	//����̱� ������ szSrcBuf=R-Value�̴�.
	//ex) 13 = 11 �����Ͽ���  �� �Ȱ��� ���̴�.
	//0x0018ff20 = 0x0018ff30 �� �Ȱ�����. 

	//���� �̷��� �Ǹ� ������ �߱⶧���� �� �� �ִ�.

	//Deep Copy!!! - ������ ����!!
	//memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));


	//�̰��� ������ �ǹ��ϳ� 
	//�������� Shallow Copy - �ּҸ� ����!!
	//pszData = szSrcBuf;

	return 0; 
}