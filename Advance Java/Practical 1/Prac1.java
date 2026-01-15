import pkg.NegativeBalanceException;

class Bank {

    private int balance;

    Bank(int balance) {
        this.balance = balance;
    }

    void showBalance() {
        System.out.println("Bank balance : " + balance);
    }

    void deposit(int amt) {
        balance += amt;
        System.out.println("Amount deposited");
    }

    void withdraw(int amt) throws NegativeBalanceException {

        if (amt > balance) {
            throw new NegativeBalanceException("Insufficient Balance");
        }

        balance -= amt; 
        System.out.println("Amount Withdrawn");
    }
}

public class Prac1 {
    public static void main(String[] args) {
        Bank b = new Bank(5000);

        b.deposit(100);

        try {
            b.withdraw(6000);
        } catch (NegativeBalanceException e) {
            System.out.println(e.getMessage());
        }
    }
}