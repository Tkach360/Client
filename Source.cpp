#include <iostream>
#include "Client.h"

int main() {
	cout << "Struct tests:" << endl;

	int test = 0;

	Client cli = InitClient("Igor", 23, "234234");
	cout << "\n" << ++test << ") Test InitClient with all parameters" << endl;
	ShowInConsole(cli);

	cout << "\n" << ++test << ") Test NewAccount" << endl;
	NewAccount(&cli, 10000);
	NewAccount(&cli, 10000);
	ShowInConsole(cli.Accounts[0]);

	cout << "\n" << ++test << ") Test NewTransaction" << endl;
	NewTransaction(&cli.Accounts[0], &cli.Accounts[1], 5000);
	ShowInConsole(cli.Accounts[1].Transactions[0]);
	ShowInConsole(cli.Accounts[0].Transactions[0]);

	cout << "\n" << ++test << ") Test NewDeposit" << endl;
	NewDeposit(&cli, 10, 10000, 1.08);
	ShowInConsole(cli.Deposits[0]);

	cout << "\n" << ++test << ") Test NewCredit" << endl;
	NewCredit(&cli, 10, 10000, 1.08, 900);
	ShowInConsole(cli.Credits[0]);

	cout << "\n" << ++test << ") Test ShowAllTransactionsInConsole" << endl;
	ShowAllTransactionsInConsole(cli.Accounts[0]);

	cout << "\n" << ++test << ") Test GetFinalContributionsPayments" << endl;
	cout << "Final contrib pay: " << GetFinalContributionsPayments(cli.Credits[0]) << endl;

	cout << "\n" << ++test << ") Test GetFinalDepositAmount" << endl;
	cout << "Final deposit amount: " << GetFinalDepositAmount(cli.Deposits[0]) << endl;

	cout << "\n" << ++test << ") Test dynamic" << endl;
	Client* cli_d = &cli;
	ShowInConsole(*cli_d);
	NewDeposit(cli_d, 20, 30000, 1.1);
	ShowInConsole(cli_d->Deposits[1]);

	cout << "\n" << ++test << ") Test InitClientFromConsole" << endl;
	Client cli_c = InitClientFromConsole();
	ShowInConsole(cli_c);

	cout << "\n" << ++test << ") Test InputNewAccountFromConsole" << endl;
	InputNewAccountFromConsole(&cli_c);
	ShowInConsole(cli_c.Accounts[0]);

	cout << "\n" << ++test << ") Test InputNewCreditFromConsole" << endl;
	InputNewCreditFromConsole(&cli_c);
	ShowInConsole(cli_c.Credits[0]);

	cout << "\n" << ++test << ") Test InputNewDepositFromConsole" << endl;
	InputNewDepositFromConsole(&cli_c);
	ShowInConsole(cli_c.Deposits[0]);

	NewAccount(&cli_c, 10000);
	cout << "\n" << ++test << ") Test InputNewTransactionFromConsole" << endl;
	InputNewTransactionFromConsole(&cli_c.Accounts[1], &cli_c.Accounts[0]);
	ShowAllTransactionsInConsole(cli_c.Accounts[0]);
}