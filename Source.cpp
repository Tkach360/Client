#include <iostream>
#include "Client.h"

int main() {
	Client cli = InitClient("Igor", 23, "234234");
	ShowInConsole(cli);

	NewAccount(&cli, 10000);
	NewAccount(&cli, 10000);
	ShowInConsole(cli.Accounts[0]);

	NewTransaction(&cli.Accounts[0], &cli.Accounts[1], 5000);
	ShowInConsole(cli.Accounts[1].Transactions[0]);
	ShowInConsole(cli.Accounts[0].Transactions[0]);

	NewDeposit(&cli, 10, 10000, 1.08);
	ShowInConsole(cli.Deposits[0]);

	NewCredit(&cli, 10, 10000, 1.08, 900);
	ShowInConsole(cli.Credits[0]);
}