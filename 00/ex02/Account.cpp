#include "Account.hpp"

#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
		: _accountIndex(_nbAccounts++)
		, _amount(initial_deposit)
		, _nbDeposits(0)
		, _nbWithdrawals(0) {
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << initial_deposit
		<< ";created"
		<< std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
		<< std::endl;
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout
		<< " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;

	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount = _amount;

	if (_amount < withdrawal) {
		_displayTimestamp();
		std::cout
			<< " index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused"
			<< std::endl;

		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;

	_nbWithdrawals++;
	_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;

	return true;
}

// https://cplusplus.com/reference/ctime/strftime/
void	Account::_displayTimestamp() {
	time_t		rawtime;
	struct tm	*timeinfo;
	char		buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer;
}
