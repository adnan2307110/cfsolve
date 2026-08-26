#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;
void line(char c = '-', int n = 60) { cout << string(n, c) << '\n'; }
void title(const string &t)
{
    line('=');
    cout << t << '\n';
    line('=');
}
// Product Base
class Product
{
protected:
    int id;
    string name;
    double price;
    int stock;
    string category;
    int soldCount;

public:
//constuctor
    Product(int id, const string &name, double price, int stock, const string &category)
        : id(id), name(name), price(price), stock(stock), category(category), soldCount(0) {}
//destructor
    virtual ~Product() = default;

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }
    string getCategory() const { return category; }
    int getSoldCount() const { return soldCount; }

    friend void applyDiscount(Product &p, double percent);

    bool reduceStock(int q)
    {
        if (q > stock)
            return false;
        stock -= q;
        soldCount += q;
        return true;
    }
    virtual string getInfo() const
    {
        stringstream ss;
        ss << "Product[" << id << "] "
           << name << " | Price=" << price
           << " | Stock=" << stock
           << " | Category=" << category;
        return ss.str();
    }
};
//operator overloading
ostream &operator<<(ostream &os, const Product &p)
{
    os << p.getInfo();
    return os;
}
//friend function
void applyDiscount(Product &p, double percent)
{
    if (percent < 0)
        percent = 0;
    if (percent > 90)
        percent = 90;
    double cut = p.price * (percent / 100.0);
    p.price -= cut;
    cout << ">> Discount " << fixed << setprecision(2) << percent << "% applied on \""
         << p.name << "\". New price = " << p.price << "\n";
}
//  Derived class: CraftItem
class CraftItem : public Product
{
    string material;
    int handmadeTime;
    string difficulty;

public:
//constuctor
    CraftItem(int id, const string &name, double price, int stock,
              const string &category, const string &material,
              int handmadeTime, const string &difficulty)
        : Product(id, name, price, stock, category),
          material(material), handmadeTime(handmadeTime),
          difficulty(difficulty) {}
    string getInfo() const override
    {
        stringstream ss;
        ss << "CraftItem[" << category << "] "
           << name << " | Price=" << fixed << setprecision(2) << price
           << " | Material=" << material
           << " | Time=" << handmadeTime << "h"
           << " | Difficulty=" << difficulty
           << " | Stock=" << stock
           << " | Sold=" << soldCount;
        return ss.str();
    }
};
// Cart & CartItem
class CartItem
{
public:
    Product *product;
    int quantity;
    CartItem(Product *p = nullptr, int q = 0) : product(p), quantity(q) {}
};
class Cart
{
    vector<CartItem> items;

public:
    void addItem(Product *p, int q)
    {
        if (!p || q <= 0)
            return;
        items.emplace_back(p, q);
    }
    double getTotal() const
    {
        double sum = 0;
        for (auto &ci : items)
            sum += ci.product->getPrice() * ci.quantity;
        return sum;
    }
    const vector<CartItem> &getItems() const { return items; }
};
void printCart(const Cart &cart)
{
    cout << left << setw(22) << "Item"
         << setw(10) << "Price"
         << setw(6) << "Qty"
         << setw(12) << "Line Total" << '\n';
    line('-');
    double total = 0.0;
    for (const auto &ci : cart.getItems())
    {
        double lineTotal = ci.product->getPrice() * ci.quantity;
        total += lineTotal;
        cout << left << setw(22) << ci.product->getName().substr(0, 21)
             << setw(10) << fixed << setprecision(2) << ci.product->getPrice()
             << setw(6) << ci.quantity
             << setw(12) << lineTotal << '\n';
    }
    line('-');
    cout << "Cart Total: " << fixed << setprecision(2) << total << "\n";
}
// Payment
class PaymentStrategy
{
public:
    virtual bool pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};
