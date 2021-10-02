/* Nanthana Thanonklin 
countHits.cpp
*/
#include "asteroid.h" //enum direction and a vector of structure declared
#include <iostream>
#include <vector>

//Time Complexity = 0(n^2) because we have a for loop inside another for loop
int countHits(std::vector<Asteroid> a) {
    std::vector<Asteroid> possibleHits;
    
    // When there is only 1 asteroid in space
    // we check for conditions to see if it's true or false = o(1)
    if (a[0].d == Direction::Right && a.size() == 1) {
        return 1;
    }
    // Loop through all elements in the asteroid vector that is passed into countHits function
    // iteraing through all indexs = o(n)
    for (int i = 0; i < a.size(); i++) {
        if(a[i].m <= 0){
            std::cerr << "Invalid input!,please check the input and try again."<<std::endl;
            std::cerr << "Mass must be greater than zero. Terminating..."<<std::endl;
            exit(1);       
        //When index is 0 and we have an asteroid going(to the right)to the space station.
        //if a[0]direction is right and the number of hit so far is zero
        //we increment the hit counts by adding it to the vector
        // we check for conditions to see if it's true or false = o(1)
         }else if (a[i].d == Direction::Right && possibleHits.size() == 0) {
            possibleHits.push_back(a[i]); // adding to the vector = o(1)         

        // When we get an asteroid going left and we have asteroids going right to the space station.
        // we check for conditions to see if it's true or false = o(1)
        }else if (a[i].d == Direction::Left && possibleHits.size() > 0) {
            // Loop through all the asteroids that can hit the space station starting from right to left to see if 
            // it will get passed the current asteroid going left.
            // iteraing through all indexs starting from the last = o(n)
            for (int j = possibleHits.size() - 1; j >= 0; j--) {
                // If an asteroid going right has a larger mass than the current asteroid going left we skip it (destroy it).
                //we check for conditions to see if it's true or false = o(1)
                if (possibleHits[j].m > a[i].m) {
                    break; //skipping to the next statement = o(1)
                }
                //the one going left with bigger mass destroys the one going right, so we remove it
                //we check for conditions to see if it's true or false = o(1)
                else if (possibleHits[j].m < a[i].m) {
                    possibleHits.pop_back();//updating a value in the vector = o(1)
                }
                //if it falls out of the above conditions, then both have the same masss
                //we check for conditions to see if it's true or false = o(1)
                else{
                    possibleHits.pop_back(); //updating a value in the vector = o(1)
                }
            }
        }
        //No asteroid going left just right to the space station.
        //we check for conditions to see if it's true or false = o(1)
        else if (a[i].d == Direction::Right) {
            possibleHits.push_back(a[i]); // assiging a value to the vector = o(1)
        }
    }
    return possibleHits.size();// assiging a value to the vector = o(1)
}