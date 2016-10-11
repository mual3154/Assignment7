#include "MovieTree.h"
#include<string>
#include<iostream>
using namespace std;


void MovieTree::addMovieNode(int ranking, string title , int releaseYear , int quantity){
	MovieNode *tmp = new MovieNode;
	tmp = root;
	MovieNode *parent = new MovieNode;
	parent = NULL;
	
	MovieNode *node = new MovieNode(ranking, title, releaseYear, quantity);
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->parent = NULL;
	
	while(tmp!=NULL){
		parent = tmp;
		if(node->title.compare(tmp->title) < 0){
			tmp = tmp->leftChild;
		}
		else if(node->title.compare(tmp->title) > 0){
			tmp = tmp->rightChild;
		}

	}
	
	if(parent == NULL){
		root = node;
	}
	else if(node->title.compare(parent->title) < 0){
		parent->leftChild = node;
		node->parent = parent;
	}
	else{
		parent->rightChild = node;
		node->parent = parent;
	}

}


void MovieTree::findMovie(string title){
	bool found = false;
	MovieNode *node = new MovieNode;
	node = root;
	while(node !=NULL){
		if(title.compare(node->title) < 0){
			node = node->leftChild;
		}
		else if(title.compare(node->title) > 0){
			node = node->rightChild;
		}
		else{
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << node->ranking << endl;
			cout << "Title:" << node->title << endl;
			cout << "Year:" << node->year << endl;
			cout << "Quantity:" << node->quantity << endl;
			found = true;
			break;
		}

	}
	if(found == false){
		cout << "Movie not found." << endl;
	}
}

void MovieTree::rentMovie(string title){
	bool found = false;
	MovieNode *node = new MovieNode;
	node = root;
	while(node !=NULL){
		if(title.compare(node->title) < 0){
			node = node->leftChild;
		}
		else if(title.compare(node->title) > 0){
			node = node->rightChild;
		}
		else{
			if(node->quantity > 0){
				cout << "Movie has been rented." << endl;
				node->quantity = node->quantity-1;
				cout << "Movie Info:" << endl;
				cout << "===========" << endl;
				cout << "Ranking:" << node->ranking << endl;
				cout << "Title:" << node->title << endl;
				cout << "Year:" << node->year << endl;
				cout << "Quantity:" << node->quantity << endl;
				found = true;
				if(node->quantity == 0){
					deleteMovieNode(node->title);
				}
				break;
			}
			else{
				cout <<"Movie out of stock." << endl;
			}
		}

	}
	if(found == false){
		cout << "Movie not found." << endl;
	}
}

void MovieTree::printMovieInventory(MovieNode *node){
	if(node->leftChild !=NULL){
		printMovieInventory(node->leftChild);
	}
	cout << "Movie: " << node->title << " " << node->quantity << endl;
	if(node->rightChild != NULL){
		printMovieInventory(node->rightChild);
	}
}

MovieTree::MovieTree(){

}

void MovieTree::printMovieInventory(){
	printMovieInventory(root);
}

int MovieTree::countMovieNodes(){
	int *m = new int;
	*m = 0;
	MovieNode *tmp = new MovieNode;
	tmp = root;
	countMovieNodes(tmp , m);
	return *m;
}


void MovieTree::countMovieNodes(MovieNode *node, int *c){
	if(node->leftChild != NULL){
		countMovieNodes(node->leftChild , c);
	}
	*c = *c + 1;
	if(node->rightChild !=NULL){
		countMovieNodes(node->rightChild, c);
	}
}

MovieNode* MovieTree::treeMinimum(MovieNode *node){
	while(node->leftChild !=NULL){
		node = node->leftChild;
		return node;
	}
}

void MovieTree::deleteMovieNode(std::string title){
	MovieNode *tmp = new MovieNode;
	MovieNode *min = new MovieNode;
	MovieNode *parent = new MovieNode;
	tmp = search(title);
	parent = tmp->parent;
	if(tmp != NULL){
		if(tmp->leftChild == NULL && tmp->rightChild == NULL){
			delete tmp;
			tmp = NULL;
		}
		else if(tmp->leftChild == NULL){
			if(tmp->title.compare(parent->title) < 0 ){
				tmp->rightChild->parent = tmp->parent;
				parent->leftChild = tmp->rightChild;
				delete tmp;
			}
			else{
				tmp->rightChild->parent = tmp->parent;
				parent->rightChild = tmp->rightChild;
				delete tmp;
			}

		}
		else if(tmp->rightChild == NULL){
			if(tmp->title.compare(parent->title) < 0 ){
				tmp->leftChild->parent = tmp->parent;
				parent->leftChild = tmp->leftChild;
				delete tmp;
			}
			else{
				tmp->leftChild->parent = tmp->parent;
				parent->rightChild = tmp->leftChild;
				delete tmp;
			}
		}
		else{
			min = treeMinimum(tmp->rightChild);
			parent = min->parent;
			if(min->rightChild !=NULL){
				min->rightChild->parent = min->parent;
				parent->leftChild = min->rightChild;
				min->rightChild = NULL;
			}
			min->leftChild = tmp->leftChild;
			if(tmp->leftChild !=NULL){
				tmp->leftChild->parent = min;
			}
			min->rightChild = tmp->rightChild;
			if(tmp->rightChild !=NULL){
				tmp->rightChild->parent = min;
			}
			parent = tmp->parent;
			min->parent = parent;
			if(min->title.compare(parent->title) <0){
				parent->leftChild = min;
			}
			else{
				parent->rightChild = min;
			}
			delete tmp;

		}



	}
	else{
		cout << "Movie not found." << endl;
	}
}

void MovieTree::DeleteAll(){
	MovieNode *tmp = new MovieNode;
	tmp = root;
	DeleteAll(tmp);
	cout << "Goodbye!" << endl;
}

void MovieTree::DeleteAll(MovieNode *node){
	if(node !=NULL){
		if(node->leftChild !=NULL){
			DeleteAll(node->leftChild);
		}
		if(node->rightChild !=NULL){
			DeleteAll(node->rightChild);
		}
		cout << "Deleting: " << node->title << endl;
		delete node;
	}
}

MovieNode* MovieTree::search(std::string title){
	bool found = false;
	MovieNode *node = new MovieNode;
	node = root;
	while(node !=NULL){
		if(title.compare(node->title) < 0){
			node = node->leftChild;
		}
		else if(title.compare(node->title) > 0){
			node = node->rightChild;
		}
		else{
			return node;
		}

	}
	
	return NULL;

}

void MovieTree::RangeSearch(string m , string n){
	RangeSearch(node, m, n)
}

void MovieTree::RangeSearch(MovieNode *node, string m , string n){
	while(node !=NULL){
		if(m.compare(node->title) < 0){
			node = node->leftChild;
		}
		else if(m.compare(node->title) > 0){
			node = node->rightChild;
		}
	}
	while(node->title != n){
		if(node->leftChild !=NULL){
	        	node = node->leftChild;
		}
	// Node *tmp = new Node;
	//Node *nxt = new Node;
		if(m.compare(node->title) >= 0){
			cout << "added " << node->title << " to the list" << endl;
			// if(head == NULL){
		        //head->key = node->key;
			//head->next = NULL;
		}
		else{	
			cout << "added " << node->title << " to the list" << endl;
        		//tmp = head;
			//nxt->key = node->key;
			//while(tmp->next != NULL){
			//  tmp->next = nxt;
                	//nxt->next = NULL;
           		 //}
        	}

	}
	if(node->rightChild != NULL){
		node = node->rightChild;
	}
}
