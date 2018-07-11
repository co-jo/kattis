#include <string>
#include <iostream>

constexpr double pi = 3.14159265358979323846;
using namespace std;

int main() {
  int segments, rings;
  cin >> segments >> rings;
  double radius;
  cin >> radius;

  int aseg, aring, bseg, bring;
  cin >> aseg >> aring >> bseg >> bring;

  if (aring < bring) {
    swap(aring, bring);
    swap(aseg, bseg);
  }

  // Length between each ring.
  double ruint = radius/double(rings);

  double inward = abs(aring - bring) * ruint;
  double proportion = abs(aseg - bseg)/double(segments);
  // Radius of inner circle.
  double rinner = radius/double(rings) * bring;
  double across = proportion * pi * rinner;

  // Two scenarios: Come in same ring level to minimize walk across.
  double inacross = inward + across;
  // Go directly to origin, back out to b.
  double inout = (aring * ruint) + (bring * ruint);

  cout << fixed;
  cout << min(inacross, inout) << endl;

  return 0;
}
