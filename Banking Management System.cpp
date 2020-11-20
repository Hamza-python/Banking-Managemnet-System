#include<iostream>
using namespace std;

struct customerinfoNode{
	customerinfoNode* prev_node_address;
	string cust_name;
	string cust_cnic;
	int cust_age;
	int cust_account_no;			
	customerinfoNode* next_node_address;			
};

struct customerMoneyNode{
	customerMoneyNode* prev_node_address;
	int cust_account_no;
	int cust_account_balance;
	int deposite_money;			
	customerMoneyNode* next_node_address;			
};
class customerinfo{
	public:
		customerinfoNode* head;
		customerinfoNode* tail;
		
	customerinfo()
	{
		head = NULL;
		tail = NULL;
	}
	void createinfoNode(string cust_name, string cust_cnic, int cust_age,int cust_account_no)
	{
		customerinfoNode *temp = new customerinfoNode;
		temp->prev_node_address = NULL;
		temp->cust_name = cust_name;
		temp->cust_cnic = cust_cnic;
		temp->cust_age = cust_age;
		temp->cust_account_no = cust_account_no;
		temp->next_node_address = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			head -> next_node_address = tail;
			tail -> prev_node_address = head;
		}
		else
		{
			customerinfoNode *currentNode = new customerinfoNode;
			currentNode = head;
			while (currentNode -> next_node_address != head)
			{
				currentNode  = currentNode->next_node_address;
			}
			
			currentNode -> next_node_address = temp;
			temp -> prev_node_address = currentNode;
			tail = temp;
			tail -> next_node_address = head;
			head -> prev_node_address = tail;
			
		}
	}
	bool searchinfoNode(int value)
	{
		customerinfoNode *temp=new customerinfoNode;
		temp = head;
		bool isvalid = false;
		if (temp == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp->next_node_address!=head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}				
				else  if (temp->cust_account_no==value)
				{
					isvalid = true;
					cout<<"Congratulation!!!!"<<endl<<"yor are successfully login"<<endl;
					break; 
				}	
			}
			if (temp->next_node_address == head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}
				else  if (temp->cust_account_no==value)
				{
					isvalid = true;
					cout<<"Congratulation!!!!"<<endl<<"yor are successfully login"<<endl;
				}
			}
	
		}
		return isvalid;
	}
	
	bool searchinfoDataNode(int value)
	{
		customerinfoNode *temp=new customerinfoNode;
		temp = head;
		bool isvalid = false;
		if (temp == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp->next_node_address!=head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}				
				else  if (temp->cust_account_no==value)
				{
					isvalid = true;
//					cout<<"Congratulation!!!!"<<endl<<"yor are successfully login"<<endl;
					cout<< "Customer's Name: " <<temp->cust_name<<endl;
					cout<< "Customer's CNIC: " <<temp->cust_cnic<<endl;
					cout<< "Customer's Age: " <<temp->cust_age<<endl;
					cout<< "Accoutn No: " <<temp->cust_account_no<<endl;
					break; 
				}	
			}
			if (temp->next_node_address == head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}
				else  if (temp->cust_account_no==value)
				{
					isvalid = true;
//					cout<<"Congratulation!!!!"<<endl<<"yor are successfully login"<<endl;
					cout<< "Customer's Name: " <<temp->cust_name<<endl;
					cout<< "Customer's CNIC: " <<temp->cust_cnic<<endl;
					cout<< "Customer's Age: " <<temp->cust_age<<endl;
					cout<< "Account No: " <<temp->cust_account_no<<endl;
				}
			}
	
		}
		return isvalid;
	}
	void del_specific_info_Node(int value)
	{	
		if (head->cust_account_no==value)
		{
			customerinfoNode *temp=new customerinfoNode;
			temp=head;
			head=head->next_node_address;
			head->prev_node_address=tail;
			tail->next_node_address=head;
			delete temp;
		}
		else if(tail->cust_account_no==value)
		{
		customerinfoNode *temp=new customerinfoNode;
		temp=tail->prev_node_address;
		temp->next_node_address=head;
		tail=temp;
		head->prev_node_address=tail;
		}
		else		
		{
			customerinfoNode *deletion=new customerinfoNode;
			customerinfoNode *nextNode=new customerinfoNode;
			customerinfoNode *previousNode=new customerinfoNode;
			customerinfoNode *temp=new customerinfoNode;
			temp=head;
		
			while (temp->next_node_address!=head)
			{
				if (temp->cust_account_no==value)
				{
					deletion=temp;
				}
				temp=temp->next_node_address;
			}
		
			nextNode=deletion->next_node_address;
			previousNode=deletion->prev_node_address;
		
			nextNode->prev_node_address=deletion->prev_node_address;		
			previousNode->next_node_address=deletion->prev_node_address;
	
		
			deletion->next_node_address=NULL;
			deletion->prev_node_address=NULL;
		}
	
	}
	void display_customerinfo()
	{
		customerinfoNode *temp = new customerinfoNode;
		temp = head;
		while (temp -> next_node_address != head)
		{
			cout<<"========================================================="<<endl;
			cout<<"Customer Name ="<<temp->cust_name<<endl;
			cout<<"Customer CNIC ="<<temp->cust_cnic<<endl;
			cout<<"Customer Age = "<<temp->cust_age<<endl;
			cout<<"Customer Account number = "<<temp->cust_account_no<<endl;
			temp = temp -> next_node_address;
		}
		cout<<"========================================================="<<endl;
		cout<<"Customer Name ="<<temp->cust_name<<endl;
		cout<<"Customer CNIC ="<<temp->cust_cnic<<endl;
		cout<<"Customer Age = "<<temp->cust_age<<endl;
		cout<<"Customer Account number = "<<temp->cust_account_no<<endl;
//		cout<<"========================================================="<<endl;
	}
};
class customerMoney{
	public:
		customerMoneyNode* head;
		customerMoneyNode* tail;
		
