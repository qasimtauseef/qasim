#include <iostream>
using namespace std;
int main()
{

    int BT[20],WT[20],TAT[20],AVGWT=0,AVGTAT=0,A,B,C;

    cout<<"Enter Total number of processes(maximum 20):";

    cin>>C;

    cout<<"\nEnter Process Burst Time\n";

    for(A=0;A< C;A++)

    {

        cout<<A+1;

        cin>>BT[A];

    }

     WT[0]=0;    
     
	 for(A=1;A<C;A++)

    {

       WT[A]=0;

        for(B=0;B<A ;B++)

           WT[A]+=BT[B];

    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";

    for(A=0;A<C;A++)

    {

       TAT[A]=BT[A]+WT[A];

        AVGWT+=WT[A];

       AVGTAT+=TAT[A];

        cout<<"\nP["<<A+1<<"]"<<"\t\t"<<BT[A]<<"\t\t"<<WT[A]<<"\t\t"<<TAT[A];

    }

    AVGWT/=A ;

    AVGTAT/=A ;
    
    cout<<"\n   Average Turnaround Time:"<<AVGTAT;

    cout<<"\n   Average Waiting Time:"<<AVGWT;

    return 0;

}
