#include <iostream>
#include <string>
#include <vector>
#include <hash>

using namespace std;

int main()
{
  //declare variables
  
  vector<string> animals {dog, cat, dog, horse, elephant};
  hash map_animals
    (
     {dog,0},
     {cat,0},
     {horse,0},
     {elephant,0}
     );
  
 for(int x = 0; x < animals.size(); x++)
   {
     for(int y = 0; y < animals.size(); y++)
       {
	 if(animals[y] == animals[x])
	   {
	     map_animals[1]++;
	   }
       }
   }

 for(int a = 0; a < animals.size(); a++)
   {
     cout << animals[a] << map_animals[a,1] << endl; 
   }
}
