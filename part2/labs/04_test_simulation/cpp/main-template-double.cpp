#include "tree-template.hpp"
#include <iostream>

template <class T>
static void preorder(node<T>* r) {
	if (r == NULL) return;
	std::cout << r->get() << std::endl;
	for (typename node<T>::iterator it = r->begin(); it != r->end(); ++it)	
		preorder(*it);
}

template <class T>
static void print(tree<T>& t) {
	std::cout << "tree: " << std::endl;
	preorder(t.root());
}

int main() {
	tree<double> t;
	node<double>* n  = t.add(10);	// add root
	node<double>* v1 = t.add(20,n);  // add child of root
	node<double>* v2 = t.add(30,n);  // add child of root
	node<double>* v3 = t.add(15,n);  // add child of root
	node<double>* v4 = t.add(25,v2); // add child of v2
	print(t);
	t.remove(v2);
	print(t);
	return 0;
}
