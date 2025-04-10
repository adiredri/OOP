// Adir Edri 206991762

#include "Account.h"
#define _CRT_SECURE_NO_WARNINGS


Account::Account()
{
	m_transactionList = nullptr;
	m_numberOfTransaction = 0;
	m_persons = nullptr;
	m_totalPersons = 0;
	m_accountNumber = 0;
	m_balance = 0;
}

Account::Account(Person** persons, int count, double balance)
{
	m_balance = balance;
	m_transactionList = nullptr;
	m_totalPersons = count;
	m_numberOfTransaction = 0;
	m_accountNumber = 0;
	m_persons = new Person * [count];
	for (int i = 0; i < count; i++)
	{
		m_persons[i] = new Person(*persons[i]);
	}
}

Account::Account(const Person& person, double balance)
{
	m_transactionList = nullptr;
	m_persons = nullptr;
	m_balance = balance;
	m_persons = new Person * [1];
	m_persons[0] = new Person(person);
	m_accountNumber = person.GetId() * 3;
	m_totalPersons = 1;
	m_numberOfTransaction = 0;
}

Account::Account(const Account& other)
{
	m_balance = other.m_balance;
	m_accountNumber = other.m_accountNumber;
	m_totalPersons = other.m_totalPersons;
	m_numberOfTransaction = other.m_numberOfTransaction;
	m_persons = new Person * [other.m_totalPersons];
	for (int i = 0; i < other.m_totalPersons; i++)
	{
		m_persons[i] = new Person(*other.m_persons[i]);
	}
	m_transactionList = new Transaction * [other.m_numberOfTransaction];
	for (int i = 0; i < other.m_numberOfTransaction; i++)
	{
		m_transactionList[i] = new Transaction(*other.m_transactionList[i]);
	}
}

Account::~Account()
{
	clearTransactions();
}

void Account::SetPersons(Person** persons, int count)
{
	clearPersons();
	m_persons = new Person * [count];
	for (int i = 0; i < count; i++)
	{
		m_persons[i] = new Person(*persons[i]);
	}
	m_totalPersons = count;
}

void Account::SetAccountNumber(int number)
{
	m_accountNumber = number;
}

void Account::SetBalance(double balance)
{
	m_balance = balance;
}

void Account::SetTransactions(Transaction** newTransaction, int count)
{
	clearTransactions();
	m_transactionList = new Transaction * [count];

	for (int i = 0; i < count; i++)
	{
		m_transactionList[i] = new Transaction(*newTransaction[i]);
	}
	m_numberOfTransaction = count;
}

Transaction** Account::GetTransactions()
{
	return m_transactionList;
}

int Account::GetNumOfTransactions()
{
	return m_numberOfTransaction;
}

Person** Account::GetPersons() const
{
	return m_persons;
}

int Account::GetTotalPersons() const
{
	return m_totalPersons;
}

int Account::GetAccountNumber() const
{
	return m_accountNumber;
}

double Account::GetBalance() const
{
	return m_balance;
}
void Account::Withdraw(double amount, const char* date)
{
	Transaction** newTransactionArr = new Transaction * [m_numberOfTransaction + 1];
	for (int i = 0; i < m_numberOfTransaction; i++)
	{
		newTransactionArr[i] = m_transactionList[i];
	}
	newTransactionArr[m_numberOfTransaction] = new Transaction(this, nullptr, amount, date);
	if (m_numberOfTransaction > 0)
		newTransactionArr[m_numberOfTransaction]->SetAmount(m_transactionList[m_numberOfTransaction - 1]->GetAmount() - amount);
	else
		newTransactionArr[m_numberOfTransaction]->SetAmount(-amount);
	newTransactionArr[m_numberOfTransaction]->SetDate(date);
	m_balance -= amount;
	m_transactionList = newTransactionArr;
	m_numberOfTransaction++;
	clearTransactions();
}

