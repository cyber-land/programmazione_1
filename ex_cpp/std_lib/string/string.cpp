#include <string>
#include <cassert>
using namespace std;
int main() {

  const string str("Hello foo, bar and world!");

  // c/cpp conversion
  char a[] = "string";
  string b("This is a string.");
  string d(a);
  b = a;
  const char* e = b.c_str(); // e points to b
  b += " hello";

  // Lexicographical comparison
  assert( !(b <= a) );
  assert( !(e <= d) );
  assert( d == a );
  assert( b == e );


  // informations
  int len = str.length(); // non conta il terminatore

  // replacement
  string _s = "Hello foo, bar and world!", alternate = "Hello foobar";
  // str.replace( start_pos_str, n_pos_str, with, with_pos_start, n_pos_with );
  _s.replace(6, 3, "bar");            //"Hello bar, bar and world!"
  _s.replace(19, 5, alternate, 6, 3); //"Hello foo, bar and foo!"
  _s.replace(19, 5, alternate, 6);    //"Hello foo, bar and foobar!"
  _s.replace(_s.begin() + 6, _s.end(), { 'B', 'o' }); //"Hello Bo"

  // conversion
  string con = to_string(4054);

  // splitting
  string newstr;
  newstr = str.substr(11); // "bar and world!"
  newstr = str.substr(15, 3); // "and"
  newstr = str.substr(); // "Hello foo, bar and world!"


  // accessing a character
  char c = str[6];  // 'w'
  c = str.at(7);    // 'o'
  // front() returns a reference to the first character
  c = str.front();  // 'H'
  // back() returns a reference to the last character
  c = str.back();   // '!'

  // check if a string is a prefix of another
  string p = "Hello";
  bool is_prefix = mismatch(p.begin(), p.end(), str.begin(), str.end()).first == p.end();
  assert(is_prefix);


  // looping through each character
  for (auto c : str) {}

  // concatenation
  string conc = "123";
  const char *comma = ", ";
  conc += conc + comma;
  conc.append("test");

  /* finding character(s) in a string */ {
  string str1 = "this is random string oiwao2j3";
  string str2 = "oiwao2j3", str3 = "random tring";
  str1.find(str2, 13);  // 22 - search skipping initial chars
  str1.rfind("s ");     // 6  - find the last substring
  assert( str1.find(str3) == string::npos );
  int pos = 0, len = 6; // of str3
  assert( str1.find(str3.c_str(), pos, len) != string::npos );

  // these don't search for substrings, but rather for chars contained in the search string
  // find_first_of     : Find first occurrence of characters
  // find_first_not_of : Find first absence of characters
  // find_last_of      : Find last occurrence of characters
  // find_last_not_of  : Find last absence of characters
  string s = "dog dog cat cat";
  s.find_last_of("gzx"); // return 6
  // In this case, the last occurrence of 'g' was found at position 6 (the other characters weren't found)
  }
  return 0;
}
