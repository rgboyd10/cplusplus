#include <cstdio>
#include <ostream>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct Pingable
{
  virtual ~Pingable() = default;
  virtual wstring ping(const wstring& message) = 0;
};

struct Pong : Pingable
{
  wstring ping(const wstring& message) override
  {
    return message + L" pong";
  }
};

#include <cpprest/http_client.h>
using namespace web;
using namespace http;
using namespace client;

struct RemotePong : Pingable
{
  wstring ping(const wstring& message) override
  {
    http_client client(U("https://localhost:9149/"));
    uri_builder builder(U("/api/pingpong/"));
    builder.append(message);
    pplx::task<wstring> task = client.request(methods::GET, builder.to_string())
      .then([=](http:response r)
	    {
	      return r.extract_string();
	    });
    task.wait();
    return task.get();
	    
  }
};

void tryit(Pingable& p)
{
  wcout << p.ping(L"ping") << "\t";
}

int main()
{
  RemotePong pp;
  for(size_t i = 0; i < 10; i++)
    {
      tryit(pp);
    }
  
  getchar();
  return 0;
}
