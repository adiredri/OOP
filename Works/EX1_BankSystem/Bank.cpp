// Adir Edri 206991762

#include "Bank.h"
#define _CRT_SECURE_NO_WARNINGS

Bank::Bank()
{
	m_account = nullptr;
	m_bankCode = 0;
	m_numbeOfAccounts = 0;
	m_totalBalance = 0;
	m_name = nullptr;
}
Bank::Bank(const char* name, int code)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	m_bankCode = code;
	m_account = nullptr;
	m_totalBalance = 0;
	m_numbeOfAccounts = 0;
}
Bank::~Bank()
{
	if (m_account != nullptr)
	{
		for (int i = 0; i < m_numbeOfAccounts; i++)
		{
			delete m_account[i];
		}
		delete[] m_account;
	}
	delete[] m_name;
}
void Bank::SetBankName(const char* name)
{
	delete[] m_name;
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}
void Bank::SetAccount(Account** account, int numbeOfAccounts) //
{
	for (int i = 0; i < m_numbeOfAccounts; i++) 
	{
		delete m_account[i];
	}
	delete[] m_account;
	m_numbeOfAccounts = numbeOfAccounts;
	m_account = new Account * [numbeOfAccounts];
	for (int i = 0; i < numbeOfAccounts; i++) 
	{
		m_account[i] = new Account(*account[i]);
		m_totalBalance += account[i]->GetBalance();
	}
}
void Bank::SetTotal(double total)
{
	m_totalBalance = total;
}
void Bank::SetCode(int code)
{
	m_bankCode = code;
}
const char* Bank::GetBankName() const 
{
	return m_name;
}
Account** Bank::GetAccounts() const 
{
	return m_account;
}
int	Bank::GetNumberOfAccounts() const
{
	return m_numbeOfAccounts;
}
double Bank::GetTotal() const
{
	return m_totalBalance;
}
int	Bank::GetCode() const
{
	return m_bankCode;
}
void Bank::AddAccount(const Account& account)
{
	if (m_account == nullptr) 
	{
		m_account = new Account * [1];
		m_account[0] = new Account(account);
		m_totalBalance += account.GetBalance();
		m_numbeOfAccounts = 1;
		m_name = nullptr;                                   //
	}

	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		if (m_account[i]->GetAccountNumber() == account.GetAccountNumber())
		{
			return;
		}
	}

	Account** newArray = new Account * [m_numbeOfAccounts + 1];
	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		newArray[i] = m_account[i];
	}
	newArray[m_numbeOfAccounts] = new Account(account);
	delete[] m_account;
	m_account = newArray;
	m_numbeOfAccounts++;
	m_totalBalance += account.GetBalance();
}

void Bank::AddAccount(const Person& per, double amount)
{
	Account account(per, amount);
	AddAccount(account);
}
void Bank::AddPerson(const Person& newPerson, const Account& account, double amount)
{
	for (int i = 0; i < m_numbeOfAccounts; i++) 
	{
		if (m_account[i]->GetAccountNumber() == account.GetAccountNumber()) 
		{
			if (m_account[i]->GetTotalPersons() == 0) 
			{
				m_account[i]->AddPerson(newPerson, amount);
				m_totalBalance += amount;
				m_account[i]->SetBalance(m_account[i]->GetBalance() + amount);
				return;
			}
			Person** persons = m_account[i]->GetPersons();
			for (int j = 0; j < m_account[i]->GetTotalPersons(); j++) 
			{
				if (persons[j]->GetId() == newPerson.GetId()) 
				{
					return;
				}
			}

			m_account[i]->AddPerson(newPerson, amount);
			m_totalBalance += amount;
			m_account[i]->SetBalance(m_account[i]->GetBalance() + amount);
			return;
		}
	}

	Account** temp = new Account * [m_numbeOfAccounts + 1];
	for (int i = 0; i < m_numbeOfAccounts; i++) 
	{
		temp[i] = m_account[i];
	}
	temp[m_numbeOfAccounts] = new Account(newPerson, amount);
	m_totalBalance += amount;
	m_numbeOfAccounts++;
	delete[] m_account;
	m_account = temp;
}

void Bank::DeleteAccount(const Account& account) 
{
	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		if (m_account[i]->GetAccountNumber() == account.GetAccountNumber())
		{
			if (i == m_numbeOfAccounts - 1)
			{
				m_totalBalance -= m_account[i]->GetBalance();
				delete m_account[i];
				m_account[i] = nullptr;
				m_numbeOfAccounts--;
				return;
			}
			else
			{
				m_totalBalance -= m_account[i]->GetBalance();
				delete m_account[i];
				m_account[i] = m_account[m_numbeOfAccounts - 1];
				m_account[m_numbeOfAccounts - 1] = nullptr;
				m_numbeOfAccounts--;
				return;
			}
		}
	}
}
void Bank::DeletePerson(const Person& p)
{
	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		Person** person = m_account[i]->GetPersons();
		Account* account = m_account[i];
		for (int j = 0; j < account->GetTotalPersons(); j++)
		{
			if (person[j]->GetId() == p.GetId())
			{
				account->DeletePerson(*person[j]);
				j--;
			}
		}
		if (account->GetTotalPersons() == 0)
		{
			DeleteAccount(*account);
			i--;
		}
	}
}





