#include <iostream>

using namespace std;

class bar3d
{
  public:
  	int width;
    int height;
    int depth;
  	bar3d(int width_, int height_, int depth_){width=width_;height=height_;depth=depth_;
  	if(width < 0 || width > 1000 || height < 0 || height > 1000 || depth < 0 || depth > 1000)
    {
      width = 0;
      height = 0;
      depth = 0;
    }
    }
};
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    bar3d B(a,b,c);
    cout<<B.width<<","<<B.height<<","<<B.depth<<"."<<endl;

    return 0;
}
