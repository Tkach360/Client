#define _CRT_SECURE_NO_WARNINGS

#include "Client.h"
#include <regex>

using namespace std;

//------------------------------------------Input-Int-Double---------------------------------

bool verifyInt(const string& ClientAge) {
	regex ClientAgeRegex("\\d+");
	if (regex_match(ClientAge, ClientAgeRegex)) return true;
	else return false;
}

int InputInt(string message) {
	string Age;
	do {
		cout << message;
		cin >> Age;
	} while (!verifyInt(Age));
	return stoi(Age);
}

bool verifyDouble(const string& Money) {
	regex MoneyRegex("[0-9]+([.,][0-9]+)?");
	if (regex_match(Money, MoneyRegex)) {
		return true;
	}
	else return false;
}

double InputDouble(string message) {
	string Money;
	do {
		cout << message;
		cin >> Money;
	} while (!verifyDouble(Money));
	return stod(Money);
}

//------------------------------------------------Client------------------------------------------

Client InitClient(string name, int age, string PhoneNumber) {
	Client client;
	client.Name = name;
	client.Age = age;
	client.PhoneNumber = PhoneNumber;
	return client;
}

string GetName(Client client) { return client.Name; }
string GetPhoneNumber(Client client) { return client.PhoneNumber; }
int GetAge(Client client) { return client.Age; }
void SetPhoeNumber(Client* client, string PhoneNumber) {
	client->PhoneNumber = PhoneNumber;
}
void SetAge(Client* client, int Age) {
	client->Age = Age;
}
void SetName(Client* client, string Name) {
	client->Name = Name;
	for (int i = 0; i < client->Accounts.size(); i++)
		client->Accounts[i].ClientName = Name;
}

double GetAllAccountsMoney(Client client) {
	double AllAccountsMoney = 0;
	for (Account account : client.Accounts)
	{
		AllAccountsMoney += account.money;
	}
	return AllAccountsMoney;
}
void ShowInConsole(Client client) {
	cout << "Name: " + client.Name + " Age: " + to_string(client.Age) + " Phone number: " +
		client.PhoneNumber << endl;
	cout << "  Accounts: " + to_string(client.Accounts.size()) + " Credits: " +
		to_string(client.Credits.size()) + " Deposits: " + to_string(client.Deposits.size()) << endl;
}
vector<Account> GetAllAccounts(Client* client) {
	return client->Accounts;
}
vector<Deposit> GetAllDeposits(Client* client) {
	return client->Deposits;
}
vector<Credit> GetAllCredits(Client* client) {
	return client->Credits;
}
vector<Transaction> GetAllTransactions(Client *client) {
	vector<Transaction> AllTransactions;
	for (Account account : client->Accounts)
		AllTransactions.insert(AllTransactions.end(), account.Transactions.begin(), account.Transactions.end());
	return AllTransactions;
}

//---------------------------------InputClientFromConsole------------------------------------

bool verifyClientName(const string& ClientName) {
	regex ClientNameRegex("^[A-Za-z]*\\s[A-Za-z]*$"); ///////
	cout << regex_match(ClientName, ClientNameRegex) << endl;
	if (regex_match(ClientName, ClientNameRegex)) return true;
	else return false;
}

string InputClientName(string message) {
	string ClientName;
	do {
		cout << message;
		getline(cin, ClientName);
	} while (!verifyClientName(ClientName));
	return ClientName;
}

bool verifyClientPhoneNumber(const string& PhoneNumber) {
	regex PhoneNumberRegex("\\d{1}-\\d{3}-\\d{3}-\\d{2}-\\d{2}");
	if (regex_match(PhoneNumber, PhoneNumberRegex)) return true;
	else return false;
}

string InputClientPhoneNumber(string message) {
	string PhoneNumber;
	do {
		cout << message;
		cin >> PhoneNumber;
	} while (!verifyClientPhoneNumber(PhoneNumber));
	return PhoneNumber;
}

