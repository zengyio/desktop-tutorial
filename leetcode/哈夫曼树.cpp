//*¹ş·òÂü±àÂë
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
struct hfmnode{
	int fath=0;
	int rchild=0;
	int lchild=0;
	int weight;
};
struct htree{
	hfmnode *m_htree;
	int m_length;
};
class hfmtree{
	public:
		void init(htree &ht,vector<int> &nums){
			int num=nums.size();
			int total=num*2-1;
			ht.m_htree=new hfmnode[total];
		
			if(!ht.m_htree){
				cout<<"init fail"<<endl;
			}
			ht.m_length=0;
			int i=0;
			for(i=0;i<num;i++){
				int weight;
				weight=nums[i];
				ht.m_htree[i].weight=weight;
				ht.m_length++;
			}
			for(;i<total;i++){
				ht.m_htree[i].weight=9999;
				ht.m_length++;
			}
			cout <<"init success"<<endl;
		};
		void test(){
			cout<<"pls input the num of leaf length"<<endl;
			int num,weight;
			//cin>>num;
		
			vector<int> hfm={7,19,2,6,32,3,21,10};
			//for(int i=0;i<num;i++){cout<<"pls input the weight of"<<endl;cin>>weight;hfm.push_back(weight);}
			//sort(hfm.begin(), hfm.end());
			htree mytree;
			init(mytree,hfm);
			
			num=hfm.size();
			int n=num;
			int min1=0,min2=0; 
			cout<<num<<" num "<<min1<<" 1min2 "<<min2<<endl;
			while(num<(2*n-1)){
				
				mintow(mytree,min1,min2,num);
				cout<<num<<" num "<<min1<<" 1min2 "<<min2<<endl;
				mytree.m_htree[num].weight=mytree.m_htree[min1].weight+mytree.m_htree[min2].weight;
				mytree.m_htree[num].lchild=min1;
				mytree.m_htree[num].rchild=min2;
				mytree.m_htree[min1].fath=mytree.m_htree[min2].fath=num++;
					cout<<num<<" num "<<min1<<" 1min2 "<<min2<<endl;
			}
			for(int i=0;i<num;i++){
				cout <<i<<" "<<	mytree.m_htree[i].weight<<" "<<mytree.m_htree[i].fath<<" "<<mytree.m_htree[i].lchild<<" "<<mytree.m_htree[i].rchild<<endl;
			}
			
		}
		void mintow(htree &ht,int &min1,int &min2,int n){
			min1=min2=0;
			int mi1=2e9,mi2=2e9;
			for(int i=0;i<n;i++){
				if(ht.m_htree[i].fath!=0) continue;
				if(ht.m_htree[i].weight<mi1){
					cout<<ht.m_htree[i].weight<<" weight "<<min1<<" mi1 "<<min1<<endl;
					mi2=mi1;min2=min1;
					mi1=ht.m_htree[i].weight; min1=i;
				}
				else if(ht.m_htree[i].weight<mi2){
					cout<<ht.m_htree[i].weight<<" weight "<<min1<<" mi2 "<<min2<<endl;
					mi2=ht.m_htree[i].weight;min2=i;
				}
			}
		}
};
int  main(){
	hfmtree ne1;
	ne1.test();
	system("pause");
	return 0;
}
