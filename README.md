# Binary KD-Trees

### Introduction
***
This README provides an overview and basic guide for understanding and using the implementation of **k-dimensional binary trees (k-d trees)**. 
K-d trees are data structures used to organize k-dimensional points in a multidimensional space to facilitate efficient operations such as search and retrieval. In this project, we have implemented standard k-d trees along with procedures to create them empty, insert k-dimensional keys, and destroy them once all necessary searches are completed.

### Authorship
***
This work has been prepared by :
- JFocking Konde
- David Benedicto
- Pau Martinez
- Jialiang Li

### Files
***
The project consists of one _.cc_ and one _.hh_: file:
- **kdtree.hh**: This file contains the declaration of the KDTree class, which represents the k-dimensional tree and defines its methods.
- **kdtree.cc**: This file contains the implementation of the methods of the KDTree class.

### Documentation
***
The first file consists of the next functions, which do the following:
> `KDTree::KDTree()`: Constructor for an empty k-d tree.
> `KDTree::KDTree(const std::vector<Point>& points)`: Constructor that builds a k-d tree from a vector of points.
> `KDTree::KDTree(int N, int K)`: Constructor that generates a k-d tree with random points.
> `KDTreeNode* KDTree::createNode(const Point& p)`: Creates a new node in the k-d tree with the specified point.
> `KDTreeNode* KDTree::insertPoint(KDTreeNode* r, const Point& p, int depth)`: Inserts a k-dimensional point into the tree.
> `void KDTree::insert(const Point& p)`: Method to insert a point into the tree.
> `void KDTree::printNode(const Point& p, int n)`: Prints a point with formatting.
> `void KDTree::print()`: Prints the k-d tree.
> `void KDTree::destroyTree(KDTreeNode* node)`: Destroys the k-d tree and frees memory.
> `float KDTree::dist(const Point& a, const Point& b)`: Calculates the squared distance between two points.
> `KDTreeNode* KDTree::closest(const Point& n, KDTreeNode* temp, KDTreeNode* r)`: Finds the closest point to a given point.
> `Point KDTree::nearestNode(const Point& p)`: Finds the nearest node to a given point.
> `KDTreeNode* KDTree::nearestNode(KDTreeNode* r, const Point& n, int depth, int& nodeExpanded)`: Helper function for finding the nearest node.
> `void KDTree::printPoint(const Point& p)`: Prints a point.

The second file, `kdtree.hh`, contains the class definition for KDTree and the Point data type, along with declarations of the methods described above.

