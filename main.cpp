#include "TopSpin.h"

int main(){
    
    int size;
    int spinSize;
    
    
    cout<<"Please enter the size: Size must be at least 1 (else it will be set to default value 20): "<<endl;
    cin>>size;
    if (size < 2 ) size = 20;
    cout<<"Please enter the spinner size: Size must be equal or less than size (else it will default to 4) "<<endl;
    cin>>spinSize;
    if (spinSize > size) spinSize = 4; //This is the case that the assignment asked us to test for
    

    //Calling the TopSpin constructor
    TopSpin* myobj = new TopSpin(size,spinSize);
    
 
    
    
    int choice = 0;
    unsigned int times =1; //user random input
    cout<<"Enter number of random loops that initializes your game: ";
    cin>>times;
    myobj -> random(times);
    cout<<*myobj;
    while (choice != 4)
    {
        cout << "Please choose from the following options enter your choice by entering the corresponding number:" << endl;
        cout<< "1. Shift Right" << endl <<"2. Shift Left"<<endl<< "3. Spin" << endl << "4. Quit" << endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1 :
                myobj->shiftRight();
                cout<<*myobj;
                //myobj->display();
                break;
            case 2 :
                myobj->shiftLeft();
                cout<<*myobj;
                //myobj->display();
                break;
            case 3 :
                myobj->spin();
                cout<<*myobj;
                //myobj->display();
                break;
            case 4 :
                choice = 4;
                break;
            default :
                cout << "Invalid Choice!" << endl;
        }
        
        if (myobj-> isSolved())
        {
            cout<<"Congrats! You did it"<<endl;
            choice = 4;
        }
    }
    
    cout<<"The End: See you Later"<<endl;
    
    delete myobj;
    
    return 0;
}
