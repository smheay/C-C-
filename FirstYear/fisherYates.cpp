#include <iostream>
#include <stdlib.h>
 

 //The Fisher–Yates shuffle is an algorithm for generating a random permutation of a finite sequence—in plain terms, the algorithm shuffles the sequence. The algorithm effectively puts all the elements into a hat; it continually determines the next element by randomly drawing an element from the hat until no elements remain. The algorithm produces an unbiased permutation: every permutation is equally likely. The modern version of the algorithm is efficient: it takes time proportional to the number of items being shuffled and shuffles them in place.

 
using namespace std;
 
void fisherYatesShuffling(int *arr, int n)
{
    int a[n];
    int ind[n];
    for (int i = 0; i < n; i++)
        ind[i] = 0;
    int index;
 
    for (int i = 0; i < n; i++)
    {
        do
        {
            index = rand() % n;
        }
        while (ind[index] != 0);
 
        ind[index] = 1;
        a[i] = *(arr + index);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
 
int main(int argc, char **argv)
{
    cout << "Enter the array size: ";
    int n;
    cin >> n;
    cout << "Enter the array elements: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fisherYatesShuffling(a, n);
}