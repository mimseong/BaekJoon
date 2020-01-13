#include <vector>
using namespace std;
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for(vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter){
        ans += *iter;
    }
	return ans;
}
