#include<iostream>
float Divide(float a, float b)
{
    if (b==0) throw "Division by zero";
    return a/b;
}
float Average(int count, int offset, float *arr)
{
    if (count==0) throw "division by zero";
    float avg = 0;
    for (int i=0;i!=count;i++)
    {
        avg = avg + arr[offset+i];
    }
    return avg/count;
} 
int main()
{
    int a=5;
    int b=0;
    float c;
    try
    {
        c = Divide(a,b);
        std::cout<<c;
    }
    catch (const char* msg)
    {
        std::cout<<msg;
    }
    ////
    float avg;
    float arr[5]={1.2,2.2,4.5,5.3,7.6};
    try
    {
        avg = Average(0,0,arr);
        std::cout<<avg;
    }
    catch (const char* msg)
    {
        std::cout<<msg;
    }
    system("pause");
}