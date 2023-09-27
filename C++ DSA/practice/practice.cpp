#include <iostream>
using namespace std;

class dispenserType {
    int cost, item;

public:
    dispenserType() : cost(0), item(0) {}
    dispenserType(int setNoOfItems, int setCost) : cost(setCost), item(setNoOfItems) {}
    int getNoOfItems() {
        return item;
    }
    int getCost() {
        return cost;
    }
    void makeSale() {
        item -= 1;
    }
};

class cashRegister {
    int bal, cash;

public:
    cashRegister() : bal(0) {}
    cashRegister(int cashIn) : bal(cashIn) {}
    int getCurrentBalance() {
        return bal;
    }
    void acceptAmount(int amountIn) {
        bal += amountIn;
    }
    void update(int am){
        bal-=am;
    }
};

void sellProduct(cashRegister& obr, dispenserType& ype, int productChoice) {
    if (productChoice > 5 || productChoice < 1) {
        cout << "Invalid selection.\n";
        return;
    }
    if (productChoice <= 4 && productChoice >= 1) {
        int co = ype.getCost();
        cout << "Please Deposit " << co << " cents\n";
        int accep, inp=0;
        cin >> accep;
        inp+=accep;
        obr.acceptAmount(accep);
        if (obr.getCurrentBalance() < co) {
            cout << "Please deposit another " << co - obr.getCurrentBalance() << " cents\n";
            cin >> accep;
            inp+=accep;
            obr.acceptAmount(accep);
        }
        if (obr.getCurrentBalance() >= co) {
            cout << "Collect your item at the bottom and enjoy.\n";
            ype.makeSale();
            obr.update(co);
        } else {
            cout << "The amount is not enough. Collect what you deposited.\n";
            obr.update(inp);
        }
    }
}

int main() {
    dispenserType candyDispenser(50, 50);
    dispenserType chipsDispenser(50, 65);
    dispenserType gumDispenser(50, 45);
    dispenserType cookiesDispenser(50, 85);
    int product;
    cashRegister cashRegister(0);
    while (true) {
        cin >> product;
        if(product==1)
                sellProduct(cashRegister, candyDispenser, product);
        if(product==2)
                sellProduct(cashRegister, chipsDispenser, product);
        if(product==3)
                sellProduct(cashRegister, gumDispenser, product);
        if(product==4)
                sellProduct(cashRegister, cookiesDispenser, product);
        if(product==5)
            break;
        }
    return 0;
}

