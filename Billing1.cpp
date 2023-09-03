#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision

using namespace std;

//Named constants - residential costumers
const double RES_BILL_PROC_FEES = 4.50;
const double RES_BASIC_SERV_COST = 20.50;
const double RES_COST_PREM_CHANNEL = 7.50;

//Named constants - business customers
const double BUS_BILL_PROC_FEES = 15.00;
const double BUS_BASIC_SERV_COST = 75.00;
const double BUS_BASIC_CONN_COST = 5.00;
const double BUS_COST_PREM_CHANNEL = 50.00;


int main(int argc, char **argv) {

  int accountNumber; //variable to store costumer's account number

  char customerCode; //variable to store costumer's code
  int numOfPremChannels; //variable to store the number of Premium Channels costumer has

  int numOfBasicServConn; //variable to store the numver of basic service connections

  double amountDue; //variable to store the billing amount
  bool validAccountCode = false;
  bool businessCode = false;

  cout << "Please enter the customer account number\n";
  cin >> accountNumber;

  while (!validAccountCode) {
    cout << "Please enter the customer code (r|R for residential or b|B for business)\n";
    cin >> customerCode;

    switch (customerCode)
    {
    case 'r':
    case 'R':
      validAccountCode = true;
      break;
    case 'b':
    case 'B':
      validAccountCode = true;
      businessCode = true;
      break;
    default:
      cout << "Error:  An invalid customer code of " << customerCode << " was entered.\n";
    }
  }

  if (businessCode) {
    cout << "Please enter the number of basic connections\n";
    cin >> numOfBasicServConn;
  }

  cout << "Please enter the number of Premium channels\n";
  cin >> numOfPremChannels;

  if (businessCode) {
    if (numOfBasicServConn <= 10) {
      amountDue = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST + numOfPremChannels * BUS_COST_PREM_CHANNEL;
    } else {
      amountDue = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST + (numOfBasicServConn - 10) * BUS_BASIC_CONN_COST + numOfPremChannels * BUS_COST_PREM_CHANNEL;
    }
  } else {
    amountDue = RES_BILL_PROC_FEES + RES_BASIC_SERV_COST +      numOfPremChannels * RES_COST_PREM_CHANNEL;
  }

  cout << "Customer Account: " << accountNumber << "\nBilling Amount:  " << fixed << setprecision(2) << amountDue;

  return 0;
}
