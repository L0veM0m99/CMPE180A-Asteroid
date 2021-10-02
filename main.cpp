#include <iostream>
#include <vector>
#include <string>
#include "asteroid.h"
#include "countHits.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;


const int points_per_test = 10;

void testCountHits(const string &test_name, const vector<Asteroid> &a,
                   int expected_hits, int points_for_this_test,
                   int &total_grade) {
    if (countHits(a) == expected_hits) {
        total_grade += points_for_this_test;
        cout << test_name + " succeeded! +" << points_for_this_test << endl;
    } else {
        cout << test_name + " failed!" << endl;
    }
}

int main() {

    int total_grade = 0;
  
    vector<Asteroid> a1 = {{5, Right}, {10, Right}, {5, Left}};
    string test10("Test1.0");
    testCountHits(test10, a1, 2, points_per_test, total_grade);
    
    vector<Asteroid> a2 = {{10, Right}, {11, Left}, {11, Right}, {5, Left}};
    string test20("Test2.0");
    testCountHits(test20, a2, 1, points_per_test, total_grade);
    
    vector<Asteroid> a3 = {{10, Right}, {11, Right}, {11, Right}};
    string test30("Test3.0");
    testCountHits(test30, a3, 3, points_per_test, total_grade);

    vector<Asteroid> a4 = {{10, Right}};
    string test40("Test4.0");
    testCountHits(test40, a4, 1, points_per_test, total_grade);

    vector<Asteroid> a5 = {{10, Left}};
    string test50("Test5.0");
    testCountHits(test50, a5, 0, points_per_test, total_grade);

    vector<Asteroid> a6 = {{8, Right}, {9, Right}, {10, Left}};
    string test60("Test6.0");
    testCountHits(test60, a6, 0, points_per_test, total_grade);

    vector<Asteroid> a7 = {{8, Left}, {11, Left}, {10, Right}};
    string test70("Test7.0");
    testCountHits(test70, a7, 1, points_per_test, total_grade);

    vector<Asteroid> a8 = {{8, Left}, {9, Right}, {10, Right}};
    string test80("Test8.0");
    testCountHits(test80, a8, 2, points_per_test, total_grade);

    vector<Asteroid> a9 = {{5, Right}, {8, Left}, {5, Left}};
    string test90("Test9.0");
    testCountHits(test90, a9, 0, points_per_test, total_grade);

    vector<Asteroid> a10 = {{8, Right}, {8, Left}};
    string test100("Test10.0");
    testCountHits(test100, a10, 0, points_per_test, total_grade);
    cout << "TOTAL GRADE=" << total_grade << endl;


}



