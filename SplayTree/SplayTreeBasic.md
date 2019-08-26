rotation principle
	interchange the root with one of its children:
	right rotation: interchange root and left child, this means its right child moves
	to the root's left child, and root moves to its right child
	left rotation: interchange root and right child, this means its left child moves 
	to the root's right child, and root moves to its left child

============================

root insertion
	actually means leaf insertion plus enough left/right rotations to get the leaf to
	the root--> the structure can change a lot by doing this
	in a heap we inserted at the leaf and then did a fix up towards the root
	--> the structure does not change(because we only swap data between parent and child)

============================

balanced trees
Approach 1: Global rebalancing
Insert nodes normally at leaves
Basic idea: move the median to the root of the tree
recursively: get the median of the left subtree and move it to the root of the left subtree
			 get the median of the right subtree and move it to the root of the right subtree

Approach 2: Local rebalancing
	the BST keeps itself 'balanced' as a 'side effect' of certain operations, such as insert
	and delete node, the BST is said to be self-balancing, the aim is the same: avoid worst-case
	behaviour by reducing BST height to log(n)
	thus, a Splay tree is a self-balancing BST the reason that self-balancing gives us O(logN)
	performance is called amortisation-->insertion, search and delete are done in O(logN) 
	amortized time

============================

In summary

search for an item in a splay tree
	the found item is splayed
	if not found, the last accessed item is splayed
insertion of an item in a splay tree
	the new item is splayed
deletion of an item in a splay tree
	the parent of the item that replaces the deleted item is splayed
search for the minimum/maximum is splayed

A 'splay' of an item involves
	ZIGZIG whenever the  item is left-left or right-right
	ZIGZAG whenever the item is left-right or right-left
	ZIG whenever the item is the child of the root

Complexity

number of comparisons per operation is O(log(N))
gives good (amortized) cost overall
no guarantee for any individual operation: worst-case behaviour may still be O(N)
remember amortisation means averaging over a large number k operations
anyway, splay tree is self-balancing, gengerally improved performance
but worst-case behaviour O(N)