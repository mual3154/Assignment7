//Muntadher AlZayer 104348447
//CSCI2270
//Hoenigmna - Guohui
//Assingment 7

#include<iostream>
#include<algorithm>
#include<fstream>
#include "MovieTree.h"
#include<string>
using namespace std;
void showmainmenu(){

cout << "======Main Menu======" << endl;
cout << "1. Find a movie" << endl;
cout << "2. Rent a movie" << endl;
cout << "3. Print the inventory" << endl;
cout << "4. Delete a movie" << endl;
cout << "5. Count the movies" << endl;
cout << "6. Quit" << endl;
}


int main(int argc , char* argv[]){
ifstream in_stream; // start of building of BST
in_stream.open(argv[1]);
string line;
MovieTree *bintree = new MovieTree;
int counter = 0;
string thearray[200];
string secline;
while(!in_stream.eof()){
getline(in_stream, line, ',');
int m = line.find('\n');
if(m!=-1){
secline = line.substr(m+1, line.length());
line = line.substr(0,m);
thearray[counter] = line;
thearray[counter+1] = secline;
counter = counter+2;
}
else{
thearray[counter] = line;
counter++;
}
}
for(int x = 0; x<200 ; x=x+4){
bintree->addMovieNode(atoi(thearray[x].c_str()) , thearray[x+1] , atoi(thearray[x+2].c_str()) , atoi(thearray[x+3].c_str()));
}//end of building of BST
string k;
while(k!="7"){
showmainmenu();
cin >> k;
if(k == "1"){
cout << "Enter title:" << endl;
string l;
getline(cin, l , '\n');
getline(cin, l , '\n');
bintree->findMovie(l);
}
else if(k=="2"){
cout << "Enter title:" << endl;
string l;
getline(cin, l, '\n');
getline(cin, l, '\n');
bintree->rentMovie(l);
}
else if(k=="3"){
bintree->printMovieInventory();
}
else if(k=="4"){
string str;
cout << "Enter a title:" << endl;
getline(cin, str , '\n');
getline(cin, str , '\n');
bintree->deleteMovieNode(str);
}
else if(k=="5"){
//counting the movies
cout  << "Tree contains: " << bintree->countMovieNodes() << " movies." << endl;
}
else if(k=="6"){
bintree->RangeSearch("Inception" , "Whiplash");
}
}
//deconstruct
bintree->DeleteAll();
}
