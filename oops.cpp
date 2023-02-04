#include <iostream>
using std:: string;

class AbstractEmployee {  // whichever class decides to sign this contract need to provide the implementation of method AskForPromotion
    
    virtual void AskForPromotion() = 0; //we will also make this function obligator ie we will force any class that signs this contract will implement this method.
                                        // we will achieve this by writing 'virtual' keyword ahead.
    };


class Employee: AbstractEmployee {
private:
    string Name, Company;
    int Age;
    
public:
    void setName (string name) {
        Name = name;
    }
    
    string getName () {
        return Name;
    }
    
    void setAge (int age) {
        Age = age;
    }
    
    int getAge () {
        return Age;
    }
    
    void setCompany (string company) {
        Company = company;
    }
    
    void IntroduceYourself () {
        std::cout<<"Name - "<<Name<<std::endl;
        std::cout<<"Company - "<<Company<<std::endl;
        std::cout<<"Age - "<<Age<<std::endl;
        
    }
    Employee (string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    
    void AskForPromotion() {
        if (Age>30) {
            std::cout<<Name<<" got promoted."<<std::endl;
        }
        else {
            std::cout<<Name<<" Sorry! No promotion for you"<<std::endl; 
        }
    }
};

int main () {
    Employee employee1 = Employee ("Aditya", "Accenture", 36);
    Employee employee2 = Employee ("Rahul", "Zerodha", 23);

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    
    
    
    
    
    
}
