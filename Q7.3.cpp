#include<iostream>
union MyUnion
{
	int iVal;
	float fVal;
	char cVal[5];
};

int main()
{
	union MyUnion u;
	u.fVal = 100;
	printf("%d\n%f\n%d\n%d\n", u.iVal, u.fVal, u.cVal[0], sizeof(u));
    system("pause");
}
/* các biến trong union sử dụng chung một vùng bộ nhớ, kích thước của union = kích thước
của kiểu dữ liệu lớn nhất trong union. Thay đổi giá trị của 1 biến sẽ dẫn đến thay đổi giá trị
của các biến còn lại */