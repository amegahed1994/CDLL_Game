//
//  TopSpin.cpp
//
//  Created by Abdelrahman Megahed on 2017-10-22.
//  Copyright © 2017 Abdelrahman Megahed. All rights reserved.
//

#include "TopSpin.h"


TopSpin::TopSpin(int size, int spinSize)
{
    this->size = size;
    this->spinSize = spinSize;
    list = new CDLL(); //creating a new CDLL obj
    
    for (int i =1; i<19; i++)
    {
        list->addData(i);
    }
    list->addData(19);
    list->addData(20);
    
    
}
TopSpin::~TopSpin()
{
    delete list;
}

void TopSpin::shiftLeft()
{
    list->decrementHead();
}
//shifts the pieces 1 to the right
void TopSpin::shiftRight()
{
    list->incrementHead();
}
//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
// 1,4,3,6 we will have 6,3,4,1
void TopSpin::spin()
{
    for (int incr = 0 ; incr < spinSize/2; incr++) list->swap(spinSize-1-incr, incr);
    //This is the algorithm I developed to swap the spinner (it takes care of the even and odd list size special cases)
    
}
//checks to see if the puzzle is solved that is to say the pieces are in numerical
//order 1-20
bool TopSpin::isSolved()
{
    int solved = 1;
    for (int i=0; i<size-1; i++)
    {
        if (list->getData(i) > list->getData(i+1))
        {
            solved = 0; //this means that the game is not solved
            i=size; //this will force it to break out of the for loop
        }
    }
    return solved;
}
void TopSpin::display()
{
    cout<<"|-------------|"<<endl;
    for (int i=0; i<size; i++)
    {
        cout<<list->getData(i);
        cout<<" ";
        if (i == spinSize-1) cout<<"| ";
    }
    cout<<endl;
    cout<<"|-------------|"<<endl;
}

