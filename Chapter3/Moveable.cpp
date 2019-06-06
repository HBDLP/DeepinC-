#include <iostream>
using namespace std;

class HugeMem
{
public:
    HugeMem(int size)
    :hm_sz(size > 0 ? size: 1)
    {
        cout << "HugeMem construct invoke!!" << endl;
        hm_pc = new int[hm_sz];
    }
    
    HugeMem(HugeMem&& moveHM):hm_sz(moveHM.hm_sz),hm_pc(moveHM.hm_pc)
    {
        moveHM.hm_pc = nullptr;
        cout << "HugeMem moveconstruct invoke!!" << endl;
    }

    HugeMem(const HugeMem& copyHM)
    {
        hm_sz = copyHM.hm_sz;
        hm_pc = new int[hm_sz];

        cout << "HugeMem copyconstruct invoke!!" << endl;
    }

    ~HugeMem()
    {
        delete hm_pc;
         cout << "HugeMem destruct invoke!!" << endl;
    }

    int* hm_pc;
    int hm_sz;
};

class Moveable
{
public:
    Moveable():ma_pc(new int(3)) ,ma_HM(1024) {
        cout << "Moveable construct invoke!!" << endl;
    }

    // Moveable(Moveable&& moveMA) : ma_pc(moveMA.ma_pc), ma_HM(move(moveMA.ma_HM)){
    Moveable(Moveable&& moveMA) : ma_pc(moveMA.ma_pc), ma_HM(moveMA.ma_HM){
        moveMA.ma_pc = nullptr;
        cout << "Moveable moveconstruct invoke!!" << endl;
    }

    Moveable(const Moveable& copyMA):ma_HM(copyMA.ma_HM.hm_sz)
    {
        ma_pc = new int(*copyMA.ma_pc);
        cout << "HugeMem copyconstruct invoke!!" << endl;
    }

    ~Moveable()
    {
        delete ma_pc;
        cout << "Moveable destruct invoke!!" << endl;
    }
    
    HugeMem ma_HM;
    int* ma_pc;
};

Moveable GetTmpMoveable()
{
    Moveable tmp = Moveable();
    return  tmp;
}

int main()
{
    Moveable a(GetTmpMoveable());
    system("pause");
}