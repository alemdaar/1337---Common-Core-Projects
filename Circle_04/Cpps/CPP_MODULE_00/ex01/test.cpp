#include <iostream>
#include <string>

class Person 
{
    private:
        std::string name;
        int age;

    public:
        // Constructor
        Person(std::string n, int a) : name(n), age(a) {
            std::cout << "Person created: " << name << std::endl;
        }

        // Destructor
        ~Person() {
            std::cout << "Person destroyed: " << name << std::endl;
        }

        // Setters
        void setName(std::string n)
        {
            name = n;
        }
        void setAge(int a)
        { 
            age = a;
        }

        // Getters
        std::string getName() const
        {
            return name;
        }
        int getAge() const
        {
            return age;
        }

        // Display
        void show() const
        {
            std::cout << name << ", age " << age << std::endl;
        }
};

int main() {
    Person p1("Alice", 25); // constructor called
    p1.show();

    p1.setAge(26);
    std::cout << p1.getName() << " is now " << p1.getAge() << " years old." << std::endl;

    // destructor called automatically at end of scope
    return 0;
}
