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

#ifndef TreeSearch_H_
#define TreeSearch_H_

#include <list>
#include <set>
#include <exception>

#include "Tree.h"
#include "algorithms/Algorithms.h"

/**
 * Proxy class for structuring the search. Embeds the algorithm passed as template parameter.
 *
 * @note Algorithm template parameter is disabled right now.
 */
template <typename TreeType, typename SearchAlgorithm/* = BreadthFirstSearch<TreeType>*/ >
class TreeSearch
{
  public:
   /**
    * Renaming a list of Paths.
    *
    * @todo Move to Path class.
    */
    typedef std::list< Path<TreeType>* > PathList;
   /**
    * Renaming of the data type stored in each node which must match the one used to define if the 
    * goal has been reached.
    */
    typedef typename TreeType::value_type::value_type GoalType;

   /**
    * List of Paths reaching the frontier. Used by all algorithms.
    *
    * @todo Move into algorithms, not needed anywhere else.
    */
    PathList _frontier;
   /**
    * Set of Nodes already explored. Used by all algorithms.
    *
    * @todo Move into algorithms, not needed anywhere else.
    */
    std::set<typename TreeType::value_type*> _explored;
   /**
    * Pointer to the Root Node of the Tree to be Searched.
    *
    * @note Redundant? Replaceable by Tree* and its memeber getRootPtr(). Searching a subtree would
    * require defining a Tree object containing only the subtree.
    */
    typename TreeType::value_type* TreeRoot;

   /**
    * Constructor.
    */
    TreeSearch(typename TreeType::value_type* mNode) : TreeRoot( mNode ) { _frontier.push_back( new Path<TreeType>(TreeRoot) ); }
   /**
    * Function for applying the algorithm to the Tree. 
    *
    * @param The goal we want to achieve.
    * @returns The best path according to the algorithm used.
    */
    Path<TreeType>* find(GoalType Goal)
    {
    /*
     Notes: A compare function must be specified to the set container.

     Pseudocode:
     Function TreeSearch(problem):
        frontier = {[initial]}
        loop:
            if frontier is empty: FAIL
            path = remove_choice(frontier)
            s = path.end
            if s is a goal: return path
            for a in actions:
                add [path + a -> Result(s, a)] to frontier
     */

    // Reuse variables instead of creating and destroying in the loop.
        Path<TreeType>* path;
        typename TreeType::value_type* Node;

// Tries using SearchAlgorithm as holder of the actual algorithm implementation.
//        SearchAlgorithm sa();
//        return sa.find(Goal);

    // Loop
        while(true)
        {
        // Sanity check
            if(_frontier.empty()) throw( std::exception() );
        // Get the shortest path on the frontier.
            path = _frontier.front();
        // Remove the path from the frontier.
            _frontier.remove(path);
        // Add the last Node of the path (Frontier Node) to the explored Nodes.
            Node = path->_path.back();
            _explored.insert(Node);
        // Check if the present Node is our goal.
            if (Node->Data == Goal) return path;

       // If 0 Node is a leaf Node and shouldn't be looked further.
            if( Node->has_children() != 0 )
            {
            // For all children.
                for(int i = 0; i < Node->child_number; ++i)
                {
                // Check if the child to be attached has been explored already.
                // Attach only the non-explored yet.
                    if( _explored.find(Node->child[i]) == _explored.end() )
                    {
                    // Add the checked Nodes children to a copy of the present path
                    // and add this path to _frontier. If 0 is a leaf Node.
                        Path<TreeType>* newpath = new Path<TreeType>(*path);
                        newpath->_path.push_back(Node->child[i]);
                        _frontier.push_back(newpath);
                    }
                }
            // Sort the _frontier list so the shortest paths are at the beginning
            // of the list.
                _frontier.sort();     
            }
        }
    }// End of find()
};// End of TreeSearch

#endif

