//Adding Required Header Files 
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill()
    {
        Item = "";
        Rate = 0;
        Quantity = 0;
    }

    void setItem(string item)
    {
        Item = item;
    }

    void setRate(int rate)
    {
        Rate = rate;
    }

    void setQuantity(int quantity)
    {
        Quantity = quantity;
    }

    string getItem()
    {
        return Item;
    }

    int getRate()
    {
        return Rate;
    }

    int getQuantity()
    {
        return Quantity;
    }
};

//Implementing the addItem() function to add Items into the cart
addItem(Bill b)  
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\t\t1: Add Item:" << endl;
        cout << "\t\t2: Close:" << endl;
        cout << "\t\tEnter your choice:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            string item;
            int rate, quat;

            cout << "Enter the name of the Item:" << endl;
            cin >> item;
            b.setItem(item);

            cout << "Enter the Rate of the Item:" << endl;
            cin >> rate;
            b.setRate(rate);

            cout << "Enter the Quantity of that Item to Add into Cart:" << endl;
            cin >> quat;
            b.setQuantity(quat);

            ofstream out("D:\C++ Programming\OOP in C++\BillAmount.txt", ios::app);
            if (!out)
            {
                cout << "\tError: Can't Open the File!" << endl;
            }
            else
            {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl;
            }
            out.close();
            cout << "\tItem Added Successfully!!" << endl;
            Sleep(2000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            Sleep(2000);
        }
    }
}

//Implementating the printBill() function to print the total bill of the Items added into the cart
printBill()
{
    system("cls");
    int count = 0;
    bool flag = false;
    while (!flag)
    {
        system("cls");
        int ch;
        cout << "\t\t1: Add Bill:" << endl;
        cout << "\t\t2: Close Bill:" << endl;
        cout << "\t\tEnter your choice:" << endl;
        cin >> ch;

        if (ch == 1)
        {
            string item;
            int quant;
            cout << "Enter the Item:" << endl;
            cin >> item;
            cout << "Enter the Quantity:" << endl;
            cin >> quant;

            ifstream in("D:\C++ Programming\OOP in C++\BillAmount.txt");
            ofstream out("D:\C++ Programming\OOP in C++\BillAmount Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line))
            {
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;
                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        count += amount;

                        out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
                    }
                    else
                    {
                        cout << "\tSorry, " << item << " stock is over now!" << endl;
                    }
                }
                else
                {
                    out << line << endl;
                }
            }
            if (!found)
            {
                cout << "\tItem Not Available into the shop!" << endl;
            }
            out.close();
            in.close();
            remove("D:\C++ Programming\OOP in C++\BillAmount.txt");
            rename("D:\C++ Programming\OOP in C++\BillAmount Temp.txt", "D:\C++ Programming\OOP in C++\BillAmount.txt");
        }

        else if (ch == 2)
        {
            flag = true;
            cout << "\tCounting Total Bill......" << endl;
        }
        Sleep(3000);
    }
    system("cls");
    cout << endl
         << endl;
    cout << "\t ---------------Total Bill ----------------- : " << count <<" Rs."<< endl
         << endl;
    cout << "\t\tThanks For Shopping!!" << endl;
    Sleep(3000);
}

int main()
{
    Bill b;
    bool flag = false;
    while (!flag)
    {
        system("cls");
        int ch;

        cout << "\t\t\tWelcome to our Super Market!!\t\t\t" << endl;
        cout << "\t\t*******************************************\t\t" << endl<<endl;
        cout << "\t\t1: Add Items:" << endl;
        cout << "\t\t2: Print Bill:" << endl;
        cout << "\t\t3: Exit:" << endl;
        cout << "\n\tEnter your choice:" << endl;
        cin >> ch;

        if (ch == 1)
        {
            system("cls");
            addItem(b);
            Sleep(2000);
        }
        else if (ch == 2)
        {
            printBill();
        }

        else if (ch == 3)
        {
            system("cls");
            flag = true;
            cout << "\tThanks & Visit Again!!" << endl;
            Sleep(2000);
        }
    }
    return 0;
}