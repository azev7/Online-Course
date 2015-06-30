#include <iostream>
using namespace std;

const int N = 10;

class QuickUnionUF{
private:
  int id[N];
  int sz[N];
  int root(int i);
public:
  QuickUnionUF();
  bool connected (int p, int q);
  void qunion(int p, int q);
  void print();
};

bool QuickUnionUF::connected(int p, int q){
    return root(p) == root(q);
} 

QuickUnionUF::QuickUnionUF(){
  for(int i = 0; i < N; i++){
    this->id[i] = i;
    this->sz[i] = 1;
  }
}
  
int QuickUnionUF::root(int i){
    while(i != id[i]) i = id[i];
    return i;
  }

void QuickUnionUF::qunion(int p, int q){
    int i = root(p);
    int j = root(q);
    if(i == j) return;
    if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
    else               { id[j] = i; sz[i] += sz[j]; }
  }

void QuickUnionUF::print(){
    for(int i = 0; i < N; i++){
      cout << id[i] << " ";
    }
    cout << endl;
}

int main(){
  QuickUnionUF r;
  int p = 0, q = 0;
  while (cin >> p >> q && p >= 0){
    r.qunion(p, q);
  }  
  r.print();
  return 0;
}
