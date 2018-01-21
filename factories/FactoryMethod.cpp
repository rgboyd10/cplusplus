#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


class Point
{
  Point(const float x, const float y)
    : x{x}, y{y}
  {}

  class PointFactory
{
public:
static  Point NewCartesian(const float x, const float y)
  {
    return{x, y};
  }

static  Point NewPolar(const float r, const float theta)
  {
    return {r * cos(theta), r * sin(theta) };
  }
  
};
  
public:
  float x, y;

  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
    return os << " x: " << obj.x << " y: " << obj.y;
  }

  static PointFactory Factory;
  
};



int main()
{
  //  Point p {1, 2};

  //  auto p = Point::PointFactory::NewCartesian(1,2);

  auto p = Point::Factory.NewCartesian(2,3);
  std::cout << p << std::endl;
  
  getchar();
  return 0; 
}
