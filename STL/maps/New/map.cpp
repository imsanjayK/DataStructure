#include "menuOperation.h"
#include <map>
#include <iterator>
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
    print("1. Add to cart \n2. Remove from cart \n3. Update Item Quantity\n4. Sum of all Items\n5. View cart\n6. Exit");
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
    //system("cls");
	//	menu();
     map<string,int> shoppingCartMap;
     string  product= "abc";
     int  qty=3;
     
    // shoppingCartMap.insert(pair<string,int>(product, qty));
     shoppingCartMap.insert(pair<string,int>("s", 2));
     shoppingCartMap.insert(pair<string,int>("d", 4));
     shoppingCartMap.insert(pair<string,int>("g", 1));
     std::map<string,int>::iterator itr = shoppingCartMap.begin();
    
     for ( itr = shoppingCartMap.begin(); itr !=shoppingCartMap.end(); ++itr)
         {
			cout<<itr->first;
		  	cout<<itr->second;
 		}
//        while(itr!=shoppingCartMap.end()){
//        string word = itr->first;
//        int value = itr->second;
//        cout<<word<<" "<<value<<endl;
//        itr++;
//        }
//	 shoppingCartMap["a"] = 1;
//     shoppingCartMap["b"] = 3;
//     shoppingCartMap["c"] = 0;
//     shoppingCartMap["d"] = 0;
//     shoppingCartMap["e"] = 4;
//     for (iterator i = shoppingCartMap.begin(); i !=shoppingCartMap.end();++i)
//     {
//     	 shoppingCartMap 
//       //  cout << dynamicArray.at(i) << " | ";
//         //	 cout << shoppingCartMap[i];
//     }
//     for (unsigned int i = 0; i < shoppingCartMap.size(); ++i)
//     {
//       //  cout << dynamicArray.at(i) << " | ";
//         	 cout << shoppingCartMap[i];
//     }
//     cout << "\n-----------------\n";
//     dynamicArray.insert(dynamicArray.begin() + 5, 6);
//
//     for (unsigned int i = 0; i < dynamicArray.size(); ++i)
//     {
//         cout << dynamicArray.at(i) << " | ";
//         // cout << dynamicArray[i];
//     }
//     // dynamicArray.erase(dynamicArray.begin() + 4);
//     dynamicArray.at(2 - 1) = 9;
//     cout << "\n-----------------\n";
//     for (unsigned int i = 0; i < dynamicArray.size(); ++i)
//     {
//         cout << dynamicArray.at(i) << " | ";
//         // cout << dynamicArray[i];
//     }
//     cout << endl
//          << dynamicArray.size();
}
