#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
using namespace std;
struct MatHang{
	string tmh;
	string dvt;
	int mmh;
	float tl;
	float dg;

};
typedef struct MatHang MH;
//Khai bao node
typedef struct node{
	MH info;
	node* next;
}NODE;
typedef NODE* NodePtr;
NodePtr pList;//pList tro nut cuoi danh sach
//Khoi tao danh sach ban dau chua co phan tu
void Init(NodePtr &pList){
       *pList = NULL;
}
// Kiem tra danh sach rong
int IsEmpty(NodePtr &pList){
	return (pList==NULL);
}
void Input(MH &mh){
	fflush(stdin);
	cout<<"[+] Nhap ten mat hang:";
	getline(cin,mh.tmh);
	cout<<"[+] Nhap don vi tinh:";
	getline(cin,mh.dvt);
	cout<<"[+] Nhap ma mat hang:";
	cin>>mh.mmh;
	cout<<"[+] Nhap trong luong:";
	cin>>mh.tl;
	cout<<"[+] Nhap don gia:";
	cin>>mh.dg;
}
void Output(MH &mh){
	cout<<left<<setw(30)<<"|"<<"Ten mat hang"<<setw(20)<<"| Don vi tinh"<<setw(15)<<"| Ma mat hang"<<setw(15)<<"| Trong luong"<<setw(15)<<"| Don gia"<<endl;
	cout<<setfill('-');
	cout<<setw(130)<<"-"<<endl;
	cout<<setfill('');
}
void ShowNode(NodePtr q){
	cout<<left<<setw(30)<<q->info.tmh<<setw(20)<<q->info.dvt<<setw(15)<<q->info.mmh<<setw(15)<<q->info.tl<<setw(15)<<q->info.dg<<endl;

}
void ShowList(NodePtr &pList){
	NodePtr p;//p con tro de duyet
	if(pList==NULL)
		return ;
	p=pList->next;
	do{
		ShowNode(p);//tac dong len nut
		p=p->next;//chuyen nut sau
	}while(p!=pList->next);

}
void InserLast(NodePtr &pList,int x){
	NodePtr node;
	node=new NODE;
	node->info=x;
	if(pList==NULL){
		pList=node;
		pList->next=pList;

	}else{
		node->next=pList->next;
		pList->next=node;
		pList=node;
	}
}
void Search(NodePtr &pList,int x){
	int x;
	fflush(stdin);
	cout<<"\n[+] Nhap vao ma hang can tim :";
	cin>>x;
	NodePtr p;//p con tro de tim
	if(pList==NULL)
	{ 
	return NULL;
	}
	p=pList->next;//tim tu dau danh sach
	do{
		p=p->next;

	}while(p->info!=x && p!=pList->next);
	if(p->info.mmh==x)
		ShowNode(p);

}
int main(){
	cout<<"\n------------------------------------MENU-------------------------------"<<endl;
	cout<<"|1.Hien thi toan bo danh sach|"<<endl;
	cout<<"|2.Tim ma hang theo ma|"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"\n\t\t\t"<<"---------MOI BAN NHAP LUA CHON----------";
	cout<<"\n[=] Nhap lua chon:";
	int lc;
	do{
		cin>>lc;
		if(lc<0||lc>2)
			cout<<"Khong co lua chon nay!Moi ban nhap lai:";
	}while(lc<0||lc>10);
	NodePtr pList;
	Init(pList);
	int n;
	cout<<"\n[-] Nhap so mat hang:";
	cin>>n;
	MH *mh=new MH[n];
	for(int i=0;i<n;i++){
		cout<<"\n + Nhap thong tin mat hang thu "<<i+1<<endl;
		Input(mh[i]);
		InserLast(pList,mh[i]);
			
	}
	switch(lc){
		case 1:{
			Output();
			ShowList(pList);
			break;
		}
	}
	    case 2:{
	    	Search(pList);
	    	break;
	    }
	    return 0;
}