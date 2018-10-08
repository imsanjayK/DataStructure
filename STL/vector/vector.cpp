#include "menuOperation.h"
void print(char const *string) // string print
{
    cout << string << endl;
}
int getOption(char const *string)
{
    int option;
    cout << string;
    cin >> option;
    cout << endl;
    return option;
}
void menu()
{
    operation arrayOperation;
    print("1. Add Item \n2. Remove Item \n3. Update Item\n4. Sum of all Items\n5. Display\n6. Exit");
    bool exit = false;
	do{
		switch (getOption("\nEnter the Choice : "))
	    {
	    case 1:
	        if(arrayOperation.addItem(getOption("Insert Value : ")))
	            print("Inserted");
	        else
	            print("Item Exist");
	        break;
	    case 2:
	        if (arrayOperation.removeItem(getOption("Insert Value : ")))
	        {
	            print("Removed");
	        }
	        else
	            print("Not Exist");
	        break;
	    case 3:
	    	//if (arrayOperation.updateItem(getOption("Insert Position : "),getOption("Insert Value : ")))
	    	if (arrayOperation.updateItem(getOption("Insert Value : ")))
	        {
	            print("Updated");
	        }
	        else
	            print("Not Updated");
	        break;
	    case 4:
	    	cout<<arrayOperation.sumOfAll();
	        break;
	    case 5:
	    	arrayOperation.display();
	        break;
	    case 6:
	    	if (arrayOperation.exitMenu())
	        {
	        	exit = true;
	            print("Exit");
	            
	        }
	        else
	            print("Continue");
	        break;
	    default:
	        print("Wrong choice!!!");
	        break;
	    }
	}while(!exit);
}
int main()
{
    system("cls");
	menu();
    // vector<int> dynamicArray;
    // dynamicArray.push_back(1);
    // dynamicArray.push_back(2);
    // dynamicArray.push_back(3);
    // dynamicArray.push_back(4);
    // dynamicArray.push_back(5);

    // for (unsigned int i = 0; i < dynamicArray.size(); ++i)
    // {
    //     cout << dynamicArray.at(i) << " | ";
    //     // cout << dynamicArray[i];
    // }
    // cout << "\n-----------------\n";
    // dynamicArray.insert(dynamicArray.begin() + 5, 6);

    // for (unsigned int i = 0; i < dynamicArray.size(); ++i)
    // {
    //     cout << dynamicArray.at(i) << " | ";
    //     // cout << dynamicArray[i];
    // }
    // // dynamicArray.erase(dynamicArray.begin() + 4);
    // dynamicArray.at(2 - 1) = 9;
    // cout << "\n-----------------\n";
    // for (unsigned int i = 0; i < dynamicArray.size(); ++i)
    // {
    //     cout << dynamicArray.at(i) << " | ";
    //     // cout << dynamicArray[i];
    // }
    // cout << endl
    //      << dynamicArray.size();
}
