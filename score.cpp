#include <vector>
#include <algorithm>

int score(const std::vector<int>& dice) {
  std::vector<int> comp{1, 2, 3, 4, 5, 6};
  
  int result = 0;
  
  int n_3 = 0;
  int number = 0;
  
  for(auto& i : comp)
  {
    n_3 = std::count(dice.begin(), dice.end(), i);
    if (n_3 >= 3)
    {
      number = i;
      break;
    }
  }
  
  if (number != 1) result = number*100;
  else result = 1000;
  
  int j = 0;
  for(auto& i: dice)
  {
    if(((number == 1) || (number == 5)) && (i == number)) 
    {
      j++;
      if(j>3)
      {
        if(i == 1) result+=100;
        if(i == 5) result+=50;
      }
    }
    else if(i == 1) result+=100;
    else if(i == 5) result+=50;
  }
  
  return result;
}