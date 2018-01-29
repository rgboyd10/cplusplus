#include <iostream>
#include <string>

struct Shape
{
  virtual string str() const = 0;
};

struct ColoredShape
{
  string color;

  explicit ColoredShape(const string& color) : color{color}
  {
  }
};

struct Circle : Shape
{
  float radius;

  Circle(){}

  explicit Circle(const float radius) : radius{radius}
  {}

  void resize(float factor)
  {
    radius *= factor;
  }
  
  string str() const override
  {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square:Shape
  {
    float side;
  explicit Square(const float side) : side{side}
  {
  }

  string str() const override
  {
    osstringstream oss;
    oss << "A square with side = " << side;
    return oss.str();
  }
};

struct ColoredShape : Shape
{
  Shape& shape;
  string color;

  ColoredShape(Shape& shape, const string& color) : shape{shape}, color{color}
  {}

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape
{
  Shape& shape;
  uint8_t transparency;

  TransparentShape(Shape& shape, const uint8_t transparency) : shape{shape}, transparency{transparency}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss << shape.str() << " has "
	<<static_cast<float>(transparency) / 255.f * 100.f
	<< "% transparency";
    return oss.str();
  }
};

template <typename T> struct ColoredShape2 : T
{

  static_assert(is_base_of<Shape,T>::value,
		"Template argument must be a Shape");

  string color;

  ColoredShape2()
  {}
  
  explicit ColoredShape2(const string& color) : color{color}
  {}

  string str() const override
  {
    ostringstream oss;
    oss << shape.str()<< " has the color " << color;
    return oss.str();
  }
};

template <typename T> struct TransparentShape2 : T
{
  uint8_t transparency;

  template<typename...Args>
  
  TransparentShape2(const uint8_t transparency, Args...args) : T::T(args...), transparency{transparency}
  {
  }

  string str() const override
  {
    ostringstream oss;
    oss << T::str() << " has "
	<< static_cast<float>(transparency) / 255.f*100.f
	<< "% transparency";
    return oss.str();
  }
};

int main()
{

  TransparentShape2<Square> hidden_square{0,15};
  cout << hidden_square.str() << endl; 
  
  getchar();
  return 0;
}
