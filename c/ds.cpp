#include <iostream>
using namespace std;

template <class T> class Tree;
template <class T>
class TreeNode {
friend class Tree<T>;
private:
  T data;
  TreeNode<T>* leftChild;
  TreeNode<T>* rightChild;
};

template <class T>
class Tree{
public:
  void Inorder();
  void Inorder(TreeNode<T>* currentNode);
  void NonrecInorder();
  void Preorder();
  void Preorder(TreeNode<T>* currentNode);
  void Postorder();
  void Postorder(TreeNode<T>* currentNode);
  void Levelorder();
private:
  TreeNode<T>* root;
};

template <class T>
class Stack {
public:
  Stack(int stackCapacity = 10);
  bool IsEmpty() const;
  T& Top() const;
  void Push(const T& item);
  void Pop();
};

template <class T>
class Queue {
public:
private:
  T* queue;
  int front, rear, capacity;
};

template <class T>
void Tree<T>::Inorder() {
  Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode) {
  if(currentNode) {
    Inorder(currentNode->leftChild);
    Visit(currentNode);
    Inorder(currentNode->rightChild);
  }
}

template <class T>
void Visit (TreeNode<T>* currentNode) {
  cout << currentNode->data;
}

template <class T>
void Tree<T>::NonrecInorder() {
  Stack<TreeNode<T>*>s;
  TreeNode<T>* currentNode = root;
  while(1) {
    while (currentNode) {
      s.Push(currentNode);
      currentNode = currentNode->leftChild;
    }
    if(s.IsEmpty()) return;
    currentNode = s.Top(); s.Pop();
    Visit(currentNode);
    currentNode = currentNode->rightChild;
  }
}

template <class T>
void Tree<T>::Preorder() {
  Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode) {
  if(currentNode) {
    Visit(currentNode);
    Preorder(currentNode->leftChild);
    Preorder(currentNode->rightChild);
  }
}

template <class T>
void Tree<T>::Postorder() {
  PostOrder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode) {
  if(currentNode) {
    Postorder(currentNode->leftChild);
    Postorder(currentNode->rightChild);
    Visit(currentNode);
  }
}

template <class T>
void Tree<T>::Levelorder() {
  Queue<TreeNode<T>*> q;
  TreeNode<T>* currentNode = root;
  while(currentNode) {
    Visit(currentNode);
    if(currentNode->leftChild) q.Push(currentNode->leftChild);
    if(currentNode->rightChild) q.Push(currentNode->rightChild);
    if(q.IsEmpty()) return;
    currentNode = q.Front();
    q.Pop();
  }
}

template <class T>
class MaxPQ {
public:
  virtual bool ISEmpty() const = 0;
  virtual const T& top() const = 0;
  virtual void Push(const T&) = 0;
  virtual void Pop() = 0;
};

template <class K, class E>
class Dictionary {
public:
  virtual bool IsEmpty() const = 0;
  virtual pair<K,E>* Get(const K&) const = 0;
  virtual void Insert(const pair<K,E>&) = 0;
  virtual void Delete(const K&) = 0;
};

class Sets {
public:
  Sets(int numberOfElements);
  void WeightedUnion(int i, int j);
  int CollapsingFind(int i);
private:
  int* parent;
  int n;
};

Sets::Sets(int numberOfElements) {
  if(numberOfElements < 2) throw "Must have at least 2 elements";
  n = numberOfElements;
  parent = new int[n];
  fill(parent, parent + n, -1);
}

void Sets::WeightedUnion(int i, int j) {
  int temp = parent[i] + parent[j];
  if (parent[i] > parent[j]) {
    parent[i] = j;
    parent[j] = temp;
  }
  else {
    parent[j] = i;
    parent[i] = temp;
  }
}

int Sets::CollapsingFind(int i) {
  int r;
  for(r = i; parent[r] >= 0; r = parent[r]);
  while(i!=r) {
    int s = parent[i];
    parent[i] = r;
    i = s;
  }
  return r;
}

void MatrixWdigraph::ShortestPath(const int n, const int v) {
  for (int i =0; i<n; i++) { s[i] = false; dist[i] = length[v][i]; }
  s[v] = true;
  dist[v] = 0;
  for (i = 0; i < n-2; i++) {
    int u = Choose(n);
    s[u] = true;
    for (int w = 0; w<n; w++)
      if(!s[w] && dist[u] + length[u][w] < dist[w])
        dist[w] = dist[u] + length[u][w];
  }
}

