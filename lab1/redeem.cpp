/* COMP 11 
 * Lab 1, Spring 2017
 * Starter Code */
// Sheng Xu, Daniel Le Breton
// Jan 31,2017

#include <iostream>
using namespace std;

const int SPIDER_TICKETS = 3;
const int MINION_TICKETS = 10;

int main()
{
  int num_tickets=0, num_minions=0, num_spiders=0, left=0, need_minion=0, need_spider=0;
  char M_or_S;
// input coupon
  cout<< "How many coupons do you have" <<endl;
  cin>> num_tickets;
// minions or spider
  cout<< "Do you prefer minions? Enter Y/N" <<endl;
  cin>> M_or_S;
// number of minions and spider
  if (M_or_S == 'Y'){
    num_minions = num_tickets/MINION_TICKETS;
    num_spiders = (num_tickets%MINION_TICKETS)/SPIDER_TICKETS;
    if (num_spiders==0 & num_minions>0){
      cout << "You can redeem your coupons for " << num_minions <<  " minion dolls."<< endl;
      cout << "You have "<< left << " leftover."<<endl;   
    }
    else{
      left = num_tickets-MINION_TICKETS*num_minions-SPIDER_TICKETS*num_spiders;
      need_spider= SPIDER_TICKETS-left;
      need_minion= MINION_TICKETS-left;
      cout << "You can redeem your coupons for " << num_minions <<  " minion dolls and "
      << num_spiders<< " spider rings!"<< endl;
      cout << "You have "<< left << " leftover."<<endl;   
    }
  }
  else {
    num_spiders = num_tickets/SPIDER_TICKETS;
    left = num_tickets - SPIDER_TICKETS*num_spiders;
    need_spider= SPIDER_TICKETS-left;
    need_minion= MINION_TICKETS-left;
    cout << "You can redeem your coupons for "  << num_spiders<< " spider rings!"<< endl;
    cout << "You have "<< left << " leftover."<<endl;    
  }
  if (left==0){
      
    cout <<"You have used all your tickets, way to go! Keep playing!"<<endl;
  }
  else{
      cout << need_spider << " tickets away from a spider (and "<< need_minion<<" from a minion). Keep playing!"<< endl;
  }
}