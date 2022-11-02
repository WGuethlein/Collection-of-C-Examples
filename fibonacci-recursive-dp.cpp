
/*
// Author: Wyatt Guethlein
// ECCS 2681: Data Structures and Algorithms 2
// Date: February 2021

  This program demonstrates using Dynamic Programming to find
  Fibonacci numbers.

  There are two versions: bottom-up and top-down 


*/

#include <iostream>
#include <string>

using namespace std;

// recursive fibonacci implementation
long fibonacci(long n){

  if (n <= 1){
    return n;
  }

  return fibonacci(n-1) + fibonacci(n-2);
}

//======================================================

// bottom-up solution
long fibonacci_db(long n){
  // Use an array to store Fibonacci numbers.
  // fTable is dynamic array

  long* fTable = new long[n+1];

  // base cases
  fTable[0] = 0;
  fTable[1] = 1;

  for(int i = 2; i <= n; i++){
    // numbers are already calculated
    // just access the fTable
    fTable[i] = fTable[i - 1] + fTable[i - 2];
  }

  return fTable[n];

}

//======================================================

// top-down solution
long fibonacci_db_mem(long n){
  // Use an array to store Fibonacci numbers.
  // fTable is dynamic array

  static long* fTable_mem = new long[n+1];
  static bool initialized = false;

  if( !initialized ){
    // base cases
    fTable_mem[0] = 0;
    fTable_mem[1] = 1;

    for(int i = 2; i <= n; i++){
      fTable_mem[i] = -1;
    }
    initialized = true;
  }

  if( fTable_mem[n] != -1){
    return fTable_mem[n];
  }
  else{
    fTable_mem[n] = fibonacci_db_mem(n-1)+fibonacci_db_mem(n-2);
    return fTable_mem[n];

  }

}

int main (int argc, char *argv[]) {

  // check correct number of arguments
  if(argc != 3){
    cout<<"Please use the following command:"<<endl;
    cout<<"./fib.o choice number "<<endl;
    cout<<"-- choice r: recursive"<<endl;
    cout<<"-- choice d: dynamic programming (bottom-up) "<<endl;
    cout<<"-- choice m: dynamic programming (tom-down) "<<endl;
    exit(0);
  }

  int number= stoi(argv[2]);

  if( strncmp(argv[1], "-r", 2) == 0){
    cout<<"\nRecursive Fibonacci -- Fib(" << number<< "): "<< fibonacci(number)<<"\n";
  }
  else if ( strncmp(argv[1], "-d", 2) == 0){
    cout<<"\nDP (bottom-up) Fibonacci -- Fib(" << number<< "): "<< fibonacci_db(number)<<"\n";
  }
  else if ( strncmp(argv[1], "-m", 2) == 0){
    cout<<"\nDP (top-down) Fibonacci -- Fib(" << number<< "): "<< fibonacci_db_mem(number)<<"\n";
  }
  else{
    cout<<"Please use the following command:"<<endl;
    cout<<"./fib.o choice number "<<endl;
    cout<<"-- choice r: recursive"<<endl;
    cout<<"-- choice d: dynamic programming (bottom-up) "<<endl;
    cout<<"-- choice m: dynamic programming (tom-down) "<<endl;

  }


  return 0;
}
