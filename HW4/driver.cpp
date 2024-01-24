#include "DayOfYearSet.hpp"

using namespace std;
using namespace Set;

int main()
{
    cout << "No parameter DayOfYearSet constructor, it is empty set: \n";
    DayOfYearSet empty_set;
    cout << empty_set;

    cout << "\nNo parameter DayOfYear constructor, it is 1 January: \n";
    DayOfYearSet::DayOfYear empty_day;
    empty_day.print();

    cout << "\n I will create two sets which are same with list initializer parameter constructor\n";

    DayOfYearSet::DayOfYear DateA(4, 2);
    DayOfYearSet::DayOfYear DateB(30, 4);
    DayOfYearSet::DayOfYear DateC(6, 4);
    DayOfYearSet::DayOfYear DateD(6, 4);
    DayOfYearSet::DayOfYear DateE(7, 8);


    DayOfYearSet SetA({DateA, DateB, DateC});
    DayOfYearSet SetB({DateA, DateB, DateC});

    cout << "-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;
    
    cout << "\nIf these two set are equal, string which is in the if will printed.\n";
    
    if(SetA == SetB)
        cout << "\nSetA and SetB are equal\n";
    else
        cout << "\nSetA and SetB are not equal\n";

    cout << "I will remove 2.month 4.day and  4. month 30. day from setB by using remove function\n";
    SetB.remove(DateA);
    SetB.remove(DateB);

    

    cout << "-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;

    cout << "I will add back 4. month 30. day to setB by using operator+ function\n";
    SetB+DateB;
    
    cout << "-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;

    cout << "\nIf these two set are equal, string which is in the if will printed.\n";
    
    if(SetA == SetB)
        cout << "\nSetA and SetB are equal\n";
    if(SetA != SetB)
        cout << "\nSetA and SetB are not equal\n";

    cout << "I will remove 2.month 4.day from setA  and 4. month 6. day by using binary operator - function\n";
    SetA - DateA;
    SetA - DateC;

    cout << "\n-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;

    cout << "I will add back 4. month 6. day to setA by using operator+ function\n";
    SetA + DateC;
    cout << "\n-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;

    cout << "\nIf these two set are equal, string which is in the if will printed.\n";
    
    if(SetA == SetB)
        cout << "\nSetA and SetB are equal\n";
    if(SetA != SetB)
        cout << "\nSetA and SetB are not equal\n";

    cout << "\n Now, I will add 1 january to SetA and 6. day 4.month to SetB which is already exist\n";
    SetA + empty_day;
    SetB + DateD;

    cout << "\n-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;

    cout << "\nIf these two set are equal, string which is in the if will printed.\n";
    
    if(SetA == SetB)
        cout << "\nSetA and SetB are equal\n";
    if(SetA != SetB)
        cout << "\nSetA and SetB are not equal\n";
    
    cout << "I will print size to of sets\nSize of SetA: " << SetA.size() << "\nSize of SetB: "<< SetB.size() << endl;
    cout << "I will add 7. day 8. month to SetB\n";
    SetB + DateE;  

    cout << "\n-----------SetA----------- \n"<<SetA << endl <<"-----------SetB----------- \n" << SetB << endl;

    cout << "Now i will add SetA and SetB and it will assign union set to union_set\n";
    DayOfYearSet union_set = SetA + SetB;

    cout << "\n-----------Union_Set----------- \n"<<union_set << endl;

    cout << "Now i will add SetA and Empty_set and it will assign union set to union_set\n";
    union_set = SetA + empty_set;

    cout << "\n-----------Union_Set----------- \n"<<union_set << endl;

    cout << "\nNow i will intersect SetA and SetB and it will assign to intersection set\n";
    DayOfYearSet intersection_set = SetA ^ SetB;
    cout << "\n-----------Intersection_Set----------- \n"<<intersection_set << endl;


    cout << "\nNow i will intersect SetA and empty_set and it will assign to intersection set\n";
    intersection_set = SetA ^ empty_set;
    cout << "\n-----------Intersection_Set----------- \n"<<intersection_set << endl;
    
    
    cout << "\nNow i will find difference set(SetA - SetB)\n";
    DayOfYearSet difference_set = SetA - SetB;

    cout << "\n-----------Difference_Set----------- \n"<<difference_set << endl;

    cout << "\nNow i will find difference set(SetB - SetA)\n";
    difference_set = SetB - SetA;

    cout << "\n-----------Difference_Set----------- \n"<<difference_set << endl;

    cout << "I will reach second element (1. index) of SetA and SetB by using index operator.\n";
    SetA[1].print();
    SetB[1].print();
    cout << "I will complete setA and assign set_complement. Then i will complete set_complement. If it is equal to SetA, it is true\n";
    DayOfYearSet complement_set = (!SetA);
    complement_set = (!complement_set);
    cout << "\n-----------Complement_Set----------- \n"<< complement_set<< endl;
    cout << "I will control if Complement_Set is equal to SetA with == operator\n"; 
    if(SetA == complement_set)
        cout << "\nSetA and Complement_Set are equal\n";
    if(SetA != complement_set)
        cout << "\nSetA and Complement_Set are not equal\n";

    return 0;
}
