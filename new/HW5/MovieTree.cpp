#include "MovieTree.hpp"
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
				break;
			}
			else{
				cout <<"Movie out of stock." << endl;
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
	if(root==NULL){
		return 0;
	}	
	else{
		int l = countMovieNodes(node->left);
		int r = countMovieNodes(node->right);
		
		return r+l+1;
	}
}

void deleteMovieNode(string title){

}

MovieNode* MovieTree::treeMinimum(MovieNode* node){
	Node *tmp = node;
	while(tmp->left !=NULL){
		tmp = tmp->left;
	}	
	return tmp;

}


