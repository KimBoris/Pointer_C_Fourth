#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>	
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
	//memcpy(pszData, szSrcBuf, sizeof(char) * 12); //이렇게 해주면 안에 내용을 고친다.
	//
	//puts(pszData);
	//free(pszData); //여기서 프로그램이 죽는다.


	/// //////////////////////////////////////////////////////완전 삽질////////////////////////////////////////


	//그래서 C++에서는 이것을 보완하고자 참조형을 만들었다
	// int &rData = nData;
	//특징 1. RData의 값은 변경 불가, nData의 초기값을 무조건 설정해야한다.





	// 이 예제를 작성하여 실행하면 실행결과가잘 출력됨을 알 수 있습니다.
	// 즉, 외형적으로나 결과적으로는 아무런 결함이 없어 보입니다.
	// 그러나 다음 코드는 두 가지 심각한 결함이 있습니다.
	// 그 두가지 결함이 무엇인지 답하고 문제가 없는 코드가 될 수 있도록 수정합니다.

	//필수 실습 문제
	//11-01 중대한 두가지 오류
	//<예제>

	//char szBuffer[12] = { "HelloWorld" };

	//char* pszData = NULL;

	//pszData = (char*)malloc(sizeof(char) * 12);
	////pszData = szBuffer;//여기서 오류 Shallow Copy
	////pszData는 malloc동적할당된 메모리의 주소를 가지고 있지만
	////위 식에서 szBuffer의 주소를 오버라이트 한 값을 가지게 된다.
	////그러므로, pszData가 가지고 있는 값은 szBuffer의 메모리 주소가 되고
	////값은 HelloWorld가 되지만, 
	////1. 메모리 릭
	////2. Free함수 호출시 szBuffer의 주소를 가지고 있기에 스택이 깨지는 오류를 발생시킨다.
	//
	////아래와 같이 memcpy함수를 활용해서 바꿔주어야 한다.
	//memcpy(pszData, szBuffer, sizeof(szBuffer));
	//
	//puts(pszData);
	//free(pszData);




//memcmp(a, b, size) > 메모리에 들어있는 값을 비교
//같다면 0 을 반환

	/*char szSrcBuf[12] = { "HelloWorld" };
	char szDstBuf[12] = { 0 };

	memcpy(szDstBuf, szSrcBuf, sizeof(szDstBuf));

	if (memcmp(szSrcBuf, szDstBuf, sizeof(szDstBuf)) == 0)
		puts("Same");
	else
		puts("Diff");
*/


//strcmp(a, b, size) > 문자를 비교

	//char szSrcBuf[12] = { "Hello" };//0x000000359A6FF9F8
	//char* pszBuffer = "Hello";//0x00007FF71D3D9C10

	//if (pszBuffer == "Hello")
	//	puts("Same");
	//else
	//	puts("Diff");

	//char* pszNewBuf = "Hello";//0x000000359A6FFA48
	//문자열 상수
	//Hello라고 입력하면 이 Hello데이터는
	//어디에 있을까??

	// >> PE Image안에 Data영역에 들어있다.
	// 그런데 Hello가 여러개 있을때 번거롭게 세번을 데이터저장시킬 필요가 있을까?
	// 없다! 
	//그렇기 때문에 pszNewBuf와 pszBuffer의 메모리에 들어있는 값이 같다.
	//그래서 Same으로 나온다.

	//문자열이라는 것은 실행파일의 일부에 저장되어 있다.

	///<strcmp> strcmp(a, b) 
	//char szbuffer[12] = { "TestString" };
	//char* pszData = "TestString";

	////다음 코드들은 주소와 상관없이 대상 메모리에 저장된
	////문자열이 같은지 비교한다.
	////만일 길이가 다르면 무조건 같은 문자열이 아니다.

	//printf("%d\n", strcmp(szbuffer, pszData));
	//printf("%d\n", strcmp("TestString", pszData));
	//printf("%d\n", strcmp("Test", "TestString"));

	////strcmp(szBuffer, pszData);

	////반환값 - 두 문자열이 같다면 0
	////0보다 큰수 = a 가 b보다 알파벳 순서상 나중
	////0보다 작은 수 = b가 a 보다 알파벳 순서상 나중






