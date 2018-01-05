#include <string>
#ifndef _Noise_H
#define _Noise_H
#include <memory>

class Noise
{
 private:
  std::string sim;
 public:
  Noise(std::string sim);
  Noise();
  ~Noise();
};
#endif
