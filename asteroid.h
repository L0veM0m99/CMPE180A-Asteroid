
//Nanthana Thanonklin
//asteroid.h
#ifndef asteroid_h
#define asteroid_h


enum Direction{Left, Right}; // by default left = 0, right =1

//Asteroid structure specified mass and direction
struct Asteroid {
        int m; // Mass
        Direction d; //Direction
};

#endif
