#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	//char szSrcBuf[12] = { "Hello" };//0x0019FED0
	//char szDstBuf[12] = { 0 };		//0x0019FEBC

	//char* pszData = malloc(sizeof(char) * 12);
	////0x006B5218
	// 
	////DeepCopy
	//memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));

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
	//memcpy(pszData, szSrcBuf, sizeof(char) * 12); //�̷��� ���ָ� �ȿ� ������ ��ģ��.
	//
	//puts(pszData);
	//free(pszData); //���⼭ ���α׷��� �״´�.


	/// //////////////////////////////////////////////////////���� ����////////////////////////////////////////


	//�׷��� C++������ �̰��� �����ϰ��� �������� �������
	// int &rData = nData;
	//Ư¡ 1. RData�� ���� ���� �Ұ�, nData�� �ʱⰪ�� ������ �����ؾ��Ѵ�.





	// �� ������ �ۼ��Ͽ� �����ϸ� ���������� ��µ��� �� �� �ֽ��ϴ�.
	// ��, ���������γ� ��������δ� �ƹ��� ������ ���� ���Դϴ�.
	// �׷��� ���� �ڵ�� �� ���� �ɰ��� ������ �ֽ��ϴ�.
	// �� �ΰ��� ������ �������� ���ϰ� ������ ���� �ڵ尡 �� �� �ֵ��� �����մϴ�.

	//�ʼ� �ǽ� ����
	//11-01 �ߴ��� �ΰ��� ����
	//<����>

	//char szBuffer[12] = { "HelloWorld" };

	//char* pszData = NULL;

	//pszData = (char*)malloc(sizeof(char) * 12);
	////pszData = szBuffer;//���⼭ ���� Shallow Copy
	////pszData�� malloc�����Ҵ�� �޸��� �ּҸ� ������ ������
	////�� �Ŀ��� szBuffer�� �ּҸ� ��������Ʈ �� ���� ������ �ȴ�.
	////�׷��Ƿ�, pszData�� ������ �ִ� ���� szBuffer�� �޸� �ּҰ� �ǰ�
	////���� HelloWorld�� ������, 
	////1. �޸� ��
	////2. Free�Լ� ȣ��� szBuffer�� �ּҸ� ������ �ֱ⿡ ������ ������ ������ �߻���Ų��.
	//
	////�Ʒ��� ���� memcpy�Լ��� Ȱ���ؼ� �ٲ��־�� �Ѵ�.
	//memcpy(pszData, szBuffer, sizeof(szBuffer));
	//
	//puts(pszData);
	//free(pszData);




//memcmp(a, b, size) > �޸𸮿� ����ִ� ���� ��
//���ٸ� 0 �� ��ȯ

	/*char szSrcBuf[12] = { "HelloWorld" };
	char szDstBuf[12] = { 0 };

	memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));

	if (memcmp(szSrcBuf, szDstBuf, sizeof(szDstBuf)) == 0)
		puts("Same");
	else
		puts("Diff");
*/


//strcmp(a, b, size) > ���ڸ� ��

	//char szSrcBuf[12] = { "Hello" };//0x000000359A6FF9F8
	//char* pszBuffer = "Hello";//0x00007FF71D3D9C10

	//if (pszBuffer == "Hello")
	//	puts("Same");
	//else
	//	puts("Diff");

	//char* pszNewBuf = "Hello";//0x000000359A6FFA48
	//���ڿ� ���
	//Hello��� �Է��ϸ� �� Hello�����ʹ�
	//��� ������??

	// >> PE Image�ȿ� Data������ ����ִ�.
	// �׷��� Hello�� ������ ������ ���ŷӰ� ������ �����������ų �ʿ䰡 ������?
	// ����! 
	//�׷��� ������ pszNewBuf�� pszBuffer�� �޸𸮿� ����ִ� ���� ����.
	//�׷��� Same���� ���´�.

	//���ڿ��̶�� ���� ���������� �Ϻο� ����Ǿ� �ִ�.

	///<strcmp> strcmp(a, b) 
	//char szbuffer[12] = { "TestString" };
	//char* pszData = "TestString";

	////���� �ڵ���� �ּҿ� ������� ��� �޸𸮿� �����
	////���ڿ��� ������ ���Ѵ�.
	////���� ���̰� �ٸ��� ������ ���� ���ڿ��� �ƴϴ�.

	//printf("%d\n", strcmp(szbuffer, pszData));
	//printf("%d\n", strcmp("TestString", pszData));
	//printf("%d\n", strcmp("Test", "TestString"));

	////strcmp(szBuffer, pszData);

	////��ȯ�� - �� ���ڿ��� ���ٸ� 0
	////0���� ū�� = a �� b���� ���ĺ� ������ ����
	////0���� ���� �� = b�� a ���� ���ĺ� ������ ����






//<strstr(const char *string, const char * strCharSet);
//string = �˻����ϴ� ���
//strCharSet = �˻��� ���ڿ��� ����� �޸� �ּ�
//��ȯ�� = ���ڿ��� ã���� ���ڿ��� ����� �޸� �ּҸ� ��ȯ
//������? = NULL�� ��ȯ
//�̷� �Լ��� Ȱ���Ҷ� ���� �� �޸𸮸� �Ѿƴٳ��.

	char szBuffer[32] = { "Iamaboy." };

	//�迭�� �ּҸ� ���
	printf("%p\n", szBuffer);

	//��� ���ڿ����� ���ڿ��� �˻��ϰ� ã�� ��ġ(�ּ�)�� ����Ѵ�
	printf("%p\n", strstr(szBuffer, "am"));
	printf("%p\n", strstr(szBuffer, "boy"));

	//���ڿ��� �˻��� ��ġ���� ������ �Ǵ� �ּҸ� ����
	//�ε����� ����� �� �ִ�.

	printf("Index : %d\n", strstr(szBuffer, "am") - szBuffer);
	printf("Index : %d\n", strstr(szBuffer, "boy") - szBuffer);
	//string.h �ʼ�



	return 0;
}