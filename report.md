### rvalue vs lvalue
+ rvalue: không có địa chỉ bộ nhớ cụ thể, không cho phép truy cập địa chỉ. rvalue được xem như là một đối tượng tạm. Vùng nhớ chứa rvalue sẽ bị hủy ngay khi kết thúc biểu thức.
+ lvalue: có địa chỉ bộ nhớ cụ thể có thể truy cập được. Vùng nhớ chứa lvalue chỉ bị hủy khi ra khỏi phạm vi của nó.
```C++
int a = 5
//a:lvalue
//5:rvalue
int func();
int *p = &func()//error
int *q = &a//ok
```
## rvalue reference vs lvalue reference
+ lvalue reference dùng để tham chiếu đến một lvalue, không thể tham chiếu đến một rvalue. Tuy nhiên const lvalue reference có thể tham chiếu đến cả rvalue và lvalue
```C++
int a = 1;
int& b = a;//oke
int& c = 1;//error
const int &d = 1;//oke 
```
+ rvalue reference: dùng để tham chiếu đến một rvalue. Kéo dài thời gian tồn tại của một rvalue, chỉ bị hủy khi ra khỏi phạm vi.
```C++
int&& a = 1;
std::cout << a;//1
```
## std::move vs std::forward
+ std::move: cast đối số truyền vào thành một rvalue reference.
+ Mục đích: 
  - "chuyển" quyền sử dụng tài nguyên từ đối tượng này sang cho đối tượng khác. ví dụ: đối với unique_ptr không thể gán một con trỏ cho một con trỏ khác, bắt buộc phải sử dụng std::move để đảm bảo 2 con trỏ không cùng trỏ tới cùng một tài nguyên.
  - để tránh các sao chép không cần thiết và loại bỏ thao tác tạo nhiều lần các đối tượng tạm thời => giảm chi phí, tiết kiệm được thời gian.
+ std::forward: Nếu nhận đối số là một rvalue reference thì nó thực hiện như std::move, còn nếu đối số truyền vào là một lvalue thì sẽ không làm gì với đối số.
## universal reference
+ Có thể liên kết đến một rvalue hoặc lvalue
```C++
template <typename T> void f(T&& arg);
f(5);//5: rvalue
int x = 5;
f(x);//x: lvalue
f(std::move(x));
```