#include "Resource.h"
#include <string>

using namespace std;

int main()
{
  {
    Resource localResource("local");
    string localString = localResource.GetName();
  }
  
  Resource* pResource = new Resource("created with new");
  string newString = pResource->GetName();
  Resource* p2 = pResource;
  string string2 = p2->GetName();
  delete pResource;
  //string string3 = pResource->GetName();
  //pResource = NULL;
  //delete pResource;
  //delete p2;
}
