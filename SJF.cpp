//Shortest Job first 
#include<bits/stdc++.h> 
using namespace std; 
  
struct Process 
{ 
   int Pid ,BT;
}; 

bool comparison(Process A, Process B) 
{ 
     return (A.BT < B.BT); 
} 

void findWaitingTime(Process proc[], int C, int WT[]) 
{ 
   
    WT[0] = 0; 
    for (int i = 1; i < C ; i++ ) 
        WT[i] = proc[i-1].BT + WT[i-1] ; 
} 

void findTurnAroundTime(Process proc[],int C,int WT[],int TAT[]) 
{ 
    for (int i = 0; i < C ; i++) 
        TAT[i] = proc[i].BT + WT[i]; 
} 

void findavgTime(Process proc[], int C) 
{ 
    int WT[C], TAT[C], Total_WT = 0, Total_TAT = 0; 

    findWaitingTime(proc, C, WT); 

    findTurnAroundTime(proc, C, WT, TAT); 

    cout << "\n NO OF Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 

    for (int i = 0; i < C; i++) 
    { 
        Total_WT = Total_WT + WT[i]; 
        Total_TAT = Total_TAT + TAT[i]; 
        cout << " " << proc[i].Pid << "\t\t"<< proc[i].BT << "\t " << WT[i] << "\t\t " << TAT[i] <<endl; 
    } 
  
    cout << "Average waiting time = "<< (float)Total_WT / (float)C; 
    cout << "\nAverage turn around time = "<< (float)Total_TAT / (float)C; 
} 
int main() 
{ 
    Process proc[] = {{1, 6}, {3, 8}, {3, 7}, {5, 3}}; 
    int C= sizeof proc / sizeof proc[0]; 
    sort(proc, proc + C, comparison); 
  
    cout << "Order in which process gets executed\n"; 
    for (int i = 0 ; i < C; i++) 
        cout << proc[i].Pid <<" "; 
  
    findavgTime(proc, C); 
    return 0; 
} 