class CardPayment : public PaymentStrategy
{
public:
    bool pay(double amount) override
    {
        cout << "Paying " << fixed << setprecision(2) << amount << " via Card.\n";
        return true;
    }
};
class MobilePayment : public PaymentStrategy
{
public:
    bool pay(double amount) override
    {
        cout << "Paying " << fixed << setprecision(2) << amount << " via Mobile Banking.\n";
        return true;
    }
};
// User & Customer & Seller
class User
{
protected:
    int id;
    string name;

public:
    User(int id, const string &name) : id(id), name(name) {}
    virtual ~User() = default;
    virtual void showInfo() const
    {
        cout << "User: " << name << " (id=" << id << ")\n";
    }
};
class Customer : public User
{
    Cart cart;

public:
    Customer(int id, const string &name) : User(id, name) {}

    void addToCart(Product *p, int q)
    {
        cart.addItem(p, q);
    }
    void showCart() const
    {
        title("Cart for " + name);
        printCart(cart);
    }
    void checkout(PaymentStrategy *pay)
    {
        title("Checkout");
        for (const auto &ci : cart.getItems())
        {
            if (ci.quantity > ci.product->getStock())
            {
                cout << "Sorry, not enough stock for: " << ci.product->getName() << "\n";
                return;
            }
        }
        double total = cart.getTotal();
        cout << "Customer " << name << " paying. Total = " << fixed << setprecision(2) << total << "\n";
        if (!(pay && pay->pay(total)))
        {
            cout << "Payment failed.\n";
            return;
        }
        for (const auto &ci : cart.getItems())
        {
            ci.product->reduceStock(ci.quantity);
        }
        cout << "Order success! Thanks, " << name << ".\n";
    }
};
class Seller : public User
{
    vector<Product *> products;

public:
    Seller(int id, const string &name) : User(id, name) {}
    void addProduct(Product *p)
    {
        if (p)
            products.push_back(p);
    }
    void showProducts() const
    {
        cout << "Products of seller " << name << ":\n";
        for (auto *p : products)
        {
            cout << "  - " << *p << '\n';
        }
    }
};
// Template 
template <typename T>
class Repository
{
    vector<T *> items;

public:
    void add(T *item)
    {
        if (item)
            items.push_back(item);
    }
    template <typename Predicate>
    T *findIf(Predicate pred)
    {
        for (auto *item : items)
        {
            if (pred(item))
                return item;
        }
        return nullptr;
    }
    void printAll() const
    {
        for (auto *item : items)
        {
            cout << *item << '\n';
        }
    }
    const vector<T *> &getAll() const { return items; }
};
// Template helper
template <typename T>
void printWithIndex(const vector<T *> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << i << ": " << *v[i] << '\n';
    }
}
//  File I/O:
void saveProductstxt(const vector<Product *> &products, const string &filename)
{
    ofstream fout(filename);
    if (!fout)
    {
        cerr << "Error opening file for writing: " << filename << "\n";
        return;
    }
    fout << "id,name,price,stock,category,sold\n";
    for (auto *p : products)
    {
        if (p)
        {
            fout << p->getId() << " "
                 << p->getName() << " "
                 << fixed << setprecision(2) << p->getPrice() << " "
                 << p->getStock() << " "
                 << p->getCategory() << " "
                 << p->getSoldCount() << "\n";
        }
    }
    fout.close();
    cout << "Products saved to file: " << filename << "\n";
}
vector<vector<string>> loadProductstxt(const string &filename)
{
    ifstream fin(filename);
    vector<vector<string>> rows;
    if (!fin)
    {
        cerr << "Error opening file for reading: " << filename << "\n";
        return rows;
    }
    string lineS;
    while (getline(fin, lineS))
    {
        vector<string> cols;
        string cell;
        stringstream ss(lineS);
        while (ss >> cell)
            cols.push_back(cell);
        if (!cols.empty())
            rows.push_back(cols);
    }
    cout << "Loaded " << rows.size() << " rows from file: " << filename << "\n";
    return rows;
}
void printProductsTable(const vector<Product *> &v)
{
    cout << left
         << setw(3) << "#"
         << setw(4) << "ID"
         << setw(22) << "Name"
         << setw(12) << "Category"
         << setw(10) << "Price"
         << setw(7) << "Stock"
         << setw(6) << "Sold"
         << '\n';
    line('-');
    for (size_t i = 0; i < v.size(); ++i)
    {
        auto *p = v[i];
        cout << left
             << setw(3) << i
             << setw(4) << p->getId()
             << setw(22) << p->getName().substr(0, 21)
             << setw(12) << p->getCategory().substr(0, 11)
             << setw(10) << fixed << setprecision(2) << p->getPrice()
             << setw(7) << p->getStock()
             << setw(6) << p->getSoldCount()
             << '\n';
    }
}
double inventoryValue(const vector<Product *> &v)
{
    return accumulate(v.begin(), v.end(), 0.0,
                      [](double acc, Product *p)
                      {
                          return acc + p->getPrice() * p->getStock();
                      });
}

