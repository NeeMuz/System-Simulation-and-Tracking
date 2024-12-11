using System;

public class BankAccount
{
    public int AccountNumber { get; private set; }
    public string Password { get; private set; }
    public decimal Balance { get; private set; }

    public BankAccount(int accountNumber, string password, decimal initialDeposit)
    {
        AccountNumber = accountNumber;
        Password = password;
        Balance = initialDeposit;
    }

    public void Deposit(decimal amount)
    {
        Balance += amount;
    }

    public bool Withdraw(decimal amount)
    {
        if (Balance >= amount)
        {
            Balance -= amount;
            return true;
        }
        return false;
    }
}

public class ATM
{
    private BankAccount account;

    public void OpenAccount(int accountNumber, string password, decimal initialDeposit)
    {
        account = new BankAccount(accountNumber, password, initialDeposit);
    }

    public bool ValidatePin(string password)
    {
        return account.Password == password;
    }

    public void Deposit(decimal amount)
    {
        account.Deposit(amount);
    }

    public bool Withdraw(string password, decimal amount)
    {
        if (ValidatePin(password))
        {
            return account.Withdraw(amount);
        }
        return false;
    }

    public decimal CheckBalance()
    {
        return account.Balance;
    }
}

public class Program
{
    public static void Main()
    {
        ATM atm = new ATM();

        atm.OpenAccount(987654, "1234", 1000.00m);
        Console.WriteLine("Account opened with a balance of 1000.00");

        atm.Deposit(500.00m);
        Console.WriteLine("Balance after deposit: " + atm.CheckBalance());

        bool success = atm.Withdraw("1234", 300.00m);
        Console.WriteLine(success ? "Cash withdrawal successful" : "Insufficient funds or incorrect PIN");

        Console.WriteLine("Current balance: " + atm.CheckBalance());
    }
}
