//Banker's Algorithm 
#include<iostream> 
using namespace std; 
//P=Processes R=Resources N=need M=max A=Allocattion AV=AVIALABLE W=WORK F=FINISHED
const int P = 4,R = 4; 
void calculateNeed(int N[P][R], int M[P][R],int A[P][R]) 
{ 
    for (int i = 0 ; i < P ; i++) 
        for (int j = 0 ; j < R ; j++) 
        N[i][j] = M[i][j] - A[i][j]; 
} 
bool isSafe(int processes[], int AV [], int M [][R],int A [][R]) 
{ 
    int N[P][R]; 
    calculateNeed(N,M, A); 
    bool F[P] = {0}; 
    int safeSeq[P]; 
    int W[R]; 
    for (int i = 0; i < R ; i++) 
        W[i] = AV[i]; 
    int count = 0; 
    while (count < P) 
    { 
        bool found = false; 
        for (int p = 0; p < P; p++) 
        { 
            if (F[p] == 0) 
            { 
                int j; 
                for (j = 0; j < R; j++) 
                    if (N[p][j] > W[j]) 
                        break;  
               if (j == R) 
                { 
                    for (int k = 0 ; k < R ; k++) 
                        W[k] += A[p][k]; 
                    safeSeq[count++] = p; 
                    F[p] = 1; 
                      found = true; 
                } } } 
        if (found == false) 
        { 
            cout << "System is not in safe state"; 
            return false; 
        } } 
    cout << "System is in safe state.\nSafe" " sequence is: "; 
    for (int i = 0; i < P ; i++) 
	cout << safeSeq[i] << " "; 
    return true; 
} 
int main() 
{ 
    int processes[] = {0, 1, 2,4}; 
    int AV[] = {3, 3, 2,3}; 
    int M[][R] = {{7, 5, 3,1}, 
                     {3, 2, 2,2}, 
                     {9, 0, 2,0,}, 
                     {2, 2, 2,0}, 
                     {4, 3, 3,0}}; 
    int A[][R] = {{0, 1, 0,1}, 
                      {2, 0, 0,1}, 
                      {3, 0, 2,0}, 
                      {2, 1, 1,0}, 
                      {0, 0, 2,0}}; 
    isSafe(processes, AV , M , A ); 
  
    return 0; 
} 
