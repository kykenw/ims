#include <iostream>
#include <fstream>
using namespace std;

//function prototypes
char menu();
void addProduct();
void display();
void searchInventory();

int main()
{
//variables
char choice = ' ';
//choice gets assigned the return value of menu() function
choice = menu();
//while choice is not equal to 'X' this loop continues
    while(choice != 'X')
    {
        //if choice equals 'A' then run addProduct function
        if (choice == 'A')
        {
            addProduct();
        }
        //if choice equals 'D' then run display function
        else if(choice == 'D')
        {
            display();
        }
        //if choice equals 'S' then run searchInventory function
        else if(choice == 'S')
        {
            searchInventory();
        }
    //assign the return value of menu function to choice variable
    choice = menu();

    }

}
//menu function which displays a menu with options and takes input from the keyboard and returns a character
char menu()
{
    //declare variable
    char selection = ' ';

    //prompt user to enter a selection from the options
    cout << "Enter the first letter of the option you'd like" << endl;
    cout << "(A)dd new product, (D)isplay inventory, (S)earch inventory, or (X) to Exit" << endl;
    //take input from the keyboard
    cin >> selection;
    //change selection to uppercase
    selection = toupper(selection);
    //clear out empty character from cin object
    cin.ignore();
    //return selection value to choice variable in main()
    return selection;
}
//addProduct function which allows you to add new items to the inventory
void addProduct()
{
    //declare variables
    string name = "";
    string price = "";
    string location = "";
    char cont = ' ';
    //create ofstream object
    ofstream a;
    //open inventory text for appending
    a.open("inventory.txt", ios::app);
    //start post test loop
    do
    {
    //prompt user to enter a product name
    cout << "What is the product name: ";
    //get line of input from the cin object and assign to name variable
    getline(cin, name);
    //prompt user for price
    cout << "What is the price of " << name << ": ";
    //get line of input from the cin object and assign to price variable
    getline(cin, price);
    //prompt user for location
    cout << "What is the location of " << name << ": ";
    //get line of input from the cin object and assign to location variable
    getline(cin, location);
    //store information into the sequencial access file that is part of the a object
    a << name << "," << price << "," << location << endl;
    //prompt user to enter whether they would like to add another product to the inventory
    cout << "Would you like to add another product?(Y/N) ";
    //get input from keyboard and assign it to cont variable
    cin >> cont;
    //change cont to uppercase
    cont = toupper(cont);
    //clear out empty space from cin object
    cin.ignore();

    }while(cont == 'Y');//continue while cont is equal to 'Y'

}
//display function that displays all items in inventory
void display()
{
//declare local variables
int charLimit = 20;
int space = 0;
string pSpace = "";
string name = "";
string price = "";
string location = "";
//create ifstream object
ifstream d;
//open inventory.txt as an input file
d.open("inventory.txt", ios::in);
//continue while pointer is not at end of file
while(!d.eof())
{
    //get line up until the comma delimitter and assign it to name variable
    getline(d, name, ',');
    //if name is an empty string break from the loop
    if(name == "")
    {
        break;
    }
    //space = charLimit - the number of characters in the name variable
    space = (charLimit - name.length());
    //space holds an integer and will add - to pSpace string that many times
    pSpace.assign(space, '-');
    //display name
    cout << "Name: "<< name << pSpace;
    //get line up until the next comma delimiter
    getline(d, price, ',');
    //calculate space integer
    space = (10 - price.length());
    //assign a number of - to the end of pSpace
    pSpace.assign(space, '-');
    //display price
    cout << "Price: $" << price << pSpace;
    //get remainder of the line and assign it to location
    getline(d, location);
    //calculate space
    space = (charLimit - location.length());
    //assign a number of - to the end of pSpace
    pSpace.assign(space, '-');
    //display location
    cout << "Location: "<< location << pSpace;
    //go to new line
    cout << endl;
}
//go to new line
cout << endl;
}
//search function
void searchInventory()
{
    //declare variables
    string sWord = "";
    string name = "";
    string price = "";
    string loc = "";
    string nString = "";
    string nLine = "";
    //prompt user for name of item to search for
    cout << "Please enter the name of the item you'd like to search for: " << endl;
    //assign input from keyboard to sWord variable
    getline(cin, sWord);
    //create searchinv ifstream object
    ifstream searchinv;
    //open inventory.txt as an input
    searchinv.open("inventory.txt", ios::in);
    //while not end of inventory.txt file
    while(!searchinv.eof())
    {
        //get line until comma delimiter and assign to name
        getline(searchinv, name, ',');
        //get line until comma delimiter and assign to price
        getline(searchinv, price, ',');
        //get remaider of line and assign to loc
        getline(searchinv, loc);
        //if search word is equal to name in this iteration
            if(sWord == name)
            {
                //assign string variables with values
                 nString = "Product: " + name + "------>" + loc;
                 nLine = "";
                //assign a number of - to the end of nLine based on the length of nString
                nLine.assign(nString.length(), '-');
                //display a line
                cout << nLine << endl;
                //display nString
                cout << nString << endl;
                //display a line
                cout << nLine << endl;
            }

    }
    //if nString is equal to an empty string after the while loop then there was no name that matched sWord
    if(nString == "")
    {
        //assign values to variables
        string err = "Could not find " + sWord + " in inventory!";
        string eLine = "";
        //assign a number of - to eLine based on the length of err string
        eLine.assign(err.length(), '-');

        //display a line
        cout << eLine << endl;
        //display err string
        cout << err << endl;
        //display a line
        cout << eLine << endl;
    }
    //go to new line
    cout << endl;
}
