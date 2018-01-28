#include<iostream>
#include<bitset>
using namespace std;
bool judge(int n){
    int b= 0;
    while(n>b){
        int temp = n%10;
        b =b*10+temp;

        if(n==b || (n/10)==b)return true;
        n /=10;
    }
    return false;
};
int main(){
    // bitset<32> bits(-1);
    // cout<<bits;
    // int a,b,c;
    // a = b = c = 12;

    int n = 3;
    cout<<judge(12112)<<" # "<<judge(123321);

}
