
using namespace std;
#include <iostream>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	if (!(n % 3)){
	    cout << n/3 *2;
	}
	else{
	    cout << (n/3 )*2+1;
	    
	}
}