void Account::Deposit(double amount, const char* date)
{
	Transaction** newTransactionArr = new Transaction * [m_numberOfTransaction + 1];
	for (int i = 0; i < m_numberOfTransaction; i++)
	{
		newTransactionArr[i] = m_transactionList[i];
	}
	newTransactionArr[m_numberOfTransaction] = new Transaction(nullptr, this, amount, date);
	if (m_numberOfTransaction > 0)
		newTransactionArr[m_numberOfTransaction]->SetAmount(m_transactionList[m_numberOfTransaction - 1]->GetAmount() + amount);
	else
		newTransactionArr[m_numberOfTransaction]->SetAmount(amount);
	newTransactionArr[m_numberOfTransaction]->SetDate(date);
	m_balance += amount;
	m_transactionList = newTransactionArr;
	m_numberOfTransaction++;
	clearTransactions();
}

void Account::AddPerson(const Person& newPerson, double amount)
{
	m_balance += amount;
	if (m_persons == nullptr)
	{
		m_persons = new Person * [1];
		m_persons[0] = new Person(newPerson);
		m_totalPersons = 1;
		return;
	}
	else
	{
		for (int i = 0; i < m_totalPersons; i++)
		{
			if (m_persons[i]->GetId() == newPerson.GetId())
			{
				return;
			}
		}
		Person** temp = new Person * [m_totalPersons + 1];
		for (int i = 0; i < m_totalPersons; i++)
		{
			temp[i] = m_persons[i];
		}
		temp[m_totalPersons] = new Person(newPerson);
		delete[] m_persons;
		m_persons = temp;
		m_totalPersons++;
	}
}

void Account::DeletePerson(const Person& oldPerson)
{
	for (int i = 0; i < m_totalPersons; i++)
	{
		if (oldPerson.GetId() == m_persons[i]->GetId())
		{
			delete m_persons[i];
			m_totalPersons--;
			if (m_totalPersons == 0) {
				delete[] m_persons;
				m_persons = nullptr;
			}
			else
			{
				Person** temp = new Person * [m_totalPersons];
				for (int j = 0, k = 0; j < m_totalPersons + 1; j++)
				{
					if (j != i)
						temp[k++] = m_persons[j];
				}
				delete[] m_persons;
				m_persons = temp;
			}
			break;
		}
	}
}
void Account::AddTransaction(const Transaction& newTransaction)
{
	
	Account* src = newTransaction.GetSource();
	Account* dst = newTransaction.GetDes();

	src->m_balance -= newTransaction.GetAmount();
	dst->m_balance += newTransaction.GetAmount();


	Transaction** temp = new Transaction * [src->m_numberOfTransaction + 1];
	for (int i = 0; i < src->m_numberOfTransaction; i++) {
		temp[i] = new Transaction(*src->m_transactionList[i]);
	}
	delete[]src->m_transactionList;

	temp[src->m_numberOfTransaction] = new Transaction(newTransaction);
	src->m_transactionList = temp;
	src->m_numberOfTransaction += 1;

	if (src->GetAccountNumber() != dst->GetAccountNumber()) {
		Transaction** temp = new Transaction * [dst->m_numberOfTransaction + 1];
		for (int i = 0; i < dst->m_numberOfTransaction; i++) {
			temp[i] = new Transaction(*dst->m_transactionList[i]);
		}
		delete[]dst->m_transactionList;

		temp[dst->m_numberOfTransaction] = new Transaction(newTransaction);
		dst->m_transactionList = temp;
		dst->m_numberOfTransaction += 1;
	}
}
void Account::clearTransactions()
{
	for (int i = 0; i < m_numberOfTransaction; i++)
	{
		delete m_transactionList[i];
	}
	delete[] m_transactionList;
	m_transactionList = nullptr;
	m_numberOfTransaction = 0;
}
void Account::clearPersons()
{
	for (int i = 0; i < m_totalPersons; i++)
	{
		delete m_persons[i];
	}
	delete[] m_persons;
	m_persons = nullptr;
	m_totalPersons = 0;
}




