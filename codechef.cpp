#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b,m;
	    cin>>a>>b>>m;
	    int ans = min((b-a),(m-b+a));
	    cout<<abs(ans)<<endl;
	}
	return 0;
}
