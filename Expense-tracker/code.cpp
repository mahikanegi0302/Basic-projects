// Expense Tracker
// │
// ├── Expense class
// │   ├── id
// │   ├── date
// │   ├── category
// │   ├── amount
// │   └── description
// │
// ├── ExpenseManager class
// │   ├── addExpense()
// │   ├── viewExpenses()
// │   ├── searchExpense()
// │   ├── updateExpense()
// │   ├── deleteExpense()
// │   ├── totalSpending()
// │   ├── monthlySummary()
// │   ├── categorySummary()
// │   ├── saveToCSV()
// │   ├── loadFromCSV()
// │   └── openCSV()
// │
// └── main()
//     └── Menu + user input

#include <bits/stdc++.h>
using namespace std;
class expense {
    string name;
    double amount;
    string expense_id;
    string expense_date;
    string description;
    string category;
public:
    expense(string name, double amount, string expense_id, string expense_date, string description, string category) {
        this->name=name;
        this->amount=amount;
        this->expense_id=expense_id;
        this->expense_date=expense_date;
        this->description=description;
        this->category=category;
    }
    string getName(){
        return name;
    }
    double getAmount(){
        return amount;
    }
    string getExpenseId(){
        return expense_id;
    }
    string getDate(){
        return expense_date;
    }
    string getCategory(){
        return category;
    }
    string getDescription() {
        return description;
    }
    void setDate(string date){
    expense_date=date;
    }
    void setCategory(string category){
    this->category=category;
    }
    void setAmount(double amount){
    this->amount=amount;
    }
    void setDescription(string description){
    this->description=description;
    }

};

int main() {
    

    return 0;
}