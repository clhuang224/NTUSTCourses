#include <iostream>
using namespace std;

void dijkstra(int** graph, int amount, char source, int** result);

int main(){
	int line, amount, **graph, weight, *result;
	char v1, v2, start;

	cin >> line; // 將資料存入graph陣列中
	amount = line * 2;
	result = new int[amount];
	graph = new int*[amount];
	for(int i=0; i<amount; i++){
		graph[i] = new int[amount];
		result[i] = -1;
		for(int j=0; j<amount; j++){
			graph[i][j] = -1;
		}
	}
	for(int i=0; i<line; i++){
		cin >> v1 >> v2 >> weight;
		graph[v1-97][v2-97] = weight;
	}
	cin >> start;
	result[start-97] = 0;
	dijkstra(graph, amount, start, &result);

	int max=result[0];
	for(int i=1; i<amount; i++){
		if(result[i]>max){
			max = result[i];
		}
	}
	for(int i=0; i<=max; i++){
		for(int j=0; j<amount; j++){
			if(result[j] >=0 && result[j]==i){
				cout << (char)(j+97) << " " << result[j] << ((i==max)?"":"\n");
			}
		}
	}


	for(int i=0; i<amount; i++){ // 釋放記憶體空間
		delete(graph[i]);
	}
	delete(graph);
	delete(result);
}
void dijkstra(int** graph, int amount, char source, int** result){
	for(int i=0; i<amount; i++){
		if(graph[source-97][i]>0){ // 如果有路
			if((*result)[i]>0){ // 而且已經存了一條路
				if((*result)[source-97]+graph[source-97][i] < (*result)[i]){ // 新的路比較短就放進去
					(*result)[i] = (*result)[source-97]+graph[source-97][i];
				}
			} else {
				(*result)[i] = (*result)[source-97]+graph[source-97][i];
			}
			dijkstra(graph, amount, i+97, &(*result)); // 以新的點作為起點繼續計算
		}
	}

}