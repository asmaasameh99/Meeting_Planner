
#include "BST.h"
#include <string.h>
#include <stdio.h>
#include<iostream>
#include <cassert>
using namespace std;
BST::BST()
{           nulltree = true;
            lefttree=NULL;
            righttree=NULL;
}
///////////////////////////////////////////////////////
void BST :: ADD(const string & titleeee,const int dayyy, const int hr)
{
if (nulltree) {
nulltree = false;
lefttree = new BST;
righttree = new BST;
treedata = titleeee;
tday=dayyy;
thour=hr;
}
//
else if ( tday == dayyy && thour == hr)
	{
		cout<< "Conflict "<<dayyy<<" "<<hr<<endl;

	}

else if (tday == dayyy)
	{
		if (thour < hr )
			righttree->ADD(titleeee,dayyy,hr);
		else
			lefttree->ADD(titleeee,dayyy,hr);
	}
	else if (tday < dayyy)
		righttree-> ADD(titleeee,dayyy,hr);
	else
		lefttree-> ADD(titleeee,dayyy,hr);
//		cout<<treedata<<" "<<tday<<" "<<thour<<endl;
}

//////////////////////////////////////////////

BST* BST::left()
	{
		assert(!nulltree);
		return lefttree;
	}
///////////////////////////////////////////////////////////////////
BST* BST::right()
	{
		assert(!nulltree);
		return righttree;
	}

///////////////////////////////////////////////////////////////

bool BST :: isEmpty()
{
    return nulltree;
}

///////////////////////////////////

void BST::Display(){
    BST *check = this;

		 if(!check->nulltree){
		(check -> left())-> Display();
		cout << treedata <<" "<< tday << " " << thour << endl;
		(check -> right())-> Display();
		}
		else return;


	}
/////////////////////////////////////////////////////
bool BST::find( const int &Day,const int &Hour)
    {
        if(nulltree)
            cout<<"Empty "<< Day <<" " << Hour<<endl;
        else if (Day==tday)
        {
            if(Hour==thour)
                cout<< treedata<<endl;
            else if(Hour < thour)
                return lefttree->find( Day ,Hour);
            else if(Hour > thour)
                return righttree->find( Day,Hour);
        }
        else if(Day < tday)
            return lefttree->find( Day ,Hour);
        else if(Day > tday)
            return righttree->find( Day,Hour);
        else
            cout<<"Empty "<< Day <<" " << Hour<<endl;

            //cout<<"Empty" << Day <<" " <<Hour <<endl;
    }

////////////////////////////////////////////////////////////
bool BST::retreive( const int &Day,const int &Hour)
    {
        if(nulltree)
            cout<<"Empty "<< Day <<" " << Hour<<endl;
        else if (Day==tday)
        {
            if(Hour==thour)
                return true;
            else if(Hour < thour)
                return lefttree->retreive( Day ,Hour);
            else if(Hour > thour)
                return righttree->retreive( Day,Hour);
        }
        else if(Day < tday)
            return lefttree->retreive( Day ,Hour);
        else if(Day > tday)
            return righttree->retreive( Day,Hour);
        else
            cout<<"Empty "<< Day <<" " << Hour<<endl;

            //cout<<"Empty" << Day <<" " <<Hour <<endl;
    }





/////////////////////////////////////////////////////////
bool BST::modify( const string &name,const int &Day,const int &Hour)
    {
        if(nulltree)
            cout<<"Empty "<< Day <<" " << Hour<<endl;
        else if (Day==tday)
        {
            if(Hour==thour)
                treedata=name;
            else if(Hour < thour)
                return lefttree->modify(name, Day ,Hour);
            else if(Hour > thour)
                return righttree->modify( name,Day,Hour);
        }
        else if(Day < tday)
            return lefttree->modify(name, Day ,Hour);
        else if(Day > tday)
            return righttree->modify(name, Day,Hour);
        else
            cout<<"Empty "<< Day <<" " << Hour<<endl;

            //cout<<"Empty" << Day <<" " <<Hour <<endl;
    }

