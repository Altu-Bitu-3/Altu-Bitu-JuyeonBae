#include<iostream> //입출력 헤더
#include<set> //셋 헤더
using namespace std;

bool isCycle(set<string>& s, string str) {
    int cnt = str.length(); //cnt = 단어 길이

    while (cnt--) {
        // 같은 단어가 있는 경우
        if (s.find(str) != s.end()) { //같은 단어가 있는 경우
            return true; //같은 단어 있으면 true 반환
        }

        // 시계 방향대로, 앞 글자를 떼어서 뒤에 붙여줌.
        str = str + str[0]; //앞 글자 떼서 뒤에 붙여줌
        str.erase(0, 1); //앞 글자 삭제
    }
    return false; //같은 단어 없으면 false 반환
}
int main() {
    int n; //단어 개수
    string str; //단어
    set<string> word; // 단어 저장

    // 입력
    cin >> n; //단어 개수 입력
    while (n--) { //단어 개수만큼 반복
        cin >> str; //단어 입력

        // 같은 단어 없으면 추가
        if (!isCycle(word, str)) { //word에 str에 입력된 단어가 없는 경우
            word.insert(str); //단어 추가
        }
    }

    // 출력
    cout << word.size(); //word.size() = 서로 다른 단어의 개수
}