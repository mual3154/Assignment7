#ifndef MOVIETREE_H
#define MOVIETREE_H

#include<iostream>
#include<string>
struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        this->quantity = in_quantity;
    }

};

class MovieTree
{
    public:
        MovieTree();
        ~MovieTree();
	int countMovieNodes();
	void DeleteAll();
	void deleteMovieNode(std::string title);
	void printMovieInventory();
        void addMovieNode(int ranking, std::string title, int releaseYear, int quantity);
        void findMovie(std::string title);
        void rentMovie(std::string title);
	void RangeSearch(string m, string n);
    protected:
    private:
	void RangeSearch(MovieNode *node, string m, string n);
        void printMovieInventory(MovieNode *node);
        MovieNode* search(std::string title);
        MovieNode *root;
	MovieNode* treeMinimum(MovieNode *node);
	void DeleteAll(MovieNode *node);
	void countMovieNodes(MovieNode *node, int *c);

};

#endif // MOVIETREE_H
