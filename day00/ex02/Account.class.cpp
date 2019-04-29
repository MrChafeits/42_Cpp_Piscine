#include "resources/Account.class.hpp"
#include <iostream>
#include <iomanip>

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	std::cout << "index:" << _nbAccounts
			  << ";amount:" << _amount
			  << ";created" << std::endl;
	++_nbAccounts;
}

Account::Account( void ) { /* private unused? constructor */ }

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
	_nbAccounts--;
}

int Account::getNbAccounts( void ) { return _nbAccounts; }

int Account::getTotalAmount( void ) { return _totalAmount; }

int Account::getNbDeposits( void ) { return _totalNbDeposits; }

int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount + deposit
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
	this->_amount += deposit;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
}

bool Account::makeWithdrawal( int withdrawal )
{
	bool ret;
	_displayTimestamp();
	if (this->_amount >= withdrawal) {
		this->_nbWithdrawals++;
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount - withdrawal
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_totalAmount -= withdrawal;
		ret = true;
	} else {
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:refused"
				  << std::endl;
		ret = false;
	}
	return ret;
}

int Account::checkAmount( void ) const
{
	std::cout << "checkAmount" << std::endl;
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[" << ltm->tm_year + 1900
			  << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1
			  << std::setfill('0') << std::setw(2) << ltm->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << ltm->tm_hour
			  << std::setfill('0') << std::setw(2) << ltm->tm_min
			  << std::setfill('0') << std::setw(2) << ltm->tm_sec
			  << "] ";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
