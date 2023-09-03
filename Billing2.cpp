#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

using namespace std;

const int CUSTOMER_CODE_RES = 1;
const int CUSTOMER_CODE_BUS = 2;

//Named constants - residential costumers
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;

//Named constants - business customers
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;

int getAccountNumber() {
  int accountNumber;
  cout << "Please enter the customer account number\n";
  cin >> accountNumber;
  return accountNumber;
}

int getCustomerCode() {
  char customerCode; //variable to store costumer's code
  int customerCodeType = -1;  // holds the definition for either residential or business customer code

  while (customerCodeType == -1) {
	cout << "Please enter the customer code (r|R for residential or b|B for business)\n";
	cin >> customerCode;

	switch (customerCode)
	{
	case 'r':
	case 'R':
	  customerCodeType = CUSTOMER_CODE_RES;
	  break;
	case 'b':
	case 'B':
	  customerCodeType = CUSTOMER_CODE_BUS;
	  break;
	default:
	  cout << "Error:  An invalid customer code of " << customerCode << " was entered.\n";
	}
  }
  return customerCodeType;
}

int getPremChannels() {
  int numOfPremChannels; //variable to store the number of Premium Channels costumer has
  cout << "Please enter the number of Premium channels\n";
  cin >> numOfPremChannels;
  return numOfPremChannels;
}

int getBasicConn() {
  int numOfBasicServConn; //variable to store the numver of basic service connections
  cout << "Please enter the number of basic connections\n";
  cin >> numOfBasicServConn;
  return numOfBasicServConn;
}

class Customer {
  private:
	  int accountNumber; //variable to store costumer's account number
	  int numOfPremChannels; //variable to store the number of Premium Channels costumer has

  public:
	  Customer(int accountNumber_, int numOfPremChannels_) {
		  accountNumber = accountNumber_;
		  numOfPremChannels = numOfPremChannels_;
	  };
	  virtual ~Customer() {};

	  int getAccountNumber() {
        return accountNumber;
	  }

	  void setAccountNumber(int accountNumber_) {
        accountNumber = accountNumber_;
	  }

	  int getNumOfPremChannels() {
		return numOfPremChannels;
	  }

	  void setNumOfPremChannels(int premChannels) {
		  numOfPremChannels = premChannels;
	  }

	  virtual double calcBill() = 0;

};

class Residential: public Customer {
  public:
	Residential(int accountNumber_, int numOfPremChannels_) : Customer(accountNumber_, numOfPremChannels_) {
	};
	~Residential() {};

	double calcBill() {
	  return (RES_BILL_PROC_FEES + RES_BASIC_SERV_COST + (getNumOfPremChannels() * RES_COST_PREM_CHANNEL));
	}
};

class Business: public Customer {
  private:
   	int numOfBasicServConn; //variable to store the numver of basic service connections

  public:
    Business(int accountNumber_, int numOfPremChannels_, int numOfBasicServConn_) : Customer(accountNumber_, numOfPremChannels_){
	  numOfBasicServConn = numOfBasicServConn_;
	};
    ~Business() {};

    double calcBill() {
      double amountDue = 0.0; //variable to store the billing amount
      if (numOfBasicServConn <= 10) {
        amountDue = (BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST + (getNumOfPremChannels() * BUS_COST_PREM_CHANNEL));
      } else {
        amountDue = (BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST +
        		((numOfBasicServConn - 10) * BUS_BASIC_CONN_COST) + (getNumOfPremChannels() * BUS_COST_PREM_CHANNEL));
      }
      return amountDue;
	}
};


int main(int argc, char **argv) {

  int accountNumber = 0; //variable to store costumer's account number
  int customerCodeType = -1;  // holds the definition for either residential or business customer code
  int numOfPremChannels = 0; //variable to store the number of Premium Channels costumer has
  int numOfBasicServConn = 0; //variable to store the number of basic service connections
  Customer *account = NULL;
  int errorCode = 0;

  accountNumber = getAccountNumber();
  customerCodeType = getCustomerCode();
  numOfPremChannels = getPremChannels();

  switch (customerCodeType) {
  case CUSTOMER_CODE_RES:
	account = new Residential(accountNumber, numOfPremChannels);
	break;
  case CUSTOMER_CODE_BUS:
	numOfBasicServConn = getBasicConn();
	account = new Business(accountNumber, numOfPremChannels, numOfBasicServConn);
	break;
  default:
	cout << "Invalid customerCodeType = " << customerCodeType;
	errorCode = -1;
  }

  if (account != NULL) {
    cout << "Customer Account: " << account->getAccountNumber()
      << "\nBilling Amount:  " << fixed << setprecision(2) << account->calcBill();
  }

  return errorCode;
}


