#include <string>  //std::string
using std::string;

class Door {
    public:
        // color
        void SetColor(string c) {
            // the door's color can only be one of the following four colors
            if (c == "white" || c == "blue" || c == "red" || c == "NONE") {
                color = c;
            }
        }
        string GetColor() {return color;}
    
        // material
        void SetMaterial(string m) {
            // material can only be wooden or metal
            if (m =="wood" || m == "metal") {
                material = m;
            }
        }
        string GetMaterial() {return material;}
    
        // locked
        void Unlock(bool l) {
            // IRL you would have lots of logic here to make sure
            // that doors cannot be easily unlocked if they are locked
            if (l) {
                locked = false;
            }
        }
        bool IsLocked() {return locked;}
    
        // height
        void SetHeight(double h) {
            // check to make sure h is positive and not greater than 100 feet (3048cm)
            if (h > 0 && h <= 3048) {
                height = h;
            }
        }
        double GetHeight() {return height;}
    
        // width 
        void SetWidth(double w) {
            if (w > 0 && w <= 1219.20) {
                width = w;
            }
        }
        double GetWidth() {return width;}
        
        // constructor
        Door(string color, string material, bool locked, double height, double width) {
            color = color;
            material = material;
            locked = locked;
            height = height;
            width = width;
        }
    
    private:
        string color{"white"};
        string material{"wood"};
        bool locked{true};  // cannot enter if locked
        double height{213.36};  //cm
        double width{106.68};  //cm
};