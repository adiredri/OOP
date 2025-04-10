using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleAppTitgul1
{

    class EyeDropsDrug : Drug   // Defining a class of medicine eye drops that will inherit the properties of the medicine from the father
    {
        private Date productionDate;  
        private Date expiryDate;  
        private int Price = 20;   

        public EyeDropsDrug(string name, int catalogueNumber, int quantity, bool imported, int a, int b, int c, int a1, int b1, int c1):base(name, catalogueNumber, quantity, imported) 
        {
            Date D1 = new Date(a, b, c); 
            Date D2 = new Date(a1, b1, c1); 
            this.productionDate = D1; 
            this.expiryDate = D2;  
        }
        public override int Shipping()  //  A function that will check if it is imported from abroad and calculate the import cost
        {
            if (imported == true)   
            {
                return quantity * Price; 
            }
            else
                return 0;    
        }
        public Date GetProductionDate()   // Get function that will get the production date
        {
            return this.productionDate;
        }
        public Date GetExpiryDate()   // Get function that will get the expiration date
        {
            return this.expiryDate;
        }
        public void SetProductionDate(Date productionDate)   // A set function that will update the production date
        {
            this.productionDate = productionDate;
        }
        public void SetExpiryDate(Date expiryDate)  // A set function that will update the expiration date
        {
            this.expiryDate = expiryDate;
        }
        public override string ToString()   //  The ToString function will inherit from the father the basis for the return pattern and add the dates created in the class, and return everything together
        {
            string st = "";
            st += base.ToString();
            st += " , " + this.productionDate + " , " + this.expiryDate;
            return st;
        }

    }
}
