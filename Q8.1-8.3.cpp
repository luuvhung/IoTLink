#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
struct Date
{
    unsigned char dow;
    unsigned char day;
    unsigned char month;
    unsigned int year;
    Date(unsigned char,unsigned char,unsigned char,int);
    void printdate();
    bool checkdate();
};
Date::Date(unsigned char dow,unsigned char day,unsigned char month,int year)
{
    this->dow = dow;
    this->day = day;
    this->month = month;
    this->year = year;
}
void Date::printdate()
{
    string dowc;
    switch (dow)
    {
    case 0:
        dowc = "Sun";
        break;
    case 1:
        dowc = "Mon";
        break;
    case 2:
        dowc = "Tue";
        break;
    case 3:
        dowc = "Wed";
        break;
    case 4:
        dowc = "Thus";
        break;
    case 5:
        dowc = "Fri";
        break;
    case 6:
        dowc = "Sat";
        break;
    default:
        dowc = "unknow";
        break;
    }
    cout<<dowc<<", "<<setw(2)<<setfill('0')<<(int)day<<"-"<<setw(2)<<setfill('0')<<(int)month<<"-"<<setw(4)<<setfill('0')<<year<<endl;
    cout<<setw(2)<<setfill('0')<<(int)day<<"/"<<setw(2)<<setfill('0')<<(int)month<<"/"<<setw(4)<<setfill('0')<<year<<endl;
    cout<<setw(2)<<setfill('0')<<(int)month<<"-"<<setw(2)<<setfill('0')<<(int)day<<"-"<<setw(4)<<setfill('0')<<year<<endl;
    cout<<dowc<<" "<<setw(2)<<setfill('0')<<(int)day<<"."<<setw(2)<<setfill('0')<<(int)month<<"."<<setw(4)<<setfill('0')<<year<<endl;
}
bool Date::checkdate()
{
    if (dow<0||dow>6||day<0||day>31||month<0||month>12) return false;
    return true;
}
int main()
{
    int dow, day, month, year;
    time_t t = time(0);
    tm *now = localtime(&t);
    dow = now->tm_wday;
    day = now->tm_mday;
    month = now->tm_mon + 1;
    year = now ->tm_year + 1900;
    Date date(dow,day,month,year);
    date.printdate();
    cout<<date.checkdate();
    system("pause");
}

