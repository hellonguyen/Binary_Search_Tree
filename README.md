# Binary_Search_Tree

## Why the project matters?
The project will help me gain better understanding of Trees, especially Binary Search Trees. It will prepare me for topics in algorithm analysis and time complexity. Furthermore, BST project will deepen my understanding of recursion pointers, and algorithms. 

## BST Interface

***Constructor:*** the constructor is make sure the root is set to nullptr and the length starts out set to 0.

***Deconstructor:*** The Deconstructor should safely delete all the tree nodes.

***int getLength():*** return the value of length.

***bool putItem(const DataType &item):*** This method will add a value to the tree, returning true if it succeeds. If that value already exists in the tree then return false to indicate the item was not added again. Every node on the left side of a node should have a value less than the tree root's node and all the values to the right child should have values greater than the value of the tree root's node.

***bool getItem(const DataType &item, DataType &found_item):*** The getItem method will search the tree for a value. The method should return a true if the value is found and a false if the value is not found.

***bool isFull():*** Returns false, always.

***void makeEmpty():*** The method safely deletes all the nodes. Then set the length to 0 and root to nullptr.

***bool getNextItem(DataType &item):*** The getNextItem simply needs to set the &item value to the value at the front of the queue and pop that item off the queue. This item should return true as long as there was an item left in the queue and false once the queue is empty.

***bool max(DataType &found_item):*** This method sets the &found_item variable to the maximum value in the tree. The method should return true if there was a value and false if the tree is empty.

***bool min(DataType &found_item):*** The min Method works just like max but for the Minimum value.

***bool deleteItem(const DataType &item):*** The method should return false if the value is not found in the tree and true if it was found and deleted. There are three cases: 
  1. The node being deleted has no children
  2. The Node being deleted has one child. Sub concern will be if the child is on the right or left.
  3. The Node being deleted has two children.

**An Assignment Operator and the Copy Constructor. Both of these will need to do a deep copy so that all the values of the tree are copied to the other tree, not the pointers to the root tree**

***void operator=(const BinarySearchTree &rhs):*** We call deleteAll before creating the new tree so that old values do not survive after the assignment.

***BinarySearchTree(const BinarySearchTree &rhs:***
