#include <iostream>
using std:: string;

class AbstractEmployee {  // whichever class decides to sign this contract need to provide the implementation of method AskForPromotion
    
    virtual void AskForPromotion() = 0; //we will also make this function obligator ie we will force any class that signs this contract will implement this method.
                            // we will achieve this by writing 'virtual' keyword ahead.
    };


class Employee: AbstractEmployee {
private:
    string  Company;
    int Age;
    
protected:
    string Name;
    
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

class Developer: public Employee {
    public :
        string FavProgrammingLanguage;
        
    Developer (string name, string company, int age, string favProgrammingLanguage)
        : Employee(name, company, age)
    {   
        FavProgrammingLanguage = favProgrammingLanguage;
        
    }
    
    void fixBug () {
        std::cout<<Name<<" fix bug using "<<FavProgrammingLanguage<<std::endl;
    }
};

class Teacher : Employee {
public: 
    string Subject;
    void prepareLesson () {
        std::cout<<Name<<" is preparing for "<<Subject<<" lesson"<<std::endl;
    }
    
    Teacher (string name, string company, int age, string subject)
        : Employee(name, company, age)
        {
            Subject = subject;
        }
};



int main () {
    Employee employee1 = Employee ("Aditya", "Accenture", 36);
    Employee employee2 = Employee ("Rahul", "Zerodha", 23);

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    
    Developer obj1 = Developer("Aditya", "Accenture", 26, "C++");
    obj1.fixBug();
    obj1.fixBug();
    obj1.fixBug();
    obj1.AskForPromotion();
    
    Teacher t = Teacher("Jack", "Cool School", 35, "History");
    t.prepareLesson();
    
    
}
