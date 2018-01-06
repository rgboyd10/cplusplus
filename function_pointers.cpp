using namespace std;

int main()
{
  typedef int (*Func)();
  Func f = []{return 10;};

  f(); // invoke lambda via function pointer

  //nested lambda
  auto mode = public_announcement;
  vector<Cabin> cabins;
  for_each(cabins.begin(), cabins.end(), [=](Cabin& cabin)
	   {
	     for_each(cabin.seat_screens().begin(), cabin.seat_screens().endl(), [=](SeatScreen* seat_screen) {seat_screen.set_mode(mode);});
	   }
}
