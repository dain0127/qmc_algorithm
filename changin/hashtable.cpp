#include "minterm.cpp"

/**
 * 첫번째로 받는 input bit length 에 따라
 * 모든 minterm들을 1의 개수에따라 분류하는 2차원 비슷한 배열을 만듦
 *
 * table ---->  table[0] ---> {m01}
 *              table[1] ---> {m01, d01, m02, ...}
 *              table[2] ---> { ... }
 *              ...
 *              table[bit_num - 1] ---> { ... }
 *
 */

class HashTable {
private:
    int bit_num;
    Minterm** table; //minterm 배열
    //1의 개수 반환
    int hash(const Minterm& copy) {
        int cnt = 0;
        for (int i = 0; i < copy.Get_bit_num(); i++) {
            if (copy.Get_literal(i) == 1)
                cnt++;
        }
        return cnt;
    }

    //n bit에서 1의 개수가 k개인 경우의 수를 구함. 
    //개수에 딱 맞는 효율적인 동적 할당에 필요함.
    //nCk = n(n-1)...(n-(k-1))/k
    int Combination_case_number(int n, int k) {
        int result = 1;
        for (int i = 0; i < k; i++) {
            result *= n - i;
        }

        return result / k;
    }

public:
    HashTable(int bit) :bit_num(bit) {
        table = new Minterm * [bit_num + 1]; //bit_num +1 만큼의 1의 개수
        for (int i = 0; i < bit_num + 1; i++) {
            table[i] = new Minterm[Combination_case_number(bit_num, i)];
        }
    }

    Minterm** Get_table(void) { return table; }
    Minterm* Get_minterm(int how_many_one) const { return table[how_many_one]; }

    void Add_minterm_to_table(Minterm& minterm) {
        table[hash(minterm)] = &minterm;
    }

    ~HashTable() {
        for (int i = 0; i < bit_num; i++)
            delete[] table[i];
        delete[] table;
    }
};
