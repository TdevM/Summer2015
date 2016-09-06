#include<iostream>
using namespace std;
class Person {
    char name[100];
    static int population;
    public:
    Person() {
        population++;
    }
    ~Person() {
        population--;
    }
    void printName() {
        cout << name << endl;
    }
    static int getPopulation() {
        return population;
    }
};
int Person::population = 0;
int main() {
    Person A, B, C;
    A.getPopulation();
    Person::getPopulation();
/*    cout << Person::population << endl;
    cout <<A.population<< endl;
    cout << B.population << endl;*/
    return 0;
}
