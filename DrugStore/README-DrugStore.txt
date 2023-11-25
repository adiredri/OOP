Inheritance and polymorphism

  In this question, an online store that manages cannabis medicines, which are allowed to be used, must be realized.
The functionality we want to have in the store is for example this:
• Should allow us to enter information about the various medications and receive this information.
• You need to save the information regularly so that it can be used in the future.
• Should provide a search function that allows finding different drugs.
• It should be possible to place an order for drugs that are out of stock.
• Should allow adding any medicine to the collection.

Another method that every class should have is ToString which returns all the details about the drug in the form of a string.
You must write appropriate classes Date, EyeDropsDrug, OilDrug, CreamDrug, Drug (with the appropriate uses and inheritances) that implement the above (properties, constructors and methods).

Part B - Polymorphism
1. Some of the medicines are imported from abroad. Assume that each medicine has a fixed cost of shipping from abroad to Israel (eye drops 20 NIS per medicine, ointments 25 NIS per medicine, ointment 30 NIS per medicine). Define where necessary a method called Shipping() that returns the shipping cost of the medicine.
2. You must write a class called Inventory. The department will have all the drugs that are allowed to be used. The features of the department are: an array of Drug and the actual number of drugs.
• The maximum size of the array will be 100.
• The methods in the department will be:
o public void AddDrug (Drug drug) - which adds a new drug to the inventory.
o public void RemoveDrug (Drug drug) - deletes a certain drug from the inventory.
o public string ToString () - which returns a string representing the entire stock of drugs when each drug is followed by a space line.
o public void RemoveAfterDate (Date date) – deletes from the inventory all the eye drops whose expiration date is before the date date (that is, all the drugs that are "broken" on the date date, because their expiration date has already passed).
o public int HowMany (int temp) – which receives an integer that is a temperature in a certain refrigerator, and returns the number of medicines that can go to this refrigerator (that is, the temperature of the refrigerator is suitable for their storage).
o public void GetOilDrug() - which prints all the oils available in the store and their respective warranty dates.
o public void Order (int x) – prints a list of medications that must be ordered. A medicine will appear in the order list if the quantity of it in stock is less than x (passed to the method as a parameter).
o public double CostAllShipping () – which returns the total cost of the drugs imported from abroad, which are in the online store, with reference to their quantity in stock and the shipping cost for the drug.