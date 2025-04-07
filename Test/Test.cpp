#include <string>

class Vertex
{
public:
    Vertex() = delete;
    Vertex(double x, double y, double z, std::string name) :
        name_(name), x_(x), y_(y), z_(z)
    {

    }
    Vertex(double x, double y, std::string name)
    {
        Vertex(x, y, 0., name);
    }
private:
    std::string name_;
    double x_ = 0.;
    double y_ = 0.;
    double z_ = 0.;
};

int main()
{
    Vertex a(0., 0., "");
    Vertex b(0., 0., 0., "");
    return 0;
}