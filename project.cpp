#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

// ----------------- Product Base (with virtual) -----------------
class Product {
protected:
    int id;
    string name;
    double price;
    int stock;
    string category;
    int soldCount;

public:
    Product(int id, const string& name, double price, int stock, const string& category)
        : id(id), name(name), price(price),
          stock(stock), category(category), soldCount(0) {}

    virtual ~Product() = default;

    // Encapsulation: getters
    int getId() const { return id; }
    double getPrice() const { return price; }
    string getCategory() const { return category; }
    int getSoldCount() const { return soldCount; }

    // decrease stock and increase sold count
    bool reduceStock(int q) {
        if (q > stock) return false;
        stock -= q;
        soldCount += q;
        return true;
    }

    // operator overloading: compare Product by price
    bool operator<(const Product& other) const {
        return this->price < other.price;
    }

    // virtual function: child ক্লাস override করবে
    virtual string getInfo() const {
        stringstream ss;
        ss << "Product[" << id << "] "
           << name << " | Price=" << price
           << " | Stock=" << stock
           << " | Category=" << category;
        return ss.str();
    }
};

// operator overloading: Product কে ostream এ প্রিন্ট করা
ostream& operator<<(ostream& os, const Product& p) {
    os << p.getInfo();   // virtual call → runtime polymorphism
    return os;
}

// ----------------- Derived class: CraftItem -----------------
class CraftItem : public Product {
    string material;
    int handmadeTime; // hours
    string difficulty;

public:
    CraftItem(int id, const string& name, double price, int stock,
              const string& category, const string& material,
              int handmadeTime, const string& difficulty)
        : Product(id, name, price, stock, category),
          material(material), handmadeTime(handmadeTime),
          difficulty(difficulty) {}

    // override virtual function
    string getInfo() const override {
        stringstream ss;
        ss << "CraftItem[" << getCategory() << "] "
           << name << " | Price=" << getPrice()
           << " | Material=" << material
           << " | Time=" << handmadeTime << "h"
           << " | Difficulty=" << difficulty
           << " | Sold=" << getSoldCount();
        return ss.str();
    }
};

// ----------------- Cart & CartItem -----------------
class CartItem {
public:
    Product* product;
    int quantity;

    CartItem(Product* p = nullptr, int q = 0)
        : product(p), quantity(q) {}
};

class Cart {
    vector<CartItem> items; // STL

public:
    void addItem(Product* p, int q) {
        if (!p || q <= 0) return;
        items.emplace_back(p, q);
    }

    double getTotal() const {
        double sum = 0;
        for (const auto &ci : items) {
            sum += ci.product->getPrice() * ci.quantity;
        }
        return sum;
    }

    const vector<CartItem>& getItems() const { return items; }
};

// ----------------- Payment (abstraction + polymorphism) -----------------
class PaymentStrategy {
public:
    virtual bool pay(double amount) = 0;  // pure virtual → abstract class
    virtual ~PaymentStrategy() = default;
};

class CardPayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paying " << amount << " via Card.\n";
        return true;
    }
};

class MobilePayment : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Paying " << amount << " via Mobile Banking.\n";
        return true;
    }
};

// ----------------- User & Customer & Seller -----------------
class User {
protected:
    int id;
    string name;

public:
    User(int id, const string& name) : id(id), name(name) {}
    virtual ~User() = default;

    virtual void showInfo() const {
        cout << "User: " << name << " (id=" << id << ")\n";
    }
};

class Customer : public User {
    Cart cart;

public:
    Customer(int id, const string& name) : User(id, name) {}

    void addToCart(Product* p, int q) {
        cart.addItem(p, q);
    }

    void checkout(PaymentStrategy* pay) {
        double total = cart.getTotal();
        cout << "Customer " << name << " checking out. Total = " << total << "\n";
        if (pay && pay->pay(total)) {
            cout << "Order success!\n";
        } else {
            cout << "Payment failed.\n";
        }
    }
};

class Seller : public User {
    vector<Product*> products;

public:
    Seller(int id, const string& name) : User(id, name) {}

    void addProduct(Product* p) {
        if (p) products.push_back(p);
    }

    void showProducts() const {
        cout << "Products of seller " << name << ":\n";
        for (auto p : products) {
            cout << "  - " << *p << '\n'; // operator<<
        }
    }
};

// ----------------- Template Repository (generic list manager) -----------------
template<typename T>
class Repository {
    vector<T*> items;  // STL vector

public:
    void add(T* item) {
        if (item) items.push_back(item);
    }

    // generic find using predicate (lambda / functor)
    template<typename Predicate>
    T* findIf(Predicate pred) {
        for (auto* item : items) {
            if (pred(item)) return item;
        }
        return nullptr;
    }

    void printAll() const {
        for (auto* item : items) {
            cout << *item << '\n'; // assumes operator<< for T
        }
    }

    const vector<T*>& getAll() const { return items; }
};

// ----------------- Template helper function -----------------
template<typename T>
void printWithIndex(const vector<T*>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << i << ": " << *v[i] << '\n';
    }
}

// ----------------- File I/O (non-template) -----------------
void saveProductsToFile(const vector<Product*>& products, const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Error opening file: " << filename << "\n";
        return;
    }
    for (auto* p : products) {
        if (p) {
            fout << p->getInfo() << "\n";
        }
    }
    fout.close();
    cout << "Products saved to file: " << filename << "\n";
}

// ----------------- main demo -----------------
int main() {
    // কিছু craft products (polymorphism via base pointer)
    CraftItem vase(1, "Handmade Vase", 500.0, 10, "HomeDecor", "Clay", 5, "Medium");
    CraftItem scarf(2, "Knitted Scarf", 300.0, 20, "Fashion", "Wool", 3, "Easy");
    CraftItem painting(3, "Acrylic Painting", 1200.0, 5, "Art", "Canvas", 10, "Hard");

    // Template Repository ব্যবহার করে Product store করা
    Repository<Product> productRepo;
    productRepo.add(&vase);
    productRepo.add(&scarf);
    productRepo.add(&painting);

    cout << "All products in repository:\n";
    productRepo.printAll();
    cout << "\n";

    // Template + lambda দিয়ে findIf
    Product* found = productRepo.findIf([](Product* p) {
        return p->getCategory() == "Fashion";
    });
    if (found) {
        cout << "Found a Fashion product: " << *found << "\n\n";
    }

    // Users
    Customer cust(1, "Farhan");
    Seller seller(2, "CraftMaster");

    seller.addProduct(&vase);
    seller.addProduct(&scarf);

    cout << "Seller info and products:\n";
    seller.showInfo();
    seller.showProducts();
    cout << "\n";

    // Customer shopping
    cust.showInfo();
    cust.addToCart(&vase, 2);
    cust.addToCart(&scarf, 1);

    CardPayment cardPay;
    cust.checkout(&cardPay);

    // STL algorithm: sort by price using overloaded operator<
    vector<Product*> allProducts = productRepo.getAll();
    sort(allProducts.begin(), allProducts.end(),
        [](Product* a, Product* b) {
            return *a < *b;  // uses Product::operator<
        });

    cout << "\nProducts sorted by price:\n";
    printWithIndex(allProducts);

    // File I/O: save products to file
    saveProductsToFile(allProducts, "products.txt");

    return 0;
}
