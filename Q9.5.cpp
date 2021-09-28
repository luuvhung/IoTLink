#include<iostream>
class ClassA
{
public:
	ClassA(int val = 0) {m_pVal = val;}
	int m_pVal;
};
void Todo1(ClassA *A, ClassA *B)
{	
	ClassA *tmp = A;
	A = B;
	B = tmp;
}

void Todo2(ClassA &A, ClassA &B)
{	
	ClassA tmp = A;
	A = B;
	B = tmp;
}

void Todo3(ClassA A, ClassA B)
{	
	ClassA tmp = A;
	A = B;
	B = tmp;
}

void Todo4(ClassA *&A, ClassA *&B)
{	
	ClassA *tmp = A;
	A = B;
	B = tmp;
}

int main()
{
ClassA *A = new ClassA(10);//m_pVal = 10
ClassA B(0);//m_pVal = 0
ClassA *C = &B;//C tro den B

printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo1(A, &B);
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo2(*A, B);
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo3(*A, B);
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo4(A, C);
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
system("pause");
}