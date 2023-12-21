#include "BinarySearchTree.h"

template<class DataType>
BinarySearchTree<DataType>::BinarySearchTree()
{
    root=nullptr;
    length=0;
    std::queue<DataType> inOrder;
}
template<class DataType>
void BinarySearchTree<DataType>::deepCopy(const Node<DataType>* tree)
{
    if(tree==nullptr){return;} // return if node is null
    this->putItem(tree->value); // put value of a node from rhs to lhs
    deepCopy(tree->left); // move to left
    deepCopy(tree->right); // move to right
}
template<class DataType>
BinarySearchTree<DataType>::BinarySearchTree(const BinarySearchTree<DataType> &rhs) //traverse BST in PreOrder
{
    root=nullptr;
    length=0;
    this->deepCopy(rhs.root);
}


template<class DataType>
BinarySearchTree<DataType>::~BinarySearchTree()
{
    deleteAll(root);
}

template<class DataType>
int BinarySearchTree<DataType>::getLength()
{
    return length;
}

template<class DataType>
bool  BinarySearchTree<DataType>::insert(Node<DataType>*root,Node<DataType> * newNode)
{
    if (root->value==newNode->value){return false;} // return false if the item was
    // already existed to make sure the item was not added again
    if (root==nullptr) // if tree is empty, we assign new node as a root
    {
        root=newNode;
        length++;
        return true;
    }
    if (root->value >newNode->value) // if value of root > item -> move to the left
    {
        if (root->left==nullptr)  //if the left side of root is null
        {
            root->left=newNode; // assign root's left to new node
            length++;
            return true;
        }
        else // recursively call insert method to find appropriate position to insert item
        {
            return insert(root->left,newNode);
        }
    }
    else // if value of root < item -> move to the right and do the same process
    // that we do above
    {
        if (root->right==nullptr)
        {
            root->right=newNode;
            length++;
            return true;
        }
        else
        {
            return insert(root->right,newNode);
        }
    }
}

template<class DataType>
bool BinarySearchTree<DataType>::putItem(const DataType &item)
{
    Node<DataType> * temp = new Node<DataType>; // create new node holds value
    // that users want to insert
    temp->value = item;
    temp->left = temp->right = nullptr;
    if(root==nullptr)
    {
        root=temp;
        length++;
        return true;
    }
    return insert(root,temp);
}
template<class DataType>
Node<DataType> *  BinarySearchTree<DataType>::find(Node<DataType>*tree, const DataType &item) const
{
    if (tree==nullptr) {return nullptr;}
    else if (tree->value==item) {return tree;}
    else if  (tree->value > item) {return find(tree->left,item);}
    else {return find(tree->right,item);}
}
template<class DataType>
bool BinarySearchTree<DataType>::getItem(const DataType &item, DataType &found_item)
{
    Node<DataType> *foundNode=find(root,item);
    if (foundNode!=nullptr)
    {
        found_item=foundNode->value;
        return true;}
    else
    {
        return false;
    }
}

template<class DataType>
bool BinarySearchTree<DataType>::isFull() {
    return false;
}

template<class DataType>
void BinarySearchTree<DataType>::deleteAll(const Node<DataType> *tree)
{
    if (tree==nullptr){return;}
    deleteAll(tree->right);
    deleteAll(tree->left);
    delete tree;
}
template<class DataType>
void BinarySearchTree<DataType>::makeEmpty()
{
    deleteAll(root);
    length=0; //after delete all nodes, set length =0 and root to nullptr
    root=nullptr;
}

template<class DataType>
void BinarySearchTree<DataType>::resetList() {
    //this is a nice fast way to reset the queue to blank
    std::queue<int> empty;
    std::swap( inOrder, empty );
    loadQueueInOrder(root);
}
template<class DataType>
void BinarySearchTree<DataType>::loadQueueInOrder(Node<DataType> *tree)
{
    if(tree==nullptr){return;} // return when the node is nullptr
    loadQueueInOrder(tree->left); // move to left side of node until node is nullptr
    inOrder.push(tree->value); // put the value into inOrder queue
    loadQueueInOrder(tree->right); // move to right side of node until node is nullptr
}
template<class DataType>
bool BinarySearchTree<DataType>::getNextItem(DataType &item) {
    if (inOrder.empty()){return false;}
    item=inOrder.front();
    inOrder.pop();
    return true;
}
template<class DataType>
Node<DataType>*  BinarySearchTree<DataType>:: min(Node<DataType>* tree)
{
    loadQueueInOrder(tree);
    return find(tree,inOrder.front());
}
template<class DataType>
Node<DataType>*  BinarySearchTree<DataType>:: max(Node<DataType>* tree)
{
    loadQueueInOrder(tree);
    return find(tree,inOrder.back());
}
template<class DataType>
bool BinarySearchTree<DataType>::min(DataType &found_item)
{
    if (root==nullptr){return false;}
    Node<DataType> *found = min(root);
    if (found!=nullptr)
    {
        found_item=found->value;
        return true;
    }
    return false;
}

template<class DataType>
bool BinarySearchTree<DataType>::max(DataType &found_item)
{
    if (root==nullptr){return false;}
    Node<DataType> *found = max(root);
    if (found!=nullptr)
    {
        found_item=found->value;
        return true;
    }
    return false;
}
template<class DataType>
bool BinarySearchTree<DataType>::remove(Node<DataType>* tree, const DataType &item)
{
    Node<DataType> * curr =tree;
    Node<DataType> * parent = nullptr;
    while(curr!=nullptr)
    {
        if (curr->value==item)
        {
            if (curr->right==nullptr && curr->left ==nullptr) // the node is leaf node
            {
                if (parent==nullptr) // the node is also root
                {
                    root=nullptr;
                }
                else if (parent->left==curr)
                {
                    parent->left=nullptr;
                }
                else
                {
                    parent->right=nullptr;
                }
                length--;
                return true;
            }
            else if (curr->right==nullptr) // node with only left child
            {
                if (parent==nullptr) {root=curr->left;} //the node is also root
                else if (parent->left==curr) // if the node is a left child of parent node
                {
                    parent->left=curr->left; // assign left parent's pointer points to left value of the curr node
                }
                else // if the node is right child
                {
                    parent->right=curr->left; // assign right parent's pointer points to left value of curr node
                }
                length--;
                return true;
            }
            else if (curr->left==nullptr) // node with only right child
            {
                if (parent==nullptr) {root=curr->right;} //the node is also root
                else if (parent->left==curr)
                {
                    parent->left=curr->right;
                }
                else
                {
                    parent->right = curr->right;
                }
                length--;
                return true;
            }
            else // with 2 children
            {
                Node<DataType> * next = min(curr->right);
                DataType data = next->value; // store min value of right subtree in data variable
                remove(root,next->value); // recursively call remove function since the next node
                // might have one or no children
                curr->value=data; // assign the data to value of curr node
                return true;
            }
        }
        else if (curr->value>item) //search left
        {
            parent=curr;
            curr=curr->left;
        }
        else // search right
        {
            parent=curr;
            curr=curr->right;
        }
    }
    return false;
}

template<class DataType>
bool BinarySearchTree<DataType>::deleteItem(const DataType &item)
{
    return remove(root,item);
}



template<class DataType>
void BinarySearchTree<DataType>::operator=(const BinarySearchTree<DataType> &rhs){
    this->deleteAll(root);
    deepCopy(rhs.root);
}
