#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


class Point
{
public:
  float x, y;

  static Point NewCartesian(const float x, const float y)
  {
    return{x, y};
  }

  static Point NewPolar(const float r, const float theta)
  {
    return {r * cos(theta), r * sin(theta) };
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& obj)
  {
    os << " x: " << obj.x << " y: " << obj.y;
  }
  
private:
  Point(const float x, const float y) : x{x}, y{y}
  {}
  
};

int main()
{
  //  Point p {1, 2};

  auto c = Point::NewCartesian(1, 2);
  std::cout << c << std::endl;

  auto p = Point::NewPolar(5, M_PI_4);
  std::cout << p << std::endl;
  
  getchar();
  return 0; 
}
