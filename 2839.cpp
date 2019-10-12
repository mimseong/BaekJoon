#include <iostream>
#define MAX 9999

int main() {
    int n, min = MAX, l;
    scanf("%d", &n);

    for(int i = 0; i <= n/3; i++){
    	if((n-3*i)%5 == 0){
    		l = (n-3*i) / 5;
    		if((l + i) < min)
    			min = l + i;
    	}
    }
    if(min == MAX)
    	printf("-1");
    else
    	printf("%d", min);
}