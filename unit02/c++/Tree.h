/*
 * The MIT License (MIT)
 * Copyright (c) 2011 Miguel Bernabeu Diaz <miguel.bernadi[AT]gmail[DOT]com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef Tree_H_
#define Tree_H_

#include <list>

/**
 * Class representing a Binary Tree.
 */
template<typename TreeNode>
class Tree
{
  public:
  /**
   * Standard facility for accessing the instantiated type from the outside.
   *
   * @note This will no longer be needed since C++0x's auto keyword.
   */
    typedef TreeNode value_type;
   /**
    * A list of Node objects.
    */
    typedef std::list< value_type* > TreeNodeList;

   /**
    * Constructor.
    */
    Tree() : _rootNode(0) { }
   /**
    * Destructor.
    */
    ~Tree() { delete _NodeList; }
   /**
    * Accessor to the Tree's Root Node.
    */
    value_type* getRootPtr() { return _rootNode; }
   /**
    * Setter for the Tree's Root Node.
    */
    void setRoot(value_type* rootNode) { _rootNode = rootNode; _NodeList.push_back( _rootNode ); }
   /**
    * Utility for adding a Node to the Tree.
    */
    void addNode(value_type* Node) { _NodeList.push_back(Node); }
   /**
    * Utility for removing a Node from the tree.
    */
    void removeNode(value_type* Node) { _NodeList.remove(Node); }

  private:
   /**
    * Internal list of Nodes belonging to this tree.
    */
    TreeNodeList _NodeList;
   /**
    * Pointer to the Root Node.
    *
    * @note Root Node's parent should be null. Otherwise the Tree would be a subtree.
    */
    value_type* _rootNode;

}; // End of Tree definition.

/**
 * Class representing a Node of the Tree.
 *
 * @param _Data Is the information structure stored in the node.
 * @param nChild Defines the maximum amount of childs a certain Node may have.
 */
template<typename _Data, int nChild = 2>
class TreeNode
{
  private:

  public:
   /**
    * Standard facility for accessing the instantiated type from the outside.
    *
    * @note This will no longer be needed since C++0x's auto keyword.
    */
    typedef _Data value_type;
   /**
    * Amount of childs a Node might have at most.
    *
    * @note Needed?
    */
    int child_number;

   /**
    * Node contained information.
    */
    value_type Data;
   /**
    * Pointer to parent Node.
    */
    TreeNode<value_type>* parent;
   /**
    * Fixed-size array containing pointers to children Nodes.
    */
    TreeNode<value_type>* child[nChild];

   /**
    * Constructor.
    */
    TreeNode(value_type Data) : child_number(nChild), Data(Data), parent(0) { }
   /**
    * Destructor.
    */
    ~TreeNode() { for(int i = 0; i < child_number; ++i) delete child[i]; }

   /**
    * Returns the number of child pointers different to null.
    *
    * @todo Redesign and reimplement. Doesn't follow code conventions.
    */
    int has_children() { int childs = 0; for(int i = 0; i < child_number; ++i) { if(child[i] != 0) ++childs; } return childs;  }

};// end of TreeNode definition

#endif

