//
//  TopSpin.h

#pragma once
#include "CDLL.cpp"

class TopSpinADT {
public:
    // shifts the pieces 1 to the left
    virtual void shiftLeft() = 0;
    //shifts the pieces 1 to the right
    virtual void shiftRight() = 0;
    //reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
    // 1,4,3,6 we will have 6,3,4,1
    virtual void spin() = 0;
    //checks to see if the puzzle is solved that is to say the pieces are in numerical
    //order 1-20
    virtual bool isSolved() = 0;
};

class TopSpin :public TopSpinADT {
public:
    int size;
    int spinSize;
    CDLL* list;
    
    TopSpin(int size, int spinSize);
    ~TopSpin();
    void random(unsigned int times);
    
    void shiftLeft();
    //shifts the pieces 1 to the right
    void shiftRight();
    //reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
    // 1,4,3,6 we will have 6,3,4,1
    void spin();
    //checks to see if the puzzle is solved that is to say the pieces are in numerical
    //order 1-20
    bool isSolved();
    void display(); //This function will display the game to the user
    friend ostream& operator<<(ostream& os, const TopSpin& dt);  //Friend function that we will use to print to the screen
    
};