void printCategoryCounts(const vector<Product *> &v)
{
    unordered_map<string, int> cnt;
    for (auto *p : v)
        cnt[p->getCategory()]++;
    cout << "Items by category:\n";
    for (auto &kv : cnt)
    {
        cout << "  " << kv.first << ": " << kv.second << '\n';
    }
}
int main()
{

    title("CRAFT SHOP)");
    //dynamic memory allocation
    auto *vase = new CraftItem(1, "Handmade Vase", 500.0, 10, "HomeDecor", "Clay", 5, "Medium");
    auto *scarf = new CraftItem(2, "Knitted Scarf", 300.0, 20, "Fashion", "Wool", 3, "Easy");
    auto *painting = new CraftItem(3, "Acrylic Painting", 1200.0, 5, "Art", "Canvas", 10, "Hard");

    Repository<Product> productRepo;
    productRepo.add(vase);
    productRepo.add(scarf);
    productRepo.add(painting);

    title("All products in repository (table view)");
    printProductsTable(productRepo.getAll());
    cout << '\n';

    Product *found = productRepo.findIf([](Product *p)
                                        { return p->getCategory() == "Fashion"; });
    if (found)
    {
        cout << "Found a Fashion product: " << *found << "\n";
        applyDiscount(*found, 10.0);
        cout << "After discount: " << *found << "\n\n";
    }

    // Users
    Customer cust(1, "Farhan");
    Seller seller(2, "CraftMaster");

    seller.addProduct(vase);
    seller.addProduct(scarf);

    title("Seller info and products");
    seller.showInfo();
    seller.showProducts();
    cout << "\n";

    // Customer shopping
    cust.showInfo();
    cust.addToCart(vase, 2);
    cust.addToCart(scarf, 1);
    cust.showCart();

    CardPayment cardPay;
    cust.checkout(&cardPay);

    // sort by price
    vector<Product *> allProducts = productRepo.getAll();
    sort(allProducts.begin(), allProducts.end(), [](Product *a, Product *b)
         { return a->getPrice() < b->getPrice(); });

    title("Products sorted by price");
    printProductsTable(allProducts);

    // analytics
    cout << '\n';
    title("Quick analytics");
    cout << "Total inventory value (price * stock of each item): "
         << fixed << setprecision(2) << inventoryValue(allProducts) << '\n';
    printCategoryCounts(allProducts);

    // Best seller
    auto *best = *max_element(allProducts.begin(), allProducts.end(),
                              [](Product *a, Product *b)
                              {
                                  return a->getSoldCount() < b->getSoldCount();
                              });
    cout << "Top sold so far: " << best->getName()
         << " (" << best->getSoldCount() << ")\n";

    // File I/O:
    const string filename = "products.txt";
    saveProductstxt(allProducts, filename);

    auto rows = loadProductstxt(filename);
    if (!rows.empty())
    {
        cout << "Preview from file:\n";
        cout << left
             << setw(4) << "ID"
             << setw(20) << "Name"
             << setw(10) << "Price"
             << setw(7) << "Stock"
             << setw(12) << "Category"
             << setw(6) << "Sold" << '\n';
        line('-');
        for (auto &r : rows)
        {
            if (r.size() >= 6)
            {
                cout << left
                     << setw(4) << r[0]
                     << setw(20) << r[1].substr(0, 19)
                     << setw(10) << r[2]
                     << setw(7) << r[3]
                     << setw(12) << r[4].substr(0, 11)
                     << setw(6) << r[5] << '\n';
            }
        }
    }
    line('=');
    cout << "Demo finished. Bye!\n";
    //free memory
    delete vase;
    delete scarf;
    delete painting;
    return 0;
}
