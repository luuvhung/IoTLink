### rvalue vs lvalue
+ **rvalue:** 
  - Các rvalue thường là những biến không có tên, không có địa chỉ bộ nhớ cụ thể, không cho phép truy cập địa chỉ.
  - Hầu hết các rvalue là các đối tượng tạm. Vùng nhớ chứa rvalue sẽ bị hủy ngay khi kết thúc biểu thức
+ **lvalue:** 
  - Các lvalue thường là những biến có tên, có địa chỉ bộ nhớ cụ thể có thể truy cập được. 
  - Vùng nhớ chứa lvalue chỉ bị hủy khi ra khỏi phạm vi của nó.
```C++
int a = 5
//a:lvalue
//5:rvalue
int func();
int *p = &func()//error
int *q = &a//ok
```
## rvalue reference vs lvalue reference
+ **lvalue reference** dùng để tham chiếu đến một lvalue, không thể tham chiếu đến một rvalue. Tuy nhiên const lvalue reference có thể tham chiếu đến cả rvalue. Khi đó rvalue đó chỉ bị hủy khi const lvalue reference đó bị hủy, chứ không bị hủy ngay sau khi biểu thức kết thúc. 
```C++
int a = 1;
int& b = a;//oke
int& c = 1;//error
const int &d = 1;//oke 
```
+ **rvalue reference:** dùng để tham chiếu đến một rvalue. Kéo dài thời gian tồn tại của một rvalue, chỉ bị hủy khi ra khỏi phạm vi.
```C++
int&& a = 1;
std::cout << a;//1
```
## std::move vs std::forward
+ **copy semantics:** thực hiện sao chép tài nguyên của đối tượng này sang đối tượng khác. Dữ liệu của đối tượng nguồn vẫn y nguyên như cũ.
+ **move semantics:** thực hiện chuyển quyền sử dụng của đối tường nguồn sang cho đối tượng đích, đối tượng nguồn sẽ không còn sở hữu tài nguyên này nữa. Điều này giúp tránh các sao chép không cần thiết và loại bỏ thao tác tạo nhiều lần các đối tượng tạm thời => giảm chi phí, tiết kiệm được nhiều thời gian. 
+ **std::move:** cast đối số truyền vào thành một rvalue reference. Do đó sẽ thực hiện việc move semantics thay vì copy semantics để giảm chi phí. Ví dụ đối với unique_ptr không thế gán một con trỏ cho một con trỏ bắt buộc phải sử dụng std::move để đảm bảo 2 con trỏ không cùng trỏ đến một tài nguyên.
```C++
#include<iostream>
#include<vector>
int main() {
  std::vector<int> v1 = { 1,2,3 };
  std::vector<int> v2;
  v2 = v1;
  std::cout << v1.size();//3
  std::cout << v2.size();//3
  v2 = std::move(v1);
  std::cout << v1.size();//0
  std::cout << v2.size();//3
}
```
+ **std::forward:** tương tự như std::move nhưng ```std::forward<T>()``` sẽ cast thành loại T&&. Như vậy cả std::move và std::forward đều có thể cast thành rvalue reference, tuy nhiên khác std::move luôn cast thành công ```std::forward<T>()``` có thể thất bại phụ thuộc vào T.
```C++
#include<iostream>
#include<vector>
void f(int&& arg) {
  std::cout << "int&&" << std::endl;
}
void f(int& arg) {
  std::cout << "int&" << std::endl;
}
int main() {
  int a = 1;
  f(a);//kq: int&
  f(std::forward<int>(a));//cast to int&& => kq: int&&
  int& b = a;
  f(b);//kq: int&
  f(std::forward<int&>(b));//cast to int& && = int& => kq: int&
  int&& c = 2;
  f(c);//kq: int&
  f(std::forward<int&&>(c));//cast to int&& && = int&& => kq: int&&
}
```
*Mục đích của std::forward là tránh sự biến dạng loại của tham số khi truyền từ một hàm sang một hàm khác. std::forward thường được sử dụng cùng với universal reference.*
## universal reference
universal reference có thể trở thành một rvalue reference hoặc lvalue reference
```C++
#include<iostream>
#include<vector>
void f(int&& arg) {
  std::cout << "int&&" << std::endl;
}
void f(int& arg) {
  std::cout << "int&" << std::endl;
}
template <typename T>
void forward(T&& a) {
  //T:int& -> a: int&
  //T:int -> a: int&&
  f(std::forward<T>(a));
}
int main() {
  int b = 1;
  forward(b);//int&
  forward(5);//int&&
}
```