/////////////////////////////////////////////////////////////
bool BST::deletee(const int& Day , const int &Hour)
{
    if(nulltree)
    {
        return false; //tree is empty, removal failed
    }
    //Searching for node to delete
    bool node_found = false;
    BST* toDelete = this;

    while (!node_found && !(toDelete->nulltree))
    {
        if (Day > toDelete -> tday ||( (Day ==toDelete -> tday) && (Hour > toDelete -> thour)))
        {

            toDelete = toDelete-> righttree;
        }
        else if (Day < toDelete -> tday ||( (Day ==toDelete -> tday) && (Hour < toDelete -> thour)))
        {
            toDelete = toDelete -> lefttree;
        }
        else
        {
            node_found = true;
        }
    }

    if(!node_found) return false;

    //now toDelete should have the node to delete

    //Case 1 : The node to delete is a leaf node (no children)
    if (toDelete -> lefttree -> nulltree && toDelete -> righttree -> nulltree)
    {
        //Set it as a null tree  to denote that it is empty
        toDelete->nulltree = true;
        //Delete its nulltree children
        delete toDelete->lefttree;
        toDelete->lefttree = NULL;
        delete toDelete->righttree;
        toDelete->righttree = NULL;
        return true;
    }
    //Case 2 : The node to delete only has a left subtree
    if (! toDelete -> lefttree -> nulltree && toDelete -> righttree -> nulltree)
    {
        //Searching for a node to replace the node to delete while keeping the tree a correct BST. The node to replace must be greater than all the elements in its left
        //subtree. The node the node that satisfies this condition is the biggest node in the leftsubtree which can be found and the most right node in the left subtree
        BST* toReplace = toDelete -> lefttree;
        while(!toReplace -> righttree -> nulltree) // Stop when there is no longer any more nodes to the right
        {
            toReplace = toReplace -> righttree;//Move to the right
        }
        //Swap nodes
        string temp1 = toReplace -> treedata;
		int temp2 = toReplace -> tday;
		int temp3 = toReplace -> thour;
        toReplace -> treedata = toDelete -> treedata;
        toDelete -> treedata = temp1;
		toReplace -> tday = toDelete -> tday;
        toDelete -> tday = temp2;
		toReplace -> thour = toDelete -> thour;
        toDelete -> thour = temp3;

        //Now we want to delete the toReplace node but it on its own might have its own children in the left subtree so we call remove for it again and not simply delete
        //This will be called multiple times until a leaf node is reached and at that point a true will be returned and the leaf node will be deleted
        return toReplace -> deletee(toReplace -> tday ,toReplace -> thour );
    }
    //Case 3 : The node to delete only has a right subtree
    if (toDelete -> lefttree -> nulltree && ! toDelete -> righttree -> nulltree)
    {
        //Searching for a node to replace the node to delete while keeping the tree a correct BST. The node to replace must be smaller than all the elements in its right
        //subtree. A node that satisfies this condition is the smallest node in the right subtree which can be found as the most left node in the right subtree
        BST* toReplace = toDelete -> righttree;
        while(!toReplace -> lefttree -> nulltree) // Stop when there is no longer any more nodes to the left
        {
            toReplace = toReplace -> lefttree;//Move to the left
        }
        //Swap nodes
        string temp1 = toReplace -> treedata;
		int temp2 = toReplace -> tday;
		int temp3 = toReplace -> thour;
        toReplace -> treedata = toDelete -> treedata;
        toDelete -> treedata = temp1;
		toReplace -> tday = toDelete -> tday;
        toDelete -> tday = temp2;
		toReplace -> thour = toDelete -> thour;
        toDelete -> thour = temp3;

        //Now we want to delete the toReplace node but it on its own might have its own children in the right subtree so we call remove for it again and not simply delete
        //This will be called multiple times until a leaf node is reached and at that point a true will be returned and the leaf node will be deleted
        return toReplace -> deletee(toReplace -> tday,toReplace -> thour);
    }
    //Case 4 : The node to delete only has both left and right subtree
    // While this condition is completely unecessary and this while branch could be merged with the previous one, I am just separating it to make the code more easy to read
    if (! toDelete -> lefttree -> nulltree && ! toDelete -> righttree -> nulltree)
    {
        //Searching for a node to replace the node to delete while keeping the tree a correct BST. The node to replace must be smaller than all the elements in its right
        //subtree and greater than all the nodes in its left subtree. Two nodes can satisfy this condition. Either the most left node in the right subtree or the most right
        //node in the left subtree. Here we choose the most left node in the right subtree but the other would work too.
        BST* toReplace = toDelete -> righttree;
        while(!toReplace -> lefttree -> nulltree) // Stop when there is no longer any more nodes to the left
        {
            toReplace = toReplace -> lefttree;//Move to the left
        }
        //Swap nodes

		string temp1 = toReplace -> treedata;
		int temp2 = toReplace -> tday;
		int temp3 = toReplace -> thour;
        toReplace -> treedata = toDelete -> treedata;
        toDelete -> treedata = temp1;
		toReplace -> tday = toDelete -> tday;
        toDelete -> tday = temp2;
		toReplace -> thour = toDelete -> thour;
        toDelete -> thour = temp3;

        //Now we want to delete the toReplace node but it on its own might have its own children in the right subtree so we call remove for it again and not simply delete
        //This will be called multiple times until a leaf node is reached and at that point a true will be returned and the leaf node will be deleted
        return toReplace -> deletee(toReplace -> tday,toReplace->thour);
    }
}




