#include<string>
#include<iostream>
#include "MovieTree.hpp"
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
				break;
			}
			else{
				deleteMovieNode(node->title);
				found = true;
				break;
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

MovieTree::~MovieTree(){
	DeleteAll(root);
}

void MovieTree::DeleteAll(MovieNode *node){
	if(node->leftChild != NULL){
		DeleteAll(node->leftChild);
	}
	if(node->rightChild != NULL){
		DeleteAll(node->rightChild);
	}
	delete node;
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


int MovieTree::countMovieNodes(){
	int *x = new int;
	*x = 0;
	MovieNode *tmp = root;
	countMovieNodes(tmp, x);
	return *x;
	
}

void MovieTree::countMovieNodes(MovieNode *node, int *c){
	if(node->leftChild != NULL){
		countMovieNodes(node->leftChild , c);
	}
	*c = *c + 1;
	if(node->rightChild != NULL){
		countMovieNodes(node->rightChild , c);
	}
}


void MovieTree::deleteMovieNode(string title){
	MovieNode *tmp = search(title);
	if(tmp == NULL){
		cout << "The movie could not be found!" << endl;
	}
	else{
		MovieNode *parent = tmp->parent;
		if(tmp->leftChild == NULL && tmp->rightChild == NULL){
			delete tmp;
		}
		else if(tmp->leftChild == NULL){
			if(parent->leftChild == tmp){
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
			if(parent->leftChild == tmp){
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
			MovieNode *x = new MovieNode; 
			x = treeMinimum(tmp->rightChild);
			tmp->ranking = x->ranking;
			tmp->title = x->title;
			tmp->year = x->year;
			tmp->quantity = x->quantity;
			if(x->rightChild !=NULL){
				x->rightChild->parent = x->parent;
			}
			if(x->parent->leftChild == x){
				x->parent->leftChild = x->rightChild;
			}
			else{
				x->parent->rightChild = x->rightChild;
			}
			delete x;
		}
	}
}

MovieNode* MovieTree::treeMinimum(MovieNode* node){
	MovieNode *tmp = node;
	while(tmp->leftChild !=NULL){
		tmp = tmp->leftChild;
	}	
	return tmp;

}


