#include <queue>
#ifndef NODE
#define NODE

template <class DataType>
struct Node {
    DataType value;
    Node<DataType>* left = nullptr;
    Node<DataType>* right = nullptr;
};
#endif


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
/**
 * BinarySearchTree class contains attributes and implementation of methods used in BST
 * BST helps users store numbers as a sorted list
 */
template <class DataType>
class BinarySearchTree {
public:

    // Section 1
    /**
     * Constructor is used to assign initial values for attributes of
     * objects in the class
     */
    BinarySearchTree();
    /**
     *  Destructor safely deletes all the tree nodes to avoid memory leak
     */
    ~BinarySearchTree();
    /**
    * The function returns the length of the tree
    * @return length of tree
    */
    int getLength();
    /**
    * The function inserts new items into the tree in an appropriate position. If that value already exists in the tree
    * then return false to indicate the item was not
    * added again. BST should follow these properties:
    * - All nodes of left subtree are smaller than the root node
    * - All nodes of right subtree are larger than the root node
    * - Both subtrees of each node are also BST
    * @param item - the item (value) that users want to put in the tree
    * @return true if the item was successfully inserted
    * @see insert, a recursive helper method used by this method to insert node
    */
    bool putItem(const DataType &item);
    /**
    * The function finds the item in the tree and assigns that item to found_item variable.
    * @param item - item that users want to find
    * @param found_item - used to assign the value of found item
    * @return true if the item was found and false if not
    * @see find, a helper method used by this method to traverse the tree finding the
    * node containing the item
    */
    bool getItem(const DataType &item, DataType &found_item);
    /**
    * The function checks whether the tree is full or not
    * @return - true if the list is full, and false if not
    */
    bool isFull();
    /**
    * The function sets the tree to empty
    * @see deleteAll, a helper function used by this method to delete all
    * nodes in the tree
    */
    void makeEmpty();
    /**
    * The function resets the queue (using to store values of tree) and recursive loadQueueInOrder
    * method to populate the inOrder queue in order
    * @see deleteAll, a helper function used by this method to delete all
    * nodes in the tree
    */
    void resetList();
    /**
     * The function sets item value to the value at the front of the queue and pop that item off the queue
     * @param item - values in the tree are assigned to the item variable
     * @return true if there was an item left in the queue and false if not
     */
    bool getNextItem(DataType &item);

    // Section 2
    /**
     * The method sets &found_item to the max value in the tree
     * @param found_item - max value in the tree will be assigned to the variable
     * @return true if the max is found and false if the tree is empty
     */
    bool max(DataType &found_item);
    /**
     * The method sets &found_item to the min value in the tree
     * @param found_item - min value in the tree will be assigned to the variable
     * @return true if the min is found and false if the tree is empty
     */
    bool min(DataType &found_item);
    /**
     * The method deletes the item that users want. There are three cases of deleted node:
     * - Has no children
     * - Has only one child (left or right)
     * - Has two children
     * @param item - value that we want to delete
     * @see remove - a helper function is used to remove a node out of the tree
     * @return true if the item is in the list and is deleted successfully; otherwise, return false
     */
    bool deleteItem(const DataType &item);

    // Section 3
    /**
    * Copy constructor does a deep copy to copy all values of one tree to another tree
    * @param rhs - the object that we want to copy its data
    * @see deepCopy, a helper function to copy the tree in preorder
    * @see deleteAll, a helper function is called before creating new tree so that old values do not
    * survive after the assginment
    */
    void operator=(const BinarySearchTree<DataType> &rhs);
    /**
    * Copy constructor does a deep copy to copy all values of one tree to another tree
    * @param rhs - the object that we want to copy its data
    * @see deepCopy, a helper function to copy the tree in preorder
    */
    BinarySearchTree(const BinarySearchTree<DataType> &rhs);

private:
    /**
     * The recursive method is used to insert a new node into the tree and make sure that
     * the node is inserted follow the rule of BST
     * @param root - a root of the tree
     * @param newNode - a node holds value of item that users want to insert
     * @return true if the insertion is successful and false if not
     */
    bool insert(Node<DataType>*root,Node<DataType>*newNode);
    /**
     * The recursive method is used to find a specific node in the tree
     * @param tree - root of the tree
     * @param item - value of item that we want to find
     * @return a node (pointer) of the node that we want to find
     */
    Node<DataType> * find(Node<DataType>*tree, const DataType &item) const;
    /**
     * The recursive method is used to find node with min value in the tree
     * @param tree - root of the tree
     * @return  node (pointer) of the node with min value in the tree
     * @see loadQueueInOrder, a helper function that put values of tree in a queue in order
     */
    Node<DataType>* min(Node<DataType>* tree);
    /**
     * The recursive method is used to find node with max value in the tree
     * @param tree - root of the tree
     * @return  node (pointer) of the node with max value in the tree
     * @see loadQueueInOrder, a helper function that put values of tree in a queue in order
     */
    Node<DataType>* max(Node<DataType>* tree);
    /**
     * The recursive method is used to remove a node out of the tree
     * @param tree - a root of tree
     * @param item - a value of item that we want to delete
     * @return true if remove successfully the node, otherwise, return false
     */
    bool remove(Node<DataType>* tree, const DataType &item);
    /**
     * The recursive method is used to put all values of tree into a queue in postorder
     * @param tree - a root of the tree
     */
    void loadQueueInOrder(Node<DataType>* tree);
    /**
     * The recursive function traverse the tree via in preorder
     * to make a deep copy of all values in one tree to another
     * @param tree - root of tree
     */
    void deepCopy(const Node<DataType>* tree);
    /**
     * The recursive function is used to delete all nodes in the tree
     * @param tree - root of tree
     */
    void deleteAll(const Node<DataType>* tree);

    Node<DataType>* root;
    int length;
    std::queue<DataType> inOrder;
};

#endif //BINARYSEARCHTREE_H
