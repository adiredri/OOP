using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleAppTitgul1
{
    class CreamDrug : Drug   // Defining a drug class An ointment that inherits the properties of the drug from the father
    {
        private int minTemperature;
        private int maxTemperature;   
        private int Price = 30;       

        public CreamDrug(string name, int catalogueNumber, int quantity, bool imported, int minTemperature, int maxTemperature):base(name, catalogueNumber, quantity, imported)
        //  Building a parameter constructor that inherits from the father the attributes name, catalog number, stock quantity and if it was brought from abroad, and adding two numbers of the minimum and maximum temperature of the medicine
        {
            this.minTemperature = minTemperature;  
            this.maxTemperature = maxTemperature; 
        }
        public override int Shipping()    //  A function that will check if it is imported from abroad and calculate the import cost
        {
            if (imported == true)  
                return quantity * Price;   
            else
                return 0;    
        }
        public int GetMinTemperature()   //   Get function that will get the minimum temperature
        {
            return this.minTemperature;
        }
        public int GetMaxTemperature()   //   Get function that will get the maximum temperature
        {
            return this.maxTemperature;
        }
        public void SetMinTemperature(int minTemperature)   //   A set function that will update the minimum temperature
        {
            this.minTemperature = minTemperature;
        }
        public void SetMaxTemperature(int maxTemperature)   //   A set function that will update the maximum temperature
        {
            this.maxTemperature = maxTemperature;
        }
        public override string ToString()  //  A To-String function will inherit from the father the basis for the return pattern and add the min and max of the temperature, and return everything together
        {
            return base.ToString() + " , " + minTemperature + " , " + maxTemperature;
        }
    }
}
