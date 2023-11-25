The travel company "Israel-Tor" decided to computerize its travel data during the year.
For this purpose, we will first define the Date class to represent a date.

1. The Date class represents a date. Two constructors were defined for the department:
• The one - constructor that accepts three parameters (day, month and year) of the date.
• The second - a copy constructor that accepts another date, and copies its values.
In addition, the public methods were defined in the department:
• The retrieval operations:
GetDay(), GetMonth(), GetYear().
• The determining actions:
SetDay(int day), SetMonth(int month), SetYear(int year).

Department methods:

• The Equals method that receives a certain date as a parameter and checks if it is the same as the date represented by the object on which the method is invoked.
• The Before method which receives a certain date as a parameter and checks whether the date represented by the object on which the method is invoked precedes the date received as a parameter.
• The After method that receives a certain date as a parameter and checks whether the date represented by the object on which the method is invoked is later than the date received as a parameter. The after method must use only the before method (it cannot calculate the answer according to the attribute values, and cannot use the equals method).
• The Difference method that accepts a certain date as a parameter, and calculates the difference in days between the date represented by the object on which the method is invoked, and the date represented by the object passed as a parameter. Note that this number will always be positive.
• The ToString method returns a string representing the date as follows: day / month / year


2. The Trip class represents a trip.
Price for a day trip - NIS 250
Supplement for each country - NIS 100

The Trip class has three constructors:
• One constructor that accepts as parameters: the name of the guide, three integers representing the departure date for the trip and three integers representing the return date from the trip, an integer representing the number of countries visited, and another integer representing the number of passengers participating in this trip.
• A copy constructor that accepts another trip, and copies its values.
• A constructor that accepts as parameters: the name of the guide, the departure date for the trip (as an object from the Date class), the return date from the trip (as an object from the Date class), an integer representing the number of countries visited, and another integer representing the number of passengers participating in this trip.

The parameters can be invalid. If the number of countries is invalid, the default value 1 will be entered, if the number of passengers is invalid, the default value 10 will be entered. If the combination between the dates is incorrect, the departure and return date must be initialized to January 1, 2000.

Get and Set operations were defined in the class according to the accepted names. In the Set operations, if the parameters are invalid nothing will change.

The following methods were also defined:
• The Equals method which receives as a parameter a certain trip and checks if it is the same as the trip represented by the object on which the method is invoked. Identical in all respects.
• SameDepartureDate a boolean method that accepts as a trip parameter and returns true if its departure date is the same as the departure date of the trip on which the method is invoked, and false otherwise;
• SameReturningDate Boolean method that accepts as a trip parameter and returns true if its return date is the same as the return date of the trip on which the method is invoked, and false otherwise;
• Overlap Boolean method that accepts as a trip parameter and returns true if there is an overlap (full or partial) between the dates of the trip received as a parameter for the trip on which the method is activated, and false otherwise
• TripDuration which returns the length of the trip - that is, the number of days it lasts (a trip whose departure and return date are the same is considered a one-day trip).
• IsLoaded Boolean method that returns true if this is a loaded trip - if the number of countries is greater than the number of days of the trip, and false otherwise.
• HowManyCars method that returns the minimum number of minibuses needed on a trip. Each minibus can fit up to 10 passengers.
• CalculatePrice method that returns the price of the trip (not including flights), according to the number of days and the number of countries where the trip takes place. If the trip takes place in the summer (months July-August), 20% must be added to the price. In order to simplify the calculation, we will define it based on the departure date only, that is, if for example the departure date was in August and the trip continued in September, for the calculation of the cost the entire trip will have an additional 20%.
• The ToString method returns a character string representing the trip as follows:
TRIP : guideName | departureDate -_returningDate | noOfCountries | noOfTravellers
For example:
TRIP: Yossi Chen | 1 / 1 / 2020 | 9 / 1 / 2020 | 5 | 25


3. The IsraelTour department represents the tour data in the company.
The representation is made by an array that saves the list of trips.
The maximum number of trips in the company - 100.
The trips (ie the objects from the class Trip) are in the array in sequence, without "holes" the array begins. The array should remain this way (without holes) after each operation.

You must exercise the IsraelTour class. The implementation of the department includes the sections below:
1. Defining the constants and attributes of the class.
2. A constructor that initializes the class attributes so that the array is of maximum size.
3. A method that returns the actual number of trips the company has.
4. Boolean AddTrip method that adds a trip to the array of trips. The method accepts the trip as a parameter. The method returns a true value if the addition was successful, if not, the method will return false.
5. Boolean RemoveTrip method that deletes a trip from the array of trips. The method accepts the trip as a parameter. The method returns true if the deletion was successful, if not, the method will return false. Remember that the array should remain without "holes" even after this operation.
6. Method HowManyTravellers that returns the number of passengers in all trips in the company.
7. HowManyTripsDeparture method that accepts as a date parameter, and returns a number that says how many trips start on that day.
8. HowManyCars method that accepts as a date parameter, and returns a number that says how many cars are needed for all the trips that start that day.
9. LongestTrip method that returns the company's longest trip.
10. Method MostPopularGuide which returns the name of the most popular guide in the company (ie the one who guides the most trips). If there is more than one, the first one must be returned.
11. Method MostExpensiveTrip that returns the company's most expensive trip.