//<strstr(const char *string, const char * strCharSet);
//string = 검색당하는 대상
//strCharSet = 검색할 문자열이 저장된 메모리 주소
//반환값 = 문자열을 찾으면 문자열이 저장된 메모리 주소를 반환
//없으면? = NULL을 반환
//이런 함수를 활용할때 제발 좀 메모리를 쫓아다녀라.

	//char szBuffer[32] = { "Iamaboy." };

	////배열의 주소를 출력
	//printf("%p\n", szBuffer);

	////대상 문자열에서 문자열을 검색하고 찾은 위치(주소)를 출력한다
	//printf("%p\n", strstr(szBuffer, "am"));
	//printf("%p\n", strstr(szBuffer, "boy"));

	////문자열이 검색된 위치에서 기준이 되는 주소를 빼면
	////인덱스를 계산할 수 있다.


	////주소에서 주소를 빼면 인덱스가 나온다.
	//printf("Index : %d\n", strstr(szBuffer, "am") - szBuffer);
	//printf("Index : %d\n", strstr(szBuffer, "boy") - szBuffer);
	////string.h 필수



 //	char szBuffer[12] = { "I am a boy." }; //0x010FFD60
	//char* pszFound = strstr(szBuffer, "am");//0x010FFD62
	//int nIndex = pszFound - szBuffer;//주소를 뺀다 60-62 = 2
	////즉 2가 인덱스
	////*상대 주소 = 기준주소 +-정수이기때문에
	//// 상대주소 - 기준주소 = 정수 (인덱스) 가 나온다.
	////이렇게 하면 인덱스가 나온다


	//char szBuffer[32] = { "You are a girl." };

	////배열의 첫번째 요소의 값을 %c형식으로 출력
	//printf("%c\n", szBuffer[0]);
	////0번 요소에 대한 주소인 배열의 이름(주소)에 대해 간접지정 연산을
	////수행하고 그 안에 담긴 정보를 출력한다.
	//printf("%c\n", *szBuffer);
	////0을 더해도 주소는 달라지지않는다.
	//printf("%c\n", *(szBuffer + 0));

	////배열 연산자는 '기준주소 + 인덱스' 연산결과로 얻은 주소를
	////간접 지정한것과 같다.
	//printf("%c\n", szBuffer[5]);
	//printf("%c\n", *(szBuffer + 5));

	////주소 연산(&)은 간접지정 연산과 상반된다.
	////그러므로 아래 세 줄의 코드는 모두 같다.
	//printf("%s\n", &szBuffer[4]);
	//printf("%s\n", &*(szBuffer + 4));
	//printf("%s\n", szBuffer + 4);

	/*char* pszData = szBuffer + 4;

	printf("%c\n", szBuffer[0]);
	printf("%c\n", pszData[0]);
	printf("%c\n", pszData[6]);
	printf("%s\n", szBuffer+4);
	printf("%s\n", pszData);
	printf("%s\n", pszData+4);*/


	//<<void *realloc(void * memblock, size_t size);
	//이미 할당된 메모리를 재할당.



//<<Sprint()함수>>

	//char *pszBuffer = NULL, *pszNewBuffer = NULL;

	////12바이트 동적할당 후
	//pszBuffer = (char*)malloc(13);
	////NULL문자를 포함해 영문 11자를 저장
	//sprintf_s(pszBuffer, "%s", "TestString");             >>>>>>>>>>>>>>>>>>>>>//왜 오류가 뜰까?
	////동적할 메모리주소, 크기, 저장된 문자열등을 출력
	//printf("[%p] %d %s\n", pszBuffer, _msize(pszBuffer), pszBuffer);>>>>>>>>>>>>>>>>//왜 오류가 뜰까?

	////12바이트의 메모리를 32바이트로 '확장'을 시도한다.
	//pszNewBuffer = (char*)realloc(pszBuffer, 32);
	//if (pszNewBuffer == NULL)
	//{
	//	free(pszBuffer);
	//}

	char szBuffer[12] = { "I am a boy" };
	/*0x001FF734  49 20 61 6d  I am
	  0x001FF738  20 61 20 62   a b
	  0x001FF73C  6f 79 cc cc  oy??*/
	//메모리에 이런식으로 들어가있는데 

	//1번째 줄
	//2번째 줄
	//3번째 줄 따로따로 들어간다 순차적으로


	//예를 들어서
	//I am a boy
	//00 01 02 03 04 05 06 07 ...
	//49 20 61 6D (I am)
	//이 값을 계산기의 16진수에 넣어보면 6D612049 - 리틀 인디안방식
	//Dec 헥사로 보면 이값은 1,835,081,801이 나온다
	////이 값을 int자료형으로 나타내면
	//int a = 1835081801;
	////이것을 포인터로 찍으면 메모리 주소가 나온다.


	//puts(&a);
	////a메모리에는 I am이 들어간다
	////참으로 신기하구만

	//
	////&a 부터 찍어서 
	////儆儆이 한자는 cc부분을 찍으면 출력된다.
	////한글이나 한자는 개당 2바이트 이기때문에 cc = 8개 = 4개의 儆
	////따라서 값은 I am儆儆儆儆I am a boy 이 나온다.

	//char* pszData = "I am a boy.";

	int nData = *((int*)szBuffer);
	printf("%d\n", nData);
	return 0;
}