	customerMoney()
	{
		head = NULL;
		tail = NULL;
	}
	void createMoneyNode(int cust_account_no, int cust_account_balance)
	{
		customerMoneyNode *temp = new customerMoneyNode;
		temp->prev_node_address = NULL;
		temp->cust_account_no = cust_account_no;
		temp->cust_account_balance = cust_account_balance;
		temp->next_node_address = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			head -> next_node_address = tail;
			tail -> prev_node_address = head;

		}
		else
		{
			customerMoneyNode *currentNode = new customerMoneyNode;
			currentNode = head;
			while (currentNode -> next_node_address != head)
			{
				currentNode  = currentNode->next_node_address;
			}
			
			currentNode -> next_node_address = temp;
			temp -> prev_node_address = currentNode;
			tail = temp;
			tail -> next_node_address = head;
			head -> prev_node_address = tail;
			
		}
	}
	void deposite_money(int value,int money)
	{
		customerMoneyNode *temp=new customerMoneyNode;
		temp = head;
		if (temp == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp->next_node_address!=head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}				
				else  if (temp->cust_account_no==value)
				{
					temp->cust_account_balance = temp->cust_account_balance + money;
					break;	
				}
				
			}
			if (temp->next_node_address == head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}
				else  if (temp->cust_account_no==value)
				{
					temp->cust_account_balance = temp->cust_account_balance + money;	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
				}
			}
	
		}
	}
	void withdraw_money(int value,int money)
	{
		customerMoneyNode *temp=new customerMoneyNode;
		temp = head;
		if (temp == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp->next_node_address!=head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}				
				else  if (temp->cust_account_no==value)
				{
					temp->cust_account_balance = temp->cust_account_balance - money;
					break;	
				}
				
			}
			if (temp->next_node_address == head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}
				else  if (temp->cust_account_no==value)
				{
					temp->cust_account_balance = temp->cust_account_balance - money;	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
				}
			}
		}
	}
	void searchMoneyDataNode(int value)
	{
		customerMoneyNode *temp=new customerMoneyNode;
		temp = head;
		if (temp == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp->next_node_address!=head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}				
				else  if (temp->cust_account_no==value)
				{
					cout<< "Account Balance: " << temp->cust_account_balance<<endl;
					break;	
				}
				
			}
			if (temp->next_node_address == head)
			{
				if(temp->cust_account_no!=value)
				{
					temp=temp->next_node_address;
				}
				else  if (temp->cust_account_no==value)
				{
					cout<< "Account Balance: " <<temp->cust_account_balance<<endl;	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
				}
			}
	
		}
	}
	void transfer_money(int send_acc_no,int recv_acc_no,int send_money)
	{
		customerMoneyNode *temp=new customerMoneyNode;
		temp = head;
		if (temp == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp->next_node_address!=head)
			{
				if(temp->cust_account_no!=send_acc_no)
				{
					temp=temp->next_node_address;
				}				
				else  if (temp->cust_account_no==send_acc_no)
				{
					temp->cust_account_balance = temp->cust_account_balance - send_money;
					break;	
				}
			}
			if (temp->next_node_address == head)
			{
				if(temp->cust_account_no!=send_acc_no)
				{
					temp=temp->next_node_address;
				}
				else  if (temp->cust_account_no==send_acc_no)
				{
					temp->cust_account_balance = temp->cust_account_balance - send_money;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
				}
			}
	
		}
		customerMoneyNode *temp1=new customerMoneyNode;
		temp1 = head;
		if (temp1 == NULL)
		{
			cout<<"List is empty:"<<endl;
		}
		else
		{
			while (temp1->next_node_address!=head)
			{
				if(temp1->cust_account_no!=recv_acc_no)
				{
					temp1=temp1->next_node_address;
				}				
				else  if (temp1->cust_account_no==recv_acc_no)
				{
					temp1->cust_account_balance = temp1->cust_account_balance + send_money;
					break;	
				}
			}
			if (temp1->next_node_address == head)
			{
				if(temp1->cust_account_no!=recv_acc_no)
				{
					temp1=temp1->next_node_address;
				}
				else  if (temp1->cust_account_no==recv_acc_no)
				{
					temp1->cust_account_balance = temp1->cust_account_balance + send_money;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
				}
			}
	
		}
	}
	void del_specific_money_Node(int value)
	{	
		if (head->cust_account_no==value)
		{
			customerMoneyNode *temp=new customerMoneyNode;
			temp=head;
			head=head->next_node_address;
			head->prev_node_address=tail;
			tail->next_node_address=head;
			delete temp;
		}
		else if(tail->cust_account_no==value)
		{
		customerMoneyNode *temp=new customerMoneyNode;
		temp=tail->prev_node_address;
		temp->next_node_address=head;
		tail=temp;
		head->prev_node_address=tail;
		}
		else		
		{
			customerMoneyNode *deletion=new customerMoneyNode;
			customerMoneyNode *nextNode=new customerMoneyNode;
			customerMoneyNode *previousNode=new customerMoneyNode;
			customerMoneyNode *temp=new customerMoneyNode;
			temp=head;
		
			while (temp->next_node_address!=head)
			{
				if (temp->cust_account_no==value)
				{
					deletion=temp;
				}
				temp=temp->next_node_address;
			}
		
			nextNode=deletion->next_node_address;
			previousNode=deletion->prev_node_address;
		
			nextNode->prev_node_address=deletion->prev_node_address;		
			previousNode->next_node_address=deletion->prev_node_address;
	
		
			deletion->next_node_address=NULL;
			deletion->prev_node_address=NULL;
		}
	
	}
	void display_customerMoney()
	{
		customerMoneyNode *temp = new customerMoneyNode;
		temp = head;
		while (temp -> next_node_address != head)
		{
//			cout<<"Customer Account number = "<<temp->cust_account_no<<endl;
			cout<<"Customer Account balance = "<<temp->cust_account_balance<<endl;
			cout<<"========================================================="<<endl;
			temp = temp -> next_node_address;
		}
//		cout<<"Customer Account number = "<<temp->cust_account_no<<endl;
		cout<<"Customer Account balance = "<<temp->cust_account_balance<<endl;
		cout<<"========================================================="<<endl;
	}

};

