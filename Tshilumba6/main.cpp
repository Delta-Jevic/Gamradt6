#include "BST.h"
#include <iostream>
using namespace std;


int
main()
{

    TElement letter = "A";
    BST mytree = BST();
    
    mytree.insert(letter);
    mytree.inView();
    
    return 0;
}