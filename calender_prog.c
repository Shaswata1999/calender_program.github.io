#include<stdio.h>

int get1stWeekday(int month, int year){
  int n;
  if(month == 1 || month == 2) {
      year--;
      if(month == 1)month=13;
      if(month == 2)month=14;
  }
  n = (2*month + (3*(month+1)/5) + year + (year/4) - (year/100) + (year/400) + 3)%7;
  return n;
}

void main() {
    int year, month,weekDay=0,init,monthDay,i;
    printf("Enter the day Month and Year (e.g: 2 2020): ");
    scanf("%d %d",&month,&year);
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||year%400==0)
        daysInMonth[1] = 29;
    init = get1stWeekday(month,year);
    monthDay = daysInMonth[month];
    printf("\n\n---------------%s-------------------\n",months[month-1]);
    printf("\n  Sat Sun  Mon  Tue  Wed  Thurs  Fri\n");
    for(weekDay=0;weekDay<init;weekDay++)
        printf("     ");

      for(i=1;i<=monthDay;i++){
        printf("%5d",i);

        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        init=weekDay;
      }

   }
