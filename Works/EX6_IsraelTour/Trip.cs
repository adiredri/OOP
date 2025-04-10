using System;
using System.Collections.Generic;
using System.Text;

namespace Work4
{
    class Trip
    {
        private string guideName; 
        private int noOfCountries;    
        private Date departureDate;  
        private Date returningDate;  
        private int noOfTravellers;   
        private int PRICE_PER_DAY = 250; 
        private int PRICE_PER_COUNTRY = 100;  
        public Trip(string guideName, int d1, int d2, int d3, int r1, int r2, int r3, int noOfCountries, int noOfTravellers)     //   Opening a parameters builder that will receive a guide's name, day, month and year of departure and return, and the number of countries and travelers on the trip
        {
            this.guideName = guideName;        
            Date D1 = new Date(d1, d2, d3);    
            Date D2 = new Date(r1, r2, r3);    
            Date D0 = new Date(1, 1, 2000);    
            if (noOfCountries < 1 || noOfCountries > 10)   
                this.noOfCountries = 1;       
            else
                this.noOfCountries = noOfCountries;  
            if (noOfTravellers < 1 || noOfTravellers > 50)     
                this.noOfTravellers = 10;     
            else
                this.noOfTravellers = noOfTravellers; 
            if (D1.Before(D2))   
            {
                this.departureDate = D1;   
                this.returningDate = D2;
            }
            else if (D1.Equals(D2))                          
            {
                this.departureDate = D1;  
                this.returningDate = D1;
            }
            else                         
            {
                this.departureDate = D0;      
                this.returningDate = D0;
            }
        }
        public Trip(Trip t)    //   Defining a copy constructor that will accept another trip
        {
            this.guideName = t.guideName;               
            this.noOfCountries = t.noOfCountries;
            this.departureDate = t.departureDate;
            this.returningDate = t.returningDate;
            this.noOfTravellers = t.noOfTravellers;
        }
        public Trip(string guideName, Date D1, Date D2, int noOfCountries, int noOfTravellers)     //   Setting up a parameter builder that will receive a guide's name, departure and return dates, and number of countries and travelers
        {
            this.guideName = guideName;  
            Date D0 = new Date(1, 1, 2000);  
            if (noOfCountries < 1 || noOfCountries > 10)   
                this.noOfCountries = 1;      
            else
                this.noOfCountries = noOfCountries;   
            if (noOfTravellers < 1 || noOfTravellers > 50)    
                this.noOfTravellers = 10;    
            else
                this.noOfTravellers = noOfTravellers;  
            if (D1.Before(D2))    
            {
                this.departureDate = D1;    
                this.returningDate = D2;
            }
            else if (D1.Equals(D2))                           
            {
                this.departureDate = D1;   
                this.returningDate = D1;
            }
            else                            
            {
                this.departureDate = D0;   
                this.returningDate = D0;
            }
        }
        public string GetGuideName()    //   Returning the directory name
        {
            return this.guideName;
        }
        public int GetNoOfCountries()    //   Returning the number of countries
        {
            return this.noOfCountries;
        }
        public Date GetDepartureDate()   //   return departure date
        {
            return this.departureDate;
        }
        public Date GetReturningDate()    //   return return date
        {
            return this.returningDate;
        }
        public int GetNoOfTravellers()   //   Returning a number of travelers
        {
            return this.noOfTravellers;
        }
        public void SetGuideName(string guideName)   //   Updating the directory name
        {
            this.guideName = guideName;
        }
        public void SetNoOfCountries(int noOfCountries)     //    Update the number of countries
        {
            if (noOfCountries >= 1 && noOfCountries <= 10)   
                this.noOfCountries = noOfCountries;
            else                                             
                return;
        }
        public void SetDepartureDate(Date departureDate)       //   Update departure date
        {
            int day = departureDate.GetDay();       
            int month = departureDate.GetMonth();
            int year = departureDate.GetYear();

            if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 1000 || year > 9999)) 
                return;
            else if ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))  
                return;
            else if (month == 2)    
            {
                if ((year % 4 != 0) && (day > 28))   
                    return;
                else if ((year % 4 == 0) && (day > 29))  
                    return;
            }
            if (returningDate.Before(departureDate))   
                return;
            this.departureDate = new Date(departureDate);  
        }
        public void SetReturningDate(Date returningDate)     //    Update return date
        {
            int day = returningDate.GetDay();        
            int month = returningDate.GetMonth();
            int year = returningDate.GetYear();
            if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 1000 || year > 9999))    
                return;
            if ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))  
                return;
            if (month == 2)     
            {
                if ((year % 4 != 0) && (day > 28))
                    return;
                else if ((year % 4 == 0) && (day > 29)) 
                    return;
            }
            if (returningDate.Before(departureDate))    
                return;
            this.returningDate = new Date(returningDate);      
        }
        public void SetNoOfTravellers(int noOfTravellers)      //    Updating the number of travelers
        {
            if (noOfTravellers >= 1 && noOfTravellers <= 50)   
                this.noOfTravellers = noOfTravellers;
            else
                return;             
        }
        public bool Equals(Trip t)     //    A function that will return true if the trip received as a parameter is equal to the trip received as an object, and false otherwise
        {
            return (this.guideName == t.guideName && this.noOfCountries == t.noOfCountries && this.departureDate.Equals(t.departureDate) &&
            this.returningDate.Equals(t.returningDate) && this.noOfTravellers == t.noOfTravellers);
        }
        public bool SameDepartureDate(Trip t)   //    A method that will check that the exit date of the object and the parameter are equal
        {
            return (this.departureDate.Equals(t.departureDate));  
        }
        public bool SameReturningDate(Trip t)   //    A method that will check that the return date of the object and the parameter are equal
        {
            return (this.returningDate.Equals(t.returningDate)); 
        }
        public bool Overlap(Trip t)   //    A function that will check if there is an overlap between the date of the object and the parameter
        {
            if ((this.returningDate).Before(t.departureDate) || t.returningDate.Before(this.departureDate))
                return false;
            else
                return true;                             
        }
        public int TripDuration()    //   A function that will return the length of the trip
        {
            if (this.departureDate.Equals(this.returningDate)) 
                return 1;    
            else
                return (this.departureDate.Difference(this.returningDate));      
        }
        public bool IsLoaded()     //    A method that checks if the trip is busy
        {
            return (this.noOfCountries > this.TripDuration());   
        }
        public int HowManyCars()   //   A method that will return a minimum number of minibuses for the trip
        {
            if (this.noOfTravellers % 10 == 0) 
                return (this.noOfTravellers / 10);  
            else
                return (this.noOfTravellers / 10 + 1);   
        }
        public double CalculatePrice()    //   A method that will return the price of a trip
        {
            int month = this.departureDate.GetMonth();  
            int countries = this.noOfCountries;  
            if (month == 8 || month == 7)
                return (double)(1.2 * (PRICE_PER_DAY * this.TripDuration() + PRICE_PER_COUNTRY * countries));
            else
                return (PRICE_PER_DAY * this.TripDuration() + PRICE_PER_COUNTRY * countries);    
        }
        public override string ToString()    //   Override method that prints the details of the trip
        {
            return ("TRIP:" + this.guideName + " | " + this.departureDate + " - " + this.returningDate + " | " + this.noOfCountries + " | " + this.noOfTravellers);    
        }
    }
}

