#include <iostream>
#include <string>

class Account {
	private:
		    const std::string _holder;
		        int _balance = 0;

				
	public:
			    void print() {
				            std::cout << "Account of: " << _holder << " has balance: " << _balance << std::endl;
					        }

			        bool deposit(int ammount) {
					        _balance += ammount;
						    }

				    bool withdraw(int ammount) {
					            _balance -= ammount;
						        }

				        Account(std::string holder)
						        : _holder(holder) {
								    }

					    Account(std::string holder, int balance)
						            : _holder(holder)
							              , _balance(balance) {
									          }
};

class Loan {
	private:
		    Account& _parent;

		        int _ammount;

	public:

			    Loan(Account& parent, int ammount)
				            : _parent(parent)
					              , _ammount(ammount) {
							              _parent.deposit(ammount);
								          }

			        void payoff(int ammount) {
					        _parent.withdraw(ammount);
						    }

				    ~Loan() {
					            payoff(_ammount);
						        }
};

int main() {
	    Account account("Petr");
	        account.print();
		    {
			            Loan loan(account, 1000);
				            account.print();
					        }
		        account.print();
}