template <class E, class K>
int SeqSearch(E* a, const int n, const K& k) {
  int i;
  for (i=1;i<=n&&a[i]!=k;i++);
  if(i>n) return 0;
  return i;
}

void Verify1(Element* l1, Element* l2, const int n, const int m) {
  bool* marked = new bool[m+1];
  fill(marked+1, marked+m+1, false);

  for (int i = 1; i<=n; i++) {
    int j = SeqSearch(l2, m, l1[i]);
    if(j==0) cout << l1[i] << " not in l2" << endl;
    else {
      if(!Compare(l1[i],l2[j]))
        cout << "Discrepancy in" << l1[i] << endl;
      marked[j] = true;
    }
  }
  for(i=1;i<=m;i++)
    if(!marked[i]) cout << i2[i] << "not in l1." << endl;
  delete [] marked;
}

void Verify2(Element* l1, Element* l2, const int n, const int m) {
  Sort(l1, n); Sort(l2, m);
  int i = 1, j =1;
  while((i<=n) && (j<=m))
    if(l1[i] < l2[j]) {
      cout << l1[i] << "not in l2" << endl; i++;
    } else if(l1[i] > l2[j]) {
      cout << l2[j] << "not in l1" << endl; j++; 
    } else {
      if(!Compare(l1[i], l2[j]))
        cout << "Discrepancy in" << l1[i] << endl;
      i++; j++;
    }
  if(i<=n) OutputRest(l1, i, n, 1);
  else if(j<=m) OutputRest(l2,j,m,2);
}

template <class T>
void Insert(const T& e, T* a, int i) {
  a[0] = 0;
  while(e < a[j]) {
    a[i+1] = a[i];
    i--;
  }
  a[i+1] = e;
}

template <class T>
void InsertionSort(T* a, const int n) {
  for(int j = 2; j<=n; j++) {
    T temp = a[j];
    Insert(temp, a, j-1);
  }
}

template <class T>
void QuickSort(T* a, const int lefrt, const int right) {
  if(left < right) {
    int i = left, j = right + 1, pivot = a[left];
    do {
      do i++; while(a[i] < pivot);
      do j--; while(a[j] > pivot);
      if(i<j) swap(a[i], a[j]);
    } while(i<j);
    swap(a[left], a[j]);

    QuickSort(a, left, j-1);
    QuickSort(a, j+1, right);
  }
}

template <class T>
void Merge(T* initList, T* mergedList, const int l, const int m, const int n) {
  int i1, iResult, i2;
  for (i1 = l, iResult = l, i2 = m+1; i1 <= m && i2 <= n; iResult++) {
    if(initList[i1] <= initList[i2]) {
      mergedList[iResult] = initList[i1];
      il++
    }
    else {
      mergedList[iResult] = initList[i2];
      i2++;
    }
  }
  copy(initList + il, initList + m + 1, mergedList + iResult);
  copy(initList + i2, initList + n + 1, mergedList + iResult);
}

template <class T>
void MergePass(T* initList, T* resultList, const int n, const int s) {
  int i;
  for(i=1; i<n-2*s+1; i+=2*s)
    Merge(initList, resultList, i, i+s-1, i+2*s-1);
  if((i+s-1)<n) Merge(initList, resultList, i, i+s-1, n);
  else copy(initList+i, initList+n+1, resultList+i);
}

template <class T>
void MergeSort(T* a, const int n) {
  T* tempList = new T[n+1];
  for (int l = 1; l<n; l *= 2) {
    MergePass(a, tempList, n, l);
    l*=2;
    MergePass(tempList, a, n, l);
  }
  delete [] tempList;
}

template <class T>
int rMergeSort(T& a, int* link, const int left, const int right) {
  if (left >= right) return left;
  int mid = (left + right) / 2;
  return ListMerge(a, link, rMergeSort(a,link,left,mid), rMergeSort(a,link,mid+1,right));
}

template <class T>
void Adjust(T* a, const int root, const int n) {
  T e= a[root];
  int j;
  for (j=2*root; j<=n; j*=2) {
    if(j<n && a[j] < a[j+1]) j++;
    if(e>=a[j]) break;
    a[j/2] = a[j];
  }
  a[j/2] = e;
}

template <class T>
void HeapSort(T& a, const int n) {
  for(int i = n/2; i>=1; i--)
    Adjust(a,i,n);
  for(int i = n-1; i>=1; i--) {
    swap(a[1], a[i+1]);
    Adjust(a,1,i);
  }
}

int main(void) {
  return 0;
}
