#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include<string.h>
#include <iostream>
#include <cassert>
using namespace std;
//template < class btElementType >
class BST
{

    public:
        BST();
        virtual ~BST();
        void ADD(const string & d,const int day, const int hour);
        BST* right();
        BST* left();
        void Display();
        bool isEmpty();
        bool find(const int &day, const int &hour);
		bool retreive(const int &day, const int &hour);
        bool modify( const string &name,const int &Day,const int &Hour);
		bool deletee(const int& Day , const int &Hour);
//        node* makeEmpty(node* t);
//        node* insert(const string &name,int Day,int Hour, node* t) ;
//        node* findMin(node* t);
//        node* findMax(node* t);
//        void  inorder(node* t);
//        void display();
    protected:

    private:
    bool nulltree;
	string treedata;
	int thour;
	int tday;
	BST* lefttree;
	BST* righttree;

};



#endif // BST_H_INCLUDED
