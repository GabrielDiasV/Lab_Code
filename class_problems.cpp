#include <iostream>
#include <cmath>

using namespace std;


class point{
    public:
        point(float px = 0, float py = 0, float pz = 0){
            x = px;
            y = py;
            z = pz;
        };
        float calc_dist(point p2);
    private:
        float x;
        float y;
        float z;
};


float point::calc_dist(point p2){
    return sqrt(pow(p2.x - x, 2) + pow(p2.y - y, 2) + pow(p2.z - z, 2));
}


int main(){
    point first_point;
    point second_point(1.3, 1.7, -2.8);
    float distance;

    distance = first_point.calc_dist(second_point);

    cout << distance;
}