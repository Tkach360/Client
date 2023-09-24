#pragma once

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

enum TransactionResult {
	InsufficientFunds, // недостаточно средств
	NegativeAmount, // отрицательная сумма
	OK // все ок
};

struct Transaction {
	bool Sent;
	double Money;
	string AlterClientName;
	int AlterAccountID;
	tm Time;
};

struct Account {
	int id;
	double money;
	std::vector<Transaction> Transactions;

	string ClientName; // нужно чтобы при использовании NewTransaction не передавать ещё и имя
};

struct Deposit {
	int year;
	double percent; // в формате 1.XX..
	double body;
};

struct Credit {
	int year;
	double percent; // в формате 1.XX..
	double body;
	double contribution;
};

struct Client {
	int Age;
	string Name;
	string PhoneNumber;

	vector<Credit> Credits;
	vector<Deposit> Deposits;
	vector<Account> Accounts;
};

//--------------------------Client-----------------------------------------------

Client InitClient(string name, int age, string PhoneNumber);
Client InitClientFromConsole();
string GetName(Client client);
string GetPhoneNumber(Client client);
int GetAge(Client client);

//---------------------------------------Account--------------------------------------

void NewAccount(Client* client, double money);
void InputNewAccountFromConsole(Client* client);
int GetAccountId(Account account);
double GetMoney(Account account);

//------------------------Get-Credit-and-Deposit---------------------------------------
int GetYear(Credit credit);
int GetYear(Deposit deposit);

double GetBody(Credit credit);
double GetBody(Deposit deposit);

double GetPercent(Credit credit);
double GetPercent(Deposit deposit);

//-------------------------------------Credit-----------------------------------------

void NewCredit(Client* client, int years, double body, double percent, double contribution);
void InputNewCreditFromConsole(Client* client);

double GetContribution(Credit credit);
double GetFinalContributionsPayments(Credit credit);

//--------------------------------------Deposit------------------------------------------

void NewDeposit(Client* client, int year, double body, double percent);
void InputNewDepositFromConsole(Client* client);

double GetFinalDepositAmount(Deposit deposit);
void ShowInConsole(Deposit deposit);

//-----------------------------------------------Transaction-------------------------

void NewTransaction(Account* Account_1, Account* Account_2, double transactionMoney);
void InputNewTransactionFromConsole(Account* Account_1, Account* Account_2);
void ShowInConsole(Transaction transaction);