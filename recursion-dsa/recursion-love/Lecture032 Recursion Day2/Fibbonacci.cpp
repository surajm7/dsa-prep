#include<iostream> 
using namespace std;


int main() {

    int fib(int n) {

            if(n <= 1)  //base case
                return n;

            return fib(n - 1) + fib(n - 2); // recurrence relation
        }
}