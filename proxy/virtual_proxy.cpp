#include <string>
using namespace std;

struct Image
{
  virtual ~Image() = default;
  virtual void draw() = 0;
  
};

struct Bitmap : Image
{
  Bitmap(const string& filename)
  {
    cout << "Loading a file from " << filename << endl;
  }
  
  void draw() override
  {
    cout << "Drawing image" << endl;
  }
};

struct LazyBitmap : Image
{
  LazyBitmap(const string& filename) : filename{filename}, bmp{nullptr}
  {}

  void draw() override
  {
    if(!bmp)
      {
	bmp = new Bitmap{filename};
      }
    bmp->draw();
  }
  ~LazyBitmap()
  {
    delete bmp;
  }
private:
  Bitmap* bmp;
  string filename;
};

void draw_image(Image& img)
{
  cout << "About to draw the image" << endl;
  img.draw();
  cout << "Done drawing the image" << endl;
}

void virtual_proxy()
{
  LazyBitmap bmp{"pokemon.png"};
  draw_image(bmp);
  draw_image(bmp);
}

int main()
{
  virtual_proxy();

  getchar();
  return 0;
}
