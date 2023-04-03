#include <stdio.h>
#include <stdlib.h>
int countDay(int year, int month);
int leapYear(int year);
int main(void) {
  int year;   // 1~9999
  int month;  // 1~12
  int day;    // 1~13
  int Dyear;  // 1~9999
  int Dmonth; // 1~12
  int Dday;   // 1~13
  int remainDay = 0;
  scanf("%d %d %d", &year, &month, &day);
  scanf("%d %d %d", &Dyear, &Dmonth, &Dday);

  if (Dyear - year >= 1000) {
    if (Dyear - year == 1000 && Dmonth <= month) {
      if (Dmonth == month && Dday >= day) {
        printf("gg");
        return 0;
      }
    } else {
      printf("gg");
      return 0;
    }
  }
  //윤년 적용
  int yyyy = year + 1;
  while (yyyy < Dyear) {
	  remainDay += 365;
    if (yyyy % 4 == 0) {
      remainDay+=leapYear(yyyy);
    }
    yyyy++;
  }

  int today = 0;
  int goalday = 0;

  
  today += countDay(year, month);
  today += day;  
  goalday += countDay(Dyear, Dmonth);
  goalday += Dday;
  remainDay += (goalday - today);
  if (year != Dyear) {
	  if(leapYear(year)==1){
		  remainDay+= 366;
	  }else{
		  remainDay += 365;
	  }
    
  }

  printf("D-%d", remainDay);
  return 0;
}
int countDay(int year, int month) {
  int day = 0;
  switch (month) {
    case 12:
      day += 30;
    case 11:
      day += 31;
    case 10:
      day += 30;
    case 9:
      day += 31;
    case 8:
      day += 31;
    case 7:
      day += 30;
    case 6:
      day += 31;
    case 5:
      day += 30;
    case 4:
      day += 31;
    case 3:
      day += 28;
      if(leapYear(year)==1){
        day++;
      }
    case 2:
      day += 31;
    case 1:
      break;
  }

  return day;
}
int leapYear(int year){
  int check = 0;
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        check=1;
      }
    } else {
      check=1;
    }
  }
  return check;
}