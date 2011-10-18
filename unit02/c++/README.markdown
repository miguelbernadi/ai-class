C++ Implementation - Miguel Bernabeu Diaz < miguel.bernadi[AT]gmail[DOT]com >
=============================================================================

Last modified: 2011/10/18

This project is based on the 2011 edition of "Stanford Online Introduction to Artificial Intelligence" (www.ai-class.com).
The code of file 'example.cpp' is released in the Public Domain. All other code is licensed under MIT License (http://www.opensource.org/licenses/mit-license.php).

README TOC
----------

 * Algorithms
 * Examples
 * Known Problems
 * BUGS
 * TODO

Algorithms
----------

All algorithms are basically the same, the difference is how they determine the best next path. For that purpose the algorithms are described simply as value compare functions. The goal of those value compare functions is to return the smallest positive value for the best option.

All algorithm headers are stored in folder algorithm/ .

 * Breadth First Search  (BFS) => Implemented
 * Uniform Cost Search   (UCS)
 * Cheapest First Search (CFS)	
 * Depth First Search    (DFS)
 * A\* Search            (ASS)

Examples
--------

You can find an usage example of the code in the file 'example.cpp'. The headers are commented with Doxygen (http://www.stack.nl/~dimitri/doxygen/index.html) comments.

Known Problems
--------------

There's no known Problems right now.

BUGS
----

If you find any bugs, please contact me at the email addressed above or post an issue at https://github.com/miguelbernadi/ai-class/issues . 

TODO
----

 * Fix Algorithm usage via template parameter (actually disabled)
 * Implement all listed algorithms
 * Rationalize interfaces (adders/removers, setters/getters, const-correctness, references, data exposure...)
 * Document whole code
 * C++0x Features? (optional by compile flag?)

