using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleAppTitgul1
{
    class Inventory   // Opening a department
    {
        private Drug[] data;  
        private int count;  
        private const int Max_Drugs = 100;  
        public Inventory()   // Opening an empty constructor initializing data
        {
            data = new Drug[Max_Drugs];  
            count = 0;    
        }
        public void AddDrug(Drug drug)   //  An add function that will add a new drug to the inventory array
        {
            int x = 0;  
            bool flag = true;   
            if (count < Max_Drugs)   
            {
                for (int i = 0; i < count; i++) 
                {
                    if (drug.GetCatalogNumber() == data[i].GetCatalogNumber())  
                    {
                        Console.WriteLine("The Catalog Number " + drug.GetCatalogNumber() + " is already in the list");  
                        x = drug.GetQuantity() + data[i].GetQuantity();  
                        data[i].SetQuantity(x);  
                        flag = false;  
                        break; 
                    }
                }
                if (flag == true) 
                {
                    data[count] = drug; 
                    count++; 
                }
            }
        }
        public void RemoveDrug(Drug drug)   //   A delete function that will delete a drug from the array
        {
            for (int i = 0; i < count; i++)  
            {
                if (data[i].GetCatalogNumber() == drug.GetCatalogNumber())    
                {
                    for (int j = i; j < count - 1; j++) 
                    {
                        data[j] = data[j + 1];  
                    }
                    count--;   
                    break;   
                }
            }
        }
        public void RemoveAfterDate(Date date)   //  The method deletes from the inventory all the eye drops whose expiration date is before the date received as a parameter
        {
            for (int i = 0; i < count; i++)   
            {
                if (data[i] is EyeDropsDrug && ((EyeDropsDrug)data[i]).GetExpiryDate().Before(date))     
                {
                    for (int j = i; j < count - 1; j++)    
                        data[j] = data[j + 1];  
                    count--;   
                }
            }
        }
        public int HowMany(int temp)   //  The method receives a number that is the temperature in the refrigerator and returns the number of medications that can go into this refrigerator
        {
            int c = 0; 
            for (int i = 0; i < count; i++)  
            {
                if (data[i] is CreamDrug && ((CreamDrug)data[i]).GetMinTemperature() <= temp && ((CreamDrug)data[i]).GetMaxTemperature() >= temp)
                    c++; 
            }
            return c;   
        }
        public void GetOilDrug()     //    Printing all the oils available in the store and their respective warranty dates 
        {
            for (int i = 0; i < count; i++)  
            {
                if (data[i] is OilDrug)   
                    Console.WriteLine(data[i]);  
            }
        }
        public void Order(int x)   //    Printing the list of drugs that need to be ordered, that is, the received parameter is greater than the stock of the drug
        {
            for (int i = 0; i < count; i++)  
            {
                if (data[i].GetQuantity() < x)   
                    Console.WriteLine(data[i]);               
            }
        }
        public double CostAllShipping()   //  Reimbursement of the total cost of the drugs that are imported from Sand
        {
            int c = 0;   
            for (int i = 0; i < count; i++)  
            {
                if (data[i].GetImported()) 
                    c += data[i].Shipping();  
            }
            return c; 
        }
        public void AdDrug(Drug drug)   // An add function that will add a new drug to the inventory array
        {
            int x = 0;  
            bool flag = true;  
            if (count < Max_Drugs)   
            {
                for (int i = 0; i < count; i++)  
                {
                    if (drug.GetCatalogNumber() == data[i].GetCatalogNumber())   
                    {
                        Console.WriteLine("The Catalog Number " + drug.GetCatalogNumber() + " is already in the list");   
                        x = drug.GetQuantity() + data[i].GetQuantity();  
                        drug.SetQuantity(x); 
                        flag = false;  
                        break;  
                    }
                }
                if (flag == true)  
                {
                    data[count] = drug;  
                    count++;   
                }
            }
        }
        public override string ToString()   //  A To-String function that will build a template that will contain all the members of the array (that is, all the drugs) that exist in it and return them
        {
            string st = " ";
            for (int i = 0; i < count; i++)
                st += data[i].ToString() + "\n";
            return st;
        }
    }

}
