# Bear question

Build instructions:
If using the bazel compiler, do

bazel build //bear:ATMDriver

You may test the program by following the prompts.

* "Card ID" - represents the data stored on the card (chip, magnetic stripe). In this situation, on a 64 bit platform, it's abstracted as a 32 bit positive integer.
* "PIN" - a 4 digit pin, numeric only. In this situation, 0007 is equivalent to 7.
* "Balance / Deposit / Withdrawal" - A number that represents a monetary amount. Must be a 32 bit positive integer.

