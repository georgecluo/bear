#include "ATMController.h"

#include <iostream>
#include <string>

// Idle state, no customer.
void ATMController::Do() {
    if (card_id_ == -1) {
        // no session started
        std::cout << "Please insert your card (Represented by a 64 bit integer card ID): ";
        bool is_card_good = InsertCard();
        std::cout << std::endl;
        if (is_card_good) {
            PromptPIN();
        } else {
            std::cout << "Invalid card. Please take your card and retry." << std::endl;
            // TODO: instruct ATM to reject physical card.
        }
    } else {
        // session started
        std::cout << "Please enter your command, 1=View Balance, 2=Deposit, 3=Withdrawal, 4=End Session: ";
        int command = GetIntegerInput();
        switch (command) {
            case 1:
                ViewBalance();
                break;
            case 2:
                DepositCash();
                break;
            case 3:
                WithdrawCash();
                break;
            case 4:
                card_id_ = -1;
                account_balance_ = 0;
                std::cout << "Session Ended. Please take your card!" << std::endl;
                // TODO: end session with bank
                break;
            default:
                std::cout << "Error, Invalid command." << std::endl;
                break;
        }
    }
}

// Card has been inserted
// card_id is the unique identifier of this user's card. In reality, it wouldn't be one int.
bool ATMController::InsertCard() {
    int input_id = GetIntegerInput();
    if (input_id > 0) {
        std::cout << "Hi! Please keep your card inserted." << std::endl;
        // TODO: verify card_id with bank
        card_id_ = input_id;
        return true;
    } else {
        return false;
    }
}

void ATMController::PromptPIN() {
    std::cout << "Please enter your 4-digit PIN: " << std::endl;
    std::string pin_string;
    int success = false;
    int tries = 0;
    int pin_int = -1;
    while (!success && tries < 3) {
      pin_int = GetIntegerInput();
      tries++;
      // TODO: should 0001 be considered equivalent to 1?
      if (pin_int < 0 || pin_int > 9999) {
          std::cout << "Invalid PIN, please try again: ";
      } else {
          success = true;
      }
    }
    std::cout << std::endl;
    if (success) {
        account_balance_ = GetAccountBalance(card_id_, pin_int);
    } else {
        std::cout << "Too many invalid PINs. Session ending, please take your card." << std::endl;
    }
}

int ATMController::GetAccountBalance(int card_id, int pin) {
    // TODO: verify card_id and PIN with bank
    return 0;
}

void ATMController::ViewBalance() {
    std::cout << "Your Balance: " << account_balance_ << std::endl;
}

void ATMController::DepositCash() {
    std::cout << "Please enter the amount of cash you wish to deposit: ";
    int deposit = GetIntegerInput();
    std::cout << std::endl;
    if (deposit < 0) {
        std::cout << "Deposits must be a positive integer." << std::endl;
        return;
    }
    if (account_balance_ + deposit < account_balance_) {
        std::cout << "Integer overflow. You have too much money." << std::endl;
        return;
    }
    account_balance_ += deposit;
}

void ATMController::WithdrawCash() {
    std::cout << "Please enter the amount of cash you wish to withdraw: ";
    int withdrawal = GetIntegerInput();
    if (withdrawal < 0) {
        std::cout << "Withdrawals must be a positive integer." << std::endl;
        return;
    }
    if (account_balance_ - withdrawal < 0) {
        std::cout << "Not enough money in your account." << std::endl;
        return;
    }
    account_balance_ -= withdrawal;
}

int ATMController::GetIntegerInput() {
    std::string string_in;
    std::cin >> string_in;
    try {
        return std::stoi(string_in);
    }
    catch (const std::out_of_range& oor) {
        std::cout << "Invalid entry, out of range." << std::endl;
        return -1;
    }
    catch ( const std::exception& e )
    {
        std::cout << "Invalid entry, must be an integer." << std::endl;
        return -1;
    }
}
