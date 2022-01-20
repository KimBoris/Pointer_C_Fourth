#include <stdio.h>

int main(void)
{
	char szSrcBuf[12] = { "Hello" }; //0x0115f92c
	//char szDstBuf[12] = { 0 };
	
	int* a = szSrcBuf;
	
	printf("a = %d", a);
	//int a = 10;
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

	return 0; 
}