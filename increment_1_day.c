#include<stdio.h>
#include<stdlib.h>

#define isMeuberet(year) ((!((year) % 400)) || (!((year) % 4) && ((year) % 100)))

void main()
{
	int day = 0, month = 0, year = 0;
	printf("");
	//scanf_s("%d%d%d", &day, &month, &year);
	day = 29; month = 2; year = 1976;

	if (month < 0 && month >12 && day > 31)
		printf("error in the input date!");

	int maxDay = 31;
	if (month == (4 || 6 || 9 || 11)) {
		maxDay = 30;
		if (day > maxDay)
			printf("you have printed a day that is not in the month %d", month);
	}
	else if (month == 2) {
		maxDay = 28;
		if (isMeuberet(year))
			maxDay = 29;
		if (day > maxDay)
			printf("you have printed a day that is not in the month %d", month);
	}



	if (day < maxDay) {
		day++;
	}
	else if (month < 12) {

		month++;
		day = 1;
	}
	else {

		year++;
		month = 1;
		day = 1;
	}


	printf("%d\t%d\t%d\t", day, month, year);
}
