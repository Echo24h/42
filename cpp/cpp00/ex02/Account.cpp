#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>


// static variables initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


// constructor(s)
Account::Account(int initial_deposit) {
	static int index;

	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = index++;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";created\n";
}


// destructor
Account::~Account(void) {
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed\n";
}


// static member functions
int		Account::getNbAccounts( void )		{ return (Account::_nbAccounts); }
int		Account::getTotalAmount( void )		{ return (Account::_totalAmount); }
int		Account::getNbDeposits( void )		{ return (Account::_totalNbDeposits); }
int		Account::getNbWithdrawals( void )	{ return (Account::_totalNbWithdrawals); }


void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout
		<< " accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals << "\n";
}


// member functions
void	Account::makeDeposit( int deposit ) {
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << "\n";
}


bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	if (withdrawal <= 0 || withdrawal > this->_amount) {
		std::cout
			<< " index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:refused\n";
		return (false);
	} else {
		int p_amount = this->_amount;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		std::cout
			<< " index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals << "\n";
		return (true);
	}
}


int		Account::checkAmount( void ) const {
	return (this->_amount);
}


void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout
		<< " index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << "\n";
}


// private static member functions
void	Account::_displayTimestamp( void ) {
	time_t t = time(nullptr);
	std::tm * time = std::localtime(&t);
	std::cout << "[" << std::put_time(time, "%Y%m%d %H%M%S") << "]";
}
