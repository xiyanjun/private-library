#include <iostream>
#include <math.h>
using namespace std;
//直接调用IsSquare函数，输入为四个点的坐标，输出为true or false;
//求两点间的距离
double Distance(int x1,int y1,int x2,int y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
//判断三个点是否构成直角，第一个参数点是顶点
bool IsRightAngle(int x1,int y1,int x2,int y2,int x3,int y3){
    if((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1)==0)
        return true;
    return false;
}
bool IsSquare(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    if(x1==x2&&x2==x3)
        return false;
    double s12=Distance(x1,y1,x2,y2);
    double s13=Distance(x1,y1,x3,y3);
    double s14=Distance(x1,y1,x4,y4);
    double s23=Distance(x2,y2,x3,y3);
    double s24=Distance(x2,y2,x4,y4);
    double s34=Distance(x3,y3,x4,y4);
    if(s12==s13&&s24==s34&&s12==s24){
        if(IsRightAngle(x1,y1,x2,y2,x3,y3)) return true;
        else return false;
    }
    if(s12==s14&&s23==s34&&s12==s23){
        if(IsRightAngle(x1,y1,x2,y2,x4,y4)) return true;
        else return false;
    }
    if(s13==s14&&s23==s24&&s13==s23){
        if(IsRightAngle(x1,y1,x3,y3,x4,y4)) return true;
        else return false;
    }
    return false;
}
int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    cout<<IsSquare(x1,y1,x2,y2,x3,y3,x4,y4)<<endl;
    return 0;
}
