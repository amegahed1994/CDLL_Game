//  CDLL.h

//  Created by Abdelrahman Megahed
//  Copyright © 2017 Abdelrahman Megahed. All rights reserved.
#include <iostream>
using namespace std;



class CDLL
{
private:
    
    class Node
    {
    public:
        
        int _data;
        Node* _next;
        Node* _previous;
        Node();
        ~Node();
        
    };
    
public:
    
    Node* _head;
    Node* _tail;
    int _size;
    
    CDLL();
    ~CDLL();
    
    void addData(int data); //Add a node to the linked-list and adds data in it
    int size();
    void incrementHead();
    void decrementHead();
    void swap(unsigned int src,unsigned int dst);///will swap the data in the 2 nodes (easier than swapping the nodes themselves)
    int getData(unsigned int i);
    Node* nodeTraversal (int n); //this function will traverse to the node we are looking for : Used by swap function
    
    
};


