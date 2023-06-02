/*Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm.*/

#include<iostream>
using namespace std;
class Heap
{
	int n;
	int *minheap,*maxheap;
	public:
	void get();
	void displayMin(){cout<<"Minimum marks are :"<<minheap[0]<<endl;}
	void displayMax(){cout<<"Maximum marks are :"<<maxheap[0]<<endl;}
	void upAdjust(bool,int);
};
void Heap::get()
{
	cout<<"Enter number of students."<<endl;
	cin>>n;
	int k;
	minheap=new int[n];
	maxheap=new int[n];
	cout<<"Enter marks of students."<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		minheap[i]=k;
		upAdjust(0,i);
		maxheap[i]=k;
		upAdjust(1,i);
	}
}
void Heap::upAdjust(bool m,int l)
{
	int s;
	if(m==0)
	{
		while(minheap[(l-1)/2]<minheap[l])
		{
			s=minheap[l];
			minheap[l]=minheap[(l-1)/2];
			minheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
	else
	{
		while(maxheap[(l-1)/2]>maxheap[l])
		{
			s=maxheap[l];
			maxheap[l]=maxheap[(l-1)/2];
			maxheap[(l-1)/2]=s;
			l=(l-1)/2;
			if(l==-1)
				break;
		}
	}
}
main()
{
	Heap H;
	H.get();
	H.displayMin();
	H.displayMax();
	return(0);
}

#include<iostream>
using namespace std;

class heap{
	int n;
	void getdata();
	void upadjust;
	int *maxheap;
	int *meanhep;
	upadjust(bool)
	void displaymin(){cout<<meanhep[0]<<endl;}
	void displaymax(){
		cout<<"the maximum number of element is: "<<maxheap[0]
	}
};
void getdata(){
	int n;
	cout<<"enter the number of marks of student to be displayed: ";
	cin>>n;
	maxheap=new int[n];
	minheap=new int[n];
	for(int i=0;i<n;i++){

		cout<<"enter marks of student: ";
		cin>>k
	 	minheap[i]=k;
	 upadjust(bool,int);
	 maxheap[i]=k;
	 upadjust(bool,int);
	}
}
void heap::upadjust(bool m,int a){
	int s;

	if(m==0){
		while(minheap[(l-1)/2]<minheap[l]{
			s=meanheap[l];
			meanheap[l]=meanheap[(l-1)/2];
			s=meanheap[(1-1)/2];
			l=(l-1)/2;
			if(l==-1){
				break;
			}
		else{
			while(minheap[(l-1)/2]<minheap[l]{
			s=meanheap[l];
			meanheap[l]=meanheap[(l-1)/2];
			s=meanheap[(1-1)/2];
			l=(l-1)/2;
			if(l==-1){
				break;
			}
		}
	}
}