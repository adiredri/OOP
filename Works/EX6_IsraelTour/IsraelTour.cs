using System;
using System.Collections.Generic;
using System.Text;

namespace Work4
{
    class IsraelTour
    {
        private Trip[] data;  
        private int noOfTrips;   
        private const int MAX_TRIPS = 100;   
        public IsraelTour()    //  Constructor initializes class attributes
        {
            this.data = new Trip[MAX_TRIPS];   
            this.noOfTrips = 0;   
        }
        public int GetNoOfTrips()   //   A method that will return the number of trips the company actually has
        {
            return this.noOfTrips;  
        }
        public bool AddTrip(Trip t)    //    A method that will add a trip to the trip array and make sure it happened
        {
            if (noOfTrips < MAX_TRIPS)  
            {
                data[noOfTrips] = new Trip(t);    
                noOfTrips++;  
                return true;   
            }
            else
                return false;   
        }
        public bool RemoveTrip(Trip t)   //   A method that will delete a specific trip from the trip array
        {
            for (int i = 0; i < noOfTrips; i++)  
            {
                if (data[i].Equals(t))   
                {
                    data[i] = null;  
                    noOfTrips--;  
                    for (int j = i; j < noOfTrips; j++)   
                        data[j] = data[j + 1];   
                    return true;    
                }
            }
            return false;   
        }
        public int HowManyTravellers()   //   A method that will return the number of passengers in all the trips that the company has
        {
            int c = 0;  
            for (int i = 0; i < noOfTrips; i++)  
            {
                c += data[i].GetNoOfTravellers();
            }
            return c;  
        }
        public int HowManyTripsDeparture(Date d)    //    A method that returns the number of trips that started on the date entered as a parameter
        {
            int c = 0; 
            for (int i = 0; i < noOfTrips; i++)
            {
                if (d.Equals(data[i].GetDepartureDate()))  
                    c++;
            }
            return c;  
        }
        public int HowManyCars(Date d)   //   A method that will receive a date as a parameter and return how many buses are required to leave on that date
        {
            int c = 0;  
            for (int i = 0; i < noOfTrips; i++)  
            {
                if (d.Equals(data[i].GetDepartureDate())) 
                {
                    c += data[i].HowManyCars();
                }
            }
            return c; 
        }
        public Trip LongestTrip()  //   A method that will return the longest trip in the agency
        {
            int c = 0;
            for (int i = 1; i < noOfTrips; i++)  
            {
                if (data[i].TripDuration() > data[c].TripDuration())  
                    c = i;  
            }
            return data[c];  
        }
        public string MostPopularGuide()   //  A method that will return the guide who guided the most trips in the agency
        {
            int c = 0, popular = 0;  
            string guide = null; 
            for (int i = 0; i < noOfTrips; i++)  
            {
                for (int j = 0; j < noOfTrips; j++) 
                {
                    if (data[i].GetGuideName() == data[j].GetGuideName())   
                        c++;  
                }
                if (popular < c)  
                {
                    popular = c; 
                    guide = data[i].GetGuideName(); 
                }
                c = 0; 
            }
            return guide;  
        }
        public Trip MostExpensiveTrip()   //  A method that will return the most expensive trip in the agency
        {
            int c = 0; 
            for (int i = 0; i < noOfTrips; i++) 
            {
                if (data[i].CalculatePrice() > data[c].CalculatePrice()) 
                    c = i; 
            }
            return data[c];  
        }
    }
}
