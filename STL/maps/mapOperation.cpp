#include <iostream>
#include <map>
#include <iterator>
using namespace std;
class shoppingCart
{
  public:
    void addToCart();
    void removeFromCart();
    void viewCart();
    void updateCart();

  private:
    string product;
    int qty;
    map<string, int> cartMap;
    map<string, int>::iterator itr;
} cart;
void shoppingCart::addToCart()
{
    cout << "Add the product : ";
    cin >> product;
    itr = cartMap.find(product);
    if (itr != cartMap.end())
    {
        ++itr->second;
        cout << "Quantity Added " << endl;
    }
    else
    {
        cout << "Add quantity : ";
        cin >> qty;
        cartMap.insert(pair<string, int>(product, qty)); // push value to map
    }
}
void shoppingCart::updateCart()
{
    cout << "Product to be updated : ";
    cin >> product;
    itr = cartMap.find(product);
    if (itr != cartMap.end())
    {
        cout << "Enter Quantity : ";
        cin >> qty;
        itr->second = qty;
        cout << "Product Updated " << endl;
    }
    else
    {
        cout << "Product Not Found" << endl;
    }
}
void shoppingCart::removeFromCart()
{
    cout << "Remove product : ";
    cin >> product;
    if (cartMap.erase(product))
    {
        cout << "Product removed from cart" << endl;
    }
    else
        cout << "Product Not Found" << endl;
}
void shoppingCart::viewCart()
{

    if (cartMap.empty())
    {
        cout << "No product to show " << endl;
    }
    else
        for (itr = cartMap.begin(); itr != cartMap.end(); ++itr)
        {
            cout << itr->first << "  " << itr->second << endl;
        }
}
void menu()
{
    bool repeat = true;
    int option;
    cout << "1. Add to cart\n2. Remove from cart\n3. View cart\n4. Update product\n5. Exit " << endl;
    while (repeat)
    {
        cout << "Enter option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cart.addToCart();
            break;
        case 2:
            cart.removeFromCart();
            break;
        case 3:
            cart.viewCart();
            break;
        case 4:
            cart.updateCart();
            break;
        case 5:
            cout << "Exit" << endl;
            repeat = false;
            // system("pause");
            break;
        default:
            cout << "Wrong Option " << endl;
            // system("pause");
            break;
        }
    }
}
int main()
{
    system("cls");
    menu();
    return 0;
}