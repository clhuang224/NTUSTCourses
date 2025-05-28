#include <iostream>
#include <vector>

using namespace std;
class VecNf
{
public:
    VecNf();
    VecNf(float*, unsigned);
    unsigned Size();
    void operator=(VecNf);
    float& operator[](unsigned index);
    VecNf operator+(VecNf);
    VecNf operator-(VecNf);
    float operator*(VecNf);
    VecNf operator*(float);

private:
    vector<float> data;
};

VecNf operator*(VecNf, float);