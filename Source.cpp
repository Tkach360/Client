#include <iostream>
#include "Client.h"

int main() {
	Client cli = InitClient("Igor", 23, "234234");
	cout << "\n1) Test InitClient with all parameters" << endl;
	ShowInConsole(cli);

	cout << "\n2) Test NewAccount" << endl;
	NewAccount(&cli, 10000);
	NewAccount(&cli, 10000);
	ShowInConsole(cli.Accounts[0]);

	cout << "\n3) Test NewTransaction" << endl;
	NewTransaction(&cli.Accounts[0], &cli.Accounts[1], 5000);
	ShowInConsole(cli.Accounts[1].Transactions[0]);
	ShowInConsole(cli.Accounts[0].Transactions[0]);

	cout << "\n4) Test NewDeposit" << endl;
	NewDeposit(&cli, 10, 10000, 1.08);
	ShowInConsole(cli.Deposits[0]);

	cout << "\n5) Test NewCredit" << endl;
	NewCredit(&cli, 10, 10000, 1.08, 900);
	ShowInConsole(cli.Credits[0]);

	cout << "\n6) Test ShowAllTransactionsInConsole" << endl;
	ShowAllTransactionsInConsole(cli.Accounts[0]);

	cout << "\n7) Test GetFinalContributionsPayments" << endl;
	GetFinalContributionsPayments(cli.Credits[0]);

	cout << "\n8) Test GetFinalDepositAmount" << endl;
	GetFinalDepositAmount(cli.Deposits[0]);

	cout << "\n9) Test InitClientFromConsole" << endl;
	Client cli_c = InitClientFromConsole();
	ShowInConsole(cli_c);

	cout << "\n10) Test InputNewAccountFromConsole" << endl;
	InputNewAccountFromConsole(&cli_c);
	ShowInConsole(cli_c.Accounts[0]);

	cout << "\n11) Test InputNewCreditFromConsole" << endl;
	InputNewCreditFromConsole(&cli_c);
	ShowInConsole(cli_c.Credits[0]);

	cout << "\n12) Test InputNewDepositFromConsole" << endl;
	InputNewDepositFromConsole(&cli_c);
	ShowInConsole(cli_c.Deposits[0]);

	NewAccount(&cli_c, 10000);
	cout << "\n13) Test InputNewTransactionFromConsole" << endl;
	InputNewTransactionFromConsole(&cli_c.Accounts[1], &cli_c.Accounts[0]);
	ShowAllTransactionsInConsole(cli_c.Accounts[0]);
}