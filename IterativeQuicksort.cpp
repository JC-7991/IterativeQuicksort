#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
 
int partition(int a[], int start, int end){
  
  int pivot = a[end];
  int pIndex = start;
 
  for(int i = start; i < end; i++){
    
    if(a[i] <= pivot){
      std::swap(a[i], a[pIndex]);
      pIndex++;
    }

  }
 
  std::swap(a[pIndex], a[end]);
 
  return pIndex;

}
 
void iterativeQuicksort(int a[], int n){

  std::stack<std::pair<int, int>> s;

  int start = 0;
  int end = n - 1;
 
  s.push(std::make_pair(start, end));
 
  while (!s.empty()){

    start = s.top().first, end = s.top().second;
    s.pop();
 
    int pivot = partition(a, start, end);

    if(pivot - 1 > start){
      s.push(std::make_pair(start, pivot - 1));
    }

    if(pivot + 1 < end){
      s.push(std::make_pair(pivot + 1, end));
    }

  }
  
}

int main(){

  int a[] = {6, -3, 5, 1, 9, 8, 3, 2, -6};
  int n = sizeof(a) / sizeof(a[0]);
 
  iterativeQuicksort(a, n);
 
  for(int i = 0; i < n; i++){
    std::cout << a[i] << " ";
  }
 
  return 0;

}