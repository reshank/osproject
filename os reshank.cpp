#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int main()
{
	srand(time(NULL));
	int n=10,ct=0,wt=0,k=0;
	int process[10],bt[10],CT[10],WT[10],bt2[10];
	char processid[10]={'a','b','c','d','e','f','g','h','i','j'},processid2[10];
	for(int i=0; i<n; i++)
		{
		bt[i] = rand()%10 + 3;
	}
	cout<<"Burst Time: ";
	for(int a=0; a<n; a++)
	{
		cout<<processid[a]<<" ";
		cout<<bt[a]<<" | ";
	}
	cout<<endl;
	cout<<"candy Distribution"<<endl;
	for(int a=0; a<n; a++)
	{
		for(int i=0; i<n; i++)
		{
			process[i]=rand()%100;    
		}
		for(int i=0; i<n; i++)
		{
			cout<<processid[i]<<" "<<process[i]<<" | ";
		}
			cout<<endl;
		int max=process[0],loc=0;
		for(int i=1; i<n; i++)
		{
			if(process[i]>max)
			{
				max=process[i];     //Finding the process or Student with maximum chocolates
				loc=i;
			}
		}
		ct=ct+bt[loc]; 
		CT[k]=ct;
		processid2[k]=processid[loc];
		bt2[k]=bt[loc];
		WT[k]=ct-bt[loc];
		k++;
		
		for(int b=loc; b<n-1; b++)
		{
			process[b]=process[b+1];
			bt[b]=bt[b+1];
			processid[b]=processid[b+1];
		}
		n--;
		a--;	
	}
	cout<<"Process ID Arrival time    Burst Time    Completion Time    Turn Around Time   Waiting Time"<<endl;
	for(int x=0; x<k; x++)
	{
		cout<<"  "<<processid2[x]<<"\t|\t"<<"0"<<"\t|\t"<<bt2[x]<<"\t|\t"<<CT[x]<<"\t|\t"<<CT[x]<<"\t|\t"<<WT[x]<<endl;	
	}
	int sum=0;
	for(int p=0; p<k; p++)
	{
		sum=sum+CT[p];   //total turned around time
	}
	cout<<"Average Turn Around time : "<<(sum/k)<<endl;
	sum=0;
	for(int p=0; p<k; p++)
	{
		sum=sum+WT[p];
	}
	cout<<"Average waiting time : "<<(sum/k);
	return 0;
}
