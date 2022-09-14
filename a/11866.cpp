#include<iostream>
#include<queue>
using namespace std;

int main(){
    //입력
    int n,k;
    queue<int> q;
    cin>>n>>k;

    //큐에 1번부터 n번까지 push
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    cout<<"<";
    //k번째 수 pop
    while(!q.empty()){
        for(int i=1;i<k;i++) {
            q.push(q.front());    //i번째 숫자를 맨뒤로 push하고
            q.pop();            //pop해줌(큐 FIFO)
        }
        cout<<q.front();
        if(q.size()!=1){ 	//마지막 원소 전까지만 , 출력
            cout<<", ";
        }
        q.pop();
    }
    cout<<">";
}
