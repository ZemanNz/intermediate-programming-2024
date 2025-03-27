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
							if(ammount < 0){
								return false;
							}
					        _balance += ammount;
							return true;
						    }

				    bool withdraw(int ammount) {
								if(ammount > _balance){
									return false;
								}
					            _balance -= ammount;
								return true;
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
	    Account account("Petr", 100);
	        account.print();
		    {
			            Loan loan(account, 1000);
				            account.print();
					        }
				std::cout << account.deposit(100) << std::endl;
				std::cout << account.withdraw(1000) << std::endl;
		        account.print();
}

