/*
	an very important data structure: tree
	1. trees are like doubly-linked lists: nodes contains data and multiple links to other nodes
		nodes: internal nodes, have links to other nodes, called their children. external nodes,
			called leaves or terminals, and have no links to other nodes
	2. a tree is an acyclic graph in which each child has at most one parent
	3. height is the length of the longest path from the root
	4. depth: for a node the length from root ro this node

	important tree type:ordered binary tree(binary search tree)
		left subtree values <= parent value
		right subtree values >= parent value
	balanced tree: number of nodes in the left and right subtrees differ by at most 1
	degenerate: tree with maximal height
	
	complete binary tree: left--left  except last two level all nodes should have degree 2
*/