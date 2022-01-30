//Generate random point in a circle

class Solution {
public:
    
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
        
    }
    
    vector<double> randPoint() {
        double len, theta;

        double ranVar = (double) rand() / RAND_MAX;
        theta = ranVar * 2 * 3.14285714286;

        double ranVar1 = (double) rand() / RAND_MAX;
        len = sqrt(ranVar1)*r;

        double xToR = x + len * cos(theta);
        double yToR = y + len * sin(theta);

        return vector<double>{xToR, yToR};
        
    }
};
