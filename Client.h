#pragma once

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

enum TransactionResult {
	InsufficientFunds, // ������������ �������
	NegativeAmount, // ������������� �����
	OK // ��� ��
};

struct Transaction {
	double money;
	string CounterName;
	int CounterAccountId;
	tm Time;
};

struct Account {
	int id;
	double money;
	std::vector<Transaction> Transactions;

	string ClientName; // ����� ����� ��� ������������� NewTransaction �� ���������� ��� � ���
};

struct Deposit {
	int year;
	double percent; // � ������� 1.XX..
	double body;
};

struct Credit {
	int year;
	double percent; // � ������� 1.XX..
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