//////////////////////////////////////////////////////////////////
BST::~BST()
{
    //dtor
}












////
//else if (d == treedata); // do nothing -- it's already here!
//else if (d < treedata)
//{lefttree->insert(d);} // insert in left subtree
//else
//righttree->insert(d); // insert in right subtree
//cout<<treedata<<endl;
//}


















//BST :: node* BST ::  makeEmpty(node* t)
//    {
//        if(t == NULL)
//            return NULL;
//        {
//            makeEmpty(t->left);
//            makeEmpty(t->right);
//            delete t;
//        }
//        return NULL;
//    }
//
//BST :: node* BST ::insert(const string &name,int Day,int Hour, node* t)
//    {
//        if(t == NULL)
//        {
//            t = new node;
//            t->data = name;
//			t->day=Day;
//			t->hour=Hour;
//            t->left = t->right = NULL;
//        }
//		else if (Day==t->day)
//		{
//			if (Hour==t->hour)
//				cout<<"Conflict "<<Day<<" " << Hour<<endl;
//            else if (Hour < t->hour)
//                t->left=insert(name,Day,Hour,t->left);
//            else if (Hour > t->hour)
//                t->right=insert(name,Day,Hour,t->right);
//		}
//
//        else if(Day < t->day)
//            t->left = insert(name,Day,Hour, t->left);
//        else if(Day > t->day)
//            t->right = insert(name,Day,Hour, t->right);
//		else if (Hour < t->hour)
//			t->left=insert(name,Day,Hour,t->left);
//		else if (Hour > t->hour)
//			t->right=insert(name,Day,Hour,t->right);
//        return t;
//    }
//BST :: node* BST ::  findMin(node* t)
//    {
//        if(t == NULL)
//            return NULL;
//        else if(t->left == NULL)
//            return t;
//        else
//            return findMin(t->left);
//    }
//
//BST :: node* BST :: findMax(node* t)
//    {
//        if(t == NULL)
//            return NULL;
//        else if(t->right == NULL)
//            return t;
//        else
//            return findMax(t->right);
//    }
//
//    void ::BST:: inorder(node* t)
//    {
//        if(t == NULL)
//            return;
//        inorder(t->left);
//        cout << t->data << " " << t->day <<" "<<t->hour<<endl;
//        inorder(t->right);
//    }
//void::BST :: display()
//    {
//        inorder(root);
//        cout << endl;
//    }

//BST::~BST()
//{//root = makeEmpty(root);
//    //dtor
//}
