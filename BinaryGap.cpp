#include <cstdlib>
#include <iostream>

int *toBinary(int N) {

    int *tmp = (int *) malloc (sizeof (int) * 32);
    int *result = (int *) malloc (sizeof (int) * 32);

    for(int i=0; i<32; i++) {
        tmp[i] = N%2;
        N /= 2;
    }

    for(int i=31; i>=0; i--)
        result[i] = tmp[31-i];

    return result;
}

int solution(int N) {

    int *binary = (int *) malloc (sizeof (int) * 32);
    binary = toBinary(N);

    int flag = 0, zero_count = 0, max_zero_count = 0;
    for(int i=0; i<32; i++) {
        
        if(binary[i] == 1) {
            flag = 1;
            if(zero_count >= 1) {
                if(max_zero_count < zero_count)
                    max_zero_count = zero_count;
                zero_count = 0;
            }
        }

        if(flag == 1 && binary[i] == 0)
            zero_count += 1;
    }
    
    return max_zero_count;
}
