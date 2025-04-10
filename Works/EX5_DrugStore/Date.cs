using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleAppTitgul1
{
	class Date    
	{
		private int day;
		private int month;
		private int year;
		public Date(int day, int month, int year)    //  The opening of the date department that captures three numbers - day, month and year
		{
			this.day = day;
			this.month = month;
			this.year = year;
			if ((day < 1 || day > 31) || (month < 1 || month > 12) || (year < 1000 || year > 9999))
			{
				this.SetDay(1);
				this.SetMonth(1);
				this.SetYear(2000);
			}
			if ((day > 30) && (month == 4 || month == 6 || month == 9 || month == 11))
			{
				this.SetDay(1);
				this.SetMonth(1);
				this.SetYear(2000);
			}
			if (month == 2)
			{
				if ((year % 4 != 0) && (day > 28))
				{
					this.SetDay(1);
					this.SetMonth(1);
					this.SetYear(2000);
				}
				else if ((year % 4 == 0) && (day > 29))
				{
					this.SetDay(1);
					this.SetMonth(1);
					this.SetYear(2000);
				}
			}
		}
		public Date(Date d)      // Copy constructor - which accepts a different date
		{
			this.day = d.day;
			this.month = d.month;
			this.year = d.year;
		}
		public int GetDay()    //  The get function returns the days of the object
		{
			return this.day;
		}
		public int GetMonth()   //  The get function returns the months of the object
		{
			return this.month;
		}
		public int GetYear()   //  The get function returns the years of the object
		{
			return this.year;
		}
		public void SetDay(int day)    //  The set function updates the days of the object
		{
			if (day >= 1 && day <= 30)
			{
				if (this.month == 4 || this.month == 6 || this.month == 9 || this.month == 11)
				{
					this.day = day;
				}
			}
			else if (this.month == 2)
			{
				if ((day >= 1 && day <= 28) && (this.year % 4 != 0))
				{
					this.day = day;
				}
				else if ((day >= 1 && day <= 29) && (this.year % 4 == 0))
				{
					this.day = day;
				}
			}
			else if (day >= 1 && day <= 31)
				this.day = day;
		}
		public void SetMonth(int month)   //  The set function updates the months of the object
		{
			if (month >= 1 && month <= 12)
			{
				if ((this.day >= 1 && this.day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
				{
					this.month = month;
				}
				else if (month == 2)
				{
					if ((this.day >= 1 && this.day <= 28) && (this.year % 4 != 0))
					{
						this.month = month;
					}
					else if ((this.day >= 1 && this.day <= 29) && (this.year % 4 == 0))
					{
						this.month = month;
					}
				}
				else
					this.month = month;
			}
		}
		public void SetYear(int year)   //  The set function updates the years of the object
		{
			if (year >= 1000 && year <= 9999)
			{
				this.year = year;
			}
		}
		public bool Before(Date d)    // A function that checks if the date of the object precedes the date of the parameter
		{
			if (this.year < d.year)
				return true;
			else if (this.year == d.year && this.month < d.month)
				return true;
			else if (this.year == d.year && this.month == d.month && this.day < d.day)
				return true;
			else
				return false;
		}
		public bool After(Date d)   //  A function that checks if the date of the object comes after the date of the parameter
		{
			return (d.Before(this));
		}
		public bool Equals(Date d)    // A function that checks if the dates are equal
		{
			return ((Before(d) == false) && (After(d) == false));
		}
		public int Difference(Date d)  //   A function that returns the difference in days between the date of an object and a parameter
		{
			return Math.Abs(CalculateDate(this.GetDay(), this.GetMonth(), this.GetYear()) - (CalculateDate(d.day, d.month, d.year)));
		}
		private int CalculateDate(int day, int month, int year)    //  A helper function that calculates the number of days the count starts
		{
			if (month < 3)
			{
				year--;
				month = month + 12;
			}
			return 365 * year + year / 4 - year / 100 + year / 400 + ((month + 1) * 306) / 10 + (day - 62);
		}
		public override string ToString()    //   A function that returns the date as a classic date string - 00/00/0000
		{
			return this.day + "/" + this.month + "/" + this.year;
		}
	}
}