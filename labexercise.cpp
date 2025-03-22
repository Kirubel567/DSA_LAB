#include <iostream> 
#include <string> 
using namespace std; 

int add(int a, int b){
    return a+b; 
}
double add(double a, int b){
    return a + b; 
}
double add(double a, double b, double c){
    return a + b + c; 
}
template <typename customtype, typename custom2 , typename custom3, typename custom4> // this "customtype" is a generic datatype
customtype add(customtype a, custom2 b, custom3 c, custom4 d){
    return a + b + c + d; 
} 
struct Pets{
    string owner; 
    int age; 
    string sex; 

} strong; 

int main(){

    Pets maya; 
    Pets mechal; 

    maya.owner = "abebe";
    maya.age = 11; 
    maya.sex = "female";
    mechal.owner = "zeamuel"; 
    mechal.age = 21;  
    mechal.sex = "male"; 
    strong.owner = "martha"; 
    strong.age = 32; 
    strong.sex = "male"; 
    cout << maya.owner << endl; 
    cout << mechal.age << endl; 
    cout << strong.sex << endl; 



    cout << add(1, 2, 3) << endl; 
    cout << add(1.2, 1.33, 2.2) << endl;  
    cout << add(1, 2, 3) << endl;
    cout << add(1.2, 1.0, 5.0) << endl; 
    cout << add(12.3, 12.4, 2, 33) << endl;
    return 0; 
}