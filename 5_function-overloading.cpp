#include <iostream>
using namespace std;
void volume(int l, int w, int h)
{
    cout << "Volume of a rectangle: " << l * w * h << endl;
}
void volume(int r, int h)
{
    cout << "Volume of a cylinder: " << 3.1416 * r * r * h << endl;
}
void volume(int sl)
{
    cout << "Volume of a cube: " << sl * sl * sl << endl;
}
int main()
{
    int l, w, h, a;
    int r;
    cout << "Enter l, h & w to calculate the volume of a rectangle:" << endl;
    cin >> l >> w >> h;
    volume(l, w, h);
    cout << "Enter r & h to calculate the volume of a cylinder:" << endl;
    cin >> r >> h;
    volume(r, h);
    cout << "Enter a to calculate the volume of a cube:" << endl;
    cin >> a;
    volume(a);

    return 0;
}
