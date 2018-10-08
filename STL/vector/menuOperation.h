#include <iostream>
#include <vector>
using namespace std;
#if 1
class operation
{
  public:
    bool addItem(int item);
    bool removeItem(int item);
    //bool updateItem(int newValue, int postion);
    bool updateItem(int item);
    void display();
    int sumOfAll();
    bool exitMenu();
    bool find(int item);
    int findPosition(int item);// return position if found
  private:
    vector<int> dynamicArray;
};
bool operation::find(int item){
	for (unsigned int i = 0; i < dynamicArray.size(); ++i){
    	if(dynamicArray.at(i) == item){	
    		return 1;
    	}		
	}
	return 0;
}

int operation::findPosition(int item){
	for (unsigned int i = 0; i < dynamicArray.size(); ++i){
    	if(dynamicArray.at(i) == item){	
    		return i;
    	}		
	}
	return -1;
}

bool operation::addItem(int item)
{
	if(find(item)){
		return 0;
	}
	dynamicArray.push_back(item);
	return 1;
	
 #if 0
    for (unsigned int i = 0; i < dynamicArray.size(); ++i){
    	if(dynamicArray.at(i) == item){	
    		return 0;
    	}		
	}
	dynamicArray.push_back(item);
	return 1;
#endif
}

bool operation::removeItem(int item)// int position
{
	if(find(item)){
		int position = findPosition(item);
		dynamicArray.erase(dynamicArray.begin() + position);
		return 1;
	}
	return 0;
#if 0
	for (unsigned int i = 0; i < dynamicArray.size(); ++i){
    	if(dynamicArray.at(i) == item){	
    		dynamicArray.erase(dynamicArray.begin() + i);
    		return 1;
    	}		
	}
	return 0;
#endif
#if 0
    if (0 < position && position <= dynamicArray.size())
    {
        dynamicArray.erase(dynamicArray.begin() + (position - 1));
        return 1;
    }
    else
        return 0;
#endif
}

//bool operation::updateItem(int position,int newValue)
bool operation::updateItem(int value)
{	
	if(find(value)){
		int position = findPosition(value);
		int length =dynamicArray.size();
			if( 0<= position && position < length){
		    	int newValue;
				cout<<"Insert new value : ";
				cin>> newValue;
					if(find(newValue)){
						return 0;
			  		}
				dynamicArray.at(position) = newValue;
				return 1;
			}
	}
	return 0;			
#if 0 
    if (0 < position && position <= dynamicArray.size())
    {
        dynamicArray.at(position - 1) = newValue;
        return 1;
    }
    else
        return 0;
#endif
}

void operation::display()
{
    for (unsigned int i = 0; i < dynamicArray.size(); ++i)
    {
        cout << dynamicArray.at(i) << " | ";
        // cout << dynamicArray[i];
    }
    cout<<endl;
    
}

int operation::sumOfAll()
{
    int sum = 0;
    for (unsigned int i = 0; i < dynamicArray.size(); ++i)
    {
        sum += dynamicArray.at(i);
    }
    return sum;
}

bool operation::exitMenu()
{
    char option;
    cout << "Exit Yes/No : ";
    cin >> option;
    if (option == 'y' || option =='Y')
    {
        return true;
    }
 //   else if(isalpha(option))
    	return false;	
//	return false;
    
}

#endif
