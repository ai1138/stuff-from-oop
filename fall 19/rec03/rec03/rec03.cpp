// rec03.cpp by Abed Islam

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



struct BankAccount
{
	string name;
	int accNum;
	
};



class BankAccounts
{
	private:
		string name;
		int accNum;
		int balance;
		class Transactions
		{
			private:
				string state;
				int num;

			public:
				Transactions(string state, int num)
				{
					this->state = state;
					this->num = num;
				}
				string getState()
				{
					return this->state;
				}
				int getNum()
				{
					return this->num;
				}
				friend ostream& operator<<(ostream& os, const BankAccounts& acc);
				ostream& operator<<(ostream& os)
				{
					os << getState() << " " << getNum();
					return os;
				}

		};
		vector<Transactions> history;
	public:
		BankAccounts(string name, int accNum)
		{
			this->name = name;
			this->accNum = accNum;
			this->balance = 0;
		}
		BankAccounts(string name, int accNum,int balance)
		{
			this->name = name;
			this->accNum = accNum;
			this->balance = balance;
		}
		string getName()
		{
			return this->name;
		}
		int getAccNum()
		{
			return this->accNum;
		}
		int getBalance()
		{
			return this->balance;
		}
		void deposit(int add)
		{
			this->balance += add;
			this->history.emplace_back("deposit",add);
		}
		void withdraw(int sub)
		{
			
			if (this->balance - sub < 0)
			{
				perror("you are withdrawing more than you have that is not allowed");
			}
			else
			{
				this->balance-= sub;
				this->history.emplace_back("withdraw", sub);
			}

		}
		/*ostream& operator<< (ostream& os)
		{
			
			os << getName() << getAccNum();
			return os;
		}*/
		friend ostream& operator<<(ostream& os,const BankAccounts& acc);
	

};



void taskOne(ifstream& accountInfo, vector<BankAccount>& bank, string fileName);
void taskTwo(ifstream& accountInfo, vector<BankAccounts>& bank, string fileName);
void taskThree(ifstream& accountInfo, vector<BankAccounts>& bank, string fileName);
void deposits(int accNum, int val, vector<BankAccounts>& bank);
void withdrawal(int accNum, int val, vector<BankAccounts>& bank);
int main()
{
	ifstream ifs("accounts.txt");
	ifstream trans("test.txt");
	//vector<BankAccount> storage;
	vector<BankAccounts> storageAcc;
	//taskOne(ifs, storage, "accounts.txt");
	taskTwo(ifs, storageAcc, "accounts.txt");
	taskThree(trans, storageAcc, "test.txt");
	
   
}



ostream& operator<<(ostream& os, const BankAccounts& acc)
{
	os << acc.name << " " << acc.accNum << " " << " " << acc.balance;
	return os;

	
}

void taskOne(ifstream& accountInfo, vector<BankAccount>& bank, string fileName)
{
	if (!accountInfo)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!accountInfo.eof())
	{
		string personName;
		int num;
		BankAccount holder;
		accountInfo >> personName;
		holder.name = personName;
		accountInfo >> num;
		holder.accNum = num;
		bank.push_back(holder);
	}
	cout << "part a"<<endl;
	accountInfo.close();
	for (int i = 0; i < bank.size(); i++)
	{
		cout << bank[i].name<< " " << bank[i].accNum << endl;
	}
	bank.clear();
	///part b of task 1
	accountInfo.open(fileName);
	if (!accountInfo)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!accountInfo.eof())
	{
		string personName;
		int num;
		accountInfo >> personName;
		accountInfo >> num;
		BankAccount holder = {personName,num};
		bank.push_back(holder);
	}
	cout << "part b"<<endl;
	for (int i = 0; i < bank.size(); i++)
	{
		cout << bank[i].name << " " << bank[i].accNum << endl;
	}
	accountInfo.close();
}

void taskTwo(ifstream& accountInfo, vector<BankAccounts>& bank, string fileName)
{
	if (!accountInfo)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!accountInfo.eof())
	{
		string personName;
		int num;
		accountInfo >> personName;
		accountInfo >> num;
		BankAccounts holder(personName, num);
		bank.push_back(holder);
	}
	cout << " " << endl;
	cout << "part b" << endl;
	for (int i = 0; i < bank.size(); i++)
	{
		cout << bank[i] << endl;
	}
	cout << " " << endl;
	cout << "part c" << endl;
	for (int i = 0; i < bank.size(); i++)
	{
		cout << bank[i] << endl;
	}
	accountInfo.close();
	bank.clear();
	accountInfo.open(fileName);
	if (!accountInfo)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!accountInfo.eof())
	{
		string personName;
		int num;
		accountInfo >> personName;
		accountInfo >> num;
		bank.push_back(BankAccounts(personName,num));
	}
	cout << " " << endl;
	cout << "part d" << endl;
	for (int i = 0; i < bank.size(); i++)
	{
		cout << bank[i] <<endl;
	}
	accountInfo.close();
	bank.clear();
	accountInfo.open(fileName);
	if (!accountInfo)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!accountInfo.eof())
	{
		string personName;
		int num;
		accountInfo >> personName;
		accountInfo >> num;
		bank.emplace_back(personName, num);
	}
	cout << " " << endl;
	cout << "part e" << endl;
	for (int i = 0; i < bank.size(); i++)
	{
		cout << bank[i] << endl;
	}
	accountInfo.close();
}

void taskThree(ifstream& accountInfo, vector<BankAccounts>& bank, string fileName)
{
	if (!accountInfo)
	{
		cerr << "Could not open the file.\n";
		exit(1);
	}
	while (!accountInfo.eof())
	{
		string command;
		int val;
		int num;
		accountInfo >> command;
		cout << "task3";
		if (command == "Account")
		{
			string name;
			int accNum;
			accountInfo >> name;
			accountInfo >> accNum;
			for (int i = 0; i < bank.size(); i++)
			{
				if (bank[i].getAccNum() == accNum && bank[i].getName() == name)
				{
					cout << bank[i] << endl;
				}
			}

		}
		accountInfo >> command;
		if (command == "Deposit")
		{
			accountInfo >> num;
			accountInfo >> val;
			deposits(num, val, bank);
		}
		accountInfo >> command;
		if (command == "Withdraw")
		{
			accountInfo >> num;
			accountInfo >> val;
			withdrawal(num, val, bank);
		}
		accountInfo.close();
		
	}
}

void deposits(int accNum, int val, vector<BankAccounts>& bank)
{
	for (int i = 0; i < bank.size(); i++)
	{
		if (bank[i].getAccNum() == accNum)
		{
			bank[i].deposit(val);
			cout << bank[i]<< endl;
		}
	}
	
}

void withdrawal(int accNum, int val, vector<BankAccounts>& bank)
{
	for (int i = 0; i < bank.size(); i++)
	{
		if (bank[i].getAccNum() == accNum)
		{
			bank[i].withdraw(val);
			cout << bank[i] << endl;
		}
	}
}


