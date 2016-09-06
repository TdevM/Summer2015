#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;

long getTimeinMicroSeconds() {
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}

int main()
{
	int i,n,p,k,min,loc,temp;
	cout<<"\n------------ SELECTION SORT ------------ \n\n";
	cout<<"Enter No. of Elements=";
	cin>>n;
	int a[1000000];
	for(i=0;i<n;i++)
	{
		a[i] = n-i;
	}
	long starttime, endtime;
	starttime = getTimeinMicroSeconds();
	for(p=1;p<=n-1;p++)              // Loop for Pass
	{
		min=a[p];                        // Element Selection
		loc=p;

		for(k=p+1;k<=n;k++)              // Finding Min Value
		{
			if(min<a[k])
			{
				min=a[k];
				loc=k;
			}
		}

		temp=a[p];              // Swap Selected Element and Min Value
		a[p]=a[loc];
		a[loc]=temp;

	}
	endtime = getTimeinMicroSeconds();
	cout << "time = " <<endtime -starttime << endl;
	cout<<"\nAfter Sorting : \n";

	for(i=1;i<=n;i++)
	{
    	cout<<a[i]<<" ";
	}
	return 0;
}
