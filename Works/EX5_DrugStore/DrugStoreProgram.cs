using System;

namespace ConsoleAppTitgul1
{

    class Program
    {
       // *********************Tests***********************
        static void Main(string[] args)
        {
              Inventory i = new Inventory();
            //  Drug e1 = new EyeDropsDrug("adir", 2, 3, true,1,1,2020,2,1,2022);
            //  Drug e2 = new OilDrug("adir", 4, 5, true, 1, 1, 2020);
            //  Drug e3 = new OilDrug("adir", 4, 9, true, 1, 4, 2020);
            //  Drug e4 = new OilDrug("adir", 4, 12, true, 1, 4, 2020);
            //  i.AddDrug(e1);
            //  i.AddDrug(e2);
            //  i.AddDrug(e3);
            //  i.AddDrug(e4);
            //  Console.WriteLine();
            //  Console.WriteLine(i.ToString());
            //  Date D1 = new Date(3, 1, 2022);
            //  Console.WriteLine(i.CostAllShipping());
            //  i.GetOilDrug();
            //  Console.WriteLine(i.ToString());
            //  Console.WriteLine(e.Shipping());
            OilDrug e = new OilDrug("a", 1, 2, true, 1, 3, 2020);
            OilDrug e2 = new OilDrug("a", 1, 2, true, 1, 3, 2020);
            i.AddDrug(e);
            i.AddDrug(e2);
            Console.WriteLine(i.ToString());
        }
    }
}
