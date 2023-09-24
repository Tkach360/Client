#include <iostream>
#include "Client.h"

int main() {
	Client cli = InitClient("Igor", 23, "234234");
	NewAccount(&cli, 10000);
	NewAccount(&cli, 10000);

	NewTransaction(&cli.Accounts[0], &cli.Accounts[1], 5000);
	ShowInConsole(cli.Accounts[1].Transactions[0]);
	ShowInConsole(cli.Accounts[0].Transactions[0]);
}