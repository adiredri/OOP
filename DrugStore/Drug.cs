using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleAppTitgul1
{

    abstract class Drug  // Opening a medicine abstract department
    {
        protected string name;  
        protected int catalogueNumber; 
        protected int quantity;
        protected bool imported; 
        public Drug(string name, int catalogueNumber, int quantity, bool imported) 
        {
            this.name = name;                       
            this.catalogueNumber = catalogueNumber;
            this.quantity = quantity;
            this.imported = imported;
        }
        public string GetName()   // A get function that will return the name of the drug
        {
            return this.name;
        }
        public int GetCatalogNumber()   // A get function that will return the catalog number 
        {
            return this.catalogueNumber;
        }
        public int GetQuantity()   // A get function that will return the quantity in stock of the drug
        {
            return this.quantity;
        }
        public bool GetImported()   // A get function that will return if the drug is imported from Israel or manufactured in Israel
        {
            return this.imported;
        }
        public void SetName(string name)   // A set function that will update the drug name
        {
            this.name = name;
        }
        public void SetCatalogNumber(int catalogueNumber)   // A set function that will update the drug's catalog number
        {
             this.catalogueNumber = catalogueNumber;
        }
        public void SetQuantity(int quantity)   // A set function that will update the drug's catalog number
        {
            this.quantity = quantity;
        }
        public void SetImported(bool imported)   // A set function that will update whether the drug is imported from Israel or manufactured in Israel
        {
            this.imported = imported;
        }
        public abstract int Shipping();       //  A delivery father function which will receive data in its sons  
        public override string ToString()    //  The ToString function will return me the template that was prepared when it was called for printing
        {
            string st = "";
            st += this.name + " , " + this.catalogueNumber + " , " + this.quantity + " , " + this.imported;
            return st;
        }
    }
}
