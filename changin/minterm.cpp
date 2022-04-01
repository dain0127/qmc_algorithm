#include <iostream>

using namespace std;

class Minterm {
private:
    int bit_num; //첫 input으로 받는
    bool Care; //don't care 여부.
    bool Primary;
    int* minterm; //0, 1, -1 들어갈 수 있음. (-1은 X. don't care을 의미함)

    //1의 개수 반환
    int hash(const Minterm& copy) {
        int cnt = 0;
        for (int i = 0; i < copy.Get_bit_num(); i++) {
            if (copy.Get_literal(i) == 1)
                cnt++;
        }
        return cnt;
    }

public:
    Minterm(void) :bit_num(0), Care(false), Primary(false) {
        this->minterm = new int[bit_num];
    }

    Minterm(int bit, bool Care) :bit_num(bit), Care(Care), Primary(false) {
        this->minterm = new int[bit_num];
    }

    Minterm& operator=(const Minterm& copy) {
        this->bit_num = copy.bit_num;
        this->Care = copy.Care;
        this->Primary = copy.Primary;
        this->minterm = new int[copy.bit_num];
    }

    //자기보다 1의 개수가 하나 많은 minterm과 비교. primeimplicant 반환.
    Minterm Compare_implicant(const Minterm& copy) {
        Minterm prime = *this;

        //hamming distance check;
        if (hash(copy) - hash(*this) != -1) {
            cout << "Minterm.Compare_implicant() is error!" << endl;
            cout << "error : Hamming distance is not 1" << endl;
            exit(0);
        }

        for (int i = 0; i < copy.bit_num; i++) {
            if (this->minterm[i] != copy.minterm[i]) {
                prime.Get_minterm()[i] = -1;
                return prime;
            }
        }
    }

    int* Get_minterm() { return minterm; }
    int Get_literal(int idx) const { return minterm[idx]; }
    int Get_bit_num() const { return bit_num; }

    bool IsCare() const { return Care; }
    bool IsPrimary() const { return Primary; }

    ~Minterm() {
        delete[] minterm;
    }

};
