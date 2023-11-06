#pragma once

#include "Client.h"
#include "Transaction.h"

using namespace std;

class Account {
	friend class Client;

private:
	int ID;
	double balance;

	Client* client;

	void setMoney(double newMoney) {
		this->balance = newMoney;
	}
	void addNewTransaction(Transaction newTransaction) {
		this->Transactions.push_back(newTransaction);
	}

public:
	vector<Transaction> Transactions;

	Account(Client* client) {
		this->client = client;
		this->balance = 0;
		this->ID = -1;
	}
	Account(Client* client, int ID) {
		this->client = client;
		this->ID = ID;
		this->balance = 0;
	}
	Account(Client* client, double balance) {
		this->client = client;
		this->balance = balance;
		this->ID = -1;
	}
	Account(Client* client, int ID, double Money) {
		this->client = client;
		this->ID = ID;
		this->balance = Money;
	}

	int getID() {
		return this->ID;
	}
	double getBalance() {
		return this->balance;
	}
	string getClientName();

	void makeTransaction(Account* alterAccount, double transactionMoney) {
		this->balance -= transactionMoney;
		alterAccount->setMoney(alterAccount->getBalance() + transactionMoney);

		Transaction NewTransactionForMyAccount(alterAccount->getClientName(), alterAccount->getID(), transactionMoney, true);
		Transaction NewTransactionForCounterAccount(alterAccount->getClientName(), this->getID(), transactionMoney, false);

		this->addNewTransaction(NewTransactionForMyAccount);
		alterAccount->addNewTransaction(NewTransactionForCounterAccount);
	}
	void inputNewTransactionFromConsole(Account* alterAccount);

	void showInConsole();

	void showAllTransactionInConsole() {
		cout << "All transaction:" << endl;
		for (Transaction transaction : Transactions)
			transaction.showInConsole();
	}

	vector<Transaction> getAllTransactions() {
		return this->Transactions;
	}
};