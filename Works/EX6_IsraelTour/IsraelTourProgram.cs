using System;

namespace Work4
{
    class Program
    {

        //*********************Tests*******************

        static void Main(string[] args)
        {       
            bool f1 = true;

            Console.WriteLine("\nChecking IsraelTour: \n");
            //*********************test AddTrip and GetNoOfTrips
            Trip trip1 = new Trip("Moshe", 2, 1, 2009, 10, 1, 2009, 5, 23);
            IsraelTour tour1 = new IsraelTour();
            if (tour1.GetNoOfTrips() != 0)
            {
                Console.WriteLine("ERROR: GetNoOfTrips returns NON-zero when there are still no trips in the list.");
                f1 = false;
            }

            //*****************test RemjoveTrip: create a new IsraelTour object, add a trip, then remove it ; then try to remove a trip from an EMPTY list

            IsraelTour tour2 = new IsraelTour();
            tour2.AddTrip(trip1);
            bool sucessfullyRemoved = tour2.RemoveTrip(trip1);
            if (!sucessfullyRemoved)
            {
                Console.WriteLine("ERROR: removeTrip returns false when trying to remove a trip.");
                f1 = false;
            }
            //*********************test HowManyTravellers

            Trip trip4 = new Trip("Shosh", 13, 2, 2005, 29, 4, 2005, 6, 26);
            Trip trip44 = new Trip("Shosh", 13, 2, 2005, 29, 5, 2005, 3, 21);
            IsraelTour tour4 = new IsraelTour();
            tour4.AddTrip(trip4);
            tour4.AddTrip(trip44);
            int countTravellers = tour4.HowManyTravellers();
            if (countTravellers != 47)
            {
                Console.WriteLine("ERROR: HowManyTravellers does not return 47 when called on a list with two trips, with exactly 47 Travellers.");
                f1 = false;
            }

            //*********************test howManyHowManyCars

            Date originalDepartureDate = new Date(13, 2, 2005);
            Trip trip5 = new Trip("Shosh", 13, 2, 2005, 29, 4, 2005, 6, 26);
            Trip trip55 = new Trip("Shosh", 13, 2, 2005, 29, 5, 2005, 3, 21);
            IsraelTour tour5 = new IsraelTour();
            tour5.AddTrip(trip5);
            tour5.AddTrip(trip55);
            int countCars = tour5.HowManyCars(originalDepartureDate);
            if (countCars != 6)
            {
                Console.WriteLine("ERROR: HowManyCars does not return 4 when called on a list with two trips, with the same departure date and 47 Travellers.");
                f1 = false;
            }

            //**********************test LongestTrip

            Trip trip6 = new Trip("Moshe", 2, 1, 2009, 10, 1, 2009, 5, 23);
            Trip trip7 = new Trip("Moshe", 12, 5, 2004, 28, 5, 2004, 2, 17);
            IsraelTour tour6 = new IsraelTour();
            tour6.AddTrip(trip6);
            tour6.AddTrip(trip7);
            Trip longestTrip = tour6.LongestTrip();
            if (longestTrip.TripDuration() != 16)
            {
                Console.WriteLine("ERROR: wrong value returned by LongestTrip.");
                f1 = false;
            }

            //***************test MostPopularGuide
            Trip trip8 = new Trip("Moshe", 2, 1, 2009, 10, 1, 2009, 5, 23);
            Trip trip9 = new Trip("Moshe", 12, 5, 2004, 28, 5, 2004, 2, 17);
            Trip trip10 = new Trip("Shosh", 12, 5, 2007, 28, 5, 2007, 2, 17);
            IsraelTour tour9 = new IsraelTour();
            tour9.AddTrip(trip8);
            tour9.AddTrip(trip9);
            tour9.AddTrip(trip10);
            string popularGuide = tour9.MostPopularGuide();
            if (!popularGuide.Equals("Moshe"))
            {
                Console.WriteLine("ERROR: wrong value returned by MostPopularGuide for a list with three trips, 2 of them guided by the same person.");
                f1 = false;
            }

            //***************test MostExpensiveTrip
            Trip trip11 = new Trip("Shosh", 12, 8, 2007, 28, 8, 2007, 2, 17);
            tour9.AddTrip(trip11);
            Trip mostExpensiveTrip = tour9.MostExpensiveTrip();
            if (!mostExpensiveTrip.Equals(trip11))
            {
                Console.WriteLine("ERROR: wrong value returned by MostExpensiveTrip for a list with four trips");
                f1 = false;
            }

            if (f1)
                Console.WriteLine("IsraelTour class passed all the tests.\n");
            Console.ReadKey();

            
        }

    }
}


