//http://www.cedricve.me/2012/03/20/c-bucket-sort/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
void print_out(vector<int> &v)
{
	for(int i=0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	} 	
	cout << endl;
}
 
void insertion_sort(vector<int> & v){
	for(int i=1; i<v.size(); i++){
		int h = v[i];
		int j=i-1;
		while(j>=0 && h<v[j]){
			v[j+1] = v[j];   
			j--;
		}
		v[j+1] = h;
	}
}
 
void vul_random(vector<int> & v, int size){
	v.clear();
	v.reserve(size);
	srand(time(0));
	for(int i=0; i<size; i++){
		v.push_back(rand()%10000);
	}
}
 
void bucket_sort(vector<vector<int> > &buckets, vector<int> &v) {
 
	for(int i = 0; i < buckets.size(); i++)
	{
		insertion_sort(buckets[i]);
	}
 
	int teller = 0;
	for(int i = 0; i < buckets.size(); i++)
	{
			for(int j =0; j < buckets[i].size(); j++)
			{
				v[teller++] = buckets[i][j];
			}
	}
 
}
 
void bucket_fill(vector<int> &v, int grootte_bucket)
{
	vector<int>::iterator result;
	result = max_element(v.begin(), v.end());
	int max =  *result;
 
	int aantal = v.size();
	int groepjes = aantal/grootte_bucket;
	vector<vector<int> > buckets(groepjes);
	for(int i=0; i < v.size(); i++)
	{
		buckets[v[i]/groepjes].push_back(v[i]);
	}
	bucket_sort(buckets,v);
}
 
int main() {
 
string lol = "";
 
vector<int> v;
int size = 100000;
v.reserve(size);
vul_random(v,size);
 
cout << " " << endl;
bucket_fill(v,100);
cout << " " << endl;
print_out(v);
 
 
cin >> lol;
return 0;	
}