Client InitClientFromConsole() {
	Client NewClient;
	string Name, PhoneNumber;
	int Age;
	NewClient.Name = InputClientName("Enter the name of the new client (First Name Last Name): ");
	NewClient.Age = InputInt("Enter the age of the new client: ");
	NewClient.PhoneNumber = InputClientPhoneNumber("Enter the phone number of the new client (X-XXX-XXX-XX-XX): ");

	cout << "Client successfully registered" << endl;
	return NewClient;
}

//---------------------------------------Account-----------------------------------------

Account InitAccount(double money) {
	Account newAccount;
	newAccount.money = money;
	return newAccount;
}

void NewAccount(Client* client, double money) {
	Account newAccount = InitAccount(money);
	newAccount.id = client->Accounts.size();

	newAccount.ClientName = client->Name; //

	client->Accounts.push_back(newAccount);
}

int GetAccountId(Account account) { return account.id; }
double GetMoney(Account account) { return account.money; }
void ShowInConsole(Account account) {
	string Info = "Client: " + account.ClientName + " num: " + to_string(account.id) +
		" balance: " + to_string(account.money);
	cout << Info << endl;
}
void ShowAllTransactionInConsole(Account account) {
	cout << "All transaction:" << endl;
	for (Transaction transaction : account.Transactions)
		ShowInConsole(transaction);
}
vector<Transaction> GetAllTransactions(Account account) {
	return account.Transactions;
}

//---------------------------------------InputNewAccountFromConsole-----------------------------------

void InputNewAccountFromConsole(Client* client) {
	double money = InputDouble("Enter the initial amount in the account: ");
	NewAccount(client, money);

	cout << "Account created successfully" << endl;
}

//-------------------------------------Get-functions-Credit-and-Deposit--------------------------

int GetYear(Credit credit) { return credit.year; }
int GetYear(Deposit deposit) { return deposit.year; }

double GetBody(Credit credit) { return credit.body; }
double GetBody(Deposit deposit) { return deposit.body; }

double GetPercent(Credit credit) { return credit.percent; }
double GetPercent(Deposit deposit) { return deposit.percent; }

//-------------------------------------Credit-----------------------------------------------------

Credit InitCredit(int year, double body, double percent, double contribution) {
	Credit newCredit;
	newCredit.year = year;
	newCredit.body = body;
	newCredit.percent = percent;
	newCredit.contribution = contribution;
	return newCredit;
}

void NewCredit(Client* client, int year, double body, double percent, double contribution) {
	Credit newCredit = InitCredit(year, body, percent, contribution);
	client->Credits.push_back(newCredit);
}

double GetContribution(Credit credit) { return credit.contribution; }
double GetFinalContributionsPayments(Credit credit) {
	double FinalContributionsPayments = 0;
	int years = GetYear(credit);
	double body = GetBody(credit);
	double percent = GetPercent(credit);
	double contribution = GetContribution(credit);
	for (int i = 0; i < years; i++) {
		if (body < contribution) {
			FinalContributionsPayments += body;
			body = 0;
		}
		else {
			FinalContributionsPayments += contribution;
			body -= contribution;
			body *= percent;
		}
	}
	return FinalContributionsPayments;
}
void ShowInConsole(Credit credit) {
	string Info = "Credit year: " + to_string(credit.year) + " body: " + to_string(credit.body) +
		" percent: " + to_string(credit.percent) + " contribution: " + to_string(credit.contribution);
	cout << Info << endl;
}

bool CheckCredit(Credit credit) {
	if (credit.body * (credit.percent - 1) >= credit.contribution || credit.percent < 1) return false;
	return true;
}

//--------------------------------------InputNewCreditFromConsole-------------------------------------

void InputNewCreditFromConsole(Client* client) {
	int year = InputInt("Enter the number of years for which you want to take out a loan: ");
	double body = InputDouble("Enter the loan amount: ");
	double percent;
	do {
		percent = InputDouble("Enter the loan interest (1.XX..): ");
		if (percent < 1) cout << "percentage cannot be less than 1" << endl;
	} while (percent < 1);
	double contribution = InputDouble("Enter the monthly payment amount: ");
	NewCredit(client, year, body, percent, contribution);

	cout << "Loan taken successfully" << endl;
}

//----------------------------------NewDeposit-----------------------------------------------------

