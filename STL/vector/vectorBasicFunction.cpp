#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    system("cls");
    vector<string> vectorObject;
    vector<string>::iterator itr;
    ostream_iterator<string> outputIterator(cout, ",");
    string item;
    int pos = 2;
    // push_back insert at end
    while (1)
    {
        cout << "Enter string push_back : ";
        cin >> item;
        vectorObject.push_back(item);
        //vectorObject.insert(vectorObject.end(), item); // insert at end
        //vectorObject.insert(vectorObject.begin(),item); // insert at begin
        //vectorObject.insert(vectorObject.begin() + pos, item); // insert at given position
        cout << endl;
        if (item == "exit")
        {
            break;
        }
    }
    cout << "Enter string at 2: ";
    cin >> item;
    vectorObject.insert(vectorObject.begin() + pos, item); // insert at given position
    vector<string> vectorCopyObject(vectorObject.begin(), vectorObject.end());
    //vectorCopyObject.erase(vectorCopyObject.begin()); // delete at begin
    //vectorCopyObject.erase(vectorCopyObject.end()); // delete at end
    // vectorCopyObject.erase(vectorCopyObject.begin() + pos); // delete at end
    vectorObject.pop_back();
    vectorCopyObject.pop_back();
    cout << "\nfor loop array style used " << endl;
    for (int index = 1; index < vectorObject.size(); ++index)
    {
        cout << vectorObject[index] << ",";
    }
    cout << "\nfor loop array style and at() used " << endl;
    for (int index = 0; index < vectorObject.size() - 1; ++index)
    {
        cout << vectorObject.at(index) << ",";
    }
    cout << "\niterator used " << endl;
    for (itr = vectorObject.begin(); itr != vectorObject.end() - 1; ++itr)
    {
        cout << *itr << vectorObject.begin() << ",";
    }
    cout << "\ncopy and ostream iterator used " << endl;
    copy(vectorObject.begin(), vectorObject.end() - 1, outputIterator);
    cout << "\ncopy vector " << endl;
    // copy(vectorObject.begin(), vectorObject.end(), vectorCopyObject.begin());
    for (itr = vectorCopyObject.begin(); itr != vectorCopyObject.end(); ++itr)
    {
        cout << *itr << ",";
    }
    vectorCopyObject.clear(); //clear all
    cout << "\ncopy and ostream iterator copy vector used " << endl;
    copy(vectorCopyObject.begin(), vectorCopyObject.end(), outputIterator);
}
