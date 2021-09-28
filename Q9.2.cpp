#include<iostream>
#include<string.h>
using namespace std;
void SayHello()
{
    cout<<"hello world"<<endl;
}
void SayHello(char s[])
{
    cout<<"hello world"<<endl<<s<<endl;
}
void SayHello1(char s[],bool capital = false)
{
    char *s1 = new char[sizeof(s)];
    strcpy(s1,s);
    if (capital == true)
    {
        for (int i=0;i<strlen(s1);i++)
        {
            if (s1[i]>=97&&s1[i]<=122) s1[i]=s1[i]-32;
        }
    }
    cout<<"hello world"<<endl;
    cout<<s1<<endl;
    delete s1;
}
int main()
{
    SayHello();
    SayHello("hung123");
    SayHello1("hung123",true);
    system("pause");
}