Deposit InitDeposit(int year, double body, double percent) {
	Deposit newDeposit;
	newDeposit.year = year;
	newDeposit.body = body;
	newDeposit.percent = percent;
	return newDeposit;
}

void NewDeposit(Client* client, int year, double body, double percent) {
	Deposit newDeposit = InitDeposit(year, body, percent);
	client->Deposits.push_back(newDeposit);
}
double GetFinalDepositAmount(Deposit deposit) {
	int years = GetYear(deposit);
	double body = GetBody(deposit);
	double percent = GetPercent(deposit);

	for (int i = 0; i < years; i++) {
		body *= percent;
	}
	return body;
}
void ShowInConsole(Deposit deposit) {
	string Info = "Deposit year: " + to_string(deposit.year) + " body: " + to_string(deposit.body) +
		" percent: " + to_string(deposit.percent);
	cout << Info << endl;
}

//----------------------------------------InputNewDepositFromConsole------------------------------------

void InputNewDepositFromConsole(Client* client) {
	int year = InputInt("Enter the number of years for which you want to open a deposit: ");
	double body = InputDouble("Enter the deposit amount: ");
	double percent;
	do {
		percent = InputDouble("Enter the interest accrued per year on the deposit (1.XX..): ");
		if (percent < 1) cout << "percentage cannot be less than 1" << endl;
	} while (percent < 1);
	NewDeposit(client, year, body, percent);

	cout << "Money has been successfully deposited" << endl;
}

//------------------------------------------NewTransaction--------------------------------------------

Transaction InitTransaction(Account account, string AlterClientName, double money, bool Sent) {
	Transaction newTransaction;
	newTransaction.Money = money;
	newTransaction.AlterClientName = AlterClientName;
	newTransaction.AlterAccountID = GetAccountId(account);
	newTransaction.Sent = Sent;

	time_t now = time(NULL);
	newTransaction.Time = (*localtime(&now));

	return newTransaction;
}

void NewTransaction(Account* Account_1, Account* Account_2, double transactionMoney) {

	Account_1->money -= transactionMoney;
	Account_2->money += transactionMoney;

	Transaction newTransactionForAccount_1 = InitTransaction(*Account_2, Account_1->ClientName, transactionMoney, false);
	Transaction newTransactionForAccount_2 = InitTransaction(*Account_1, Account_2->ClientName, transactionMoney, true);

	Account_1->Transactions.push_back(newTransactionForAccount_1);
	Account_2->Transactions.push_back(newTransactionForAccount_2);
}

//-------------------------------------InputTransactionFromConsole------------------------------------

void InputNewTransactionFromConsole(Account* Account_1, Account* Account_2) {
	string message = "Enter the amount you wish to transfer from " + Account_1->ClientName +
		" account number " + to_string(Account_1->id) + " to " + Account_2->ClientName +
		" account number " + to_string(Account_2->id) + ": ";

	double transactionMoney;
	do {
		transactionMoney = InputDouble(message);
		if (transactionMoney == 0) cout << "The transfer amount cannot be zero" << endl;
	} while (transactionMoney == 0);

	NewTransaction(Account_1, Account_2, transactionMoney);
	cout << "Operation was successfully completed" << endl;
}

void ShowInConsole(Transaction transaction) {
	string strTime = to_string(transaction.Time.tm_mday) + "." + to_string(transaction.Time.tm_mon + 1) + "."
		+ to_string(transaction.Time.tm_year + 1900) + " " + to_string(transaction.Time.tm_hour) + ":" 
		+ to_string(transaction.Time.tm_min);
	string strMoney, strAlterClientName, strAlterAccountID;

	if (transaction.Sent) {
		strMoney = "-" + to_string(transaction.Money);
		strAlterClientName = "to " + transaction.AlterClientName;
	}
	else {
		strMoney = "+" + to_string(transaction.Money);
		strAlterClientName = "from " + transaction.AlterClientName;
	}

	strAlterAccountID = to_string(transaction.AlterAccountID);
	cout << "Time: " + strTime + " " + strMoney + " " + strAlterClientName + " acc. " + strAlterAccountID << endl;
}
