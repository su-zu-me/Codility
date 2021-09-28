#include <cstdlib>
#include <iostream>

vector<int> solution(vector<int> &A, int K) {

    vector<int> result;

    if(A.empty())
    	return {};	// Finally test error on lacking this

    if(K > A.size())
        K = K%A.size();
    
    for(int i=A.size()-K; i<A.size(); i++)
        result.push_back(A[i]);

    for(int i=0; i<A.size()-K; i++)
        result.push_back(A[i]);
        
    return result;
}