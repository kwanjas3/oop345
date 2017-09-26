#include <map>
#include <iostream>
using namespace std;

int main() {

	map<int, char> example = { { 1, 'a' },{ 3, 'b' },{ 5, 'c' },{ 7, 'd' } };

	auto search = example.find(3);
	if (search != example.end()) {
		cout << "Found " << search->first << " " << search->second << '\n';
	}
	else {
		cout << "Not found\n";
	}

}

#if 0
// map_at.cpp  
// compile with: /EHsc  
#include <map>  
#include <iostream>  
  
typedef std::map<char, int> Mymap;   
int main()   
    {   
    Mymap c1;   
  
    c1.insert(Mymap::value_type('a', 1));   
    c1.insert(Mymap::value_type('b', 2));   
    c1.insert(Mymap::value_type('c', 3));   
  
// find and show elements  
    std::cout << "c1.at('a') == " << c1.at('a') << std::endl;   
    std::cout << "c1.at('b') == " << c1.at('b') << std::endl;   
    std::cout << "c1.at('c') == " << c1.at('c') << std::endl;   
  
    return (0);   
    }   

#endif 
