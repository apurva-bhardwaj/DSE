#include <iostream>
using namespace std;
void visit(int current, vector<int> adjacency_list[],vector<bool>& visited){
	visited[current]=true;
	for(int i = 0; i<adjacency_list[current].size(); i++ ){
		int nei = adjacency_list[current][i];	
		if (visited[nei]==false){
			visit(nei, adjacency_list, visited);
	    }
	}
}	
void DFS(int vertices, vector<int> adjacency_list[]){
	vector<bool> visited (vertices, false);
	for(int i = 0; i<vetices; i++){
		if(visited[i]==false){
			visit(i, adjacency_list, visited);	
		}
		
	}
	
}

