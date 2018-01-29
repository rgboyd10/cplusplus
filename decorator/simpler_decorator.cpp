
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

int main()
{
  Circle circle{5};
  cout << circle.str() << endl;

  ColoredShape red_circle{circle, "red"};
  cout << red_circle.str() << endl;

  TransparentShape half_transparent_circle{circle, 128};
  cout << half_transparent_circle.str() << endl;

  TransparentShape half_tr_red_circle{red_circle, 128};
  cout << half_tr_red_circle.str() << endl;
  
  getchar();
  return 0;
}
