#include<iostream>
using namespace std;

int fact(int n){
    if(n == 1)
       return 1;
    return fact(n-1) * n;
}

int factIter(int n){
    int fact = 1;
    for(int i = 2;i<=n;i++){
        fact *= i;
    }
    return fact;
}

int main(){
   cout<<factIter(5)<<endl;
}