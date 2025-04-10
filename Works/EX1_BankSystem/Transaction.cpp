// Adir Edri 206991762

#include "Transaction.h"
#define _CRT_SECURE_NO_WARNINGS


Transaction::Transaction(Account* s, Account* d, double amount, const char* date)
{
	m_source = s;
	m_destination = d;
	m_amount = amount;
	m_date = nullptr;
	m_date = new char[strlen(date) + 1];
	strcpy(m_date, date);
}

Transaction::Transaction(const Transaction& other)
{
	m_amount = other.GetAmount();
	m_date = other.GetDate();
	m_source = other.GetSource(); 
	m_destination = other.GetDes();
}

void Transaction::SetSource(Account* src)
{
	m_source = src;
}
void Transaction::SetDes(Account* dst)
{
	m_destination = dst;
}
void Transaction::SetAmount(double amount)
{
	m_amount = amount;
}
void Transaction::SetDate(const char* date)
{
	delete[] m_date;
	m_date = new char[strlen(date) + 1];
	strcpy(m_date, date);
}
Account* Transaction::GetSource() const
{
	return m_source;
}
Account* Transaction::GetDes() const
{
	return m_destination;
}
double Transaction::GetAmount() const
{
	return m_amount;
}
char* Transaction::GetDate() const      
{
	return m_date;
}








