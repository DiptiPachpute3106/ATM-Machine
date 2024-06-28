#include<iostream>
using namespace std;
class ATM{
	private:
		int balance;
		int pinCode,success;
	public:
		ATM(int bal,int pin)
		{
			balance=bal;
			pinCode=pin;
		}
		int getBalance()
		{
			return balance;
		}
		int withdraw(int amount,int pin)
		{
			if(amount>balance)
			{
				return false;
			}
			balance = balance - amount;
			return true;
		}
		void deposit(int amount)
		{
			balance = balance + amount;
		}
		int transfer(int amount,ATM receiver,int pin)
		{
			if(pin!=pinCode)
			{
				return false;
			}
			success=withdraw(amount,pin);
			if(success)
			{
				receiver.deposit(amount);
				return true;
			}
			else
			{
				return false;
			}
		}
};
main()
{
	ATM atm(1000,1234);
	int choice,amount,success,pin;
	char op;
	do{
		system("cls");
		cout<<"<---------ATM--------->\n";
		cout<<"1.View Balance"<<endl;
		cout<<"2.Cash Withdraw"<<endl;
		cout<<"3.Cash Deposit"<<endl;
		cout<<"4.Cash Transfer"<<endl;
		cout<<"5.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Your Balance:"<<atm.getBalance();
				break;
			
			case 2:
				cout<<"Your Avaialble Balance:"<<atm.getBalance()<<endl;
				cout<<"Enter the amount to withdraw:";
				cin>>amount;
				success=atm.withdraw(amount,1234);
				if(success)
				{
					cout<<"Withdraw successfull..."<<endl;
				}
				else
				{
					cout<<"Insufficient balance..."<<endl;
				}
				break;
			
			case 3:
				cout<<"Enter the amount to deposit:";
				cin>>amount;
				atm.deposit(amount);
				cout<<"Deposit successfull..."<<endl;
				break;
				
			case 4:
				cout<<"Enter the amount to transfer:";
				cin>>amount;
				cout<<"Enter pin code:";
				cin>>pin;
				success=atm.transfer(amount,atm,pin);
				if(success)
				{
					cout<<"Transfer successfully..."<<endl;
	
				}
				else
				{
					cout<<"Invalid pin or insufficient balance"<<endl;
				}
				break;
				
			case 5:
				cout<<"Thanks for using ATM"<<endl;
				break;
				
			default:
				cout<<"Invalid choice"<<endl;
		}		
		cout<<"\nDo you want to try another transaction[Yes/No]:";
		cin>>op;
		
   	}while(op=='y'||op=='Y');
}


