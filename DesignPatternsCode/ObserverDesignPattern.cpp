#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NotificationAlertObserver {
    public:

    virtual void update() = 0;
};

class StockObservable {
    public:
    
    virtual void add(NotificationAlertObserver* observer) = 0;
    virtual void remove(NotificationAlertObserver* observer) = 0;
    virtual void notifySubscribers() = 0;
    virtual void setStockCount(int newStockAdded)= 0;
    virtual int getStockCount() = 0;
};

class IphoneObservable : public StockObservable {
    private: 
        vector<NotificationAlertObserver*> observers;
        int stockCount;
    private: 
        void add(NotificationAlertObserver* observer)  {
            observers.push_back(observer);
        };

        void remove(NotificationAlertObserver* observer)  {
            auto it = find(observers.begin(), observers.end(), observer);
            if(it != observers.end()){
                observers.erase(it);
            }
        };

        void notifySubscribers()  {
            for(NotificationAlertObserver* observer : observers) {
                observer->update();
            }
        };

        void setStockCount(int newStockAdded)  {
            if(stockCount == 0 && newStockAdded){
                notifySubscribers();
            }
            stockCount = stockCount + newStockAdded;
        };

        int getStockCount()  {
            return stockCount;
        }
};

class EmailAlertObserver : public NotificationAlertObserver {
    private: 
        string emailId;
        StockObservable *stockObservable;
    
    public: 
        EmailAlertObserver(string emailId,StockObservable *observable) {
            this->emailId = emailId;
            this->stockObservable = observable;
        };

        void update()  {
            sendEmail(emailId, "Product is available");
        };

        void sendEmail(string emailId, string msg) {
            cout<<"Mail sent to: " + emailId<<endl;
        };
};

class MobileAlertObserver : public NotificationAlertObserver {
    private: 
        string username;
        StockObservable *stockObservable;
    
    public: 
        MobileAlertObserver(string username,StockObservable *observable) {
            this->username = username;
            this->stockObservable = observable;
        };

        void update() {
            sendMsgOnMobile(username, "Product is available");
        };

        void sendMsgOnMobile(string username, string msg) {
            cout<<"Mail sent to: " + username<<endl;
        };
};


int main(){
    StockObservable *iphoneObservable = new IphoneObservable();

    NotificationAlertObserver *observer1 = new EmailAlertObserver("mail1@gmail.com", iphoneObservable);
    NotificationAlertObserver *observer2 = new MobileAlertObserver("mobile1", iphoneObservable);
    NotificationAlertObserver *observer3 = new EmailAlertObserver("mail2@gmail.com", iphoneObservable);

    iphoneObservable->add(observer1);
    iphoneObservable->add(observer2);
    iphoneObservable->add(observer3);

    iphoneObservable->setStockCount(0);
    iphoneObservable->setStockCount(10);
    iphoneObservable->setStockCount(0);
    iphoneObservable->setStockCount(100);
    return 0;
};