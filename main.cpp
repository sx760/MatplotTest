#include <matplotlibcpp.h>
#include <vector>
#include <map>

namespace plt = matplotlibcpp;
class Painter
{
public:
    Painter(double width, double height)
    {
        plt::figure_size(width, height);
        plt::xlim(0, (int)width);
        plt::ylim(0, (int)height);
        plt::axis("off");
        reset();
    }
    ~Painter()
    {
        plt::show();
    }

    void reset()
    {
        map_["color"] = "black";
        map_["linestyle"] = "-";
        map_["marker"] = "";
    }

public:
    void setColor(const std::string &color)
    {
        map_["color"] = color;
    }
    
    void line(double x1, double y1, double x2, double y2)
    {
        plt::plot(std::vector{ x1, x2 }, std::vector{ y1, y2 }, map_);
    }

private:
    std::map<std::string, std::string> map_;

};

int main() 
{
    Painter* p = new Painter(200, 200);
    p->setColor("blue");
    p->line(0.0, 0.0, 100.0, 50.0);
    p->setColor("green");
    p->line(0.0, 150.0, 150.0, 150.0);
    delete p;
    return 0;
}