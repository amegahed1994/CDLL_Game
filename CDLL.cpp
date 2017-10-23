//  CDLL.cpp

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
        Node()
        {
            //cout<<"Node constructor reached"<<endl;
            _next = NULL;
            _previous = NULL;
        }
        ~Node(){
            //cout<<"Node Deconstructor reached"<<endl;
        }
        
    };
    
public:
    
    Node* _head;
    Node* _tail;
    int _size;
    
    CDLL(){
        //cout<<"Linked List Constructor reached"<<endl;
        _head = NULL;
        _tail = NULL;
        _size = 0;
    }
    ~CDLL(){
        //cout<<"Linked List Deconstructor reached"<<endl;
        
        //If you delete first node and deallocate memory you will not gurantee that you will be able to jump the next node
        //Therefore we need to free memory from last node to first
        
        while (_size) //When the size reaches zero that means that all the nodes have been deleted
        {
            Node *temp = _tail -> _previous;
            delete _tail;
            _size--;
            _tail = temp;
        }
    }
    
    void addData(int data) //Add a node to the linked-list and adds data in it
    {
        Node* _newNode = new Node;
        _newNode->_data = data;
        
        //If head equal NULL , this means that the list is empty and contains no nodes at all
        if (_head == NULL){
            _tail = _newNode;
            _head = _newNode;
            _newNode -> _next = _newNode;
            _newNode -> _previous = _newNode;
            //I have implemented the next and previous of the first node to point to itself in this special case
            //when the LL is empty
        }
        else{
            _tail->_next = _newNode;
            _head -> _previous = _newNode;
            _newNode -> _previous = _tail;
            _newNode -> _next = _head;
            _tail = _newNode;
        }
        _size++; //This will keep state LL size
    }
    int size()
    {
        return _size;
    }
    void incrementHead() //will advance head to next node
    {
        if (_size == 0) cout<<"The Linked List contains no nodes/is empty: Action Forbiden"<<endl;
        else _head = _head -> _next;
    }
    void decrementHead()  //will move head to previous node
    {
        if (_size == 0) cout<<"The Linked List contains no nodes/is empty: Action Forbiden"<<endl;
        else _head = _head -> _previous;
    }
    void swap(unsigned int src,unsigned int dst)///will swap the data in the 2 nodes (easier than swapping the nodes themselves)
    {
        //Note node 0 is the first node. This is not matlab we start with 0 here!!
        if ( ((src+1) >_size ) || ((dst+1) > _size))
        {
            cout<<"Linked List Out of bounds: Note element 0 in the LL is the first element"<<endl;
        }
        else //traverse to these nodes and replace elements
        {
            
            Node *tempSrc = nodeTraversal(src); //Traversing to the node we are looking for and getting back its address
            Node *tempDst = nodeTraversal(dst); //Doing the same for the dst node
            int srcTemp = tempSrc -> _data;     //In the next three lines we are exchanging the data contained in these nodes.
            tempSrc -> _data = tempDst -> _data;
            tempDst -> _data = srcTemp;
        }
    }
    int getData(unsigned int i)
    {
        Node *_temp;
        _temp = _head;
        int _tempData = 99;
        
        if (i >= _size) //The less than zero inequality is tested automatically because the input is unsigned
            //The if sttmnt would be (i<0 || i>= _size) if input was signed
        {
            cout<<"Linked List Out of Bounds Exception"<<endl;
        }
        else
        {
            for (int t =0; t<i; t++)
            {
                _temp = _temp -> _next;
            }
            
        }
        _tempData = _temp->_data;
        return _tempData;
        
    }
    Node* nodeTraversal (int n) //this function will traverse to the node we are looking for : Used by swap function
    {
        //This function will traverse to the ith node
        
        Node *temp = _head;
        
        for (int i =0; i< n ; i++)
        {
            temp = temp->_next;
        }
        return temp;
    }
    
    
};


