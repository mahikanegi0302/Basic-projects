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
#include <fstream>
using namespace std;
class expense{
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
    void setName(string name){
    this->name=name;
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
class expensemanager{
    vector<expense> expenses;
    public:
    void addExpense(expense e){
        expenses.push_back(e);
    }
    void viewExpenses(){
        for(auto e:expenses){
            cout<<"Expense ID: "<<e.getExpenseId()<<endl;
            cout<<"Name: "<<e.getName()<<endl;
            cout<<"Amount: "<<e.getAmount()<<endl;
            cout<<"Date: "<<e.getDate()<<endl;
            cout<<"Category: "<<e.getCategory()<<endl;
            cout<<"Description: "<<e.getDescription()<<endl;
            cout<<endl;
        }
    }
    void searchExpense(string expense_id){
        for(auto e:expenses){ //e is a copy of the expense object in the vector, so we can access its members using the dot operator
            if(e.getExpenseId()==expense_id){
                cout<<"Expense ID: "<<e.getExpenseId()<<endl;
                cout<<"Name: "<<e.getName()<<endl;
                cout<<"Amount: "<<e.getAmount()<<endl;
                cout<<"Date: "<<e.getDate()<<endl;
                cout<<"Category: "<<e.getCategory()<<endl;
                cout<<"Description: "<<e.getDescription()<<endl;
                cout<<endl;
                return;
            }
        }
        cout<<"Expense not found!"<<endl;
    }
    void updateExpense(string expense_id, string name, double amount, string date, string category, string description){
        for(auto &e:expenses){ //e is a reference to the expense object in the vector, so we can modify its members using the dot operator
            if(e.getExpenseId()==expense_id){
                e.setName(name);
                e.setDate(date);
                e.setCategory(category);
                e.setAmount(amount);
                e.setDescription(description);
                cout<<"Expense updated!"<<endl;
                return;
            }
        }
        cout<<"Expense not found!"<<endl;
    }
    void deleteExpense(string expense_id){
        for(auto it=expenses.begin();it!=expenses.end();it++){
            if(it->getExpenseId()==expense_id){
                expenses.erase(it);
                cout<<"Expense deleted!"<<endl;
                return;
            }
        }
        cout<<"Expense not found!"<<endl;
    }
    void totalSpending(){
        double total=0;
        for(auto e:expenses){
            total+=e.getAmount();
        }
        cout<<"Total spending: "<<total<<endl;
    }
    void monthlySummary(int month, int year){
        double total=0;
        for(auto e:expenses){
            string date=e.getDate();
            int expense_month=stoi(date.substr(5,2)); // Extract month from date string using substr() and convert to int using stoi()
            int expense_year=stoi(date.substr(0,4));
            if(expense_month==month && expense_year==year){
                total+=e.getAmount();
            }
        }
        cout<<"Total spending in "<<month<<"/"<<year<<": "<<total<<endl;
    }
    void categorySummary(string category){
        double total=0;
        for(auto e:expenses){
            if(e.getCategory()==category){
                total+=e.getAmount();
            }
        }
        cout<<"Total spending in "<<category<<": "<<total<<endl;
    }
    void saveToCSV(string filename){
        ofstream file(filename);
        file<<"Expense ID,Name,Amount,Date,Category,Description"<<endl;
        for(auto e:expenses){
            file<<e.getExpenseId()<<","<<e.getName()<<","<<e.getAmount()<<","<<e.getDate()<<","<<e.getCategory()<<","<<e.getDescription()<<endl;
        }
        file.close();
        cout<<"Expenses saved to "<<filename<<endl;
    }
    void loadFromCSV(string filename){
        ifstream file(filename);
        string line;
        getline(file,line); // Skip header line
        while(getline(file,line)){
            stringstream ss(line);
            string expense_id,name,date,category,description;
            double amount;
            getline(ss,expense_id,',');
            getline(ss,name,',');
            ss>>amount;
            ss.ignore();
            getline(ss,date,',');
            getline(ss,category,',');
            getline(ss,description);
            expense e(name,amount,expense_id,date,description,category);
            expenses.push_back(e);
        }
        file.close();
        cout<<"Expenses loaded from "<<filename<<endl;
    }
};

int main() {
    int choice;
    expensemanager manager;
    do {
        cout << "Expense Tracker Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Search Expense" << endl;
        cout << "4. Update Expense" << endl;
        cout << "5. Delete Expense" << endl;
        cout << "6. Total Spending" << endl;
        cout << "7. Monthly Summary" << endl;
        cout << "8. Category Summary" << endl;
        cout << "9. Save to CSV" << endl;
        cout << "10. Load from CSV" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, expense_id, date, description, category;
                double amount;
                cout << "Enter expense ID: ";
                cin >> expense_id;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter amount: ";
                cin >> amount;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter category: ";
                cin >> category;
                cout << "Enter description: ";
                cin.ignore();
                getline(cin, description);
                expense e(name, amount, expense_id, date, description, category);
                manager.addExpense(e);
                break;
            }
            case 2:
                manager.viewExpenses();
                break;
            case 3: {
                string expense_id;
                cout << "Enter expense ID to search: ";
                cin >> expense_id;
                manager.searchExpense(expense_id);
                break;
            }
            case 4: {
                string expense_id, name, date, category, description;
                double amount;
                cout << "Enter expense ID to update: ";
                cin >> expense_id;
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new amount: ";
                cin >> amount;
                cout << "Enter new date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter new category: ";
                cin >> category;
                cout << "Enter new description: ";
                cin.ignore();
                getline(cin, description);
                manager.updateExpense(expense_id, name, amount, date, category, description);
                break;
            }
            case 5:
            {
                string expense_id;
                cout << "Enter expense ID to delete: ";
                cin >> expense_id;
                manager.deleteExpense(expense_id);
                break;
            }
            case 6:
                manager.totalSpending();
                break;
            case 7:
            {
                int month, year;
                cout << "Enter month (1-12): ";
                cin >> month;
                cout << "Enter year (YYYY): ";
                cin >> year;
                manager.monthlySummary(month, year);
                break;
            }
            case 8:
            {
                string category;
                cout << "Enter category: ";
                cin >> category;
                manager.categorySummary(category);
                break;
            }
            case 9:
            {
                string filename;
                cout << "Enter filename to save (e.g., expenses.csv): ";
                cin >> filename;
                manager.saveToCSV(filename);
                break;
            }
            case 10:
            {
                string filename;
                cout << "Enter filename to load (e.g., expenses.csv): ";
                cin >> filename;
                manager.loadFromCSV(filename);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}