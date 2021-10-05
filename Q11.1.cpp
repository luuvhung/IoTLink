#include<iostream>
template<class R,class T> R Average(int count, T* list)
{
    R avg;
    for (int i=0;i<count;i++)
    {
        avg = avg + list[i];
    }
    return avg/count;
}
int main()
{
    int a[5] = {2,1,1,1,1};
    float b[5] = {2.1,1.2,1.5,1.6,1};
    std::cout<< Average<float,int>(5,a);
    std::cout<< Average<float,float>(5,b);
    system("pause");
}