//问题描述：
//  第一题，硬币找零，最少多少张纸币   
//  有面值1,5,10,50,100，分别对应变量：a、b、c、d、e
//  若有k元钱，最少多少张纸币能找零，若不能则输出-1


#include<iostream>
using namespace std;
 
int main()
{
    int a,b,c,d,e;
    int k;
 
    cin >> a >> b >> c >> d >> e;
    cin >> k;
 
    int res = 0;
 
    if(k >= 100 && e) {
        int s = k/100;
        if(s <= e) {
            res += s;
            k = k%100;
        } else {
            res += e;
            k = k - (e * 100);
        }
    }
 
    if(k >= 50 && d) {
        int s = k/50;
        if(s <= d) {
            res += s;
            k = k%50;
        } else {
            res += d;
            k = k - (d * 50);
        }
    }
 
    if(k >= 10 && c) {
        int s = k/10;
        if(s <= c) {
            res += s;
            k = k%10;
        } else {
            res += c;
            k = k - (c * 10);
        }
    }
 
    if(k >= 5 && b) {
        int s = k/5;
        if(s <= b) {
            res += s;
            k = k%5;
        } else {
            res += b;
            k = k - (b * 5);
        }
    }
 
    if(k <= a)
        cout << res+k;
    else
        cout << -1;
    return 0;
}