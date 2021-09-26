#include <iostream>
using namespace std;

enum SEASON {SPRING = 0x1, SUMMER = 0x10, FALL = 0x100, WINTER};

void CheckSeason(int season)
{
	switch (season)
	{
	case SPRING:
		printf("SPRING is %d\n", SPRING);
		break;
	case SUMMER:
		printf("SUMMER is %d\n", SUMMER);
		break;
	case FALL:
		printf("FALL is %d\n", FALL);
		break;
	case WINTER:
		printf("WINTER is %d\n", WINTER);
		break;
	default:
		printf("UNKNOWN: %d", season);
		break;
	}
}

int main()
{
	SEASON season = WINTER;//FALL = 0x100 = (dec)256=> season = WINTER = 257
	CheckSeason(season);
	CheckSeason(1);
	CheckSeason(5);
}
