#include "Account.hpp"
#include <iostream>
using std::cout;
using std::endl;


int		Account::_nbAccounts;
int		Account::_totalAmount;
int		Account::_totalNbDeposits;
int		Account::_totalNbWithdrawals;

Account::Account( int initial_deposit ) :
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits 
		<< ";withdrawals:" << _totalNbWithdrawals << endl;
}


void Account::displayStatus(void) const {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" 
		<< _nbWithdrawals << endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal) {
		cout << "refused" << endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << endl;
	return true;
}

void Account::_displayTimestamp( void )
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
}
