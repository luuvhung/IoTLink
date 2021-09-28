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
ClassA *C = &B;

printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo1(A, &B);//todo1 là hàm swap giá trị của 2 con trỏ=> không ảnh hưởng đến giá trị tại địa chỉ A trỏ đến và B, *C = B nên *C cũng không thay đổi
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo2(*A, B);//tham chiếu *A và B vào hàm todo2 =>swap giá trị *A và B, *C = B
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo3(*A, B);//truyền *A và B vào hàm todo3 và sao chép vào 2 biến A và B của hàm=> sẽ không ảnh hưởng đến *A và B, *C
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
Todo4(A, C);//truyền tham chiếu A và C vào hàm todo4, swap 2 giá trị con trỏ này.
printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
system("pause");
}