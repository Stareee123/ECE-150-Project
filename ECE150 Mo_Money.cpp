#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"


// 'Tasks' are written by Jongwon (Isaac) Kim and 'Givens' are provided as a part of ECE 150 Course

// Constructor
// TASK 1
//
Transaction::Transaction( std::string ticker_symbol, unsigned int day_date, unsigned int month_date, unsigned year_date, bool buy_sell_trans, unsigned int number_shares, double trans_amount){
    symbol = ticker_symbol;
    day = day_date;
    month = month_date;
    year = year_date;
    shares = number_shares;
    amount = trans_amount;

    if (buy_sell_trans){
      trans_type = "Buy";
    }else{
      trans_type = "Sell";
    }

    trans_id = assigned_trans_id;
    assigned_trans_id = assigned_trans_id + 1;
    Transaction *p_next = get_next();
  }


// Destructor
// TASK 1
//
Transaction:: ~ Transaction(){

}




// Overloaded < operator.
// TASK 2
//
bool Transaction::operator<( Transaction const &other ){
  if (this->get_year() < other.year){
    return true;
  }else if(this->get_year() > other.year){
    return false;
  }else if(this->get_year() == other.year){
    if (this->get_month() < other.month){
      return true;
    }else if(this->get_month() > other.month){
      return false;
    }else if(this->get_month() == other.month){
      if(this->get_day() < other.day){
        return true;
      }else if(this->get_day() > other.day){
        return false;
      }else if(this->get_day() == other.day){
        if (this->get_symbol() < other.symbol){
          return true;
        }else{
          return false;
        }
      }
    }
  }
  
  return true;
}

// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK 3
//
History::History():
p_head{nullptr} {

}



// Destructor
// TASK 3
//
History::~History(){
  /*delete p_head;
  p_head = nullptr;*/

  Transaction *next_p;
  Transaction *fake_p_head;
  fake_p_head = p_head;
  bool loop_until = true;

  while(loop_until){
    if (fake_p_head != nullptr){
      next_p = fake_p_head -> get_next();
      delete fake_p_head;
      fake_p_head = next_p;
    }else{
      loop_until = false;
    }
  }
}


// read_history(...): Read the transaction history from file.
// TASK 4
//
void History::read_history(){
  ece150::open_file();
  bool loop_until = true;
  while(loop_until){
    if (ece150::next_trans_entry()){
      std::string symbol = ece150::get_trans_symbol();
      unsigned int day = ece150::get_trans_day();
      unsigned int month = ece150::get_trans_month();
      unsigned int year = ece150::get_trans_year();
      bool trans_type = ece150::get_trans_type();
      unsigned int shares = ece150::get_trans_shares();
      double amount = ece150::get_trans_amount();
      Transaction *new_p;
      new_p = new Transaction (symbol, day, month, year, trans_type, shares, amount);
      History::insert(new_p);
    }else{
      loop_until = false;
    }
  }
}

// insert(...): Insert transaction into linked list.
// TASK 5
//
void History::insert( Transaction *p_new_trans ){
  if (p_head == nullptr){
    p_head = p_new_trans;
  }else{
    Transaction *test_p;
    test_p = p_head;
    bool loop_until = true;
    while(loop_until){
      if((test_p->get_next()) != nullptr){
        test_p = test_p->get_next();
      }else{
        loop_until = false;
      }
    }
    test_p->set_next(p_new_trans);
  }


}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//
void History::sort_by_date(){

}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//
void History::update_acb_cgl(){

}


// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8
double History::compute_cgl( unsigned int year ){
  return 0;
}



// print() Print the transaction history.
//TASK 9
//
void History::print(){
  std::cout << "====== BEGIN TRANSACTION HISTORY ==========" << std::endl;
  Transaction *test_p; 
  test_p = p_head;

  bool loop_until = true;
  while(loop_until){
    if(test_p != nullptr){
      test_p -> print();
      test_p = test_p->get_next();
    }else{
      loop_until = false;
    }
  }
  std::cout << "========== END TRANSACTION HISTORY ==========" << std::endl;
}


// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }
