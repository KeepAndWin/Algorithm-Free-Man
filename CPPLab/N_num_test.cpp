#include<iostream>
#include<thread>
#include<chrono>

using namespace std;
using namespace chrono;

void func1(long long n){
    long long k = 0;
    for (long long i = 0; i < n; i++){
        k++;
    }
}

void func2(long long n){
    long long k =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            k++;
        }
    }
}

void func3(long long n){
    long long k =0;
    for(int i = 0; i < n; i++){
        for(int j =1;j<n;j=j*2)
        {
            k++;
        }
    }
}

int main(){
    long long n ;
    while(1)
    {
        cout<<"ÊäÈën:";
        cin>>n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        func1(n); // O(n)
        // func2(n); // O(n^2)
        // func3(n); // O(nlogn)
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
        );
        cout<<"time_cost:" <<milliseconds(end_time).count() - milliseconds(start_time).count()<<" ms"<<endl;
    }

}