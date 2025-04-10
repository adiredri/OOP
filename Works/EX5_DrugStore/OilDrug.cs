using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleAppTitgul1
{

    class OilDrug : Drug    // Defining a drug class An oil that inherits the drug's properties from the father
    {
        private Date guaranteeDate;  
        private int Price = 25;   

        public OilDrug(string name, int catalogueNumber, int quantity, bool imported, int a, int b, int c):base(name, catalogueNumber, quantity, imported)
        //  Building a parameter constructor that will inherit from the father the attributes name, catalog number, stock quantity and if it was brought from abroad, and adding the date of the drug's warranty
        {
            Date D1 = new Date(a, b, c);      
            this.guaranteeDate = D1;    
        }
        public override int Shipping()     //  A function that will check if it is imported from abroad and calculate the import cost
        {
            if (imported == true)   
            {
                return quantity * Price;    
            }
            else
                return 0;     
        }
        public Date GetGuaranteeDate()       // Get function that will get the warranty date 
        {
            return this.guaranteeDate;
        }
        public void SetGuaranteeDate(Date guaranteeDate)    // A set function that will update the warranty date
        {
            this.guaranteeDate = guaranteeDate;
        }
        public override string ToString()   //  The ToString function will inherit from the father the basis for the return pattern and add the date created in the class, and return everything together
        {
            return base.ToString() + " , " + guaranteeDate;
        }
    }
}
