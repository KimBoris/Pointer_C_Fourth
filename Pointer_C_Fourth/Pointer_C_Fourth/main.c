#include <stdio.h>

int main(void)
{
	//char szSrcBuf[12] = { "Hello" }; //0x0115f92c
	////char szDstBuf[12] = { 0 };
	//
	//int* a = szSrcBuf;
	//
	//printf("a = %d", a);
	////int a = 10;
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



	/// //////////////////////////////////////////////////////���� ����////////////////////////////////////////
	char szSrcBuf[12] = { "Hello" };//0x0019FED0
	char szDstBuf[12] = { 0 };		//0x0019FEBC

	char* pszData = malloc(sizeof(char) * 12);
	//0x006B5218
	 
	//DeepCopy
	memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));

	//shallow Copy
	//&pszData = 0x0019FEB0  18 52 6b 00
	//pszData = 0x006B5218

	/*�ּ� ���� ������ �ִ� ����*/
	//pszData = szSrcBuf; // �ּ�
	//���⼭ szSrcBuf�� �ִ� Hello ������ pszData�� ������ ������ ���� ����. 
	//0x0019FEB0 = d0 fe 19 00 �̵ȴ�.
	//pszData ������ ������ �����Ѿ� �� ���� malloc���� �Ҵ� ���� ���� �����Ѿ� �ϴµ�
	//���� ���� ������ ���� szSrcBuf�� �ּҰ��� ����Ų��.  �̰��� ������ ������
	//�̷��� �Ǹ� '�޸� ��'�� �ȴ�.

	//why? �̰��� ����Ű�� ���� Stack �̴�.(�ڵ��޸�, ��, szSrcBuf�� �����̴�.)
	//���� - 1. ������ ������ , 2. �޸� ���� �ɸ���.

	//�̰��� �ٸ��� ��ġ��
	memcpy(pszData, szSrcBuf, sizeof(char) * 12); //�̷��� ���ָ� �ȿ� ������ ��ģ��.
	
	puts(pszData);
	free(pszData); //���⼭ ���α׷��� �״´�.

	
	/// //////////////////////////////////////////////////////���� ����////////////////////////////////////////


	//�׷��� C++������ �̰��� �����ϰ��� �������� �������
	// int &rData = nData;
	//Ư¡ 1. RData�� ���� ���� �Ұ�, nData�� �ʱⰪ�� ������ �����ؾ��Ѵ�.

	return 0;
}