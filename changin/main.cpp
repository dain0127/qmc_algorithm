#include <iostream>
#include <fstream>
#include "hashtable.cpp"

using namespace std;

    /**
	 * step 1. fstream을 이용해서, 적절하게 첫번째 hashtable에 데이터를 할당한다.
	 * input bit length에 따라서 hashtable의 크기와, 1의 개수에 따라 개별적 row에 저장한다.
	 * 
	 * step 2. prime implicant를 추출하는 작업을 반복한다.
	 * input에 X(don't care)를 늘릴때마다 새로운 hashtable에 할당해준다.
	 * 
     * hashtable이 기본적으로 input이 n개라고 하면 n+1개 존재해야한다.
     * hashtable(n), hashtable(n-1), ... , hashtable(1)까지 존재해야한다.
	 * 물론 중간에 prime implicant가 필수적인 것으로 결정이 날 수도 있다.
	 * 하지만 특수케이스 까지 (Y=1) 고려해야함.
	 * 
	 * prime implicant는 따로 step 3를 위해 따로 저장해둔다. 
	 * 
	 * step 3. prime implicant 중에서 필수적인 것을 넣는다.
	 * 
	 * step 4. 필수적이지 않은 prime implicant 중에서 cost가 가장 적은 것을 찾는다.
	 * cost는 사용된 트랜지스터의 수이다. 문제에서 AND, OR, inverter만 사용이 가능하다.
	 * 
	 * AND : (prime implicant에서 곱해진 literal의 수) * 2 + 2. 각 prime implicnat에서 적용한 후 더함. (만약에 개수가 하나라면 0)
	 * OR : (prime implicant 의 개수 * 2) + 2 (만약에 개수가 하나라면 0)
	 * inverter : (invers literal의 개수 * 2)
	 * 
	 * step 5: result.txt에 결과를 출력한다. 열었던 파일을 닫는다.
     */

int main(void){
    ifstream fin("input_minterm.txt");
	int bit_num=0;
    
    if(!fin.is_open()){
        cout<<"Unable to open()"<<endl;
        exit(0);
    }

	fin>>bit_num;
	cout<<"bit_num:"<<bit_num<<endl;

    fin.close();

    return 0;
}
