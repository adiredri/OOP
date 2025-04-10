
#ifndef SRC_Q3_H_
#define SRC_Q3_H_

using namespace std;

class Date{
  int day,month,year; 
  
  void adjust(){
      if(day>30){
          month+=day/30;
          day%=30;
      }
      if(month>12){
          year+=month/12;
          month%=12;
      }
      if(day<1){
          month-=(-day)/30;
          month-=1;
          day= 30-(-day)%30;
      }
      if(month<1){
          year-=(-month) / 12;
          year-=1;
          month=12-(-month)%12;
      }
  }
  
  public:
  Date(int Day,int Month, int Year){
      set(Day,Month,Year);
  }

  void set(int Day,int Month, int Year){
      day=Day;
      month=Month;
      year=Year;
  }
  
  int getDay(){ return day;}
  int getMonth(){ return month;}
  int getYear(){ return year;}
  
  // implement operators

  void operator++(){
      day++;
      adjust();
  }
  void operator--(){
      day--;
      adjust();
  }
  void operator+=(int x){
      day+=x;
      adjust();
  }
  void operator-=(int x){
      day-=x;
      adjust();
  }
  
  void operator*=(int x){
      month+=x;
      adjust();
  }
  
  void operator/=(int x){
      month-=x;
      adjust();
  }
  

  bool operator==(Date other){
      return day==other.day && month==other.month && year==other.year;
  }
  
};



#endif /* SRC_Q3_H_ */
