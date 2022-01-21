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
	////b에다가 a를 넣으세요
	//b = a;
	//

	////그런데 배열은 대입이 안된다.
	//szSrcBuf = szDstBuf;
	//에러가 나는 이유 = L-value가 상수 이기 때문에.
	//상수이기 때문에 szSrcBuf=R-Value이다.
	//ex) 13 = 11 대입하여라  와 똑같은 말이다.
	//0x0018ff20 = 0x0018ff30 과 똑같은말. 

	//차라리 이렇게 되면 오류가 뜨기때문에 알 수 있다.

	//Deep Copy!!! - 내용을 복사!!
	//memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));


	//이것은 무엇을 의미하냐 
	//전형적인 Shallow Copy - 주소만 복사!!
	//pszData = szSrcBuf;



	/// //////////////////////////////////////////////////////완전 삽질////////////////////////////////////////
	char szSrcBuf[12] = { "Hello" };//0x0019FED0
	char szDstBuf[12] = { 0 };		//0x0019FEBC

	char* pszData = malloc(sizeof(char) * 12);
	//0x006B5218
	 
	//DeepCopy
	memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));

	//shallow Copy
	//&pszData = 0x0019FEB0  18 52 6b 00
	//pszData = 0x006B5218

	/*주소 값을 가지고 있는 변수*/
	//pszData = szSrcBuf; // 주소
	//여기서 szSrcBuf에 있던 Hello 내용이 pszData의 내용을 날리고 덮어 쓴다. 
	//0x0019FEB0 = d0 fe 19 00 이된다.
	//pszData 포인터 변수가 가르켜야 할 곳은 malloc으로 할당 받은 곳을 가리켜야 하는데
	//위와 같은 식으로 인해 szSrcBuf의 주소값을 가르킨다.  이것이 굉장한 개삽질
	//이렇게 되면 '메모리 릭'이 된다.

	//why? 이것이 가르키는 곳이 Stack 이다.(자동메모리, 즉, szSrcBuf의 구역이다.)
	//이유 - 1. 스택이 깨지고 , 2. 메모리 릭이 걸린다.

	//이것을 바르게 고치면
	memcpy(pszData, szSrcBuf, sizeof(char) * 12); //이렇게 해주면 안에 내용을 고친다.
	
	puts(pszData);
	free(pszData); //여기서 프로그램이 죽는다.

	
	/// //////////////////////////////////////////////////////완전 삽질////////////////////////////////////////


	//그래서 C++에서는 이것을 보완하고자 참조형을 만들었다
	// int &rData = nData;
	//특징 1. RData의 값은 변경 불가, nData의 초기값을 무조건 설정해야한다.

	return 0;
}