int main()
{
	char ch;
	string cust_name;
	string cust_cnic;
	int cust_age;
	int cust_account_no;
	int cust_balance;
	int acc_no;
	bool x;
	x = true;
	customerinfo l1;
	customerMoney l2;
	cout<<"================================================================================================="<<endl;
	cout<<"\t\t\t\t Welcome to Banking Management System\t\t\t\t"<<endl;
	cout<<"================================================================================================="<<endl;
	do
	{
		cout<<"\n\n\t\t\t Press \"A\" to create new account.";
		cout<<"\n\n\t\t\t Press \"B\" to login as customer.";
		cout<<"\n\n\t\t\t Press \"C\" to login as Admin.";
		cout<<"\n\n\t\t\t Select Option From \"A\" \"B\" \"C\".: ";
		cin>>ch;
		switch(ch)
		{
		case 'A':
			cout<<"\nEnter customer Info:"<<endl;
			cout<<"\n\t Enter Name: ";
			cin>>cust_name;
			cout<<"\n\t Enter CNIC: ";
			cin>>cust_cnic;
			cout<<"\n\t Enter Age: ";
			cin>>cust_age;
			cout<<"\n\t Enter Account number: ";
			cin>>cust_account_no;
			cout<<"\n\t Enter Account Balance: ";
			cin>>cust_balance;
			l1.createinfoNode(cust_name,cust_cnic,cust_age,cust_account_no);
			l2.createMoneyNode(cust_account_no,cust_balance);
			cout<<""<<endl;
			cout<<"Your account has been successfully created.";
			break;
		case 'B':
			cout<<"Enter the account number to login in system: "<<endl;
			cin>>acc_no;
			if(l1.searchinfoNode(acc_no) == true)
			{
				cout<<"Login Menu"<<endl;
				char ch1;
				cout<<"\n\t Press V to view money.";
				cout<<"\n\t Press D to deposite money in account.";
				cout<<"\n\t Press T to transfer money in another account.";
				cout<<"\n\t press W to withdraw money from your account.";
				cout<<"\n\n\tSelect Your Option: ";
				cin>>ch1;
				switch(ch1)
				{
					case 'V':
						cout<<"\n";
						l1.searchinfoDataNode(acc_no);
						l2.searchMoneyDataNode(acc_no);
						break ;
					case 'D':
						int deposite_money;
						cout<<"Enter your amount you want to deposit: ";
						cin>>deposite_money;
						l2.deposite_money(acc_no,deposite_money);
						cout<<"Your Amount was successfully deposite in your account.";
						break ;
					case 'T':
						int sender_acc_no;
						int reciver_acc_no;
						int sender_amount;
						cout<<"Enter the sender account number: ";
						cin>>sender_acc_no;
						cout<<"Enter amount which you want to send: ";
						cin>>sender_amount;
						cout<<"Enter the reciver account number: ";
						cin>>reciver_acc_no;
						l2.transfer_money(sender_acc_no,reciver_acc_no,sender_amount);
						break ;
					case 'W':
						int withdraw_money;
						cout<<"Enter your amount you want to withdrawl: "<<endl;
						cin>>withdraw_money;
						l2.withdraw_money(acc_no,withdraw_money);
						cout<<"Your Amount was successfully withdrawl from your account."<<endl;
						break ;
				}	
			}
			else
			{
				cout<<"Enter correct account number for login in system.";
			}
			break;
		case 'C':
			cout<<"Login Admin"<<endl;
			char ch2;
			cout<<"\n\n\t Press L to view list of all account holders and their money in bank.";
			cout<<"\n\n\t Press D to remove any account from the system."<<endl;
			cin>>ch2;
			switch(ch2)
			{
				case 'L':
					cout<<"List of all account holders and their money in bank: \n\n";
					l1.display_customerinfo();
					l2.display_customerMoney();	
					break ;
				case 'D':
					int del_acc;
					cout<<"Enter the \"Account Number\" which you want to delete"<<endl;
					cin>>del_acc;
					l1.del_specific_info_Node(del_acc);
					l2.del_specific_money_Node(del_acc);	
					break ;
						
			}
			break;
		case 'Q':
			x = false;
			break;
		}
	}while(x == true);
	
	return 0;
}
