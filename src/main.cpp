#include <iostream>
#include <avltree.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <curl/curl.h>
#include <checkUrl.h>
#define SearchNode
using namespace std;
//ifstream lineStream ("listSites.txt");
int main() {
	string command;
	string line;
	string url;
	node * root = NULL;
	cout << "> ";
	getline(cin, line);
	while(!cin.eof()){
		stringstream mycin(line);
		mycin >> command;
		if(command == "insert"){
			cout << "inserting" << endl;
			fstream file;
			file.open("/Users/emilyhuang/Documents/projects/websites/src/listSites.txt");
			if (!file) {
				cerr << "Unable to open file listSites.txt" << endl;
				exit(1); 
			}
			while(!file.eof()){
				file >> ws;
				file >> url; 
				int checkValid = check_url(url);
				if(checkValid == 1){
					cout << "url to insert: " << url << endl;
					root = insert(root, url);
					cout << "done inserting" << endl;
				}else{
					cout << "invalid" << endl;
				}
				
			}
		}else if(command == "printAll"){
			printInorder(root);  
		}else if(command == "find"){
			mycin >> ws;
			mycin >> url;
			
			node * searchNode = searchTreeByKey (root, url);
			if(searchNode == NULL){
				cout << "can't find this node" << endl;
			}else{
				#ifdef SearchNode
				cout << "found" << endl;
				cout << searchNode;
				#endif
			}
		}else if(command == "delete"){
			mycin >> ws;
			mycin >> url;
		    root = deleteNode(root, url);
		}
		//lineStream.str("");
        //lineStream.clear();
        cout << "> ";
        getline(cin, line);
	}

	return 0;
}
