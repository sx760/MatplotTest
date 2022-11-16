#define _USE_MATH_DEFINES

#include <matplotlibcpp.h>
#include <vector>
#include <map>
#include <cmath>

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
        settings_["linewidth"] = "1.0";
        settings_["color"] = "black";
        settings_["linestyle"] = "-";
        settings_["marker"] = "";
    }

public: // setting
    void setLineWidth(const double width)
    {
        settings_["linewidth"] = std::to_string(width);
    }
    void setLineColor(const std::string& color)
    {
        settings_["color"] = color;
    }
    void setLineStyle(const std::string &style)
    {
        settings_["linestyle"] = style;
    }
    void setLineMarker(const std::string& marker)
    {
        settings_["marker"] = marker;
    }

public: // draw
    void line(double x1, double y1, double x2, double y2)
    {
        plt::plot(std::vector{ x1, x2 }, std::vector{ y1, y2 }, settings_);
    }

    void lineArrow(double x1, double y1, double x2, double y2)
    {
        
    }

    void rect(double left, double top, double right, double bottom)
    {
        line(left, top, right, top);
        line(right, top, right, bottom);
        line(right, bottom, left, bottom);
        line(left, bottom, left, top);
    }

    void rectFill(double left, double top, double right, double bottom)
    {
        
    }

    void circle(double x, double y, double r)
    {
        
    }

    void circleFill(double x, double y, double r)
    {

    }

    void text(double x, double y, const std::string &str)
    {
        plt::text(x, y, str);
    }

    void test()
    {
        
    }

private:
    std::map<std::string, std::string> settings_;

};

int main() 
{
    Painter* p = new Painter(200, 200);

    p->setLineWidth(2.0);
    p->setLineColor("blue");
    p->line(0.0, 0.0, 100.0, 50.0);

    p->setLineWidth(5.0);
    p->setLineColor("green");
    p->line(0.0, 150.0, 150.0, 150.0);

    p->reset();
    p->rect(100.0, 100.0, 150.0, 150.0);

    p->test();

    p->text(10, 10, "12");
    delete p;
    return 0;
}