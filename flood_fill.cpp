#include <iostream>
using namespace std;
int arr[100][100];
int m,n;
void floodfill(int arr[100][100],int newcolor,int oldcolor,int i,int j){
    if(i<0 || i>=m || j<0 || j>=n){
        return;
    }
    else if(arr[i][j]!=oldcolor){
        return;
    }
    else if(arr[i][j]==oldcolor){
        arr[i][j]=newcolor;
    }
    floodfill(arr,newcolor,oldcolor,i+1,j);
    floodfill(arr,newcolor,oldcolor,i-1,j);
    floodfill(arr,newcolor,oldcolor,i,j+1);
    floodfill(arr,newcolor,oldcolor,i,j-1);


}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){

	    cin>>m>>n;

	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
	    int a,b;
	    cin>>a>>b;
	    int newcolor;
	    cin>>newcolor;
	    int oldcolor=arr[a][b];
	    floodfill(arr,newcolor,oldcolor,a,b);
	    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
	    }
	    cout<<endl;
	}
	return 0;
}
