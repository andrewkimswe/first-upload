#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> target) {
  int n = target.size();
  int temp;
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if(target[j] < target[j+1]) {
        temp = target[j];
        target[j] = target[j+1];
        target[j+1] = temp;
      }
    }
    for (int c = 0; c < n; c++) {
      cout << target[c] << " ";
    }
    cout << endl;
  }
  return target;
}

vector<int> selectionSort(vector<int> target){
    int lastIdx = target.size()-1;
    
    for(int i=0; i<lastIdx; i++){
        int nowIdx = i;

        int minNum = target[nowIdx];
        int minIdx = nowIdx;

        for(int j= nowIdx+1; j <= lastIdx; j++){
            int nextIdx = j;
            if(target[nextIdx] < minNum){
                minNum = target[nextIdx];
                minIdx = nextIdx;
            }
        }

        int temp = target[nowIdx];
        target[nowIdx] = minNum;
        target[minIdx] = temp;
    }
    return target;
}

vector<int> insertionSort(vector<int> vec){

    for(int i=1; i<vec.size(); i++){
        int nowIdx = i;

        for(int j=i; j>0; j--){
            if(vec[j] < vec[j-1]){
                int temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
            }
        }
    }

    return vec;
}

template<typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2){
    
    vector<T> merged;
    
    auto iter1 = arr1.begin();
    auto iter2 = arr2.begin();
    
    while(iter1 != arr1.end() && iter2 != arr2.end()){
        if(*iter1 < *iter2){
            merged.push_back(*iter1);
            iter1++;
        }
        else{
            merged.push_back(*iter2);
            iter2++;
        }
    }
    
    if(iter1 != arr1.end()){
        for(; iter1 != arr1.end(); iter1++)
            merged.push_back(*iter1);
    }
    else{
        for(; iter2 != arr2.end(); iter2++)
            merged.push_back(*iter2);
    }

    return merged;
}

template<typename T>
vector<T> mergeSort(vector<T> arr){
    if(arr.size() > 1){
        auto mid = size_t(arr.size() / 2);

        auto left_half = mergeSort<T>(vector<T>(arr.begin(), arr.begin()+mid));
        auto right_half = mergeSort<T>(vector<T>(arr.begin()+mid, arr.end()));

        return merge<T>(left_half, right_half);
    }

    return arr;
}

void quickSort(vector<int>& vec, int start, int end) {
	if (start >= end)
		return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (left <= end && vec[left] <= vec[pivot])
			left++;
		while (right >= start + 1 && vec[right] >= vec[pivot])
			right--;

		if (left > right) {
			int temp = vec[right];
			vec[right] = vec[pivot];
			vec[pivot] = temp;
		}
      
		else {
			int temp = vec[left];
			vec[left] = vec[right];
			vec[right] = temp;
		}
	}

	quickSort(vec, start, right - 1);
	quickSort(vec, right + 1, end);
	
}

int main(void) {
  int n = 5;
  vector<int> target = {5,3,1,4,2};
  auto result1 = bubbleSort(target);
  auto result2 = selectionSort(target);
  auto result3 = insertionSort(target);
  auto result4 = mergeSort(target);
  
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << result1[i] << " ";
  }

  cout << endl;
  
  for (int i = 0; i < n; i++) {
    cout << result2[i] << " ";
  }
  
  cout << endl;
  
  for (int i = 0; i < n; i++) {
    cout << result3[i] << " ";
  }

  cout << endl;
  
  for (int i = 0; i < n; i++) {
    cout << result4[i] << " ";
  }


  quickSort(target, 0, 4);
  cout << endl;
  
  for (int i = 0; i < n; i++) {
    cout << target[i] << " ";
  }
  return 0;
}
