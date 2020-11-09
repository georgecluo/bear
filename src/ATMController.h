

class ATMController {

  public:
    ATMController() {}

    // One Step
    void Do();

    // Card has been inserted
    // card_id is the unique identifier of this user's card. In reality, it wouldn't be one int.
    bool InsertCard();

    void PromptPIN();

    int GetAccountBalance(int card_id, int pin);

    void ViewBalance();
    void DepositCash();
    void WithdrawCash();
    int GetIntegerInput();

  private:
    int card_id_ = -1;
    int account_balance_ = 0;
};
