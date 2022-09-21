#include <iostream>
using namespace std;

int main(){
    int red,brown; //빨간 타일, 갈색 타일 입력
    cin>>red>>brown;

    //갈색 타일 깔려면 방크기 3x3부터 가능
    for(int i=3;i<5000;i++){
        for(int j=3;j<5000;j++){
            /* 갈색 타일 = (i-2)*(j-2)
             * 빨간 타일 = 갈색 타일 가로*2 + 세로*2 + 모서리 4 */
            //i, j 증가시키면서 (2*(i-2)+2*(j-2)+4)==red 만족하면.
            if((2*(i-2)+(2*(j-2))+4)==red){
                //i*j == 타일의 합 일 경우, i와 j 중 큰 수를 먼저 출력
                if(i*j==(red+brown)&&i>=j){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
    }
    return 0;
}