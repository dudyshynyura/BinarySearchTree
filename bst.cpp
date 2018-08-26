#include <iostream>
using namespace std;

template <typename T> struct Node{
  T data;
  Node<T> *left, *right, *p;
};

template <typename T> class Tree {
public:
  Node<T> *root;
  Tree(){root = NULL;};
  void Display(Node<T> *cur);
  Node<T>* RecursionSearch(Node<T> *cur, T key);
  Node<T>* IterativeSearch(Node<T> *cur, T key);
  Node<T>* Min(Node<T> *cur);
  Node<T>* Max(Node<T> *cur);
  void Insert(T value);
};

template <typename T> void Tree<T> :: Display(Node<T> *cur){ // inorder tree walk
  if(cur){
    Display(cur->left);
    cout << cur->data << "  ";
    Display(cur->right);
  }
}

template <typename T> Node<T>* Tree<T> :: RecursionSearch(Node<T> *cur, T key){
  if(!cur || key == cur->data) return cur;
  if(key < cur->data) return RecursionSearch(cur->left, key);
  else return RecursionSearch(cur->right, key);
}

template <typename T> Node<T>* Tree<T> :: IterativeSearch(Node<T> *cur, T key){
  while(cur && key != cur->data){
    if(key < cur->data) cur = cur->left;
    else cur = cur->right;
  }
  return cur;
}

template <typename T> Node<T>*  Tree<T> :: Min(Node<T> *cur){
  while(cur->left){
    cur = cur->left;
  }
  return cur;
}

template <typename T> Node<T>* Tree<T> :: Max(Node<T> *cur){
  while(cur->right){
    cur = cur->right;
  }
  return cur;
}

template <typename T> void Tree<T> :: Insert(T value){
  Node<T> *tmp = new Node<T>;
  tmp = NULL;

  Node<T> *NewNode = new Node<T>;
  NewNode->data = value;
  NewNode->left = NULL;
  NewNode->right = NULL;

  Node<T> *cur = new Node<T>;
  cur = root;

  while(cur){
      tmp = cur;
      if(NewNode->data < cur->data) cur = cur->left;
      else cur = cur->right;
  }
  if(!tmp) root = NewNode;
  else if(NewNode->data < tmp->data) tmp->left = NewNode;
  else tmp->right = NewNode;
}

int main(){
  Tree<int> tree;
  for(int i = 0; i < 10; i++){
    tree.Insert(i);
  }
  tree.Display(tree.root);

  Node<int> *m = new Node<int>;

  m = tree.Min(tree.root);
  cout <<  endl << m->data << endl;
  m = tree.Max(tree.root);
  cout << m->data << endl;

  return 0;
}
